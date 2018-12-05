package dogedroid.com.watchdoge;

import android.util.Log;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.function.Function;

public class Pairing {
    public static boolean connected = false;
    public static String dogeAddress="";
    public static final int port = 8001;
    private Thread pairingThread;

    public Pairing() {
        this.pairingThread = new Thread(new Connect());
        pairingThread.start();
    }

    private class Connect implements Runnable{
        private void connectionSuccess(String ip){
            Pairing.connected = true;
            Pairing.dogeAddress = ip;
        }

        @Override
        public void run() {
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

                DatagramPacket packet = new DatagramPacket(sendData, sendData.length,serverAddr, port);
                DatagramPacket receivePacket;

                while (run) {
                    try {
                        udpSocket.send(packet);
                        receivePacket = new DatagramPacket(message,message.length);
                        udpSocket.setSoTimeout(1500);
                        udpSocket.receive(receivePacket);

                        connectionSuccess(receivePacket.getAddress().toString());
                        run = false;
                        udpSocket.close();



                    } catch (SocketTimeoutException e) {
                        Log.d("Timeout Exception","UDP Connection:",e);
                    } catch (IOException e) {
                        Log.d("UDP client IOException", "error: ", e);
                    }
                }
            } catch (SocketException e) {
                Log.d("Socket Open:", "Error:", e);
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}