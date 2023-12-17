/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Esp8266.SendData;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Burak
 */
public class SendData {
    private static PrintWriter prWriter;
    
    public SendData(Socket client)
    {
        try {
            prWriter = new PrintWriter(client.getOutputStream());
        } catch (IOException ex) {
            Logger.getLogger(SendData.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    public static boolean sendDataToEsp8266(String Data)
    {
        prWriter.println(Data);
        prWriter.flush();
        return true;
    }
    
}
