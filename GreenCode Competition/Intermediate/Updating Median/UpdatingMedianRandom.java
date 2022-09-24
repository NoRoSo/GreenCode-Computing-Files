import java.io.File;
import java.io.FileWriter;
import java.util.*;
public class UpdatingMedianRandom {
    static Random rand = new Random(124);
    public static void main(String[] args) throws Exception{
        FileWriter fw = new FileWriter(new File("Input"));
        int queries = 10000;

        fw.write(queries + "\n");

        for(int q = 0; q < queries - 1; q++){
            int actionChance = rand.nextInt(50);
            String action = actionChance < 44 ? "add " : "median";
            if(action.contains("add")){
                int randNum = rand.nextInt(100_000) + 1;
                fw.write(action + randNum + "\n");
            }else{
                fw.write(action + "\n");
            }
        }
        fw.write("median\n");
        fw.close();
    }
}
