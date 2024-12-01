import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;


public class day12 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day12.txt"));
        ArrayList<d12node> d = new ArrayList<>();
        ArrayList<String> ds = new ArrayList<>();
        while (s.hasNextLine()){
            String[] in = s.nextLine().split("-");
            if(!ds.contains(in[0])){
                ds.add(in[0]);
                d.add(new d12node(in[0]));
            }
            if(!ds.contains(in[1])){
                ds.add(in[1]);
                d.add(new d12node(in[1]));
            }
            d.get(ds.indexOf(in[0])).addPtr(d.get(ds.indexOf(in[1])));
            d.get(ds.indexOf(in[1])).addPtr(d.get(ds.indexOf(in[0])));
        }
        d12node start = d.get(ds.indexOf("start"));

        int ans1;
        int ans2;
        ArrayList<d12node> vis = new ArrayList<>();
        ans1 = look(vis, start, true);
        ans2 = look(vis, start, false);

        System.out.printf("Part 1: %d\nPart 2: %d\n", ans1, ans2);
    }

    public static int look(ArrayList<d12node> vis, d12node start, boolean again){
        ArrayList<d12node> thisVis = new ArrayList<>();
        boolean thisAgain = again;
        for(int i = 0; i < vis.size(); i++){
            thisVis.add(vis.get(i));
        }
        if(thisVis.contains(start)){
            if(!start.getBig()){
                thisAgain = true;
            }
        } else {
            thisVis.add(start);
        }
        int sum = 0;
        for(int i = 0; i < start.getPtr().size(); i++){
            if((!thisVis.contains(start.getPtr().get(i))) || !thisAgain || start.getPtr().get(i).getBig()){
                if(start.getPtr().get(i).getName().equals("end")){
                    sum += 1;
                } else {
                    if(!start.getPtr().get(i).getName().equals("start")){
                        sum += look(thisVis, start.getPtr().get(i), thisAgain);
                    }
                }
            }
        }
        return sum;
    }
}
