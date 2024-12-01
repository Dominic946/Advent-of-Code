import java.lang.Math;

public class day5line {
    int x0;
    int y0;
    int x1;
    int y1;
    int dx;
    int dy;
    int[][] line;
    int length;

    public day5line(String input) {
        String[] data = input.split(" -> ");
        this.x0 = Integer.parseInt(data[0].split(",")[0]);
        this.y0 = Integer.parseInt(data[0].split(",")[1]);
        this.x1 = Integer.parseInt(data[1].split(",")[0]);
        this.y1 = Integer.parseInt(data[1].split(",")[1]);

        this.dx = this.x0 == this.x1 ? 0:1;
        if (this.dx == 1 && this.x0 > this.x1){
            this.dx = -1;
        }
        this.dy = this.y0 == this.y1 ? 0:1;
        if (this.dy == 1 && this.y0 > this.y1){
            this.dy = -1;
        }
        if(this.dx == 0){
            this.length = Math.abs(this.y1 - this.y0) + 1;
        }else{
            this.length = Math.abs(this.x1 - this.x0) + 1;
        }

        this.line = new int[this.length][2];
        makeLine(dx, dy, length);
    }

    public boolean isOrtho(){
        return (this.x0 == this.x1 || this.y0 == this.y1);
    }

    private void makeLine(int dx, int dy, int length){
        for(int i = 0; i < length; i++){
            this.line[i][0] = this.x0 + i*dx;
            this.line[i][1] = this.y0 + i*dy;
        }
    }

    public int[][] getLine(){
        return this.line;
    }

}
