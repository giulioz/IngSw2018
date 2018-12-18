package dogedroid.com.watchdoge;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v4.view.MenuItemCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import com.squareup.picasso.MemoryPolicy;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.onboarding.OnBoarding_1;
import dogedroid.com.watchdoge.utility.DogeLogAdapter;

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
        DogeLogAdapter listAdaptor = new DogeLogAdapter(getApplicationContext(), "/unread");
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

        setupAlarm();


        //Storico Intrusioni
        historyText.setOnClickListener((v) ->
                startActivity(new Intent(this, DogeLogActivity.class)));

        //Ip
        this.connectedText.setText(DiscoveryActivity.dogeAddress.substring(1));

    }

    // Prevent Back Button
    public void onBackPressed() {
        return;
    }

    private void setupAlarm() {
        String url = DiscoveryActivity.getUrl("/alarm/status");
        JsonObjectRequest request = new JsonObjectRequest(Request.Method.GET, url, null,
                (response) -> {
                    try {
                        alarmSwitch.setEnabled(true);
                        alarmSwitch.setText("Allarme");
                        alarmSwitch.setChecked(response.getBoolean("active"));
                        alarmSwitch.setOnClickListener((v) -> {
                            if (alarmSwitch.isChecked()) {
                                Toast.makeText(getApplicationContext(), "ON", Toast.LENGTH_SHORT).show();
                                toggleAlarm("on");
                            } else {
                                Toast.makeText(getApplicationContext(), "OFF", Toast.LENGTH_SHORT).show();
                                toggleAlarm("off");
                            }
                        });
                    } catch (JSONException e) {
                        Log.d("DASHBOARD", "setupAlarm: errore json");
                    }
                },
                (err) -> {
                    Log.d("DASHBOARD", "setupAlarm: errore get");
                }
        ){
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

    private void toggleAlarm(String add) {
        String url = DiscoveryActivity.getUrl("/alarm/" + add);

        StringRequest request = new StringRequest(Request.Method.POST, url,
                (response) -> {
                },
                (error) -> {
                    Log.d("DASHBOARD", "toggleAlarm: errore toggle");
                }) {
            @Override
            public Map<String, String> getHeaders() {
                Map<String, String> params = new HashMap<String, String>();
                params.put("Content-Type", "application/json; charset=UTF-8");
                params.put("Authorization", "Bearer " + DiscoveryActivity.token);
                return params;
            }

        };
        RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
        queue.add(request);
    }

    //Menu stuff:
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.dashboard_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.action_unpair:
                SharedPreferences pref = getSharedPreferences("watchdoge",Context.MODE_PRIVATE);
                pref.edit().putString("authToken","").commit();
                startActivity(new Intent(this, OnBoarding_1.class));
                return true;

            case R.id.action_credits:
                startActivity(new Intent(this, CreditsActivity.class));
                return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
