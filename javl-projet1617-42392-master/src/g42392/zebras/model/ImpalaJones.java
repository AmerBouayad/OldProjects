package g42392.zebras.model;

/**
 * @author G42392
 *
 * Impala Jones is a pawn that moves around the reserve and checks where the
 * player can play
 */
public class ImpalaJones {

    private int position;

    /**
     * The position of Impala Jones is initialized at -1
     */
    public ImpalaJones() {
        this.position = -1;
    }

    /**
     *
     * @return the current position of Impala Jones
     */
    public int getPosition() {
        return position;
    }

    /**
     *
     * @param nb = new position of Impala Jones
     *
     * the current position of ImpalaJones'll be at nb
     */
    public void init(int nb) {
        this.position = nb;
    }

    /**
     *
     * @param distance
     *
     * Adds the distance at the current position of Impala Jones
     */
    public void move(int distance) {
        this.position = (this.getPosition() + distance) % 22;
    }

    /**
     *
     * @return true if Impala Jones is above the reserve
     */
    public boolean isUp() {
        return this.position >= 0 && this.position <= 5;
    }

    /**
     *
     * @return true if Impala is below the reserve
     */
    public boolean isDown() {
        return this.position >= 11 && this.position <= 16;
    }

    /**
     *
     * @return true if Impala is to the left of the reserve
     */
    public boolean isLeft() {
        return this.position >= 17 && this.position <= 21;
    }

    /**
     *
     * @return true if Impala is to the right of the reserve
     */
    public boolean isRight() {
        return this.position >= 6 && this.position <= 10;
    }

    /**
     *
     * @return the column at the current position of Impala Jones
     */
    public int getColumn() {
        int pos = -1;
        if (this.isUp()) {
            pos = this.getPosition();
        }
        if (this.isDown()) {
            pos = 5 - (this.getPosition() - 11);
        }
        return pos;
    }

    /**
     *
     * @return the row at the current position of Impala Jones
     */
    public int getRow() {
        int pos = -1;
        if (this.isLeft()) {
            pos = 5 - (this.getPosition() - 16);
        }
        if (this.isRight()) {
            pos = this.getPosition() - 6;
        }
        return pos;
    }

    /**
     *
     * @param reserve
     * @param distance
     * @return true if there is at least one empty box in front of Impala Jones
     */
    public boolean checkMove(Reserve reserve, int distance) {
        int temp = this.position;
        this.move(distance);
        boolean hasMoved = false;
        if (this.isLeft() || this.isRight()) {
            hasMoved = reserve.freeRow(this.getRow());
        }
        if (this.isUp() || this.isDown()) {
            hasMoved = reserve.freeColumn(this.getColumn());
        }
        this.position = temp;
        return hasMoved;
    }

    /**
     *
     * @param pos
     * @return true if the row/column matches with the position of Impala Jones
     */
    public boolean valid(Coordinates pos) {
        return this.getRow() == pos.getRow() || this.getColumn() == pos.getColumn();
    }

    /**
     *
     * @param reserve
     * @return the smallest displacement to find an empty box in front of Impala
     * Jones but if there is no empty box, the method returns -1
     */
    public int findFirst(Reserve reserve) {
        int cpt = 1;
        while (!this.checkMove(reserve, cpt)) {
            cpt++;
            if (cpt == 23) {
                cpt = -1;
                break;
            }
        }
        return cpt;
    }
}
