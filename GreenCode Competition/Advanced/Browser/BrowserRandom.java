import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class BrowserRandom {
    static Random rand = new Random(123);
    public static void main(String[] args) throws Exception{
        FileWriter fw = new FileWriter(new File("Input"));

        int queries = 10_000;
        fw.write(queries + "\n");
        for(int i = 0; i < 5; i++){
            fw.write("visit ");
            String randWebsite = "";
            int randLength = rand.nextInt(20) + 5;
            for(int x = 0; x < randLength; x++){
                randWebsite += (char)(rand.nextInt(26) + 97);
            }
            fw.write(randWebsite + ".com\n");
        }

        int websiteCounter = 5;
        int forwardWebsiteCounter = 0;
        for(int c = 0; c < queries - 5; c++){
            int randChance = rand.nextInt(20);
            if(randChance <= 15){
                websiteCounter++;
                forwardWebsiteCounter = 0;
                fw.write("visit ");
                String randWebsite = "";
                int randLength = rand.nextInt(20) + 5;
                for(int x = 0; x < randLength; x++){
                    randWebsite += (char)(rand.nextInt(26) + 97);
                }
                fw.write(randWebsite + ".com\n");

            }
            if(randChance <= 18 && randChance > 15){
                int randBack = rand.nextInt(websiteCounter < 0? 10 : websiteCounter + 1 ) + 1;
                fw.write("back " + randBack + "\n");
                websiteCounter -= randBack;
                forwardWebsiteCounter += randBack;
            }
            if(randChance == 19){
                int randForward = rand.nextInt(forwardWebsiteCounter + 1) + 3;
                fw.write("forward " + randForward + "\n");
            }
        }
        fw.close();
    }
}
