import java.util.*;

class Main{

	enum Morse {
	    MC_1(".====", '1'), MC_2("..===", '2'),MC_3("...==", '3'),

	    MC_4("....=", '4'), MC_5(".....", '5'), MC_6("=....", '6'),

	    MC_7("==...", '7'), MC_8("===..", '8'), MC_9("====.", '9'),

	    MC_0("=====", '0'), MC_A(".=", 'A'), MC_B("=...", 'B'),

	    MC_C("=.=.", 'C'), MC_D("=..", 'D'), MC_E(".", 'E'),

	    MC_F("..=.", 'F'), MC_G("==.", 'G'), MC_H("....", 'H'),

	    MC_I("..", 'I'), MC_J(".===", 'J'), MC_K("=.=", 'K'),

	    MC_L(".=..", 'L'), MC_M("==", 'M'), MC_N("=.", 'N'),

	    MC_O("===", 'O'), MC_P(".==.", 'P'), MC_Q("==.=", 'Q'),

	    MC_R(".=.", 'R'), MC_S("...", 'S'), MC_T("=", 'T'),

	    MC_U("..=", 'U'), MC_V("...=", 'V'), MC_W(".==", 'W'),

	    MC_X("=..=", 'X'), MC_Y("=.==", 'Y'), MC_Z("==..", 'Z'),
	    MC_SPACE("/", ' ');

	    public final String morse;
	    public final char code;

	    Morse(String morse, char code) {
	        this.morse = morse;
	        this.code = code;
	    }
	}

	public static boolean isValid(char c) {
        for (Morse m : Morse.values()) {
            if (c == m.code) return true;
        }
        throw new IllegalArgumentException("Invalid Entry: " + c + ". Non-space input may only be: 0-9, A-Z, or a-z");
    }	

	public static String morseConversion(String s) {
        String ms = s.toUpperCase().trim(); // modified string
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < ms.length(); i++) {
            isValid(ms.charAt(i));

            for (Morse c : Morse.values()) {
                if (ms.charAt(i) == ' ' && ms.charAt(i - 1) == ' '); // Ignore consecutive spaces
                else if (ms.charAt(i) == c.code) {
                    result.append(c.morse);
                    if (i != ms.length() - 1) { result.append((" ")); }
                }
            }
        }
        return result.toString();
    }

	public static void main(String ... args){
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		String morseCode;
		while(T-- > 0){
			morseCode = scanner.nextLine();
			System.out.print(morseConversion(morseCode));
		}
	}
}