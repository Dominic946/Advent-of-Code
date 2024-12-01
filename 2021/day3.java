import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class day3 {
    public static void main(String[] args) throws FileNotFoundException {
        int m = 12;
        int n = 5;
        Scanner s = new Scanner(new File("test3.txt"));
        int[] totals = new int[n];
        String[] data = new String[m];
        String in;
        for(int i = 0; i < m; i++){
            in = s.nextLine();
            data[i] = in;
            for(int j = 0; j < n; j++){
                totals[j] += Character.getNumericValue(in.charAt(j));
            }
        }

        boolean most1;
        int[] popular = new int[n];
        int[] loser = new int[n];
        for(int i = 0; i < n; i++){
            most1 = totals[i] >= m/2;
            popular[i] = most1 ? 1:0;
            loser[i] = most1 ? 0:1;
        }
        s.close();
        boolean[] oxygen = new boolean[m]; //true = kicked out, false = good for now
        boolean[] scrubber = new boolean[m];
        int remaining = m;
        int digit = 0;

        while(remaining > 1){
            remaining = 0;
            for(int i = 0; i < m; i++){
                if(!oxygen[i]){ //if false
                    if(Character.getNumericValue(data[i].charAt(digit)) == popular[digit]){
                        remaining += 1;
                    } else {
                        oxygen[i] = true;
                    }
                }
            }
            digit++;
        }
        int a = 0;
        while(oxygen[a]){ a++; }

        remaining = 3;
        digit = 0;
        while(remaining > 2){
            remaining = 0;
            for(int i = 0; i < m; i++){
                if(!scrubber[i]){ //if false
                    if(Character.getNumericValue(data[i].charAt(digit)) == loser[digit]){
                        remaining += 1;
                    } else {
                        scrubber[i] = true;
                    }
                }
            }
            digit++;
        }


        int b = 0;
        while(scrubber[b]){ b++; }
        System.out.println(data[a]);
        System.out.println(data[b]);
    }
}
