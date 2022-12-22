import java.lang.Math;
public class lionfishSTRUCT {
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

    public lionfishSTRUCT(String s) {
        String[] fields = s.split(",");
        String[] dates = fields[0].split("/");

        this.month = parseInt(dates[0]);
        this.day = parseInt(dates[1]);
        this.year = parseInt(dates[2]);
        this.conf = parseFloat(fields[1]);
        this.len_tail = parseFloat(fields[2]);
        this.len_tailless = parseFloat(fields[3]);
        this.noodles = parseInt(fields[4]);
        this.beard = parseInt(fields[5]);
        this.sex = parseInt(fields[6]);
        this.eggs = parseInt(fields[7]);
        this.stomach = fields[8];

    }
    public String toString () {
        return month + "/" + day + "/" + year + "," + conf + "," + len_tail + "," + len_tailless + "," + noodles + "," + beard + ","
                + sex + "," + eggs + "," + stomach;
    }
    public int getHashDate() {
        return (10000 * (year - 2000)) + (100 * month) + day; //i.e. 03/12/2022 = 220312
    }

    public int getSortKey() {
        return Math.round((100 * len_tail) + len_tailless);
    }

}
