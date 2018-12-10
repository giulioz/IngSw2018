package dogedroid.com.watchdoge;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageView;

import dogedroid.com.watchdoge.utility.LiveFeed;

public class LiveFeedActivity extends AppCompatActivity {
    private ImageView liveImage;
    private Button stopButton;
    private LiveFeed liveThread;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_live_feed);
        liveImage = findViewById(R.id.live_image);
        stopButton = findViewById(R.id.stop_live_btn);

        liveThread = new LiveFeed(liveImage);
        liveThread.execute();
        stopButton.setOnClickListener(v -> liveThread.stopLive());

    }

    @Override
    protected void onPause() {
        super.onPause();
        liveThread.stopLive();
    }
}
