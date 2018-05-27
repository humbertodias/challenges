import java.util.*;

public class Main{ 
      
      public static void main(String [] args) throws Exception
      {
          String l;
          String [] lines;
          int X, H;
          Scanner scanner = new Scanner(System.in);

          while( scanner.hasNext() ){
              l = scanner.nextLine();
              lines = l.split(" ");

              for(int i=0; i < lines.length; i++){
                    X = Integer.parseInt(lines[i],8);

                    switch( X ){
                        case 64: System.out.format( "%c", ' ' ); break;

                        case 129: System.out.format( "%c", 'a' ); break;
                        case 130: System.out.format( "%c", 'b' ); break;
                        case 131: System.out.format( "%c", 'c' ); break;
                        case 132: System.out.format( "%c", 'd' ); break;
                        case 133: System.out.format( "%c", 'e' ); break;
                        case 134: System.out.format( "%c", 'f' ); break;
                        case 135: System.out.format( "%c", 'g' ); break;
                        case 136: System.out.format( "%c", 'h' ); break;
                        case 137: System.out.format( "%c", 'i' ); break;
             
                        case 145: System.out.format( "%c", 'j' ); break;
                        case 146: System.out.format( "%c", 'k' ); break;
                        case 147: System.out.format( "%c", 'l' ); break;
                        case 148: System.out.format( "%c", 'm' ); break;
                        case 149: System.out.format( "%c", 'n' ); break;
                        case 150: System.out.format( "%c", 'o' ); break;
                        case 151: System.out.format( "%c", 'p' ); break;
                        case 152: System.out.format( "%c", 'q' ); break;
                        case 153: System.out.format( "%c", 'r' ); break;
             
                        case 162: System.out.format( "%c", 's' ); break;
                        case 163: System.out.format( "%c", 't' ); break;
                        case 164: System.out.format( "%c", 'u' ); break;
                        case 165: System.out.format( "%c", 'v' ); break;
                        case 166: System.out.format( "%c", 'w' ); break;
                        case 167: System.out.format( "%c", 'x' ); break;
                        case 168: System.out.format( "%c", 'y' ); break;
                        case 169: System.out.format( "%c", 'z' ); break;

                        case 192: System.out.format( "%c", '{' ); break;
                        case 193: System.out.format( "%c", 'A' ); break;
                        case 194: System.out.format( "%c", 'B' ); break;
                        case 195: System.out.format( "%c", 'C' ); break;
                        case 196: System.out.format( "%c", 'D' ); break;
                        case 197: System.out.format( "%c", 'E' ); break;
                        case 198: System.out.format( "%c", 'F' ); break;
                        case 199: System.out.format( "%c", 'G' ); break;
                        case 200: System.out.format( "%c", 'H' ); break;
                        case 201: System.out.format( "%c", 'I' ); break;
             
                        case 208: System.out.format( "%c", '}' ); break;
                        case 209: System.out.format( "%c", 'J' ); break;
                        case 210: System.out.format( "%c", 'K' ); break;
                        case 211: System.out.format( "%c", 'L' ); break;
                        case 212: System.out.format( "%c", 'M' ); break;
                        case 213: System.out.format( "%c", 'N' ); break;
                        case 214: System.out.format( "%c", 'O' ); break;
                        case 215: System.out.format( "%c", 'P' ); break;
                        case 216: System.out.format( "%c", 'Q' ); break;
                        case 217: System.out.format( "%c", 'R' ); break;
             
                        case 226: System.out.format( "%c", 'S' ); break;
                        case 227: System.out.format( "%c", 'T' ); break;
                        case 228: System.out.format( "%c", 'U' ); break;
                        case 229: System.out.format( "%c", 'V' ); break;
                        case 230: System.out.format( "%c", 'W' ); break;
                        case 231: System.out.format( "%c", 'X' ); break;
                        case 232: System.out.format( "%c", 'Y' ); break;
                        case 233: System.out.format( "%c", 'Z' ); break;
             
                        case 240: System.out.format( "%c", '0' ); break;
                        case 241: System.out.format( "%c", '1' ); break;
                        case 242: System.out.format( "%c", '2' ); break;
                        case 243: System.out.format( "%c", '3' ); break;
                        case 244: System.out.format( "%c", '4' ); break;
                        case 245: System.out.format( "%c", '5' ); break;
                        case 246: System.out.format( "%c", '6' ); break;
                        case 247: System.out.format( "%c", '7' ); break;
                        case 248: System.out.format( "%c", '8' ); break;
                        case 249: System.out.format( "%c", '9' ); break;
                    }

                    if(i == lines.length-1)
                      System.out.println();
              }
          }

      }

}