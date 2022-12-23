public class LionfishMANAGER {
  public static void main(String[] args) {
    LionfishTBL lt = new LionfishTBL("MASTER_DATA.csv");
    System.out.println("Success!");
  }

  public static float getRATIO(int key, LionfishTBL lt; int startKey, int endKey) {
  //key: the setting on which the function operates. 0: noodles, 1: sex <<< % MALE.
    //Pseudocode:
    //Start at log entry chain of startKey
    //End at log entry chain greater than endKey
    //Sum all entries of either noodles (+ 0), beards (+1), or eggs, (3)
    //before I do this, let's consider: should I create a diagnostic object with totals to speed up computing time?
  }


}
