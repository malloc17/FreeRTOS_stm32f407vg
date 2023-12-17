/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TCPClient;

import Esp8266.ReceiveData.ReceiveAndProcessThread;
import Esp8266.SendData.SendData;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import View.InputView.InputIPAddressPort;
import View.MainView.Main;
import java.util.LinkedList;
import java.util.Queue;
import javax.swing.JTextField;

/**
 *
 * @author Burak
 */
public class TcpClient {
        Socket client;
        
    public TcpClient(String IPAddress, int Port, InputIPAddressPort IIAP) throws IOException
    {   
        client = new Socket(IPAddress,Port);
        InputIPAddressPort.jLbl.setText("Connection is Successful!!!");   
        IIAP.setVisible(false);
        new Main(client).setVisible(true);
    }
}
