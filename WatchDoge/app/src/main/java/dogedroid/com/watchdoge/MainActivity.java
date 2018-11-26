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

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.URL;
import java.net.UnknownHostException;

import dogedroid.com.watchdoge.onboarding.OnBoarding_1;


public class MainActivity extends AppCompatActivity {

    public static boolean running = true;

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
        try {
            final String serveradd = getServerAdd();
            final ImageView imageView = findViewById(R.id.imageView);
            final int refreshIntervalMs = 42;
            final Handler handler = new Handler();
            final Runnable imageUpdater = new Runnable() {
                @Override
                public void run() {
                    new LiveFeed(imageView).execute(serveradd+":8000/shoot");
                    handler.postDelayed(this, refreshIntervalMs);
                }
            };
            handler.post(imageUpdater);
        /*if(!MainActivity.running){
            Log.d("RUN", "image_livefeed: NOT RUNNING");
            handler.removeCallbacks(imageUpdater);
        }*/
        }catch(IOException e){
            Log.d("UDP_ERROR", "SEI USCITO");
        }
    }

    public String getServerAdd() throws IOException {
        DatagramSocket clientSocket = new DatagramSocket();

        byte adr = (byte) 255;
        byte[] address = {adr, adr, adr, adr};

        InetAddress IPAddress = InetAddress.getByAddress(address);

        byte[] sendData = new byte[1024];
        byte[] receiveData = new byte[1024];

        String sentence = "DOGE_SEARCH";
        sendData = sentence.getBytes();
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 8001);

        clientSocket.send(sendPacket);

        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

        clientSocket.receive(receivePacket);

        clientSocket.close();

        return receivePacket.getAddress().toString();
    }
}

