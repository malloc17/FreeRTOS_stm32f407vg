/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Esp8266.ReceiveData;

import View.MainView.Main;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Burak
 */
public class ReceiveAndProcessThread {
    Socket client;
    private Queue<byte[]> messageQueue;
    private DataInputStream dataInputStream;
    private Main MainView;

    public ReceiveAndProcessThread(Socket client, Main MainView) {
        this.client = client;
        this.MainView = MainView;
        
        messageQueue = new LinkedList<>();
        
        InputStream inputStream;
        try {
            inputStream = client.getInputStream();
            dataInputStream = new DataInputStream(inputStream);
        } catch (IOException ex) {
            Logger.getLogger(ReceiveAndProcessThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        Thread listenThread = new Thread(new listenThread());
        Thread processThread = new Thread(new processThread());
        
        listenThread.start();
        processThread.start();
    }
    
    public class listenThread implements Runnable
    {

        private listenThread() {
           
        }

        @Override
        public void run() {
            while(true)
            {         
                byte[] buffer = new byte[10];
                try {
                    
                    int bytesRead = dataInputStream.read(buffer);

                    if (bytesRead == -1) {
                        break; // End of stream reached
                    }
                    
                    int val = buffer[0] & 0xFF;
                    val = buffer[1] & 0xFF;
                } catch (IOException ex) {
                    Logger.getLogger(listenThread.class.getName()).log(Level.SEVERE, null, ex);
                }

                addToQueue(buffer);
            }             
        }
    }
    
    private synchronized void addToQueue(byte [] message) {
        messageQueue.offer(message);
        notify(); // Yeni bir mesaj eklendiğinde beklemede olan thread'i uyar
    }
    
    public class processThread implements Runnable
    {

        private processThread() {
            
        }

        @Override
        public void run() {
            while(true)
            {
                ParseReceivedData(processNextMessage()); 
            }
        }
    }
    
    private void ParseReceivedData(byte [] receiveValue) {
        System.out.println(Arrays.toString(receiveValue));
        
        MainView.setjTextField1(Arrays.toString(receiveValue));
    }
    
    private synchronized byte[] processNextMessage() {
        while (messageQueue.isEmpty()) {
            try {
                wait(); // Kuyruk boşsa bekleyelim
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return messageQueue.poll();
    }
}