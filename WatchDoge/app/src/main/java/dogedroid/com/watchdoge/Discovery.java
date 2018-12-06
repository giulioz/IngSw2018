package dogedroid.com.watchdoge;

import android.os.AsyncTask;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;

public class Discovery extends AsyncTask<Void, Void, String> {

    public static String dogeAddress = "";
    public static final int port = 8001;
    private TextView connectedText;
    private Button btn1;
    private Button btn2;
    private Button btn3;

    Discovery(TextView text, Button btn1, Button btn2, Button btn3){
        this.connectedText = text;
        this.btn1 = btn1;
        this.btn2 = btn2;
        this.btn3 = btn3;
    }

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

            DatagramPacket packet = new DatagramPacket(sendData, sendData.length, serverAddr, Discovery.port);
            DatagramPacket receivePacket;

            while (run) {
                try {
                    udpSocket.send(packet);
                    receivePacket = new DatagramPacket(message, message.length);
                    udpSocket.setSoTimeout(1500);
                    udpSocket.receive(receivePacket);


                    run = false;
                    udpSocket.close();
                    Discovery.dogeAddress = receivePacket.getAddress().toString();
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
        connectedText.setText(Discovery.dogeAddress.substring(1));
        btn1.setVisibility(View.VISIBLE);
        btn2.setVisibility(View.VISIBLE);
        btn3.setVisibility(View.VISIBLE);
    }
}


