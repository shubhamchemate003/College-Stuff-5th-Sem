
public class MacroDet {
	private String name;
	private int PP, KP, MDTP, KPDP;
	
	MacroDet(String name, int pp, int kp, int mdtp, int kpdp) {
		this.name = name;
		PP = pp;
		KP = kp;
		MDTP = mdtp;
		KPDP = kpdp;
	}

	public String getName() { return name; }
	public int getPP() { return PP; }
	public int getKP() { return KP; }
	public int getMDTP() { return MDTP; }
	public int getKPDP() { return KPDP; }
}