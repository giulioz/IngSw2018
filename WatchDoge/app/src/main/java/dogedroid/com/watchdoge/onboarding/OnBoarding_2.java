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
        nextBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_3.class)));

        Button backBtn = findViewById(R.id.button_BackOnBoarding_2);
        backBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_1.class)));
    }
}
