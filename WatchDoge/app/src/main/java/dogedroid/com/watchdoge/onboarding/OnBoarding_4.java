package dogedroid.com.watchdoge.onboarding;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.WindowManager;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.android.volley.RequestQueue;
import com.android.volley.toolbox.Volley;

import dogedroid.com.watchdoge.R;
import dogedroid.com.watchdoge.utility.GetPairingKey;
import dogedroid.com.watchdoge.utility.SendPairingKey;

public class OnBoarding_4 extends AppCompatActivity {
    private final String TAG = "PORCODIO";
    Button nextBtn;
    Button backBtn;
    TextView ipDoge;
    TextView waitingText;
    ImageView logo;
    EditText input;
    String clientKey;
    ProgressBar progressBar;

    RequestQueue queue;
    SendPairingKey sendThread;
    GetPairingKey getThread;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_on_boarding_4);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        nextBtn = findViewById(R.id.button_AcceptOnBoarding_4);
        backBtn = findViewById(R.id.button_BackOnBoarding_4);
        ipDoge = findViewById(R.id.ip_dogefound);
        logo = findViewById(R.id.doge_logofound);
        progressBar = findViewById(R.id.progressBarOnboarding4);
        input = findViewById(R.id.input_pin);
        input.setOnEditorActionListener((v, actionId, event) -> {
            if (actionId==EditorInfo.IME_ACTION_DONE)
                executeSendThread();
            return false;
        });
        waitingText = findViewById(R.id.waiting_text);

        nextBtn.setOnClickListener(v -> executeSendThread());
        backBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_3.class)));

        queue = Volley.newRequestQueue(getApplicationContext());

        executeGetThread();
    }

    private void initSendThread() {
        Log.d(TAG, "initSendThread: SEND INIZIATO");
        sendThread = new SendPairingKey((succeded) -> {
            if (succeded) {
                Log.d(TAG, "initSendThread: SUCCEDED SEND");
                Intent i = new Intent(getApplicationContext(), OnBoarding_5.class);

                i.putExtra("token", clientKey);
                startActivity(i);
            } else {
                Log.d(TAG, "initSendThread: FAILED SEND");
                ipDoge.setText(R.string.waiting_OnBoarding_4);

                nextBtn.setVisibility(View.GONE);
                nextBtn.setText(R.string.button_AcceptOnBoarding_4);
                nextBtn.setBackgroundResource(R.color.colorPrimary);
                waitingText.setVisibility(View.VISIBLE);
                input.setVisibility(View.GONE);
                executeGetThread();
            }
        }, queue, clientKey, input);
    }

    public void executeSendThread(){
        if(sendThread.getStatus() == AsyncTask.Status.PENDING){
            nextBtn.setBackgroundResource(R.color.colorDisabled);
            nextBtn.setText(R.string.button_AcceptOnBoarding_4_waiting);
            sendThread.execute();
        }
    }

    private void executeGetThread() {
        progressBar.setVisibility(View.VISIBLE);
        getThread = new GetPairingKey(response -> {
            Log.d(TAG, "executeGetThread: RISPOSTA GET: " + response);
            clientKey = response.substring(1, response.length() - 1);
            ipDoge.setText(OnBoarding_3.ip.substring(1));
            nextBtn.setVisibility(View.VISIBLE);
            waitingText.setVisibility(View.GONE);
            input.setVisibility(View.VISIBLE);
            progressBar.setVisibility(View.GONE);
            initSendThread();
        }, queue);

        getThread.execute();
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (sendThread.getStatus() == AsyncTask.Status.RUNNING)
            sendThread.stopThread();
        if (getThread.getStatus() == AsyncTask.Status.RUNNING)
            getThread.stopThread();
    }
}