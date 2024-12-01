import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class day5 {
    static int n = 500;
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day5.txt"));
        String[] in = new String[n];
        int m = 0;
        while(s.hasNextLine()){
            in[m] = s.nextLine();
            m++;
        }
        day5line[] data = new day5line[n];
        for(int i = 0; i < n; i++){
            data[i] = new day5line(in[i]);
        }

        int[][] totals = new int[1000][1000];
        for(int i = 0; i < n; i++) {
            if (data[i].isOrtho() || true) {
                int[][] oneLine = data[i].getLine();
                for (int j = 0; j < oneLine.length; j++) {
                    totals[oneLine[j][0]][oneLine[j][1]] += 1;
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < 1000; i++){
            for(int j = 0; j < 1000; j++){
                sum += (totals[i][j] > 1)? 1:0;
            }
        }
        System.out.println(sum);
    }
}
