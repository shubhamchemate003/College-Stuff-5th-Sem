import java.net.*;
import java.util.*;
import java.io.*;

public class TCPClient {

	public static void main(String[] args) throws Exception {
		System.out.println("Connecting..");
		
		Socket socket=new Socket("localhost",6000);
		DataInputStream  readInput = new DataInputStream(socket.getInputStream());
	    DataOutputStream writeOutput = new DataOutputStream(socket.getOutputStream());
	    Scanner in = new Scanner(System.in);
	    
	    System.out.println("Start Communication..");
	    
	    String line="";
	    while(!line.equals("Stop"))
	    {
	    	line=in.nextLine();
	    	writeOutput.writeUTF(line);
	    	if(line.equals("Stop"))
	    	break;
	    	line=readInput.readUTF();
	    	System.out.println(line);
	     }
	   
	    System.out.println("Closing connection"); 
	     
	     // close connection 
	     socket.close(); 
	     readInput.close();
	     writeOutput.close();
	     in.close();

	}

}
