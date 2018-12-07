package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import dogedroid.com.watchdoge.dogelog.DogeLogActivity;
import dogedroid.com.watchdoge.dogelog.ListaLog;

public class DashboardActivity extends AppCompatActivity {
    TextView connectedText;
    ImageView liveFeedImage;
    RecyclerView unreadLog;
    TextView historyText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dashboard);

        this.connectedText = findViewById(R.id.connectedText_dashboard);
        this.liveFeedImage = findViewById(R.id.live_image_view);
        this.unreadLog = findViewById(R.id.unread_log_view);
        this.historyText = findViewById(R.id.history_text);

        //Dogelog (Unread)
        ListaLog listAdaptor = new ListaLog(getApplicationContext(), "/unread");
        unreadLog.setAdapter(listAdaptor);
        unreadLog.setLayoutManager(new LinearLayoutManager(this));

        //Live Image
        String url = "http:/" + DiscoveryActivity.dogeAddress + ":8000/shoot";
        Picasso.get().load(url).into(liveFeedImage);
        liveFeedImage.setOnClickListener((v) ->
                startActivity(new Intent(this, LiveFeedActivity.class))
        );

        //Storico Intrusioni
        historyText.setOnClickListener((v) ->
                startActivity(new Intent(this, DogeLogActivity.class)));

        //Ip
        this.connectedText.setText(DiscoveryActivity.dogeAddress.substring(1));

    }

    // Prevent Back Button
    public void onBackPressed() { return; }


}
