package dogedroid.com.watchdoge;

import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.utility.LiveFeed;

public class LiveFeedActivity extends AppCompatActivity {
    private final String TAG = "LIVEFEED";
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
        stopButton.setOnClickListener(v -> stopLiveButton());

        moveRightButton.setOnTouchListener(new RepeatListener(400, 100, view -> {
            sendCommand("right");
        }));
        moveLeftButton.setOnTouchListener(new RepeatListener(400, 100, view -> {
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
        RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
        queue.add(request);
    }

    private class RepeatListener implements View.OnTouchListener {

        private Handler handler = new Handler();

        private int initialInterval;
        private final int normalInterval;
        private final View.OnClickListener clickListener;
        private View touchedView;

        private Runnable handlerRunnable = new Runnable() {
            @Override
            public void run() {
                if (touchedView.isEnabled()) {
                    handler.postDelayed(this, normalInterval);
                    clickListener.onClick(touchedView);
                } else {
                    handler.removeCallbacks(handlerRunnable);
                    touchedView.setPressed(false);
                    touchedView = null;
                }
            }
        };

        public RepeatListener(int initialInterval, int normalInterval,
                              View.OnClickListener clickListener) {
            if (clickListener == null)
                throw new IllegalArgumentException("null runnable");
            if (initialInterval < 0 || normalInterval < 0)
                throw new IllegalArgumentException("negative interval");

            this.initialInterval = initialInterval;
            this.normalInterval = normalInterval;
            this.clickListener = clickListener;
        }

        public boolean onTouch(View view, MotionEvent motionEvent) {
            switch (motionEvent.getAction()) {
                case MotionEvent.ACTION_DOWN:
                    handler.removeCallbacks(handlerRunnable);
                    handler.postDelayed(handlerRunnable, initialInterval);
                    touchedView = view;
                    touchedView.setPressed(true);
                    clickListener.onClick(view);
                    return true;
                case MotionEvent.ACTION_UP:
                case MotionEvent.ACTION_CANCEL:
                    handler.removeCallbacks(handlerRunnable);
                    touchedView.setPressed(false);
                    touchedView = null;
                    return true;
            }

            return false;
        }

    }
}
