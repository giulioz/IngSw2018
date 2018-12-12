package dogedroid.com.watchdoge.onboarding;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.DiscoveryActivity;
import dogedroid.com.watchdoge.R;

public class OnBoarding_4 extends AppCompatActivity {

    Button nextBtn;
    Button backBtn;
    TextView ipDoge;
    ImageView logo;
    EditText input;
    String key;

    @Override

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_on_boarding_4);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        nextBtn = findViewById(R.id.button_AcceptOnBoarding_4);
        backBtn = findViewById(R.id.button_BackOnBoarding_4);
        ipDoge = findViewById(R.id.ip_dogefound);
        ipDoge.setText(OnBoarding_3.ip.substring(1));
        logo = findViewById(R.id.doge_logofound);
        input = findViewById(R.id.input_pin);
        nextBtn.setOnClickListener(v -> {
            key = input.getText().toString();
            //sendKey();
            startActivity(new Intent(this, OnBoarding_4.class));
        });
        backBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_3.class)));
    }

    /*private void sendKey(String add) {
        String url = DiscoveryActivity.getUrl("/pair");

        StringRequest request = new StringRequest(Request.Method.POST, url,
                (response) -> {
                },
                (error) -> {
                    Log.d("PAIRKEY", "sendKey: errore send");
                }) {
            @Override
            public Map<String, String> getHeaders() throws AuthFailureError {
                Map<String, String> params = new HashMap<String, String>();
                params.put("Content-Type", "application/json; charset=UTF-8");
                params.put("Authorization", "Bearer " + key);
                return params;
            }

        };
        RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
        queue.add(request);
    }*/

}
