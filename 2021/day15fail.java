import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

//2269 < x

public class day15fail {
    static int n;
    static int p;
    static int[][] least;
    static int[][] data;

    public static void main(String[] args) throws FileNotFoundException {
        ArrayList<String> input = new ArrayList<>();
        Scanner s = new Scanner(new File("day15.txt"));
        while(s.hasNextLine()){
            input.add(s.nextLine());
        }

        n = input.size();
        p = input.get(0).length();
        data = new int[n][p];

        //for each spot in the grid, 'least' is the length of the shortest path to get there.
        least = new int[n][p];

        //set the data array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                data[i][j] = Integer.parseInt(String.valueOf(input.get(i).charAt(j)));
            }
        }

        setLeast(0,0);

        int total = 0;
        int[] minSpot;

        path(0,0);
        minSpot = findMin();
        total += minSpot[2];
        levelUp(minSpot);
        total += data[minSpot[1]][minSpot[0]];

        for(int box = 0; box < 6; box++){
            setLeast(minSpot[0],minSpot[1]);
            path(minSpot[1],minSpot[0]);
            minSpot = findMin();
            total += minSpot[2];
            levelUp(minSpot);
            total += data[minSpot[1]][minSpot[0]];
        }

        path(minSpot[1],minSpot[0]);

        System.out.println(total + least[n-1][p-1]);

    }

    public static void path(int x, int y){
        int myCost = least[y][x];
        /*
        if (x > 0 && (least[y][x-1] > myCost + data[y][x - 1] || least[y][x-1] == -1)){
            least[y][x-1] = myCost + data[y][x - 1];
            path(x-1, y);
        }
         */
        if (x < p - 1 && (least[y][x+1] > myCost + data[y][x + 1] || least[y][x+1] == -1)){
            least[y][x+1] = myCost + data[y][x + 1];
            path(x+1, y);
        }
        /*
        if (y > 0 && (least[y-1][x] > myCost + data[y - 1][x] || least[y-1][x] == -1)){
            least[y-1][x] = myCost + data[y - 1][x];
            path(x, y-1);
        }
         */
        if (y < n - 1 && (least[y+1][x] > myCost + data[y + 1][x] || least[y+1][x] == -1)){
            least[y+1][x] = myCost + data[y + 1][x];
            path(x, y+1);
        }
    }

    public static int[] findMin(){
        int min = least[n-1][p-1];
        int minX = p-1;
        int minY = n-1;
        for(int i = 0; i < n; i++){
            if (least[i][p-1] < min){
                minX = p-1;
                minY = i;
                min = least[i][p-1];
            }
        }
        for(int i = 0; i < p; i++){
            if(least[n-1][i] < min){
                minX = i;
                minY = n-1;
                min = least[n-1][i];
            }
        }
        return new int[]{minX, minY, min};
    }

    public static void levelUp(int[] minSpot){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                data[i][j] += 1;
                if(data[i][j] == 10){
                    data[i][j] = 1;
                }
            }
        }
        if(minSpot[0] < p-1){
            minSpot[1] = 0;
        } else if(minSpot[1] < n-1){
            minSpot[0] = 0;
        } else{
            data[-1][-1] = 0;
        }
    }

    public static void setLeast(int x, int y){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                least[i][j] = -1;
            }
        }
        least[y][x] = 0;
    }
}
