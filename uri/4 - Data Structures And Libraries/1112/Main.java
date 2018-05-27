import java.io.*;

public class Main {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

      while (true) {
         String[] entrada = br.readLine().trim().split(" ");
         int tamX = Integer.parseInt(entrada[0]);
         int tamY = Integer.parseInt(entrada[1]);
         int Preco = Integer.parseInt(entrada[2]);

         if (tamX == 0 && tamY == 0 && Preco == 0) {
            break;
         }

         FenwickTree2D campo = new FenwickTree2D(tamX, tamY);

         int Q = Integer.parseInt(br.readLine());
         for (int i = 0; i < Q; i++) {

            entrada = br.readLine().split(" ");

            if (entrada[0].equals("A")) {
               int N = Integer.parseInt(entrada[1]);
               int X = Integer.parseInt(entrada[2]);
               int Y = Integer.parseInt(entrada[3]); // (X,Y)
               campo.add(X, Y, N);

            } else {
               int X1 = Integer.parseInt(entrada[1]);
               int Y1 = Integer.parseInt(entrada[2]); // (X,Y)
               int X2 = Integer.parseInt(entrada[3]);
               int Y2 = Integer.parseInt(entrada[4]); // (Z,W)

               int achados = campo.sum(Math.min(X1, X2), Math.min(Y1, Y2),
                     Math.max(X1, X2), Math.max(Y1, Y2));
               out.println(achados * Preco);
            }
         }
         out.println("");
      }

      out.flush();
   }

}

class FenwickTree2D {

   int[][] t;
   int max_x, max_y;

   public FenwickTree2D(int max_x, int max_y) {
      this.max_x = max_x;
      this.max_y = max_y;
      this.t = new int[max_x][max_y];
   }

   public FenwickTree2D(int[][] t) {
      this.t = t;
      max_x = t.length;
      max_y = t[0].length; // maybe a BUG
   }

   public void add(int r, int c, int value) {
      for (int i = r; i < t.length; i |= i + 1)
         for (int j = c; j < t[0].length; j |= j + 1)
            t[i][j] += value;
   }

   // sum[(0, 0), (r, c)]
   public int sum(int r, int c) {
      int res = 0;
      for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
         for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
            res += t[i][j];
      return res;
   }

   // sum[(r1, c1), (r2, c2)]
   public int sum(int r1, int c1, int r2, int c2) {
      return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1)
            + sum(r1 - 1, c1 - 1);
   }

   public int get(int r, int c) {
      return sum(r, c, r, c);
   }

   public void set(int r, int c, int value) {
      add(r, c, -get(r, c) + value);
   }

}