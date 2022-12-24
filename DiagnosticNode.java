public class DiagnosticNode {
 //This class is at the start of every chain. It allows us to avoid iteration bu keeping a tally for every time we insert, making runtime significantly faster.
  private int dateKey;
  private int males;
  private int females;
  public int[] tallies;
  public float MtailTally;
  public float MtaillessTally;
  public int MNoodles;
  public int FNoodles;
  public float FtailTally;
  public float FtaillessTally;//more fields coming soon

  public DiagnosticNode(int dateKey) {
    tallies = new int[3];
    MtailTally = 0;
    MtaillessTally = 0;
    FtailTally = 0;
    FtaillessTally = 0;
    MNoodles = 0;
    FNoodles = 0;

    this.dateKey = dateKey;
    males = 0;
    females = 0;
  }

  public int identify() {
    return dateKey;
  }

  public int getCount() {
    return males + females;
  }

  public void update(LionfishSTRUCT ls) {
    tallies[0] = tallies[0] + ls.getNoodles();
    tallies[1] = tallies[1] + ls.getEggs();
    tallies[2] = tallies[2] + ls.getBeard();
    if (ls.getSex() == 2) {
      MtailTally = MtailTally + ls.getLenTail();
      MtaillessTally = MtaillessTally + ls.getLenTailless();
      males++;
    }
    else {
      FtailTally = FtailTally + ls.getLenTail();
      FtaillessTally = FtaillessTally + ls.getLenTailless();
      females++;
    }

  }
  public String toString() { return "Node " + dateKey + " has " + (males + females) + " lionfish, of total noodle " + tallies[0] + ", total egg " + tallies[1] + ", and total beard " + tallies[2] + "."; }
}
