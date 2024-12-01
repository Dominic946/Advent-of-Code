import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

//672870911 < x


public class day10 {
    static final Character[] temp = {'(','[','{','<'};
    static final List<Character> open = Arrays.asList(temp);
    static final Character[] temp2 = {')',']','}','>'};
    static final List<Character> close = Arrays.asList(temp2);
    static final int[] scores = {3,57,1197,25137};
    static final int[] scores2 = {1,2,3,4};

    public static void main(String[] args) throws FileNotFoundException {
        Scanner s = new Scanner(new File("day10.txt"));
        int total1 = 0;
        ArrayList<Long> total2 = new ArrayList<>();
        while(s.hasNextLine()){
            String in = s.nextLine();
            total1 += corrupt(in);
            long v = incomplete(in);
            if(v != -1){
                total2.add(v);
            }
        }
        Collections.sort(total2);
        System.out.println(total1);
        System.out.println(total2.get(total2.size()/2));
    }

    public static int corrupt(String input){
        LinkedList<Character> stack = new LinkedList<>();
        for(int i = 0; i < input.length(); i++){
            if(open.contains(input.charAt(i))) {
                stack.push(input.charAt(i));
            } else {
                char pop = stack.pop();
                if(open.indexOf(pop) != close.indexOf(input.charAt(i))){
                    return scores[close.indexOf(input.charAt(i))];

                }
            }
        }
        return 0;
    }

    public static long incomplete(String input){
        LinkedList<Character> stack = new LinkedList<>();
        for(int i = 0; i < input.length(); i++){
            if(open.contains(input.charAt(i))) {
                stack.push(input.charAt(i));
            } else {
                char pop = stack.pop();
                if(open.indexOf(pop) != close.indexOf(input.charAt(i))){
                    return -1;
                }
            }
        }
        long sum = 0;
        while(!stack.isEmpty()){
            char pop = stack.pop();
            sum *= 5;
            sum += scores2[open.indexOf(pop)];
            if(sum < 0){
                System.out.println("err");
            }
        }
        return sum;
    }
}
