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

import com.squareup.picasso.MemoryPolicy;
import com.squareup.picasso.Picasso;

import java.net.URL;

import dogedroid.com.watchdoge.onboarding.OnBoarding_1;


public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button onBoardBtn = findViewById(R.id.onBoardButton);
        onBoardBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                go_OnBording();
            }
        });

        findViewById(R.id.fetchButton).setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View view) {
                image_livefeed();
            }
        });
    }

    public void go_OnBording() {
        startActivity(new Intent(this, OnBoarding_1.class));
    }

    public void image_livefeed(){
        final ImageView imageView = findViewById(R.id.imageView);
        final int refreshIntervalMs =  42;
        final Handler handler = new Handler();
        Runnable imageUpdater = new Runnable() {
            @Override
            public void run() {
                new LiveFeed(imageView).execute("http://192.168.1.38:8000/shoot");
                handler.postDelayed(this, refreshIntervalMs);
            }
        };
        handler.post(imageUpdater);
    }

}

