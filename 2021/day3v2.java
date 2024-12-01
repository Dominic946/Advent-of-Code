import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class day3v2 {
    public static void main(String[] args) throws FileNotFoundException {
        int m = 1000;
        Scanner s = new Scanner(new File("day3.txt"));
        String[] data = new String[m];
        for(int i = 0; i < m; i++){
            data[i] = s.nextLine();
        }

        boolean[] oxygen = new boolean[m]; //true = kicked out, false = good for now
        boolean[] scrubber = new boolean[m];
        int max;

        int remaining = 3;
        int digit = 0;

        while(remaining > 1){
            remaining = 0;
            max = major(data, oxygen, digit, 1); //find max of remaining items
            for(int i = 0; i < m; i++){ //loop through all numbers
                if(!oxygen[i]){ //if not yet kicked
                    if(Character.getNumericValue(data[i].charAt(digit)) == max){
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

        while(remaining > 1){
            remaining = 0;
            max = 1-major(data, scrubber, digit, 1); //find max of remaining items
            for(int i = 0; i < m; i++){ //loop through all numbers
                if(!scrubber[i]){ //if not yet kicked
                    if(Character.getNumericValue(data[i].charAt(digit)) == max){
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

    public static int major(String[] data, boolean[] kicked, int idx, int trump){
        int count = 0;
        for(int i = 0; i < data.length; i++){
            if(!kicked[i]) {
                count += Character.getNumericValue(data[i].charAt(idx)) * 2 - 1;
            }
        }
        if (count == 0){ return trump; }
        if (count > 0){ return 1; }
        return 0;
    }
}
