package dogedroid.com.watchdoge.utility;

import android.os.AsyncTask;
import android.util.Log;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;

import dogedroid.com.watchdoge.DiscoveryActivity;

public class DiscoverDoge extends AsyncTask<Void, Void, Void> {
    private final String TAG = "DiscoverDoge";
    
    public interface DiscoverInterface{
        void onPre();
        void onPost(boolean success, String ip);
    }

    private final DiscoverInterface discover;

    private boolean success;
    private boolean run;
    private String ip;

    public DiscoverDoge(DiscoverInterface listener) {
        this.discover = listener;
    }

    public void stopThread() {
        run = false;
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
        discover.onPre();
    }

    @Override
    protected Void doInBackground(Void... voids) {
        run = true;
        success = false;
        ip = "";
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
                    Log.d(TAG, "doInBackground: CERCANDO");
                    udpSocket.send(packet);
                    receivePacket = new DatagramPacket(message, message.length);
                    udpSocket.setSoTimeout(1500);
                    udpSocket.receive(receivePacket);
                    success = true;
                    run = false;
                    udpSocket.close();
                    ip = receivePacket.getAddress().toString();
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
        return null;
    }

    @Override
    protected void onPostExecute(Void aVoid) {
        super.onPostExecute(aVoid);
        discover.onPost(success,ip);
    }
}
