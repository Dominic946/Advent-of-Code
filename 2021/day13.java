import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class day13 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day13.txt"));

        //my input had 923 points and 12 folds
        int[][] data = new int[923][2];
        String[][] folds = new String[12][2];
        //read in the points
        for(int i = 0; i < data.length; i++){
            String[] in = s.nextLine().split(",");
            data[i][0] = Integer.parseInt(in[0]);
            data[i][1] = Integer.parseInt(in[1]);
        }

        //skip over the empty line in the input
        s.nextLine();

        //read in the folds
        for(int i = 0; i < folds.length; i++){
            String[] in = s.nextLine().split(" ");
            String[] fold = in[2].split("=");
            folds[i][0] = fold[0];
            folds[i][1] = fold[1];
        }

        //loop through all the folds, check if it is x fold or y fold
        //for each fold, loop through all points and flip it across the fold line if on the other side
        for(int i =  0; i < folds.length; i++){
            if(folds[i][0].equals("x")){
                for(int j = 0; j < data.length; j++){
                    if(data[j][0] > Integer.parseInt(folds[i][1])){
                        data[j][0] = Integer.parseInt(folds[i][1]) * 2 - data[j][0];
                    } else {
                        if(data[j][0] == Integer.parseInt(folds[i][1])){
                            data[j][0] = -1;
                            data[j][1] = -1;
                        }
                    }
                }
            }
            if(folds[i][0].equals("y")){
                for(int j = 0; j < data.length; j++){
                    if(data[j][1] > Integer.parseInt(folds[i][1])){
                        data[j][1] = Integer.parseInt(folds[i][1]) * 2 - data[j][1];
                    } else {
                        if(data[j][1] == Integer.parseInt(folds[i][1])){
                            data[j][0] = -1;
                            data[j][1] = -1;
                        }
                    }
                }
            }
        }

        //now we are done folding.
        //seen is a array of all the unique dot locations, and size is the number of unique dots
        int[][] seen = new int[data.length][2];
        int size = 0;
        //loop through all points, if we have not yet seen a point in this location, add it to the list and increase size
        for(int i = 0; i < data.length; i++){
            if(!contain(seen, size, data[i])){
                seen[size][0] = data[i][0];
                seen[size][1] = data[i][1];
                size += 1;
            }
        }

        //This prints out all the points
        int[] temp = new int[2];
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 10; j++){
                temp[0] = i;
                temp[1] = j;
                if(contain(seen, size, temp)){
                    System.out.print("#");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println(" ");
        }

    }

    //function checks if the "saw" array contains the "ask" array. len is the number of unique points in the saw array.
    private static boolean contain(int[][] saw, int len, int[] ask){
        for(int k = 0; k < len; k++){
            if(saw[k][0] == ask[0] && saw[k][1] == ask[1]){
                return true;
            }
        }
        return false;
    }
}