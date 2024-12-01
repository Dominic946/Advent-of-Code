import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

//2269 < x
//not 2902

public class day15 {
    static int n;
    static int p;
    static int[][] least;
    static int[][] data;
    static int[][] base;

    public static void main(String[] args) throws FileNotFoundException {
        ArrayList<String> input = new ArrayList<>();
        Scanner s = new Scanner(new File("day15.txt"));
        while(s.hasNextLine()){
            input.add(s.nextLine());
        }

        n = input.size();
        p = input.get(0).length();
        base = new int[n][p];
        data = new int[n*5][p*5];

        //for each spot in the grid, 'least' is the length of the shortest path to get there.
        least = new int[5*n][5*p];

        //set the base array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                base[i][j] = Integer.parseInt(String.valueOf(input.get(i).charAt(j)));
            }
        }


        levelUp(0,0,0);

        levelUp(1, n, 0);
        levelUp(1, 0, p);

        levelUp(2, 2*n, 0);
        levelUp(2, n, p);
        levelUp(2, 0, 2*p);

        levelUp(3, 3*n, 0);
        levelUp(3, 2*n, p);
        levelUp(3, n, 2*p);
        levelUp(3, 0, 3*p);

        levelUp(4, 4*n, 0);
        levelUp(4, 3*n, p);
        levelUp(4, 2*n, 2*p);
        levelUp(4, n, 3*p);
        levelUp(4, 0, 4*p);

        levelUp(5, 4*n, p);
        levelUp(5, 3*n, 2*p);
        levelUp(5, 2*n, 3*p);
        levelUp(5, n, 4*p);

        levelUp(6, 4*n, 2*p);
        levelUp(6, 3*n, 3*p);
        levelUp(6, 2*n, 4*p);

        levelUp(7, 4*n, 3*p);
        levelUp(7, 3*n, 4*p);

        levelUp(8, 4*n, 4*p);


        for(int i = 0; i < 5*n; i++){
            for(int j = 0; j < 5*p; j++){
                least[i][j] = -1;
            }
        }
        least[0][0] = 0;

        path();

        System.out.println(least[5*n-1][5*p-1]);
    }

    public static void path(){
        boolean again = false;
        for(int y = 0; y < 5*n; y++){
            for (int x = 0; x < 5*p; x++){
                int myCost = least[y][x];

                if (x > 0 && (least[y][x-1] > myCost + data[y][x - 1] || least[y][x-1] == -1)){
                    least[y][x-1] = myCost + data[y][x - 1];
                    again = true;
                }
                if (x < (5*p)-1 && (least[y][x+1] > myCost + data[y][x + 1] || least[y][x+1] == -1)){
                    least[y][x+1] = myCost + data[y][x + 1];
                }
                if (y > 0 && (least[y-1][x] > myCost + data[y - 1][x] || least[y-1][x] == -1)){
                    least[y-1][x] = myCost + data[y - 1][x];
                    again = true;
                }
                if (y < (5*n) -1 && (least[y+1][x] > myCost + data[y + 1][x] || least[y+1][x] == -1)){
                    least[y+1][x] = myCost + data[y + 1][x];
                }
            }
        }
        if(again){
            path();
        }
    }

    public static void levelUp(int level, int offy, int offx){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                data[i + offy][j + offx] = base[i][j] + level;
                if(data[i + offy][j + offx] > 9){
                    data[i + offy][j + offx] -= 9;
                }
            }
        }
    }
}
