public class DiagnosticNode {
 //This class is at the start of every chain. It allows us to avoid iteration by keeping a tally for every time we insert, making runtime significantly faster.
  public float[] tallies;
  private int dateKey;
  public DiagnosticNode(int dateKey) {
    tallies = new float[8];
    this.dateKey = dateKey;
  }

  public int identify() {
    return dateKey;
  }

  public int getCount() {
    return Math.round(tallies[7] + tallies[6]);
  }

  public void update(LionfishSTRUCT ls) {
    int sex = ls.getSex();
    tallies[sex - 2] = tallies[sex - 2] + ls.getNoodles();
    tallies[sex] = tallies[sex] + ls.getLenTail();
    tallies[sex + 2] = tallies[sex + 2] + ls.getLenTailless();
    tallies[sex + 4] = tallies[sex + 4] + 1;

  }

  public int getMales() {
    return Math.round(tallies[6]);
  }
  public int getFemales() {
    return Math.round(tallies[7]);
  }

  public String toString() { return "Node " + dateKey + " has " + getCount() + " lionfish, of total noodle " + (tallies[0] + tallies[1]) + ", total egg " + (tallies[7]) + ", and total beard " + tallies[6] + "."; }
}
