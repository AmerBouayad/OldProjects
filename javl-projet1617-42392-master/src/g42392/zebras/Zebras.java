package g42392.zebras;

import g42392.zebras.model.*;
import g42392.zebras.view.*;

/**
 * @author G42392
 *
 * Game Launcher of Funny Zebras
 */
public class Zebras {

    public static void main(String[] args) {
        Model game = new Game();
        play(game);
    }

    /**
     *
     * @param game The current game
     *
     * Launches the game given as a parameter and continues the game as long as
     * it is not finished by displaying the stock, the reserve and the score of
     * the players
     *
     * When the game is over, it displays the board and the score of the players
     * And also the winner
     */
    public static void play(Model game) {
        game.start();
        Display.boardGame(game);
        nextAction(game);
        while (!game.isOver()) {
            if (game.getStatus() == GameStatus.ANIMAL) {
                Display.stock(game);
            }
            Display.boardGame(game);
            Display.score(game);
            nextAction(game);
        }
        Display.boardGame(game);
        Display.endOfGame(game);
    }

    /**
     *
     * @param game The current game
     *
     * It chooses the next action to be performed according to the status of the
     * game given as a parameter
     */
    private static void gameStatus(Model game) {
        if (game.getStatus() == GameStatus.INIT) {
            game.setImpalaJonesFirstPosition(User.posImpala());
        } else if (game.getStatus() == GameStatus.ANIMAL) {
            game.putAnimal(User.posAnimal(game.getImpalaJones()), User.species());
        } else if ((game.getStatus() == GameStatus.IMPALA) && !game.isOver()) {
            game.moveImpalaJones(User.moveImpala(game));
        }
    }

    /**
     *
     * @param game The current game
     *
     * Does the same action as long as there are no more GameException which is
     * thrown and it displays the error message
     */
    private static void nextAction(Model game) {
        boolean isGood = false;
        while (!isGood) {
            try {
                gameStatus(game);
                isGood = true;
            } catch (GameException ex) {
                System.out.println("► ERREUR : " + ex.getMessage() + " ◄");
            }
        }
    }
}
