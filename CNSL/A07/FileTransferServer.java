import java.io.*;
import java.net.*;
import java.util.*;

public class FileTransferServer {

	public static void main(String[] args) throws Exception {
		ServerSocket server = new ServerSocket(6000);

		System.out.println("Server started");
		System.out.println("Waiting for a client..");

		Socket socket = server.accept();

		System.out.println("Client has joined.");

		DataInputStream readInput = new DataInputStream(socket.getInputStream());
		DataOutputStream writeOutput = new DataOutputStream(socket.getOutputStream());

		Scanner ip = new Scanner(System.in);

		// get Stream socket input
		String lines = readInput.readUTF();

		// write to files
		FileWriter myWriter = new FileWriter("D:/College-Stuff-5th-Sem/CNSL/A07/newfile.txt");
		myWriter.write(lines);
		myWriter.close();

		server.close();
		socket.close();
		writeOutput.close();
		readInput.close();
		ip.close();

	}

}
