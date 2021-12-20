import java.io.*;
import java.net.*;
import java.util.*;

public class FileTransferClient {

	public static void main(String[] args) throws Exception {
		System.out.println("Connecting..");

		Socket socket = new Socket("localhost", 6000);
		DataInputStream readInput = new DataInputStream(socket.getInputStream());
		DataOutputStream writeOutput = new DataOutputStream(socket.getOutputStream());
		Scanner ip = new Scanner(System.in);

		System.out.println("Start transfering");

		String transfer = "";

		// read file
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader("D:/College-Stuff-5th-Sem/CNSL/A07/oldfile.txt"));
			String line = reader.readLine();
			while (line != null) {
				transfer = transfer + line + "\n";
				line = reader.readLine();
			}
			reader.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

		// write to stream output
		writeOutput.writeUTF(transfer);

		System.out.println("Transfer done!\nClosing connection.");

		// close connection
		socket.close();
		readInput.close();
		writeOutput.close();
		ip.close();
	}

}
