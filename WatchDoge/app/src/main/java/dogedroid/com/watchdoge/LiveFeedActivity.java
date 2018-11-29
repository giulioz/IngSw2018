package dogedroid.com.watchdoge;

import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class LiveFeedActivity extends AppCompatActivity {
    public final int refreshIntervalMs = 42;

    private ImageView liveImage;
    private Button stopButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_live_feed);
        liveImage = findViewById(R.id.live_image);
        stopButton = findViewById(R.id.stop_live_btn);
        image_livefeed();
    }



    private void image_livefeed() {
        final Handler handler = new Handler();
        final Runnable imageUpdater = new Runnable() {
            @Override
            public void run() {
                new LiveFeed(liveImage).execute("http:/" + Pairing.dogeAddress + ":8000/shoot");
                handler.postDelayed(this, refreshIntervalMs);
            }
        };
        handler.post(imageUpdater);
        stopButton.setOnClickListener(v -> handler.removeCallbacks(imageUpdater));
    }
}
