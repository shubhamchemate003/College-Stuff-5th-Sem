import java.io.*;
import java.util.ArrayList;

public class MacroPassTwo {
	
	static ArrayList<MacroDet> MNTAB = new ArrayList<MacroDet>();
	static ArrayList<KeyParam> KPDTAB = new ArrayList<KeyParam>();
	static ArrayList<String> MDT = new ArrayList<String>();
	
	public static void fillMNTAB() throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("MNTAB.txt")));
		
		String curLine;
		while ((curLine = reader.readLine()) != null) {
			// name pp kp mdtp kpdp
			String[] words = curLine.split(" ");
			MacroDet newEntry = new MacroDet(words[0], Integer.parseInt(words[1]), Integer.parseInt(words[2]), Integer.parseInt(words[3]), Integer.parseInt(words[4]));
			MNTAB.add(newEntry);
		}
		
		reader.close();
	}

	public static void fillKPDTAB() throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("KPDTAB.txt")));
		
		KPDTAB.add(null);
		
		String curLine;
		while ((curLine = reader.readLine()) != null) {
			// keyword_param val
			String[] words = curLine.split(" ");
			KeyParam newEntry = new KeyParam(words[0], words.length>1?words[1]:"");
			KPDTAB.add(newEntry);
		}
		
		reader.close();
	}
	
	public static void fillMDT() throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File("MDT.txt")));
		
		MDT.add(null);
		
		String curLine;
		while ((curLine = reader.readLine()) != null)
			MDT.add(curLine);
		
		reader.close();
	}
	
	public static int isMacro(String curName) {
		int ans=-1;
		for (int i=0; i<MNTAB.size(); i++)
			if (MNTAB.get(i).getName().equals(curName)) {
				ans=i;
				break;
			}
		return ans;
	}
	
	public static void main(String[] args) throws Exception {
		
		fillMNTAB();
		fillKPDTAB();
		fillMDT();
		
		BufferedReader reader = new BufferedReader(new FileReader(new File("source_code_pass2.txt")));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		String curLine;
		while ((curLine = reader.readLine()) != null) {
			String[] words = curLine.split(" ");
			
			int mntabidx = isMacro(words[0]);
			
			if (mntabidx != -1) {
				
				System.out.println("Processing Start for Macro: " + words[0]);
				
				int pp=MNTAB.get(mntabidx).getPP(), kp=MNTAB.get(mntabidx).getKP();
				int kpdp=MNTAB.get(mntabidx).getKPDP(), mdtp=MNTAB.get(mntabidx).getMDTP();
				
				int totEntries = pp+kp;
				String[] APTAB = new String[totEntries+7];
				
				// filling positional arguments
				for (int i=1; i<=pp; i++) {
					int wordEnd = words[i].indexOf(",");
					if (wordEnd==-1)
						wordEnd=words.length;
					APTAB[i]=words[i].substring(0, wordEnd);
				}
				
				// filling keyword arguments
				for (int i=pp+1; i<=totEntries; i++, kpdp++) {
					String name=KPDTAB.get(kpdp).getName();
					String val =KPDTAB.get(kpdp).getVal();
					
					
					for (int j=0; j<words.length; j++) {
						if (words[j].charAt(0)!='&')
							continue;
						
						int wordEnd = words[j].indexOf(",");
						if (wordEnd==-1)
							wordEnd=words[j].length();
						
						String curName = words[j].substring(1, words[j].indexOf("="));
						if (curName.equals(name))
							val=words[j].substring(words[j].indexOf("=")+1, wordEnd);
					}
					
					APTAB[i]=val;
				}
				
				for (int i=1; i<=totEntries; i++)
					System.out.println(APTAB[i]);
				
				for (int i=mdtp; ; i++) {
					String newLine = MDT.get(i);
					if (newLine.equals("MEND"))
						break;
					
					String newLineToAdd="+ ";
					String[] newWords = newLine.split(" ");
					for (String newWord : newWords) {
						if (newWord.length()>=2 && newWord.charAt(1)=='p') {
							int aptidx = Integer.parseInt(newWord.substring(newWord.indexOf(',')+1, newWord.indexOf(')')));
							newLineToAdd += APTAB[aptidx]+", ";
						}
						else newLineToAdd += newWord+", ";
					}
					
					newLineToAdd=newLineToAdd.substring(0, newLineToAdd.length()-2);
					newLineToAdd += '\n';
					
					writer.write(newLineToAdd);
				}
				
			}
			else writer.write(curLine+'\n');
		}
		
		reader.close();
		writer.close();
		
	}

}
