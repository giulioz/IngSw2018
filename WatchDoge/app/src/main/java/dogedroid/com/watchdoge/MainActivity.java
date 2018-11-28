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

        new Pairing();


        Button onBoardBtn = findViewById(R.id.onBoardButton);
        onBoardBtn.setOnClickListener(v -> go_OnBording());

        findViewById(R.id.fetchButton).setOnClickListener(view -> image_livefeed());

        findViewById(R.id.stop_button).setOnClickListener(v -> MainActivity.running = false);
    }

    public void go_OnBording() {
        startActivity(new Intent(this, OnBoarding_1.class));
    }

    public void image_livefeed() {

        final ImageView imageView = findViewById(R.id.imageView);
        final TextView textView = findViewById(R.id.text);
        final int refreshIntervalMs = 42;
        final Handler handler = new Handler();
        final Runnable imageUpdater = new Runnable() {
            @Override
            public void run() {
                textView.setText("http:/"+Pairing.dogeAddress + ":8000/shoot");
                new LiveFeed(imageView).execute("http:/"+Pairing.dogeAddress + ":8000/shoot");
                handler.postDelayed(this, refreshIntervalMs);
            }
        };
        handler.post(imageUpdater);
    }


}

