package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.squareup.picasso.MemoryPolicy;
import com.squareup.picasso.Picasso;

import dogedroid.com.watchdoge.utility.ListaLog;

public class DashboardActivity extends AppCompatActivity {
    TextView connectedText;
    ImageView liveFeedImage;
    RecyclerView unreadLog;
    TextView historyText;
    Switch alarmSwitch;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dashboard);

        this.connectedText = findViewById(R.id.connectedText_dashboard);
        this.liveFeedImage = findViewById(R.id.live_image_view);
        this.unreadLog = findViewById(R.id.unread_log_view);
        this.historyText = findViewById(R.id.history_text);
        this.alarmSwitch = findViewById(R.id.on_off_switch);

        //Dogelog (Unread)
        ListaLog listAdaptor = new ListaLog(getApplicationContext(), "/unread");
        unreadLog.setAdapter(listAdaptor);
        unreadLog.setLayoutManager(new LinearLayoutManager(this));

        //Live Image
        DiscoveryActivity.picasso
                .load(DiscoveryActivity.getUrl("/shoot"))
                .memoryPolicy(MemoryPolicy.NO_CACHE, MemoryPolicy.NO_STORE)
                .into(liveFeedImage);

        liveFeedImage.setOnClickListener((v) ->
                startActivity(new Intent(this, LiveFeedActivity.class))
        );

        alarmSwitch.setOnClickListener((v) -> {
            if(alarmSwitch.isChecked()){
                Toast.makeText(getApplicationContext(), "ON", Toast.LENGTH_SHORT).show();
            }
            else {
                Toast.makeText(getApplicationContext(), "OFF", Toast.LENGTH_SHORT).show();
            }
        });

        //Storico Intrusioni
        historyText.setOnClickListener((v) ->
                startActivity(new Intent(this, DogeLogActivity.class)));

        //Ip
        this.connectedText.setText(DiscoveryActivity.dogeAddress.substring(1));

    }

    // Prevent Back Button
    public void onBackPressed() { return; }


}
