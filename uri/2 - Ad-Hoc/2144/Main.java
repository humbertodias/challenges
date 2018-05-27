import java.util.*;

public class Main {

  public static void main(String args[]) {

    Scanner scanner = new Scanner(System.in);

    // W = Peso a ser levantado.
    // R = Número de repetições.
    int W1, W2, W = 0, R, qtd = 0;
    float M, esq, dir;
    float media, acumulacao = 0;
    while (scanner.hasNext()) {
      W1 = scanner.nextInt();
      W2 = scanner.nextInt();
      R = scanner.nextInt();

      esq = W1 * (1 + R / 30f);
      dir = W2 * (1 + R / 30f);

      media = (esq + dir) / 2;
      acumulacao += media;

      if (W1 != 0 && W2 != 0 && R != 0) {
        qtd++;
        if (media >= 1 && media < 13) {
          System.out.println("Nao vai da nao");
        }
        if (media >= 13 && media < 14) {
          System.out.println("E 13");
        }
        if (media >= 14 && media < 40) {
          System.out.println("Bora, hora do show! BIIR!");
        }
        if (media >= 40 && media <= 60) {
          System.out.println("Ta saindo da jaula o monstro!");
        }
        if (media > 60) {
          System.out.println("AQUI E BODYBUILDER!!");
        }

      }

      if (W1 == W2 && W2 == R && R == 0) {
        if ((acumulacao / qtd) > 40) {
          System.out.printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");
        }

      }
    }

  }
}