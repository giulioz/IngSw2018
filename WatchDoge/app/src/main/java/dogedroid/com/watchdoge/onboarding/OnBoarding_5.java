package dogedroid.com.watchdoge.onboarding;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;
import android.widget.Button;

import com.squareup.picasso.OkHttp3Downloader;
import com.squareup.picasso.Picasso;

import dogedroid.com.watchdoge.DashboardActivity;
import dogedroid.com.watchdoge.DiscoveryActivity;
import dogedroid.com.watchdoge.R;
import okhttp3.OkHttpClient;
import okhttp3.Request;

public class OnBoarding_5 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_on_boarding_5);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        Button onBoardBtn = findViewById(R.id.button_OnBoarding_5);
        onBoardBtn.setOnClickListener(v -> startActivity(new Intent(this, DiscoveryActivity.class)));

        // Saving token
        String token = getIntent().getStringExtra("token");
        SharedPreferences pref = getSharedPreferences("watchdoge",Context.MODE_PRIVATE);
        pref.edit().putString("authToken",token).commit();

    }
}
