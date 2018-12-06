package dogedroid.com.watchdoge;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;


public class DiscoveryActivity extends AppCompatActivity {
    public static String dogeAddress = "";
    public static final int port = 8001;

    private TextView connectedText;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        connectedText = findViewById(R.id.connectedText);
        new Discovery().execute();
    }


    private void connectedSuccesfully() {
        startActivity(new Intent(this, DashboardActivity.class));
    }


    private class Discovery extends AsyncTask<Void, Void, String> {
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
                        serverAddr, DiscoveryActivity.port);
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

