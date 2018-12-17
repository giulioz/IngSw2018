package dogedroid.com.watchdoge;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.squareup.picasso.OkHttp3Downloader;
import com.squareup.picasso.Picasso;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;

import dogedroid.com.watchdoge.onboarding.OnBoarding_1;
import okhttp3.OkHttpClient;
import okhttp3.Request;


public class DiscoveryActivity extends AppCompatActivity {
    public static String dogeAddress = "";
    public static final int port = 8000;
    public static final int UDPport = 8001;
    public static String token = "";
    public static Picasso picasso;


    private TextView connectedText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (getToken() && OnBoarding_1.ini) {
            connectedText = findViewById(R.id.connectedText);
            creaPicasso();
            new DiscoverDoge().execute();
        } else
            startActivity(new Intent(this, OnBoarding_1.class));

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

    private void connectedSuccesfully() {
        startActivity(new Intent(this, DashboardActivity.class));
    }

    // Ritorna TRUE se ha trovato il token
    private boolean getToken() {
        SharedPreferences pref = getSharedPreferences("watchdoge", Context.MODE_PRIVATE);
        token = pref.getString("authToken", "");
        return !(token.equals(""));

    }

    private class DiscoverDoge extends AsyncTask<Void, Void, String> {
        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            connectedText.setText("Cercando il Doge...");
        }

        protected String doInBackground(Void... params) {
            boolean run = true;
            try {
                byte adr = (byte) 255;
                byte[] address = {adr, adr, adr, adr};
                byte[] sendData;
                byte[] message = new byte[1024];

                DatagramSocket udpSocket = new DatagramSocket();
                udpSocket.setBroadcast(true);
                InetAddress serverAddr = InetAddress.getByAddress(address);

                String sentence = "DOGE_SEARCH";
                sendData = sentence.getBytes();

                DatagramPacket packet = new DatagramPacket(sendData, sendData.length,
                        serverAddr, DiscoveryActivity.UDPport);
                DatagramPacket receivePacket;

                while (run) {
                    try {
                        udpSocket.send(packet);
                        receivePacket = new DatagramPacket(message, message.length);
                        udpSocket.setSoTimeout(1500);
                        udpSocket.receive(receivePacket);

                        run = false;
                        udpSocket.close();
                        DiscoveryActivity.dogeAddress = receivePacket.getAddress().toString();
                        return "";

                    } catch (SocketTimeoutException e) {
                        Log.d("Timeout Exception", "UDP Connection:", e);
                    } catch (IOException e) {
                        Log.d("UDP client IOException", "error: ", e);
                    }
                }
            } catch (SocketException e) {
                Log.d("Socket Open:", "Error:", e);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return "";
        }

        @Override
        protected void onPostExecute(final String s) {
            super.onPostExecute(s);
            connectedSuccesfully();
        }
    }

}

