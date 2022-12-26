import java.util.ArrayList;
import java.io.*;
import java.util.Date;
public class LionfishMANAGER {
  public static void main(String[] args) {
    LionfishTBL lt = new LionfishTBL("MASTER_DATA.csv");
    //System.out.println("Closest to (lower) of 999999: " + lt.fitLower(999999));
    //lt.review();
    //lt.printKeys();
    buildCSV(1, 3, "Female_full_fixed.csv", lt, 000000, 999999);
    buildCSV(1, 2, "Male_full_fixed.csv", lt, 000000, 999999);
    buildCSV(1, 1, "Int_full_fixed.csv", lt, 000000, 999999);


    System.out.println("Male: " + getRATIO(1, 2, lt, 000000, 999999) + ";\nFemale: " + getRATIO(1, 3, lt, 000000, 999999) + ";\nBoth: " + getRATIO(1, 1, lt, 000000, 999999));


  }
  public static void buildCSV(int key, int sex, String filename, LionfishTBL lt, int startKey, int endKey) {
    if (filename.equals("")) {
      Date date = new Date();
      filename = date.getTime() + ".csv";
    }
    int startLoc = 0;
    int endLoc = 0;
    startKey = lt.fitUpper(startKey);
    endKey = lt.fitLower(endKey);
    ArrayList<Integer> kl = lt.getKeyList();
    for (int i = 0; i < kl.size(); i++) {
      if (startKey == kl.get(i)) {
        startLoc = i;
      }
      if (endKey == kl.get(i)) {
        endLoc = i;
      }
    }
    System.out.println(startLoc + "," + endLoc);
    System.out.println(kl.size());
    BufferedWriter bw;
    try {
      bw = new BufferedWriter(new FileWriter(filename));
      float x;
      String ret = "";
      for (int i = startLoc; i < endLoc; i++) {
        //System.out.println(kl.get(i) + "," + kl.get(i + 1));
        x = getRATIO(key, sex, lt, kl.get(i), kl.get(i + 1));
        ret = kl.get(i) + "," + kl.get(i + 1) + "," + x + "\n";
        //System.out.println(ret);
       bw.write(ret);
      }
      bw.close();
    }
    catch (IOException e) {
      e.printStackTrace();
    }
  }
  /*
  public static LionfishTBL binRead(String filename) {
    try {
      FileInputStream fis = new FileInputStream(filename);
      ObjectInputStream ois = new ObjectInputStream(fis);
      Object ret = ois.readObject();
      ois.close();
      fis.close();
      return (LionfishTBL) ret;
    }
    catch (Exception e) {
      e.printStackTrace();
      return null;
    }
  } */
  public static float getRATIO(int key, int sex, LionfishTBL lt, int startKey, int endKey) { //key: 0 = noodles, 1 = len with tail, 2 = len without; sex: 1 for both, other 2 normal
    int startDex = 0;
    if (lt.diagnose(startDex) == null) {
      return 0;
    }
    while (lt.diagnose(startDex).identify() < startKey) {
      startDex++;
    }
    float total = 0;
    float count = 0;
    DiagnosticNode dn = null;
    if (sex != 1) {
      int key2 = key - 1; //simplified key for calculation purposes
      do {
        dn = lt.diagnose(startDex);
        if (dn == null) {
          return 0;
        }
        //System.out.println("Visited " + dn.identify());
        total = total + dn.tallies[sex + (2 * key2)];
        count = count + dn.tallies[sex + 4];
        startDex++;
      }  while (dn.identify() < endKey && startDex < lt.getWidth());
    }
    else {
      do {
        dn = lt.diagnose(startDex);
        //System.out.println("Visited " + dn.identify());
        total = total + dn.tallies[2 * key];
        total = total + dn.tallies[(2 * key) + 1];
        count = count + dn.getCount();
        startDex++;
      }  while (dn.identify() < endKey && startDex < lt.getWidth());
      }
    return total / count;

}

}
