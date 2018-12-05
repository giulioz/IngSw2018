package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import dogedroid.com.watchdoge.dogelog.DogeLogActivity;
import dogedroid.com.watchdoge.onboarding.OnBoarding_1;


public class MainActivity extends AppCompatActivity {
    private Button onBoardBtn;
    private Button liveBtn;
    private Button logBtn;
    private TextView connectedText;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        onBoardBtn = findViewById(R.id.onBoardButton);
        liveBtn = findViewById(R.id.live_activity_btn);
        logBtn = findViewById(R.id.log_activity_btn);
        connectedText = findViewById(R.id.connectedText);

        onBoardBtn.setOnClickListener(v ->
                startActivity(new Intent(this, OnBoarding_1.class))
        );

        liveBtn.setOnClickListener((v) ->
                startActivity(new Intent(this, LiveFeedActivity.class))
        );

        logBtn.setOnClickListener((v) ->
                startActivity(new Intent(this, DogeLogActivity.class))
        );

        // SE SIAMO CONNESSI
        new Pairing();


        connectedText.setText("");
        liveBtn.setVisibility(View.VISIBLE);
        onBoardBtn.setVisibility(View.VISIBLE);
        logBtn.setVisibility(View.VISIBLE);

    }

}

