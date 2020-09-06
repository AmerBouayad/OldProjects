package g42392.zebras.model;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author G42392
 *
 * A sector is recognized by a number and lies on several positions, there are 6
 * sectors in the reserve
 */
public class Sector {

    private final int number;
    private final List<Coordinates> coordinates;
    private final Reserve reserve;

    /**
     *
     * @param reserve A sector is on a reserve
     * @param number A sector is recognized using a number
     * @param coordinates A sector is on several positions
     *
     * A sector has number and lies on several positions
     *
     */
    public Sector(Reserve reserve, int number, Coordinates... coordinates) {
        this.number = number;
        this.coordinates = new ArrayList<>();
        this.coordinates.addAll(Arrays.asList(coordinates));
        this.reserve = reserve;
    }

    /**
     *
     * @return The number of the current sector
     */
    public int getNumber() {
        return number;
    }

    /**
     *
     * @param position
     * @return true if the position given as a parameter is located in the
     * current sector
     */
    public boolean contains(Coordinates position) {
        return this.coordinates.contains(position);
    }

    /**
     *
     * @return true if all the positions of a sector are full
     */
    public boolean isFull() {
        boolean full = true;
        int i = 0;
        while (full && i < this.coordinates.size()) {
            full = !this.reserve.isFree(this.coordinates.get(i));
            i++;
        }
        return full;
    }

    /**
     *
     * @param color Color of a player
     * @return true if the color given as a parameter, is the majority in the
     * current sector, if the color given as a parameter is greater than the
     * entire division by 2 of the sector
     *
     */
    public boolean hasMajority(Color color) {
        int counter = 0;
        int sizeSectorDIV2 = this.coordinates.size() / 2;
        for (Coordinates coord : this.coordinates) {
            if (!this.reserve.isFree(coord)) {
                if (this.reserve.getAnimal(coord).getColor() == color) {
                    counter++;
                }
            }
        }
        return counter > sizeSectorDIV2;
    }

    /**
     *
     * @return The score of the current sector
     */
    public int getScore() {
        int score = 0;
        for (Coordinates coord : this.coordinates) {
            if (!this.reserve.isFree(coord)) {
                score = score + this.reserve.getAnimal(coord).getValue();
            }
        }
        return score;
    }
}
