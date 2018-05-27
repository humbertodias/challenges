import java.util.*;
import java.io.*;
import static java.lang.System.*;

public class Main {
    public static void main(String... args) throws Throwable {
        Scanner s = new Scanner(System.in);
        s.useDelimiter("\\s+");
        int L = s.nextInt(), N = s.nextInt();
        Map<String, String> m = new HashMap<String, String>();
        while (L-- > 0) {
            String a = s.next();
            String b = s.next();
            m.put(a, b);
        }
        while (N-- > 0) {
            String w = s.next();
            if (m.containsKey(w)) {
                out.println(m.get(w));
            } else if (w.endsWith("y") && "aeiou".indexOf(w.charAt(w.length() - 2)) < 0) {
                out.println(w.substring(0, w.length() - 1) + "ies");
            } else if (w.endsWith("o") || w.endsWith("s") || w.endsWith("ch") || w.endsWith("sh")
                    || w.endsWith("x")) {
                out.println(w + "es");
            } else {
                out.println(w + "s");
            }
        }
    }
}

