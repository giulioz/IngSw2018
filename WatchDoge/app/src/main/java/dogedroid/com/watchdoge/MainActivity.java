package dogedroid.com.watchdoge;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.MemoryPolicy;
import com.squareup.picasso.Picasso;

import java.io.IOException;

import dogedroid.com.watchdoge.onboarding.OnBoarding_1;


public class MainActivity extends AppCompatActivity {
    private Button onBoardBtn;
    private Button liveBtn;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        onBoardBtn = findViewById(R.id.onBoardButton);
        liveBtn = findViewById(R.id.live_activity_btn);

        // SE SIAMO CONNESSI
        new Pairing();


        onBoardBtn.setOnClickListener(v ->
                startActivity(new Intent(this, OnBoarding_1.class))
        );

        liveBtn.setOnClickListener((v) ->
                startActivity(new Intent(this, LiveFeedActivity.class))
        );
    }




}

