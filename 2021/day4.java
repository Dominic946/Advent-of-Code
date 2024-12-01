import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class day4 {
    public static void main(String[] args) throws FileNotFoundException {

        //read in the input, and store the list of called numbers in the 'calls' array
        Scanner s = new Scanner(new File("day4.txt"));
        String[] callString = s.nextLine().split(",");
        int[] calls = new int[callString.length];
        for(int i = 0; i < callString.length; i++){
            calls[i] = Integer.parseInt(callString[i]);
        }

        //Load each board in the input to a temporary 2d array, then convert them to board objects.
        //"boards" is an array of board objects.
        day4board[] boards = new day4board[100];
        int[][] tempBoard = new int[5][5];
        int n = 0;
        while(s.hasNextInt()){
            for(int i = 0; i<5; i++){
                for(int j = 0; j<5; j++){
                    tempBoard[i][j] = s.nextInt();
                }
            }
            boards[n] = new day4board(tempBoard);
            n++;
        }

        //make times is an int array of how long it takes each board to be solved.
        int[] times = new int[100];
        for(int i = 0; i < 100; i++){
            int j = 0;
            while(!boards[i].isGood()){
                boards[i].mark(calls[j]);
                times[i]++;
                j++;
            }
        }

        //find boards with the min and max times.
        int min = 100;
        int minIdx = 0;
        int max = 0;
        int maxIdx = 0;
        for(int i = 0; i < 100; i++){
            if(times[i] < min){
                min = times[i];
                minIdx = i;
            }
            if(times[i] > max){
                max = times[i];
                maxIdx = i;
            }
        }

        //print answers.
        System.out.printf("Part 1 solution: %d\n", boards[minIdx].getLast() * boards[minIdx].getSum());
        System.out.printf("Part 2 solution: %d\n", boards[maxIdx].getLast() * boards[maxIdx].getSum());
    }
}
