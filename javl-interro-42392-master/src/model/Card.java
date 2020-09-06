package model;

/**
 *
 * @author G42392
 *
 * A card has a value and a color
 */
public class Card {

    private final Color color;
    private final int value;

    /**
     *
     * @param color Color of the current card is initialized at the color given
     * as a parameter
     * @param value Integer given as a parameter which initializes the value of
     * a card
     * 
     * @throws UnoException if the value isn't between 0 and 9
     */
    public Card(Color color, int value) throws UnoException{
        if (value < 0 || value > 9 ) {
            throw new UnoException("Valeur non comprise entre 0 et 9 !");
        }
        this.color = color;
        this.value = value;
    }

    /**
     *
     * @return The color of the current card
     */
    public Color getColor() {
        return this.color;
    }

    /**
     *
     * @return The value of the current card
     */
    public int getValue() {
        return this.value;
    }

    /**
     *
     * @param color Color
     * @return true if the color given as a parameter equals the color of the
     * current card
     */
    public boolean sameColor(Color color) {
        return this.getColor() == color;
    }

    /**
     *
     * @param value Integer which is equivalent to the value of a card
     * @return true if the value given as a parameter equals the value of the
     * current card
     */
    public boolean sameValue(int value) {
        return this.getValue() == value;
    }
}
