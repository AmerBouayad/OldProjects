package g42392.zebras.model;

import java.util.ArrayList;
import java.util.List;

/**
 * @author G42392
 *
 * A reserve is a board of 5x6 boxes which each box can be empty or can get a
 * pawn inside and there are 6 sectors in this reserve
 */
public class Reserve {

    private final Animal animals[][];
    private final List<Sector> sectors;

    /**
     * The reserve is initialized as an array of 5x6 boxes and has 6 sectors
     */
    public Reserve() {
        this.animals = new Animal[5][6];
        this.sectors = new ArrayList<>();
        this.sectors.add(new Sector(this, 1, pos(0, 0), pos(1, 0), pos(2, 0),
                pos(2, 1), pos(3, 1)));
        this.sectors.add(new Sector(this, 2, pos(0, 1), pos(1, 1), pos(1, 2),
                pos(2, 2), pos(3, 2), pos(3, 3), pos(3, 4)));
        this.sectors.add(new Sector(this, 3, pos(0, 2), pos(0, 3), pos(0, 4),
                pos(0, 5), pos(1, 3), pos(2, 3), pos(2, 4)));
        this.sectors.add(new Sector(this, 4, pos(1, 4), pos(1, 5), pos(2, 5)));
        this.sectors.add(new Sector(this, 5, pos(3, 0), pos(4, 0), pos(4, 1)));
        this.sectors.add(new Sector(this, 6, pos(4, 2), pos(4, 3), pos(4, 4),
                pos(4, 5), pos(3, 5)));
    }

    /**
     *
     * @param x The row of the new Coordinates
     * @param y The column of the new Coordinates
     * @return The new Coordinates
     *
     * It makes the creation of a coordinates shorter
     */
    private Coordinates pos(int x, int y) {
        Coordinates pos = new Coordinates(x, y);
        return pos;
    }

    /**
     * @param pos which contains a row and a column
     * @return true if the position is empty
     */
    public boolean isFree(Coordinates pos) {
        return animals[pos.getRow()][pos.getColumn()] == null;
    }

    /**
     * @param animal which contains a color and a species/type
     * @param pos which contains a row and a column
     */
    public void put(Animal animal, Coordinates pos) {
        animals[pos.getRow()][pos.getColumn()] = animal;
    }

    /**
     * @param pos which contains a row and a column
     * @return the animal in a position given in parameter
     */
    public Animal getAnimal(Coordinates pos) {
        return animals[pos.getRow()][pos.getColumn()];
    }

    /**
     *
     * @param pos Access to the desired row with pos
     * @return true if the row at the position pos has at least a free box
     */
    public boolean freeRow(int pos) {
        boolean isFree = false;
        int i = 0;
        while (i < animals[pos].length && !isFree) {
            isFree = animals[pos][i] == null;
            i++;
        }
        return isFree;
    }

    /**
     *
     * @param pos Access to the desired column with pos
     * @return true if the column at the position pos has at least a free box
     */
    public boolean freeColumn(int pos) {
        boolean isFree = false;
        int i = 0;
        while (i < animals.length && !isFree) {
            isFree = animals[i][pos] == null;
            i++;
        }
        return isFree;
    }

    /**
     *
     * @param position Current position
     * @return the list of positions adjacent included in the reserve to the
     * position given as a parameter
     */
    public List<Coordinates> getAdjacents(Coordinates position) {
        List<Coordinates> adjacentsBoxes = new ArrayList<>();
        int x = position.getRow();
        int y = position.getColumn();
        adjacentsBoxes.addAll(getAdjacentsRow(x, y));
        adjacentsBoxes.addAll(getAdjacentsColumn(x, y));
        return adjacentsBoxes;
    }

    /**
     *
     * @param x Row of the position
     * @param y Column of the position
     * @return the list of positions adjacent to the given position (x,y) as a
     * parameter but the column doesn't change
     */
    private List<Coordinates> getAdjacentsRow(int x, int y) {
        List<Coordinates> adjacentsBoxes = new ArrayList<>();
        switch (x) {
            case 0:
                adjacentsBoxes.add(new Coordinates(x + 1, y));
                break;
            case 4:
                adjacentsBoxes.add(new Coordinates(x - 1, y));
                break;
            default:
                adjacentsBoxes.add(new Coordinates(x - 1, y));
                adjacentsBoxes.add(new Coordinates(x + 1, y));
        }
        return adjacentsBoxes;
    }

    /**
     *
     * @param x Row of the position
     * @param y Column of the position
     * @return the list of positions adjacent to the given position (x,y) as a
     * parameter but the row doesn't change
     */
    private List<Coordinates> getAdjacentsColumn(int x, int y) {
        List<Coordinates> adjacentsBoxes = new ArrayList<>();
        switch (y) {
            case 0:
                adjacentsBoxes.add(new Coordinates(x, y + 1));
                break;
            case 5:
                adjacentsBoxes.add(new Coordinates(x, y - 1));
                break;
            default:
                adjacentsBoxes.add(new Coordinates(x, y - 1));
                adjacentsBoxes.add(new Coordinates(x, y + 1));
        }
        return adjacentsBoxes;
    }

    /**
     *
     * @param pos A position in the reserve
     *
     * Deletes the animal in the position given as a parameter
     *
     * @return The animal in the given position that has been remove from the
     * reserve
     */
    public Animal remove(Coordinates pos) {
        Animal animal = this.animals[pos.getRow()][pos.getColumn()];
        this.animals[pos.getRow()][pos.getColumn()] = null;
        return animal;
    }

    /**
     *
     * @param coord Coordinates in the reserve
     * @return The sector that contains the coordinates given as a parameter
     */
    public Sector getSector(Coordinates coord) {
        Sector sector = null;
        for (int i = 0; i < this.sectors.size(); i++) {
            if (this.sectors.get(i).contains(coord)) {
                sector = this.sectors.get(i);
                break;
            }
        }
        return sector;
    }

    /**
     *
     * @param color Color of the a player
     * @return A player's score
     *
     * Checks if a sector is filled and if the color given as a parameter is in
     * the majority then we add the score of this sector for this color
     */
    public int getScore(Color color) {
        int score = 0;
        for (Sector sector : this.sectors) {
            if (sector.isFull() && sector.hasMajority(color)) {
                score = score + sector.getScore();
            }
        }
        return score;
    }
}
