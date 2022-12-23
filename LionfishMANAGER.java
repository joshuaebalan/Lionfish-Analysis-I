import java.util.ArrayList;
public class LionfishMANAGER {
  public static void main(String[] args) {
    LionfishTBL lt = new LionfishTBL("MASTER_DATA.csv");
    System.out.println("Success!");
    System.out.println(getRATIO(0, lt, 210301, 220301));
  }

  public static float getRATIO(int key, LionfishTBL lt, int startKey, int endKey) {
    int startDex = 0;
    while (lt.diagnose(startDex).identify() < startKey) {
      startDex++;
    }
    int total = 0;
    int count = 0;
    DiagnosticNode dn = null;
    do {
      dn = lt.diagnose(startDex);
      total = total + dn.tallies[key];
      count = count + dn.getCount();
      startDex++;
    }  while (dn.identify() < endKey && startDex < lt.getWidth());
    return total / count;
  }


}
