package dogedroid.com.watchdoge;

import android.util.Log;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;

public class Pairing {
    public static String dogeAddress;
    public static final int port = 8001;

    public Pairing(){
        new Thread(new connect()).start();
    }

    private class connect implements Runnable{
        @Override
        public void run() {
            boolean run = true;
            try {
                byte adr = (byte) 255;
                byte[] address = {adr, adr, adr, adr};
                byte[] sendData = new byte[1024];

                DatagramSocket udpSocket = new DatagramSocket(Pairing.port);
                InetAddress serverAddr = InetAddress.getByAddress(address);

                String sentence = "DOGE_SEARCH";
                sendData = sentence.getBytes();

                DatagramPacket packet = new DatagramPacket(sendData, sendData.length,serverAddr, Pairing.port);
                udpSocket.send(packet);
                while (run) {
                    try {
                        byte[] message = new byte[8000];
                        DatagramPacket receivePacket = new DatagramPacket(message,message.length);
                        Log.i("UDP client: ", "about to wait to receive");
                        udpSocket.setSoTimeout(10000);
                        udpSocket.receive(receivePacket);
                        Pairing.dogeAddress = receivePacket.getAddress().toString();
                        run = false;
                    } catch (IOException e) {
                        Log.e(" UDP client IOException", "error: ", e);
                        run = false;
                        udpSocket.close();
                    }
                }
            } catch (SocketException e) {
                Log.e("Socket Open:", "Error:", e);
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}

/*
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
        while(!clientSocket.isClosed()){
            clientSocket.receive(receivePacket);

            clientSocket.close();

        }

        return receivePacket.getAddress().toString();
*/