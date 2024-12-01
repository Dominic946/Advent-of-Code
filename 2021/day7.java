import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.lang.Math;

public class day7 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day7.txt"));
        String[] in = s.nextLine().split(",");
        int[] input = new int[in.length];
        int max = 0;
        for(int k = 0; k < in.length; k++){
            input[k] = Integer.parseInt(in[k]);
            if(input[k] > max){
                max = input[k];
            }
        }

        int minD = -1;
        int minIdx = 0;
        for(int i = 0; i < max; i++){
            int sum = 0;
            for (int j = 0; j < input.length; j++){
                int n = Math.abs(input[j] - i);
                sum += (n * (n + 1)) / 2;
            }
            if(sum < minD || minD == -1){
                minD = sum;
                minIdx = i;
            }
        }

        System.out.println(minD);


    }
}
