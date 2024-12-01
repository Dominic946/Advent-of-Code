import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.LinkedList;

//not 13156

//197 pits in my input
public class day9 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day9.txt"));
        int a = 0;
        int n = 100;
        int pits = 197;
        String[] in = new String[n];

        while(s.hasNextLine()){
            in[a] = s.nextLine();
            a++;
        }
        int m = in[0].length();

        int[][] grid = new int[n][in[0].length()];
        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                grid[i][j] = Integer.parseInt(String.valueOf(in[i].charAt(j)));
            }
        }
        int[][] lows = new int[pits][2];
        int b = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == n - 1 || grid[i][j] < grid[i+1][j]){
                    if(i == 0 || grid[i][j] < grid[i-1][j]){
                        if(j == m - 1 || grid[i][j] < grid[i][j+1]){
                            if (j == 0 || grid[i][j] < grid[i][j-1]) {
                                lows[b][0] = i;
                                lows[b][1] = j;
                                b++;
                            }
                        }
                    }
                }
            }

        }


        int[] max = new int[3];
        for(int i = 0; i<pits; i++){
            System.out.println(i);
            int size = 0;
            LinkedList<String> visited = new LinkedList<>();
            LinkedList<int[]> stack = new LinkedList<>();
            stack.push(lows[i]);
            visited.push(lows[i][0] + "," + (lows[i][1]));
            while(!stack.isEmpty()){
                size += 1;
                int[] cur = stack.pop();
                int[] temp = new int[2];
                if (cur[0] > 0 && grid[cur[0] - 1][cur[1]] < 9){
                    temp[0] = cur[0]-1;
                    temp[1] = cur[1];
                    if(!(visited.contains((temp[0]) + "," +(temp[1])))){
                        stack.push(temp.clone());
                        visited.push((temp[0]) + "," + (temp[1]));
                    }
                }
                if (cur[0] < n-1 && grid[cur[0] + 1][cur[1]] < 9){
                    temp[0] = cur[0]+1;
                    temp[1] = cur[1];
                    if(!(visited.contains((temp[0]) + "," +(temp[1])))){
                        stack.push(temp.clone());
                        visited.push((temp[0]) + "," +(temp[1]));
                    }
                }
                if (cur[1] > 0 && grid[cur[0]][cur[1]-1] < 9){
                    temp[0] = cur[0];
                    temp[1] = cur[1]-1;
                    if(!(visited.contains((temp[0]) + "," +(temp[1])))){
                        stack.push(temp.clone());
                        visited.push((temp[0]) + "," +(temp[1]));
                    }
                }
                if (cur[1] < m-1 && grid[cur[0]][cur[1]+1] < 9){
                    temp[0] = cur[0];
                    temp[1] = cur[1] + 1;
                    if(!(visited.contains((temp[0]) + "," +(temp[1])))){
                        stack.push(temp.clone());
                        visited.push((temp[0]) + "," +(temp[1]));
                    }
                }
            }
            if(size > max[0]){
                max[2]=max[1];
                max[1]=max[0];
                max[0] = size;
            } else {
                if (size > max[1]){
                    max[2]=max[1];
                    max[1]=size;
                } else {
                    if (size > max[2]) {
                        max[2] = size;
                    }
                }
            }
        }

        System.out.println(max[0]*max[1]*max[2]);


    }
}
