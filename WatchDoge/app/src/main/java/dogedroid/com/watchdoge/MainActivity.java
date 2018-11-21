package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

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
    }

    public void go_OnBording() {
        startActivity(new Intent(this, OnBoarding_1.class));
    }
}
