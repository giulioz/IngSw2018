package dogedroid.com.watchdoge.onboarding;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;

import dogedroid.com.watchdoge.DiscoveryActivity;
import dogedroid.com.watchdoge.R;
import dogedroid.com.watchdoge.utility.DiscoverDoge;

public class OnBoarding_3 extends AppCompatActivity {
    Button nextBtn;
    Button backBtn;
    TextView description;
    TextView ipDoge;
    ImageView logo;
    public static String ip;
    DiscoverDoge thread;
    ProgressBar pr;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_on_boarding_3);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        nextBtn = findViewById(R.id.button_AcceptOnBoarding_3);
        backBtn = findViewById(R.id.button_BackOnBoarding_3);
        description = findViewById(R.id.description_OnBoarding_3);
        ipDoge = findViewById(R.id.ip_dogefound);
        logo = findViewById(R.id.doge_logo);
        pr = findViewById(R.id.onboarding3_progressBar);

        thread = new DiscoverDoge(new DiscoverDoge.DiscoverInterface() {
            @Override
            public void onPre() { }
            @Override
            public void onPost(boolean success,String ip) {
                if(success){
                    OnBoarding_3.ip = ip;
                    description.setText(R.string.description_OnBoarding_3_found);
                    ipDoge.setText(ip.substring(1));
                    pr.setVisibility(View.GONE);
                    logo.setVisibility(View.VISIBLE);
                    nextBtn.setVisibility(View.VISIBLE);
                }
            }
        });
        thread.execute();

        nextBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_4.class)));

        backBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_2.class)));
    }

    @Override
    protected void onPause() {
        super.onPause();
        if(thread.getStatus() == AsyncTask.Status.RUNNING)
            thread.stopThread();
    }
}
