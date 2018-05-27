import java.util.*;

class Main{

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        float a = scanner.nextFloat();
        float b = scanner.nextFloat();
        float c = scanner.nextFloat();
        float d = scanner.nextFloat();

        float media = (a*2 + b*3 + c*4 + d*1)/(10.0f);
        System.out.format("Media: %.1f\n", media);

        if(media >= 7.0)
                System.out.format( "Aluno aprovado.\n");
        if(media < 5.0)
                System.out.format( "Aluno reprovado.\n");
        if(media >= 5.0 && media < 7.0){
            System.out.format( "Aluno em exame.\n");
            double e = scanner.nextFloat();
            System.out.format("Nota do exame: %.1f\n", e);
            if((media + e)/2.0f >= 5.0)
                System.out.format( "Aluno aprovado.\n");
            else
                System.out.format( "Aluno reprovado.\n");
            System.out.format("Media final: %.1f\n", (media + e)/2.0f );
        }

    }

}