package dogedroid.com.watchdoge;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

public class DashboardActivity extends AppCompatActivity {
    Button liveFeedBtn;
    TextView connectedText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dashboard);

        this.connectedText = findViewById(R.id.connectedText_dashboard);

        this.liveFeedBtn = findViewById(R.id.live_activity_btn);

        this.connectedText.setText(DiscoveryActivity.dogeAddress);

    }
}
