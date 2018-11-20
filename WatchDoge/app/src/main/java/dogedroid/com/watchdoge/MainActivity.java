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

    public static boolean running = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        Pairing.text = findViewById(R.id.text);

        Pairing connection = new Pairing();



        Button onBoardBtn = findViewById(R.id.onBoardButton);
        onBoardBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                go_OnBording();
            }
        });

        findViewById(R.id.fetchButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                image_livefeed();
            }
        });

        findViewById(R.id.stop_button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity.running = false;
            }
        });
    }

    public void go_OnBording() {
        startActivity(new Intent(this, OnBoarding_1.class));
    }

    public void image_livefeed() {

        final ImageView imageView = findViewById(R.id.imageView);
        final int refreshIntervalMs = 500;
        final Handler handler = new Handler();
        final Runnable imageUpdater = new Runnable() {
            @Override
            public void run() {
                new LiveFeed(imageView).execute("http:/" + Pairing.dogeAddress + ":8000/shoot");
                handler.postDelayed(this, refreshIntervalMs);
            }
        };
        handler.post(imageUpdater);
    }


}

