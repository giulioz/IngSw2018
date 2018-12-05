package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;

import dogedroid.com.watchdoge.dogelog.DogeLogActivity;
import dogedroid.com.watchdoge.onboarding.OnBoarding_1;


public class MainActivity extends AppCompatActivity {
    private Button onBoardBtn;
    private Button liveBtn;
    private Button logBtn;
    public TextView connectedText;


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


        new Pairing(connectedText,liveBtn,onBoardBtn,logBtn).execute();
    }






}

