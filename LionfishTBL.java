import java.util.ArrayList;
import java.io.*;
public class LionfishTBL {
    private int count; //the number of fish in the table
    private int width; //the number of chains in this table
    private ArrayList<Integer> keyList;
    private ArrayList<Object> table;
    public LionfishTBL(String filename) { //build new table from file
       table = new ArrayList<Object>();
       keyList = new ArrayList<Integer>();
       BufferedReader buf;
       try {
        buf = new BufferedReader(new FileReader(filename));
        String line = buf.readLine();
        int i = 1;
        while (line != null) {
          LionfishSTRUCT ls;
          try {
            ls = new LionfishSTRUCT(line);
          }
          catch (OhNoException e) {
            line = buf.readLine();
            i++;
            System.out.println(i);
            continue;
          }
          insert(ls);
          //System.out.println(count + ", " + width);
          line = buf.readLine();
          i++;
        }
       }
       catch (IOException e) {
        System.out.println("Something went wrong with file input!");
       }
    }
    public ArrayList<Integer> getKeyList() {
      return keyList;
    }
    public void printKeys() {
      System.out.println("Keys:");
      for (int i = 0; i < keyList.size(); i++) {
        System.out.print(keyList.get(i) + ", ");
      }
    }
   public int fitLower(int n) {
      for (int i = 1; i < keyList.size(); i++) {
        if (n < keyList.get(i)) {
          return keyList.get(i - 1);
        }
      }
      return keyList.get(keyList.size() - 2);
    }
    public int fitUpper(int n) {
      for (int i = 1; i < keyList.size(); i++) {
        if (n < keyList.get(i)) {
          return keyList.get(i);
        }
      }
      return keyList.get(keyList.size() - 1);
    }
   public void appendFILE(String filename) { //build new table from file
       BufferedReader buf;
       try {
        buf = new BufferedReader(new FileReader(filename));
        String line = buf.readLine();
        int i = 1;
        while (line != null) {
          LionfishSTRUCT ls;
          try {
            ls = new LionfishSTRUCT(line);
          }
          catch (OhNoException e) {
            line = buf.readLine();
            i++;
            System.out.println(i);
            continue;
          }
          insert(ls);
          //System.out.println(count + ", " + width);
          line = buf.readLine();
          i++;
        }
       }
       catch (IOException e) {
        System.out.println("Something went wrong with file input!");
       }
    }
    public void insert(LionfishSTRUCT ls) { //using all bits of the date a fish was caught, insert it into the table
        int key = ls.getHashDate();
        for (int i = 0; i < table.size(); i++) {
            ArrayList<Object> cur = (ArrayList<Object>) table.get(i);
            if (table.isEmpty() || ((DiagnosticNode) cur.get(0)).identify() > key) {
                ArrayList<Object> baby = new ArrayList<Object>();
                DiagnosticNode ds = new DiagnosticNode(key);
                //System.out.println("New key: " + key);
                ds.update(ls);
                baby.add(ds);
                baby.add((Object) ls);
                count++;
                width++;
                table.add(i, baby);
                keyList.add(i, key);
                return;
            }
            else if (((DiagnosticNode) cur.get(0)).identify() < key) {
                continue;
            }
            else { //a matching slot already exists
                count++;
                int placer = ls.getSortKey();

                ArrayList<Object> baby = (ArrayList<Object>) table.get(i);
                DiagnosticNode ds = diagnose(i);
                for (int j = 1; j < baby.size(); j++) {
                    LionfishSTRUCT ls2 = (LionfishSTRUCT) baby.get(j);
                    if (ls2 == null) {
                        baby.add(j, (Object) ls);
                        ds.update(ls);
                        return;
                    }
                    int key2 = ls2.getSortKey();
                    if (placer <= key2) {
                        baby.add(j, (Object) ls);
                        ds.update(ls);
                        return;
                    }
                }
                baby.add((Object) ls);
                ds.update(ls);
                return;
            }
        }
                ArrayList<Object> baby = new ArrayList<Object>();
                DiagnosticNode ds = new DiagnosticNode(key);
                //System.out.println("New key: " + key);
                ds.update(ls);
                baby.add(ds);
                baby.add((Object) ls);
                count++;
                width++;
                table.add(baby);
                return;

    //throw new OhNoException();
    }

  public DiagnosticNode diagnose(int i) {
    ArrayList<Object> x;
    try {
      x = (ArrayList<Object>) table.get(i);
    }
    catch (IndexOutOfBoundsException e) {
      return null;
    }
    if (x == null) {
      return null;
    }

    return (DiagnosticNode) x.get(0);
  }
  public int getWidth() {
    return table.size();
  }
  public void review() {
    for (int i = 0; i < table.size(); i++) {
      System.out.println(diagnose(i).toString());
    }
  }
  public void writeAll(String filename) {
    try {
      BufferedWriter buf = new BufferedWriter(new FileWriter(filename));
      for (int i = 0; i < table.size(); i++) {
        ArrayList<Object> ob = (ArrayList<Object>) table.get(i);
        for (int j = 1; j < ob.size(); j++) {
          buf.write(((LionfishSTRUCT) ob.get(j)).toString() + "\n");
        }
      }
      buf.close();
      }
      catch (IOException e) {
        e.printStackTrace();
      }
    }

/*public void binDump(String filename) {
  try {
    FileOutputStream fos = new FileOutputStream(filename);
    ObjectOutputStream oos = new ObjectOutputStream(fos);
    oos.writeObject(table);
    oos.close();
    fos.close();
  }
  catch (IOException e) {
    e.printStackTrace();
  }
} */

}
