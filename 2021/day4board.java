public class day4board {
    private int[][] nums;
    private boolean[][] marked;
    private int lastCall;
    private boolean good;

    public day4board(int[][] matrix){
        //lastCall is the last number that was marked on the board
        //nums is the matrix for the board numbers
        //good is a boolean if the board has won (true) or not yet won (false)
        //marked is boolean array if each square on the board has been marked yet
        this.lastCall = -1;
        this.nums = new int[5][5];
        this.good = false;
        this.marked = new boolean[5][5];

        //Copy the input matrix to this object
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                this.nums[i][j] = matrix[i][j];
            }
        }
    }

    //If a number is on the board, then set it as marked.
    //Also update the last marked number, and check if this caused it to win
    public void mark(int num){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(this.nums[i][j] == num){
                    this.marked[i][j] = true;
                    this.lastCall = num;
                    this.good = checkGood();
                    return;
                }
            }
        }
    }

    //This checks if the board has a bingo
    private boolean checkGood(){
        for (int i = 0; i < 5; i++){
            if (this.marked[i][0] && this.marked[i][1] && this.marked[i][2] && this.marked[i][3] && this.marked[i][4]){
                return true;
            }
            if (this.marked[0][i] && this.marked[1][i] && this.marked[2][i] && this.marked[3][i] && this.marked[4][i]){
                return true;
            }
        }
        return false;
    }

    public boolean isGood(){
        return this.good;
    }

    public int getLast(){
        return lastCall;
    }

    //sum all the unmarked numbers on the board
    public int getSum(){
        int sum = 0;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                sum += nums[i][j] * (marked[i][j]? 0:1);
            }
        }
        return sum;
    }
}
