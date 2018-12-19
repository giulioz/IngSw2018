package dogedroid.com.watchdoge;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.squareup.picasso.OkHttp3Downloader;
import com.squareup.picasso.Picasso;

import dogedroid.com.watchdoge.onboarding.OnBoarding_1;
import dogedroid.com.watchdoge.utility.DiscoverDoge;
import okhttp3.OkHttpClient;
import okhttp3.Request;


public class DiscoveryActivity extends AppCompatActivity {
    private final String TAG = "PORCODIO";
    public static String dogeAddress = "";
    public static final int port = 8000;
    public static final int UDPport = 8001;
    public static String token = "";
    public static Picasso picasso;

    private DiscoverDoge thread;

    private TextView connectedText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (getToken()) {
            Log.d(TAG, "onCreate: TOKEN: " + token);
            connectedText = findViewById(R.id.connectedText);
            creaPicasso();
            thread = new DiscoverDoge(new DiscoverDoge.DiscoverInterface() {
                @Override
                public void onPre() {
                    connectedText.setText("Cercando il Doge...");
                }
                @Override
                public void onPost(boolean success, String ip) {
                    DiscoveryActivity.dogeAddress = ip;
                    startActivity(new Intent(getApplicationContext(), DashboardActivity.class));
                }
            });
            thread.execute();
        } else{
            Log.d(TAG, "onCreate: TOKEN NON TROVATO");
            startActivity(new Intent(this, OnBoarding_1.class));
        }

    }

    public static String getUrl(String add) {
        return "http:/" + DiscoveryActivity.dogeAddress + ":" + DiscoveryActivity.port + add;
    }

    private void creaPicasso() {
        OkHttpClient client = new OkHttpClient.Builder()
                .addInterceptor(chain -> {
                    String authString = "Bearer " + token;
                    Request newRequest = chain.request().newBuilder()
                            .addHeader("Authorization", authString)
                            .build();
                    return chain.proceed(newRequest);
                })
                .build();

        picasso = new Picasso.Builder(this)
                .downloader(new OkHttp3Downloader(client))
                .build();
    }

    // Ritorna TRUE se ha trovato il token
    private boolean getToken() {
        SharedPreferences pref = getSharedPreferences("watchdoge", Context.MODE_PRIVATE);
        token = pref.getString("authToken", "");
        Log.d(TAG, "getToken: LETTO: " + token);
        return !(token.isEmpty());

    }

}

