import java.io.*;
import java.util.ArrayList;

public class MacroPassOne {
	
	static ArrayList<MacroDet> MNTAB = new ArrayList<MacroDet>();
	static ArrayList<KeyParam> KPDTAB = new ArrayList<KeyParam>();

	public static void main(String[] args) throws Exception  {
		
		BufferedReader reader = new BufferedReader(new FileReader(new File("source_code_pass1.txt")));
		BufferedWriter writer = new BufferedWriter(new FileWriter("MDT.txt"));
		  
		int lineCounter=1;
		
		String curLine;
		while ((curLine = reader.readLine()) != null) {
			
			if (curLine.equals("MACRO")) { // we have macro
				
				System.out.println("MACRO PROCESSING STARTED..");
				
				boolean firstLine = true;
				String[] PNTAB = new String[100]; 
				int paramCount = 0;
				
				while ((curLine=reader.readLine()) != null) {
					if (curLine.equals("MEND")) {
						lineCounter++;
						writer.write("MEND\n");
						break;
					}
					
					// split cur line
					String[] words = curLine.split(" ");
					
					if (firstLine) {
						String curMacroName="";
						int pp=0, kp=0, kpdp=KPDTAB.size() +1;
						
						for (int i=0; i<words.length; i++) {
							if (i==0)
								curMacroName=words[0];
							else {
								int wordEnd = words[i].indexOf(",");
								if (wordEnd == -1)
									wordEnd = words[i].length();
								
								if (words[i].indexOf("=")==-1) { // positional parameter
									pp++;
									paramCount++;
									PNTAB[paramCount] = words[i].substring(1, wordEnd);
								}
								else { // keyword parameter
									String kpname = words[i].substring(1, words[i].indexOf("="));
									String kpdval = words[i].substring(words[i].indexOf("=")+1, wordEnd);
									
									KeyParam curkp = new KeyParam(kpname, kpdval);
									KPDTAB.add(curkp);
									
									paramCount++;
									kp++;
									
									PNTAB[paramCount] = kpname;
								}
							}
						}
						
						MacroDet curMacro = new MacroDet(curMacroName, pp, kp, lineCounter, kpdp);
						
						MNTAB.add(curMacro);
						firstLine = false;
					}
					else {
						String newMDTLine="";
						for (int cur=0; cur<words.length; cur++) {
							String word=words[cur];
							
							int wordStart=word.indexOf("&");
							if (wordStart==-1) { // cur word is not parameter
								newMDTLine+= word;
								if (cur != words.length-1)
									newMDTLine += " ";
								continue;
							}
							
							wordStart+=1;
							
							int wordEnd = word.indexOf("=", wordStart);
							if (wordEnd==-1)
								wordEnd = word.indexOf(",", wordStart);
							if (wordEnd==-1)
								wordEnd = word.length();
								
							String name = word.substring(wordStart, wordEnd);
							
							int pntabp=-1; // get index of curword from PNTAB
							for (int i=1; i<=paramCount; i++)
								if (PNTAB[i].equals(name)) {
									pntabp=i;
									break;
								}
							
							newMDTLine += "(p," + pntabp + ")";
							if (cur != words.length-1)
								newMDTLine += ", ";
						}
						newMDTLine += "\n";
						writer.write(newMDTLine);
						lineCounter++;
					}
				}
				
				System.out.println("PN TABLE:");
				for (int i=1; i<= paramCount; i++)
					System.out.println(i+" "+PNTAB[i]);
				System.out.println();
			}
		}
		
		reader.close();
		writer.close();
		
//		creating MNTTAB and KPDTAB files
		writer = new BufferedWriter(new FileWriter("MNTAB.txt"));
		for (MacroDet md:MNTAB)
			writer.write(md.getName()+" "+md.getPP()+" "+md.getKP()+" "+md.getMDTP()+" "+md.getKPDP()+"\n");
		writer.close();
		
		writer = new BufferedWriter(new FileWriter("KPDTAB.txt"));
		for (KeyParam kp:KPDTAB)
			writer.write(kp.getName()+" "+kp.getVal()+"\n");
		writer.close();
	}

}
