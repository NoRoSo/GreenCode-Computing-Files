import java.io.File;
import java.io.FileWriter;
import java.util.*;
public class SoldierRankRandom {
    static Random rand = new Random(123);
    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter(new File("Input"));

        int soldiers = 10_000;

        fw.write(soldiers + "\n");

        for(int i = 0; i < soldiers; i++){
            int randAttack = rand.nextInt(100_000) + 1, randDefense = rand.nextInt(100_000) + 1;
            fw.write(randAttack + " " + randDefense + "\n");
        }

        fw.close();
    }
}
