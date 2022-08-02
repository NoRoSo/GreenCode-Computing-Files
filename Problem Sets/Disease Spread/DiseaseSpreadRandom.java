import java.io.File;
import java.io.FileWriter;
import java.util.*;
public class DiseaseSpreadRandom {
    static Random rand = new Random(123);
    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter(new File("Input"));

        int cases = 1000;
        fw.write(cases + "\n");
        for(int z = 0; z < cases; z++){
            int days = rand.nextInt(50) + 50;
            int delay = rand.nextInt(6) + 3;
            int relief = rand.nextInt(5) + delay + 1;
            fw.write(days + " " + delay + " " + relief + "\n");
        }

        fw.close();
    }
}
