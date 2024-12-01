import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.lang.Math;

//300 > x > 197

public class day8 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day8.txt"));
        String[][] notes = new String[200][10];
        String[][] answers = new String[200][4];
        int i = 0;
        while(s.hasNextLine()){
            String[] in = s.nextLine().split(" \\| ");
            notes[i] = in[0].split(" ");
            answers[i] = in[1].split(" ");
            i++;
        }

        int total = 0;
        for(int j = 0; j < 200; j++){
            total += determine(notes[j], answers[j]);
        }
        System.out.println(total);
    }

    //cipher array indices
    //  0
    //1   2
    //  3
    //4   5
    //  6

    public static int determine(String[] key, String[] out){
        char[] cipher = new char[7];
        //first find the known characters
        int zer = 0;
        int one = 0;
        int four = 0;
        int six = 0;
        int sev = 0;
        int ate = 0;
        int nin = 0;
        //set the four confirmed numbers
        for(int k = 0; k < 10; k++){
            if (key[k].length() == 2){
                one = k;
            }
            if (key[k].length() == 3){
                sev = k;
            }
            if (key[k].length() == 4){
                four = k;
            }
            if (key[k].length() == 7){
                ate = k;
            }
        }

        //check the difference of one and seven, that is the top part
        for(int k = 0; k < 3; k++) {
            if (!key[one].contains(String.valueOf(key[sev].charAt(k)))) {
                cipher[0] = key[sev].charAt(k);
            }
        }

        //find the numbers with 6 parts
        int[] sixes = new int[3];
        int a = 0;
        for(int k = 0; k < 10; k++) {
            if (key[k].length() == 6) {
                sixes[a] = k;
                a++;
            }
        }
        //9 is the only number length 6 that has all of 4
        for(int k = 0; k < 3; k++){
            boolean match = true;
            for(int l = 0; l < 4; l++){
                if(!key[sixes[k]].contains(String.valueOf(key[four].charAt(l)))){
                    match = false;
                    break;
                }
            }
            if(match){
                nin = sixes[k];
            }
        }
        //the bottom part is the one part of 9 that is not in 4 and not the top part
        for(int k = 0; k < 6; k++){
            if(!(key[four].contains(String.valueOf(key[nin].charAt(k))) || key[nin].charAt(k) == cipher[0])){
                cipher[6] = key[nin].charAt(k);
            }
        }
        //the part in 8 but not in 9 is bottom left
        for(int k = 0; k < 7; k++){
            if(!(key[nin].contains(String.valueOf(key[ate].charAt(k))))){
                cipher[4] = key[ate].charAt(k);
            }
        }
        //if the other sixes contain all of one, then that is 0. Otherwise, it is 6.
        for(int k = 0; k < 3; k++){
            if(!(sixes[k] == nin)){
                boolean match = true;
                for(int l = 0; l < 2; l++){
                    if(!key[sixes[k]].contains(String.valueOf(key[one].charAt(l)))){
                        match = false;
                    }
                }
                if(match) {
                    zer = sixes[k];
                } else {
                    six = sixes[k];
                }
            }
        }

        //the part in 8 but not in 0 is middle
        //the part in 8 but not in 6 is top right
        for(int k = 0; k < 7; k++){
            if(!(key[zer].contains(String.valueOf(key[ate].charAt(k))))){
                cipher[3] = key[ate].charAt(k);
            }
            if(!(key[six].contains(String.valueOf(key[ate].charAt(k))))){
                cipher[2] = key[ate].charAt(k);
            }
        }

        //the part in 1 that isn't top right is the bottom right
        if(key[one].charAt(0) == cipher[2]){
            cipher[5] = key[one].charAt(1);
        } else {
            cipher[5] = key[one].charAt(0);
        }

        //the part in 4 not yet discovered is top left
        for(int k = 0; k < 4; k++){
            if (!(key[four].charAt(k) == cipher[2] || key[four].charAt(k) == cipher[3] || key[four].charAt(k) == cipher[5])){
                cipher[1] = key[four].charAt(k);
            }
        }

        //cipher is complete, now decode answer
        int sum = 0;
        //for each of the four output numbers...
        for(int m = 0; m < 4; m++){
            //convert each letter to its screen segment
            int screen = 0;
            for(int o = 0; o < out[m].length(); o++){
                screen += Math.pow(2, index(out[m].charAt(o), cipher));
            }
            if(screen == 119){
                sum += 0 * Math.pow(10, (3-m));
            }
            if(screen == 36){
                sum += 1 * Math.pow(10, (3-m));
            }
            if(screen == 93){
                sum += 2 * Math.pow(10, (3-m));
            }
            if(screen == 109){
                sum += 3 * Math.pow(10, (3-m));
            }
            if(screen == 46){
                sum += 4 * Math.pow(10, (3-m));
            }
            if(screen == 107){
                sum += 5 * Math.pow(10, (3-m));
            }
            if(screen == 123){
                sum += 6 * Math.pow(10, (3-m));
            }
            if(screen == 37){
                sum += 7 * Math.pow(10, (3-m));
            }
            if(screen == 127){
                sum += 8 * Math.pow(10, (3-m));
            }
            if(screen == 111){
                sum += 9 * Math.pow(10, (3-m));
            }
        }

        return sum;
    }

    public static int index(char c, char[] cipher){
        for(int n = 0; n < cipher.length; n++){
            if(cipher[n] == c){
                return n;
            }
        }
        return -1;
    }
}
