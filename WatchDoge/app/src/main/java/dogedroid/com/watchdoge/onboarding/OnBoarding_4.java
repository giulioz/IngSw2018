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
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.R;

public class OnBoarding_4 extends AppCompatActivity {
    Button nextBtn;
    Button backBtn;
    TextView ipDoge;
    TextView waitingText;
    ImageView logo;
    EditText input;
    String clientKey;

    RequestQueue queue;
    SendKey sendThread;
    GetClientKey getThread;

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

        nextBtn.setOnClickListener(v -> sendThread.execute());
        backBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_3.class)));

        queue = Volley.newRequestQueue(getApplicationContext());

        sendThread = new SendKey();
        getThread = new GetClientKey();
        getThread.execute();
    }

    private class SendKey extends AsyncTask<Void, Void, Void> {
        private boolean run;
        private boolean succeded;

        public void stopThread() {
            this.run = false;
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            super.onPostExecute(aVoid);
            if (succeded) {
                Intent i = new Intent(getApplicationContext(), OnBoarding_5.class);
                i.putExtra("token", clientKey);
                startActivity(i);
            }
        }

        @Override
        protected Void doInBackground(Void... voids) {
            run = true;
            succeded = false;
            String url = "http:/" + OnBoarding_3.ip + ":8000/pair";


            Map<String, String> params = new HashMap<>();
            params.put("clientKey", clientKey);
            params.put("pairKey", input.getText().toString());

            JSONObject json = new JSONObject(params);

            Log.d("PORCODIO", "SendKey params: " + json);
            Log.d("PORCODIO", "SendKey: " + url);

            while (run) {
                Log.d("PORCODIO", "doInBackground: LOOP");
                StringRequest request = new StringRequest(Request.Method.POST, url,
                        (response) -> {
                            succeded = true;
                            run = false;
                        },
                        (error) -> {
                            Log.d("PAIRKEY", "sendKey: errore send");
                        }) {
                    @Override
                    public Map<String, String> getHeaders() {
                        Map<String, String> params = new HashMap<>();
                        params.put("Content-Type", "application/json");
                        return params;
                    }

                    @Override
                    public byte[] getBody() {
                        return json.toString().getBytes();
                    }
                };
                queue.add(request);
                Thread.currentThread();
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            return null;
        }
    }

    private class GetClientKey extends AsyncTask<Void, Void, Void> {
        private boolean run;

        public void stopThread() {
            this.run = false;
        }

        @Override
        protected Void doInBackground(Void... voids) {
            run = true;
            String url = "http:/" + OnBoarding_3.ip + ":8000/pair";
            while (run) {
                StringRequest request = new StringRequest(Request.Method.GET, url,
                        (response) -> {
                            clientKey = response.substring(1, response.length() - 1);
                            Log.d("PORCODIO", "GET client key: " + clientKey);
                            nextBtn.setVisibility(View.VISIBLE);
                            waitingText.setVisibility(View.GONE);
                            input.setVisibility(View.VISIBLE);
                            run = false;
                        },
                        (err) -> {
                            Log.d("ONBOARDING 4", "getClientKey: errore fetch");
                        }
                ) {
                };
                queue.add(request);
                Thread.currentThread();
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            return null;
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        sendThread.stopThread();
        getThread.stopThread();
    }
}
