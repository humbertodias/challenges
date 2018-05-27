import java.util.*;

public class Main{

    public static int numberOfOccurrences(String source, String sentence) {
        int occurrences = 0;

        if (source.contains(sentence)) {
            int withSentenceLength    = source.length();
            int withoutSentenceLength = source.replace(sentence, "").length();
            occurrences = (withSentenceLength - withoutSentenceLength) / sentence.length();
        }

        return occurrences;
    }

    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        String seq, subseq;
        long caso=0, qtd, pos;
        while(scanner.hasNext()){
            subseq = scanner.nextLine();
            seq = scanner.nextLine();
            qtd = numberOfOccurrences(seq, subseq);
            pos = seq.lastIndexOf(subseq);

            System.out.format("Caso #%d:\n",++caso);
            if(qtd > 0){
                System.out.printf("Qtd.Subsequencias: %d\n", qtd);
                System.out.printf("Pos: %d\n\n",pos+1);
            }else{
                System.out.printf("Nao existe subsequencia\n\n");
            }
        }
    }
}