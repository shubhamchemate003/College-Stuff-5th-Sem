import java.net.*;
import java.util.*;

public class DNS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		System.out.print("Choose:\n\t1.to enter host name\n");
		System.out.print("\t2.to enter IP address\n: ");
		int choice = sc.nextInt();
		
		String host;
		if (choice == 1) {
			Scanner in = new Scanner(System.in);
			System.out.print("Enter host name: ");
			host = in.nextLine();
			
			try {
				InetAddress address = InetAddress.getByName(host);
				System.out.println("IP Address: " + address.getHostAddress());
				System.out.println("Host Name: " + address.getHostName());
				System.out.println("Host name and IP address: " + address.toString());
			}
			catch (UnknownHostException ex) {
				System.out.println("Cannot find " + host);
			}
			
			in.close();
		}
		else {
			Scanner in = new Scanner(System.in);
			System.out.print("Enter IP Address: ");
			host = in.nextLine();
			
			try {
				InetAddress address = InetAddress.getByName(host);
				System.out.println("Host Name: " + address.getHostName());
				System.out.println("IP Address: " + address.getHostAddress());
				System.out.println("Host name and IP address: " + address.toString());
			}
			catch (UnknownHostException ex) {
				System.out.println("Cannot find " + host);
			}
			
			in.close();
		}
		
		sc.close();
	}

}
