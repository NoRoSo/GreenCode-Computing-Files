import java.io.File;
import java.io.FileWriter;
import java.util.*;
public class RapidWaterRandom {
    static Random rand = new Random(123);
    public static void main(String[] args) throws Exception{
        FileWriter fw = new FileWriter(new File("Input"));

        int cases = 100;

        fw.write(cases + "\n");
        while(cases-- != 0){
            int randN = rand.nextInt(99) + 2;
            fw.write(randN + "\n");
            for(int i = 0; i < randN; i++){
                for(int x = 0; x < randN; x++){
                    int randNum = rand.nextInt(50) + 1;
                    fw.write(randNum + " ");
                }
                fw.write("\n");
            }
        }
        fw.close();
    }
}
