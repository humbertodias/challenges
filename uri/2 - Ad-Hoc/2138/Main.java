import java.util.*;
import java.util.Map.*;

public class Main{

  public static void main(String args[]){
    HashMap<Integer,Integer> map = new HashMap<>();

    Scanner scanner = new Scanner(System.in);

    Integer num;
    while(scanner.hasNext()){

      for(char c : scanner.next().toCharArray()) {
        num = Character.getNumericValue(c);
        if(!map.containsKey(num))
          map.put(num, 0);
        else
          map.put(num, map.get(num)+1);
      }

      Integer maxIndex = -1;
      Integer maxValueInMap=(Collections.max(map.values()));  // This will return max value in the Hashmap
      for (Entry<Integer, Integer> entry : map.entrySet()) {  // Itrate through hashmap
          if (entry.getValue()>=maxValueInMap) {

              if(entry.getKey() > maxIndex)
              maxIndex = entry.getKey();

              maxValueInMap = entry.getValue();
          }
      }

      System.out.println(maxIndex);
      map.clear();

    }

  }

}