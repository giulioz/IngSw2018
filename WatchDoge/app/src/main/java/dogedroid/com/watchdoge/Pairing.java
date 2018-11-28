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
    public static String dogeAddress="";
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
                byte[] sendData;
                byte[] message = new byte[1024];

                DatagramSocket udpSocket = new DatagramSocket();
                udpSocket.setBroadcast(true);
                InetAddress serverAddr = InetAddress.getByAddress(address);

                String sentence = "DOGE_SEARCH";
                sendData = sentence.getBytes();

                DatagramPacket packet = new DatagramPacket(sendData, sendData.length,serverAddr, port);
                udpSocket.send(packet);

                DatagramPacket receivePacket;

                while (run) {
                    try {
                        receivePacket = new DatagramPacket(message,message.length);
                        udpSocket.setSoTimeout(1000);
                        udpSocket.receive(receivePacket);
                        if(receivePacket.getAddress()!=null){
                            Pairing.dogeAddress = receivePacket.getAddress().toString();
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