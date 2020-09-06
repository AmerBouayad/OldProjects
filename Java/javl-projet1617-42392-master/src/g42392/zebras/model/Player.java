package g42392.zebras.model;

/**
 *
 * @author G42392
 *
 * A player is represented by a color and has a score
 */
public class Player {

    private final Color color;
    private int score;

    /**
     *
     * @param color a player has a color, RED or GREEN
     *
     * And the score of this player is initialized at 0
     */
    public Player(Color color) {
        this.color = color;
        this.score = 0;
    }

    /**
     *
     * @return the color of the current player
     */
    public Color getColor() {
        return color;
    }

    /**
     *
     * @return The score of the current player
     */
    public int getScore() {
        return this.score;
    }

    /**
     *
     * @param score Score of the currentPlayer
     *
     * It changes the score of the current player with the given value in
     * parameter
     */
    public void setScore(int score) {
        this.score = score;
    }
}
