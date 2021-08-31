import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) {
		
		File file=new File("source.txt");
		
		int LC=0;
		String line;
		
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
			// reading line by line from file
		    while ((line = br.readLine()) != null) {
		    	// removing additional white spaces
		    	line = line.replaceFirst("^ *", "");
		    	String[] words = line.split("\\s+");
		    	for (int i = 0; i < words.length; i++)
		    		words[i] = words[i].replaceAll("[^\\w]", "");
		    	
		    	// processing the instruction
		    	for (int i=0; i<words.length; i++) {
		    		if (words[0].equals("START")) {
		    			LC = Integer.parseInt(words[1]);
		    			System.out.println("(AD, 01) (C, "+LC+")");
		    			break;
		    		}
		    		else if (words[0].equals("END")) {
		    			System.out.println("(AD, 02) (C, "+LC+")");
		    			break;
		    		}
		    		else {
		    			System.out.print(words[i] + ' ');
		    		}
		    	}
		    	System.out.println();
		    }
		}
		catch (IOException ioe) {
			ioe.printStackTrace();
		}
		
	}
}
