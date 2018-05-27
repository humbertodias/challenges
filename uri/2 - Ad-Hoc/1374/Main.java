import java.util.*;

public class Main {
    public static int N;
    public static int sum;
    public static int nDays;

    public static boolean isLeap(int y) {
        return (((y % 4) == 0 && (y % 100) != 0) || (y % 400) == 0);
    }

    public static boolean consecutive(int d1, int m1, int y1, int d2, int m2, int y2) {
        if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12) {
            if (d1 <= 30 && d2 == d1 + 1 && m2 == m1 && y2 == y1) {
                return true;
            }
            if (d1 == 31 && m1 < 12 && d2 == 1 && m2 == m1 + 1 && y2 == y1) {
                return true;
            }
            if (d1 == 31 && m1 == 12 && d2 == 1 && m2 == 1 && y2 == y1 + 1) {
                return true;
            }
        } else if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11) {
            if (d1 <= 29 && d2 == d1 + 1 && m2 == m1 && y2 == y1) {
                return true;
            }
            if (d1 == 30 && d2 == 1 && m2 == m1 + 1 && y2 == y1) {
                return true;
            }
        }

        else if (m1 == 2) {
            if ((d1 <= 27 || (d1 == 28 && isLeap(y1))) && d2 == d1 + 1 && m2 == m1 && y2 == y1) {
                return true;
            }
            if (((d1 == 29 && isLeap(y1)) || (d1 == 28 && !isLeap(y1))) && d2 == 1 && m2 == 3 && y2 == y1) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d1, m1, y1, d2, m2, y2;
        int c1, c2;
        N = sc.nextInt();
        while (N != 0) {

            nDays = 0;
            sum = 0;
            d1 = sc.nextInt();
            m1 = sc.nextInt();
            y1 = sc.nextInt();
            c1 = sc.nextInt();
            for (int i = 1; i < N; i++) {
                d2 = sc.nextInt();
                m2 = sc.nextInt();
                y2 = sc.nextInt();
                c2 = sc.nextInt();
                if (consecutive(d1, m1, y1, d2, m2, y2)) {
                    nDays++;
                    sum += (c2 - c1);
                }
                d1 = d2;
                m1 = m2;
                y1 = y2;
                c1 = c2;
            }
            System.out.println(nDays + " " + sum);
            N = sc.nextInt();
        }
    }
}