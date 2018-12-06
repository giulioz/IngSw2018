package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import dogedroid.com.watchdoge.dogelog.DogeLogActivity;
import dogedroid.com.watchdoge.dogelog.ListaLog;

public class DashboardActivity extends AppCompatActivity {
    Button moveLeft;
    Button moveRight;
    TextView connectedText;
    ImageView liveFeedImage;
    LiveFeed liveThread;
    RecyclerView unreadLog;
    TextView historyText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dashboard);

        this.connectedText = findViewById(R.id.connectedText_dashboard);
        this.moveLeft = findViewById(R.id.left_btn);
        this.moveRight = findViewById(R.id.right_btn);
        this.liveFeedImage = findViewById(R.id.live_image_view);
        this.unreadLog = findViewById(R.id.unread_log_view);
        this.historyText = findViewById(R.id.history_text);

        liveThread = new LiveFeed(liveFeedImage);
        liveThread.execute();
        
        ListaLog listAdaptor = new ListaLog(getApplicationContext(), "/unread");
        unreadLog.setAdapter(listAdaptor);
        unreadLog.setLayoutManager(new LinearLayoutManager(this));

        historyText.setOnClickListener((v) ->
                startActivity(new Intent(this, DogeLogActivity.class)));

        this.connectedText.setText(DiscoveryActivity.dogeAddress);

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        liveThread.stopLive();
    }
}
