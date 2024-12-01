import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.File;

public class day2 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day2.txt"));
        int depth = 0;
        int position = 0;
        int aim = 0;
        String[] input;
        while(s.hasNext()){
            input = s.nextLine().split(" ");
            if(input[0].equals("forward")){
                position += Integer.parseInt(input[1]);
                depth += aim * Integer.parseInt(input[1]);
            }
            if(input[0].equals("down")){
                aim += Integer.parseInt(input[1]);
            }
            if(input[0].equals("up")){
                aim -= Integer.parseInt(input[1]);
            }
        }
        System.out.println(depth * position);

    }
}
