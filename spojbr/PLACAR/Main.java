import java.util.*;

public class Main {

    static void solve() {

        ArrayList<String> nomesComp = new ArrayList<String>();
        ArrayList<Integer> acertosComp = new ArrayList<Integer>();
        Scanner s = new Scanner(System.in);
        int k = 0;
        int qtdeComp;

        String inicioEntrada = null;
        while (s.hasNextLine()) {
            inicioEntrada = s.nextLine();
            k++;
            qtdeComp = Integer.parseInt(inicioEntrada);
            
                while (qtdeComp > 0) {
                    String entrada = s.nextLine();
                    String[] aux = entrada.split(" ");
                    nomesComp.add(aux[0]);
                    acertosComp.add(Integer.parseInt(aux[1]));
                    qtdeComp--;
                }

                for (int i = 0; i < nomesComp.size(); i++) {
                    for (int j = 0; j < nomesComp.size() - 1; j++) {
                        if (acertosComp.get(j) < acertosComp.get(j + 1)) {
                            String aux = nomesComp.get(j + 1);
                            nomesComp.set(j + 1, nomesComp.get(j));
                            nomesComp.set(j, aux);

                            Integer auxN = acertosComp.get(j + 1);
                            acertosComp.set(j + 1, acertosComp.get(j));
                            acertosComp.set(j, auxN);
                        } else if (acertosComp.get(j) == acertosComp.get(j + 1)
                                && nomesComp.get(j).compareTo(nomesComp.get(j + 1)) > 0) {
                            String aux = nomesComp.get(j + 1);
                            nomesComp.set(j + 1, nomesComp.get(j));
                            nomesComp.set(j, aux);

                            Integer auxN = acertosComp.get(j + 1);
                            acertosComp.set(j + 1, acertosComp.get(j));
                            acertosComp.set(j, auxN);
                        }
                    }
                }

                System.out.format("Instancia %d\n",k);
                System.out.format("%s\n\n", nomesComp.get(nomesComp.size() - 1));
                acertosComp.clear();
                nomesComp.clear();
            
        }
    }
    
    public static void main(String[] args) {
       solve();
    }

}