import java.util.*;

public class Main{

    public static void main(String [] args){

        Scanner scanner = new Scanner(System.in);
        int QArma, QMonstro, QMaxBala;
        long sumMonstro, sumMunicao;
        while(scanner.hasNext()){
            QArma = scanner.nextInt();
            sumMunicao = 0;
            for(int i=0; i < QArma; i++){
                scanner.next();
                sumMunicao += scanner.nextInt();
            }

            QMonstro = scanner.nextInt();
            sumMonstro = 0;
            for(int i=0; i < QMonstro; i++){
                scanner.next();
                sumMonstro += scanner.nextInt();
            }

            QMaxBala = scanner.nextInt();

            System.out.printf("Armas: %d, Monstro: %d, Municao: %d, MaxBala: %d\n", QArma, sumMonstro, sumMunicao, QMaxBala);

        }

    }
}