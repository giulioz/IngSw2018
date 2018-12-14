package dogedroid.com.watchdoge.onboarding;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.DiscoveryActivity;
import dogedroid.com.watchdoge.R;

public class OnBoarding_4 extends AppCompatActivity {

    Button nextBtn;
    Button backBtn;
    TextView ipDoge;
    TextView waitingText;
    ImageView logo;
    EditText input;
    String clientKey;

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
        waitingText = findViewById(R.id.waiting_text);

        nextBtn.setOnClickListener(v -> new SendKey().execute());
        backBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_3.class)));

        new GetClientKey().execute();
    }

    private class SendKey extends AsyncTask<Void,Void,Void>{

        @Override
        protected Void doInBackground(Void... voids) {
            String url = DiscoveryActivity.getUrl("/pair");

            StringRequest request = new StringRequest(Request.Method.POST, url,
                    (response) -> {
                        Intent i = new Intent(getApplicationContext(), OnBoarding_5.class);
                        i.putExtra("token", response);
                        startActivity(i);
                    },
                    (error) -> {
                        Log.d("PAIRKEY", "sendKey: errore send");
                    }) {

                @Override
                protected Map<String, String> getParams() {
                    Map<String, String> params = new HashMap<>();
                    params.put("clientKey", clientKey);
                    params.put("pairKey", input.getText().toString());
                    return params;
                }


            };
            RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
            queue.add(request);
            return null;
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            super.onPostExecute(aVoid);
            startActivity(new Intent(getApplicationContext(), OnBoarding_5.class));
        }
    }

    private class GetClientKey extends AsyncTask<Void, Void, Void> {

        @Override
        protected Void doInBackground(Void... voids) {
            String url = DiscoveryActivity.getUrl("/pair");
            JsonObjectRequest request = new JsonObjectRequest(Request.Method.GET, url, null,
                    (response) -> {
                        try {
                            clientKey = response.getString("clientKey");
                            nextBtn.setVisibility(View.VISIBLE);
                            waitingText.setVisibility(View.GONE);
                            input.setVisibility(View.VISIBLE);

                        } catch (JSONException e) {
                            Log.d("ONBOARDING 4", "getClientKey: errore json");
                            e.printStackTrace();
                        }
                    },
                    (err) -> {
                        Log.d("ONBOARDING 4", "getClientKey: errore fetch");
                    }
            ) {
            };
            RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
            queue.add(request);
            return null;
        }
    }
}
