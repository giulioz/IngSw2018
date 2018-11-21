package dogedroid.com.watchdoge.onboarding;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;

import dogedroid.com.watchdoge.R;

public class OnBoarding_2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_on_boarding_2);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        Button nextBtn = findViewById(R.id.button_AcceptOnBoarding_2);
        nextBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                go_OnBordingNext();
            }
        });

        Button backBtn = findViewById(R.id.button_BackOnBoarding_2);
        backBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                go_OnBordingPrev();
            }
        });
    }
    public void go_OnBordingNext() {
        startActivity(new Intent(this, OnBoarding_3.class));
    }

    public void go_OnBordingPrev() {
        startActivity(new Intent(this, OnBoarding_1.class));
    }

}
