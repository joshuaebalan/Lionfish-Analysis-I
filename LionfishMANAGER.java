import java.util.ArrayList;
public class LionfishMANAGER {
  public static void main(String[] args) {
    LionfishTBL lt = new LionfishTBL("MASTER_DATA.csv");

    //lt.review();
    //System.out.println(getRATIO(0, 3, lt, 000000, 999999));
  }

  public static float getRATIO(int key, int sex, LionfishTBL lt, int startKey, int endKey) { //key: 0 = noodles, 1 = len with tail, 2 = len without; sex: 1 for both, other 2 normal
    int startDex = 0;
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
