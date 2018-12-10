package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import com.squareup.picasso.MemoryPolicy;
import com.squareup.picasso.Picasso;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.utility.ListaLog;
import okhttp3.Response;

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
                toggleAlarm("on");
            }
            else {
                Toast.makeText(getApplicationContext(), "OFF", Toast.LENGTH_SHORT).show();
                toggleAlarm("off");
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

    private void toggleAlarm(String add){
        String url = DiscoveryActivity.getUrl("/alarm/" + add);

        StringRequest request = new StringRequest(Request.Method.POST, url,
                (response) -> {},
                (error) -> {
                    Log.d("DASHBOARD", "toggleAlarm: errore toggle");
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
