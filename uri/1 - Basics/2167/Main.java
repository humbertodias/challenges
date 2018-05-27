import java.util.*;

class Main{

    public static void main(String [] args){

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int rpm, rpm_old = -1, rpm_ind_queda = 0;
        for(int i=0; i < N; i++){
            rpm = scanner.nextInt();
            if(rpm < rpm_old){
                rpm_ind_queda = i+1;
                break;
            }
            rpm_old = rpm;
        }
        System.out.println(rpm_ind_queda);

    }
}