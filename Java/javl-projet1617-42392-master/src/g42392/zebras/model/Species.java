package g42392.zebras.model;

/**
 * @author G42392
 *
 * A constant that gives the species/type of a pawn and his value
 */
public enum Species {
    GAZELLE(2), ZEBRA(6), LION(1), ELEPHANT(5), CROCODILE(0);

    private final int value;

    /**
     *
     * @param value Value of a species
     *
     * A species has a value
     */
    private Species(int value) {
        this.value = value;
    }

    /**
     *
     * @return the value of a species
     */
    public int getValue() {
        return this.value;
    }
}
