package dogedroid.com.watchdoge.onboarding;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;

import dogedroid.com.watchdoge.R;

public class OnBoarding_1 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_on_boarding_1);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);


        Button onBoardBtn = findViewById(R.id.button_OnBoarding_1);
        onBoardBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_2.class)));
    }

}
