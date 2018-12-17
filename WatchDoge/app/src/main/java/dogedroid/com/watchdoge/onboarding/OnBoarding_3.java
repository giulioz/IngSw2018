package dogedroid.com.watchdoge.onboarding;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;

import dogedroid.com.watchdoge.DiscoveryActivity;
import dogedroid.com.watchdoge.R;

public class OnBoarding_3 extends AppCompatActivity {
    Button nextBtn;
    Button backBtn;
    TextView description;
    TextView ipDoge;
    ImageView logo;
    public static String ip;
    DiscoverDoge thread;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_on_boarding_3);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        nextBtn = findViewById(R.id.button_AcceptOnBoarding_3);
        backBtn = findViewById(R.id.button_BackOnBoarding_3);
        description = findViewById(R.id.description_OnBoarding_3);
        ipDoge = findViewById(R.id.ip_dogefound);
        logo = findViewById(R.id.doge_logo);

        thread = new DiscoverDoge();
        thread.execute();

        nextBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_4.class)));

        backBtn.setOnClickListener(v -> startActivity(new Intent(this, OnBoarding_2.class)));
    }

    private void founded() {
        description.setText(R.string.description_OnBoarding_3_found);
        ipDoge.setText(ip.substring(1));
        logo.setVisibility(View.VISIBLE);
        nextBtn.setVisibility(View.VISIBLE);
    }

    private class DiscoverDoge extends AsyncTask<Void, Void, String> {
        private boolean run;
        private boolean success = false;

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
        }

        public void stopThread() {
            run = false;
        }

        protected String doInBackground(Void... params) {
            try {
                run = true;
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
                        Log.d("PORCODIO", "doInBackground: prova ");
                        udpSocket.send(packet);
                        receivePacket = new DatagramPacket(message, message.length);
                        udpSocket.setSoTimeout(1500);

                        udpSocket.receive(receivePacket);
                        run = false;
                        success = true;
                        udpSocket.close();
                        ip = receivePacket.getAddress().toString();
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
            if(success)
                founded();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if(thread.getStatus() == AsyncTask.Status.RUNNING)
            thread.stopThread();
    }
}
