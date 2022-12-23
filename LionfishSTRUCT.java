import java.lang.Math;
public class LionfishSTRUCT {
    private int day;
    private int month;
    private int year;
    private float conf;
    private float len_tail;
    private float len_tailless;
    private int noodles;
    private int beard;
    private int sex;
    private int eggs;
    private int juv;
    private String stomach;

    public LionfishSTRUCT(String s) throws OhNoException {
        String[] fields = s.split(",");
        if (fields.length != 9) {
          throw new OhNoException();
        }
        String[] dates = fields[0].split("/");

        this.month = Integer.parseInt(dates[0]);
        this.day = Integer.parseInt(dates[1]);
        this.year = Integer.parseInt(dates[2]);
        this.conf = Float.parseFloat(fields[1]);
        this.len_tail = Float.parseFloat(fields[2]);
        this.len_tailless = Float.parseFloat(fields[3]);
        this.noodles = Integer.parseInt(fields[4]);
        this.beard = Integer.parseInt(fields[5]);
        this.sex = Integer.parseInt(fields[6]);
        this.eggs = Integer.parseInt(fields[7]);
        this.stomach = fields[8];

    }
    public String toString () {
        return month + "/" + day + "/" + year + "," + conf + "," + len_tail + "," + len_tailless + "," + noodles + "," + beard + ","
                + sex + "," + eggs + "," + stomach;
    }
    public int getHashDate() {
        return (10000 * (year)) + (100 * month) + day; //i.e. 03/12/2022 = 220312
    }

    public int getSortKey() {
        return Math.round((100 * len_tail) + len_tailless);
    }
    public int getNoodles() {
      return noodles;
    }
    public int getSex() {
      return sex;
    }
    public int getBeard() {
      return beard;
    }
    public int getEggs() {
      return eggs;
    }
    public float getTotal() {
      return len_tail;
    }
    public float getTailless() {
      return len_tailless;
    }
    public String getStomach() {
      return stomach;
    }
    public float getConf() {
      return conf;
    }
    public int getDay() {
      return day;
    }
    public int getMonth() {
      return month;
    }
    public int getYear() {
      return year;
    }
}
