public class DiagnosticNode {
 //This class is at the start of every chain. It allows us to avoid iteration bu keeping a tally for every time we insert, making runtime significantly faster.
  private int dateKey;
  private int count;
  public int[] tallies;
  //more fields coming soon
  public DiagnosticNode(int dateKey) {
    tallies = new int[3];
    this.dateKey = dateKey;
    count = 0;
  }

  public int identify() {
    return dateKey;
  }

  public int getCount() {
    return count;
  }

  public void update(LionfishSTRUCT ls) {
    tallies[0] = tallies[0] + ls.getNoodles();
    tallies[1] = tallies[1] + ls.getEggs();
    tallies[2] = tallies[2] + ls.getBeard();
    count++;
  }

}
