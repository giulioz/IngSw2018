package dogedroid.com.watchdoge;

import android.util.Log;
import android.widget.Button;
import android.widget.TextView;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;
import java.util.function.Function;

public class Pairing {
    public static String dogeAddress="";
    public static TextView text;

    public static final int port = 8001;

    public Pairing(Function<String, Void> callback){
        new Thread(new connect(callback)).start();

    }

    private class connect implements Runnable{
        Function<String, Void> callback;
        public connect(Function<String, Void> callback) {
            this.callback = callback;
        }
        @Override
        public void run() {
            boolean run = true;
            try {
                byte adr = (byte) 255;
                byte[] address = {adr, adr, adr, adr};
                byte[] sendData = new byte[1024];
                byte[] message = new byte[1024];

                DatagramSocket udpSocket = new DatagramSocket();
                udpSocket.setBroadcast(true);
                InetAddress serverAddr = InetAddress.getByAddress(address);

                String sentence = "DOGE_SEARCH";
                sendData = sentence.getBytes();

                DatagramPacket packet = new DatagramPacket(sendData, sendData.length,serverAddr, port);
                udpSocket.send(packet);

                DatagramPacket receivePacket = null;

                while (run) {
                    try {
                        receivePacket = new DatagramPacket(message,message.length);
                        Log.d("UDP client: ", "about to wait to receive");
                        udpSocket.setSoTimeout(1000);
                        udpSocket.receive(receivePacket);
                        Log.d("UDP client: ", "ricevuto");
                        //Pairing.text.setText(receivePacket.getAddress().toString());
                        Log.d("UDP client: ", "ritorno");
                        if(receivePacket.getAddress()!=null){
                            Log.d("UDP client: ", "var");
                            Log.d("UDP return: ", receivePacket.getAddress().toString());
                            this.callback.apply(receivePacket.getAddress().toString());
                            run = false;
                            udpSocket.close();
                        }
                    } catch (SocketTimeoutException e) {
                        Log.d("Timeout Exception","UDP Connection:",e);
                        run = false;
                        udpSocket.close();
                    } catch (IOException e) {
                        Log.d("UDP client IOException", "error: ", e);
                        run = false;
                        udpSocket.close();
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