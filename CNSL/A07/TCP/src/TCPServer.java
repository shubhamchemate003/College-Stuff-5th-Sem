import java.io.*;
import java.net.*;
import java.util.*;

public class TCPServer {

	public static void main(String[] args) throws Exception {
		ServerSocket server = new ServerSocket(6000);

		System.out.println("Server started");
		System.out.println("Waiting for a client...");

		Socket socket = server.accept();

		System.out.println("Client has joined.");

		DataInputStream readInput = new DataInputStream(socket.getInputStream());
		DataOutputStream writeOutput = new DataOutputStream(socket.getOutputStream());

		Scanner in = new Scanner(System.in);

		String line = "";

		while (!line.equals("Stop")) {
			line = readInput.readUTF();
			if (line.equals("Stop"))
				break;
			System.out.println(line);
			line = in.nextLine();
			writeOutput.writeUTF(line);
		}

		server.close();
		socket.close();
		writeOutput.close();
		readInput.close();
		in.close();
	}

}
