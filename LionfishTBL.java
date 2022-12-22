import java.util.ArrayList;
public class LionfishTBL {
    private int count; //the number of fish in the table
    private int width; //the number of chains in this table
    private ArrayList<Object> table;
    public LionfishTBL(String filename) {
        //build hash based on file characteristics
    }
    public void insert(Object o) { //using all bits of the date a fish was caught, insert it into the table
        LionfishSTRUCT ls = (LionfishSTRUCT) o;
        int key = ls.getHashDate();
        for (int i = 0; i < table.size(); i++) {
            ArrayList<Object> cur = table.get(i);
            if (cur == null || (int)(cur.get(0)) > key) {
                ArrayList<Object> baby = new ArrayList<Object>();
                baby.add((Object) key);
                baby.add((Object) ls);
                count++;
                width++;
                table.add(i, baby);
                return;
            }
            else if ((int)cur.get(0) < key) {
                continue;
            }
            else { //a matching slot already exists
                int placer = ls.getSortKey();
                ArrayList<Object> baby = (ArrayList<Object>) table.get(i);
                for (int j = 1; j < baby.size(); j++) {
                    LionfishSTRUCT ls2 = (LionfishSTRUCT) baby.get(j);
                    if (ls2 == null) {
                        baby.add(j, (Object) ls);
                        return;
                    }
                    int key2 = ls2.getSortKey();
                    if (placer <= key2 || ) {
                        baby.add(j, (Object) ls);
                        return;
                    }
                }
                baby.add((Object) ls);
                return;
            }
        }
    throw new OhNoException();
    }



}
