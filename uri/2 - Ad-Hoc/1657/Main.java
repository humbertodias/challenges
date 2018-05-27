import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        HashMap<String,Integer> dict = new HashMap<String,Integer>();
        for (int i=0; i<n; i++) {
            String s = in.next();
            dict.put(s,i);
        }
        int q = in.nextInt();
        while(q-- > 0) {
            String qw = in.next();
            if (dict.get(qw) != null) {
                System.out.println(qw + " is correct");
                continue;
            }
            int bestIndex = n;
            String realword = null;
            for (int i=0; i<qw.length(); i++) {
                String t = qw.substring(0,i) + qw.substring(i+1);
                int v;
                if (dict.get(t) != null) {
                    v = dict.get(t);
                    if (v < bestIndex) {
                        bestIndex = v;
                        realword = t;
                    }
                }
                for (char c='a'; c<='z'; c++) {
                    t = qw.substring(0,i) + c + qw.substring(i+1);
                    if (dict.get(t) == null)
                        continue;
                    v = dict.get(t);
                    if (v < bestIndex) {
                        bestIndex = v;
                        realword = t;
                    }
                }
                if (i+1 < qw.length()) {
                    t = qw.substring(0,i) + qw.charAt(i+1) + qw.charAt(i) + qw.substring(i+2);
                    if (dict.get(t) != null) {
                        v = dict.get(t);
                        if (v < bestIndex) {
                            bestIndex = v;
                            realword = t;
                        }
                    }
                }
            }
            for (int i=0; i<=qw.length(); i++) {
                StringBuffer t = new StringBuffer();
                if (i > 0)
                    t.append(qw.substring(0,i));
                t.append(' ');
                if (i < qw.length())
                    t.append(qw.substring(i));
                for (char c='a'; c<='z'; c++) {
                    t.setCharAt(i,c);
                    if (dict.get(t.toString()) == null)
                        continue;
                    int v = dict.get(t.toString());
                    if (v < bestIndex) {
                        bestIndex = v;
                        realword = t.toString();
                    }
                }
            }
            if (realword != null)
                System.out.println(qw + " is a misspelling of " + realword);
            else
                System.out.println(qw + " is unknown");
        }
    }
}