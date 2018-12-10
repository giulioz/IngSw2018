package dogedroid.com.watchdoge;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.ImageView;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.utility.LiveFeed;

public class LiveFeedActivity extends AppCompatActivity {
    private ImageView liveImage;
    private Button moveLeftButton;
    private Button moveRightButton;
    private Button stopButton;
    private LiveFeed liveThread;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_live_feed);
        liveImage = findViewById(R.id.live_image);
        moveLeftButton = findViewById(R.id.move_left_btn);
        moveRightButton = findViewById(R.id.move_right_btn);
        stopButton = findViewById(R.id.stop_live_btn);

        liveThread = new LiveFeed(liveImage);
        liveThread.execute();
        stopButton.setOnClickListener(v -> liveThread.stopLive());

        moveLeftButton.setOnClickListener(v -> sendCommand("left"));
        moveRightButton.setOnClickListener(v -> sendCommand("right"));

    }

    @Override
    protected void onPause() {
        super.onPause();
        liveThread.stopLive();
    }

    private void sendCommand(String add){
        String url = DiscoveryActivity.getUrl("/move/" + add);

        StringRequest request = new StringRequest(Request.Method.POST, url,
                (response) -> {},
                (error) -> {
                    Log.d("LIVEFEED", "sendCommand: errore send");
                }){
            @Override
            public Map<String, String> getHeaders() throws AuthFailureError {
                Map<String, String> params = new HashMap<String, String>();
                params.put("Content-Type", "application/json; charset=UTF-8");
                params.put("Authorization", "Bearer " + DiscoveryActivity.token);
                return params;
            }

        };
        RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
        queue.add(request);
    }
}
