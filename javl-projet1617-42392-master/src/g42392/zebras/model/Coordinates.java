package g42392.zebras.model;

/**
 * @author G42392
 *
 * The coordinates represent a position/box in the Reserve, there are 5x6 boxes
 */
public class Coordinates {

    private final int row;
    private final int column;

    /**
     * @param Row
     * @param Column
     *
     * The object Coordinates represents a box/position in the Reserve
     */
    public Coordinates(int Row, int Column) {
        this.row = Row;
        this.column = Column;
    }

    /**
     * Get the value of Column
     *
     * @return the value of Column
     */
    public int getColumn() {
        return column;
    }

    /**
     * Get the value of Row
     *
     * @return the value of Row
     */
    public int getRow() {
        return row;
    }

    /**
     * @return the hashCode of a coordinate
     */
    @Override
    public int hashCode() {
        int hash = 3;
        hash = 41 * hash + this.row;
        hash = 41 * hash + this.column;
        return hash;
    }

    /**
     *
     * @param obj
     * @return true if 2 coordinates are equal
     */
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Coordinates other = (Coordinates) obj;
        if (this.row != other.row) {
            return false;
        }
        if (this.column != other.column) {
            return false;
        }
        return true;
    }
}
