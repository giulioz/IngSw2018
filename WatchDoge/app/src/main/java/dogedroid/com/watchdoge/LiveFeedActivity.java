package dogedroid.com.watchdoge;

import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.Button;
import android.widget.ImageView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.utility.LiveFeed;
import dogedroid.com.watchdoge.utility.RepeatListener;

public class LiveFeedActivity extends AppCompatActivity {
    private final String TAG = "LIVEFEED";
    private ImageView liveImage;
    private Button moveLeftButton;
    private Button moveRightButton;
    private Button stopButton;
    private LiveFeed liveThread;
    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_live_feed);
        liveImage = findViewById(R.id.live_image);
        moveLeftButton = findViewById(R.id.move_left_btn);
        moveRightButton = findViewById(R.id.move_right_btn);
        stopButton = findViewById(R.id.stop_live_btn);
        queue = Volley.newRequestQueue(getApplicationContext());

        liveThread = new LiveFeed(liveImage);
        liveThread.execute();
        stopButton.setOnClickListener(v -> stopLiveButton());

        moveRightButton.setOnTouchListener(new RepeatListener(50, 150, view -> {
            sendCommand("right");
        }));
        moveLeftButton.setOnTouchListener(new RepeatListener(50, 150, view -> {
            sendCommand("left");
        }));

    }

    @Override
    protected void onPause() {
        super.onPause();
        if (liveThread.getStatus() == AsyncTask.Status.RUNNING)
            liveThread.stopLive();
    }

    private void stopLiveButton() {
        //Resume
        if (liveThread.getStatus() == AsyncTask.Status.FINISHED) {
            liveThread = new LiveFeed(liveImage);
            liveThread.execute();
            stopButton.setText(R.string.livefeed_stop);
        }
        //Stop
        else {
            liveThread.stopLive();
            stopButton.setText(R.string.livefeed_resume);
        }
    }

    private void sendCommand(String add) {
        String url = DiscoveryActivity.getUrl("/move/" + add);

        StringRequest request = new StringRequest(Request.Method.POST, url,
                (response) -> {
                },
                (error) -> Log.d(TAG, "sendCommand: errore send")) {
            @Override
            public Map<String, String> getHeaders() {
                Map<String, String> params = new HashMap<>();
                params.put("Content-Type", "application/json; charset=UTF-8");
                params.put("Authorization", "Bearer " + DiscoveryActivity.token);
                return params;
            }

        };
        queue.add(request);
    }
}
