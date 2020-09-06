package g42392.zebras.view;

import g42392.zebras.model.*;

/**
 *
 * @author G42392
 *
 * The game display : the stock and the board of the game
 */
public class Display {

    /**
     *
     * @param game Game that is currently played who has a list of remaining
     * animals
     *
     * Displays the list of animals with the remaining number of each species
     * for the current player
     */
    public static void stock(Model game) {
        System.out.println("==========================");
        System.out.println(setColor(game.getCurrentColor()) + "Stock" + setBlack()
                + "\n" + "-----");
        for (Species species : Species.values()) {
            if (species == Species.ZEBRA) {
                System.out.print(game.getNb(species) + " Zebre");
            } else {
                System.out.print(game.getNb(species)
                        + " " + species.toString().charAt(0)
                        + species.toString().substring(1).toLowerCase());
            }
            if (game.getNb(species) > 1) {
                System.out.print("s");
            }
            System.out.println();
        }
    }

    /**
     *
     * @param game Game that is currently played
     *
     * Displays the reserve with the position of ImpalaJones around the reserve
     *
     * Displays also the color of the current player
     */
    public static void boardGame(Model game) {
        System.out.println("==========================");
        impalaUP(game.getImpalaJones());
        for (int i = 0; i < 5; i++) {
            row(game.getImpalaJones(), game.getReserve(), i);
            displaySectorColumn(game.getReserve(), i);
        }
        impalaDOWN(game.getImpalaJones());
        turnPlayerOrEnd(game);
    }

    /**
     *
     * @param game Game that is currently played by two players
     *
     * Displays the color of the player who must play his turn or an end if that
     * is the end of the game
     */
    private static void turnPlayerOrEnd(Model game) {
        System.out.println("════════════════");
        if (!game.isOver()) {
            System.out.println("Tour du joueur : " + setColor(
                    game.getCurrentColor()) + game.getCurrentColor());
        } else {
            System.out.println("           FIN");
        }
        System.out.println("════════════════");
    }

    /**
     *
     * @param game Game that is currently played by two players and they each
     * have their own score
     *
     * Displays the score of the two players in the game given as a parameter
     */
    public static void score(Model game) {
        final String colorLightGrey = "\033[37m";
        System.out.println(setBlack() + "Score du joueur : ");
        for (int i = 0; i < 2; i++) {
            System.out.print(colorLightGrey + "• " + setColor(game.getPlayers()
                    .get(i).getColor()) + game.getPlayers().get(i).getColor());
            if (game.getPlayers().get(i).getColor() == Color.RED) {
                System.out.print("  ");
            }
            System.out.println(setBlack() + " → "
                    + game.getPlayers().get(i).getScore());
        }
        System.out.println("=========================="
                + setColor(game.getCurrentColor()));
    }

    /**
     *
     * @param game Game that is currently played by two players and they each
     * have their own score
     *
     * Displays the score of the two players in the game given as a parameter
     *
     * And it displays the winner of the game if there is one otherwise it
     * displays that there is no winner
     */
    public static void endOfGame(Model game) {
        score(game);
        int scoreJ1 = game.getPlayers().get(0).getScore();
        int scoreJ2 = game.getPlayers().get(1).getScore();
        Color colorJ1 = game.getPlayers().get(0).getColor();
        Color colorJ2 = game.getPlayers().get(1).getColor();
        if (scoreJ1 == scoreJ2) {
            System.out.println(setBlack() + "Il n'y a pas de gagnant !");
        } else {
            System.out.print(setBlack() + "Le gagnant est : ");
            if (scoreJ1 > scoreJ2) {
                System.out.println(setColor(colorJ1) + colorJ1);
            } else {
                System.out.println(setColor(colorJ2) + colorJ2);
            }
        }
        System.out.println("==========================");
    }

    /**
     * @param impala The current ImpalaJones
     *
     * The top display of the game with ImpalaJones if his position is above the
     * reserve
     */
    private static void impalaUP(ImpalaJones impala) {
        System.out.println("      1  2  3  4  5  6");
        System.out.print("      ");
        for (int i = 0; i < 6; i++) {
            impala(impala, i);
            System.out.print("  ");
        }
        System.out.println("\n    ====================");

    }

    /**
     *
     * @param impala current ImpalaJones
     * @param reserve Reserve of animal
     * @param i Line number
     *
     * Displays the row i of the reserve and ImpalaJones on the left/right side
     * if it's the case otherwise it displays a dot
     */
    private static void row(ImpalaJones impala, Reserve reserve, int i) {
        System.out.print(setBlack() + (i + 1) + " ");
        impala(impala, 21 - i);
        System.out.print("|  ");
        for (int j = 0; j < 6; j++) {
            Coordinates pos = new Coordinates(i, j);
            displayAnimal(reserve, pos);
            displaySectorRow(reserve, pos);
        }
        System.out.print(setBlack() + "  |");
        impala(impala, i + 6);
        System.out.println();
    }

    /**
     *
     * @param reserve Reserve that can contains animals
     * @param pos Coordinates of the animal
     *
     * It displays a position on the reserve, there are 3 possibilities :
     * empty("•")/afraid animal("#")/animal(the first char of his species)
     *
     * If the position of this reserve is not empty the animal will be shown
     * with the color of the current player
     */
    private static void displayAnimal(Reserve reserve, Coordinates pos) {
        if (reserve.isFree(pos)) {
            System.out.print(setBlack() + "•");
        } else if (reserve.getAnimal(pos).getState() == AnimalState.HIDDEN) {
            System.out.print(setColor(reserve.getAnimal(pos).getColor()) + "#");
        } else {
            System.out.print(setColor(reserve.getAnimal(pos).getColor())
                    + reserve.getAnimal(pos).getSpecies().toString().charAt(0));
        }
    }

    /**
     *
     * @param reserve Reserve of animal
     * @param pos The current position
     *
     * It displays two spaces with a blue background between 2 positions if the
     * current position and the one at its right have a different sector number
     * otherwise it just displays two spaces with a white background
     */
    private static void displaySectorRow(Reserve reserve, Coordinates pos) {
        if (pos.getColumn() < 5) {
            Coordinates ajdPos = new Coordinates(pos.getRow(), pos.getColumn() + 1);
            if (reserve.getSector(pos).getNumber()
                    != reserve.getSector(ajdPos).getNumber()) {
                System.out.print(setBlue() + "  ");
            } else {
                System.out.print("  ");
            }
        }
    }

    /**
     *
     * @param reserve Reserve of animal
     * @param i Line number
     *
     *
     * If the current position and the position below this position have a
     * different sector number, it displays three spaces with a blue background
     * between the 2 positions
     *
     * Else if they are equal and the line number entered as a parameter is less
     * than 5, it displays a space with a with background followed by two spaces
     * with a blue background
     *
     * Otherwise it just displays three spaces with a white background
     */
    private static void displaySectorColumn(Reserve reserve, int i) {
        if (i < 4) {
            displayHeader(i);
            for (int j = 0; j < 6; j++) {
                Coordinates pos = new Coordinates(i, j);
                Coordinates ajdPos = new Coordinates(i + 1, j);
                if (reserve.getSector(pos).getNumber()
                        != reserve.getSector(ajdPos).getNumber()) {
                    System.out.print(setBlue() + "   " + setBlack());
                } else if (j < 5) {
                    System.out.print(" " + setBlue() + "  " + setBlack());
                } else {
                    System.out.print("   ");
                }
            }
            System.out.println("|");
        }
    }

    /**
     *
     * @param i Line number
     *
     *
     * If the line number is equal to 2 the bar will be followed by two spaces
     * with a blue background otherwise it is a basic display with a white
     * background
     *
     * This method shortens another
     */
    private static void displayHeader(int i) {
        if (i == 2) {
            System.out.print("   |" + setBlue() + "  ");
        } else {
            System.out.print("   |  ");
        }
    }

    /**
     *
     * @param impala The current ImpalaJones
     *
     * The bottom display of the game with ImpalaJones if his position is below
     * the reserve
     */
    private static void impalaDOWN(ImpalaJones impala) {
        System.out.print("    ==================== \n      ");
        for (int i = 16; i > 10; i--) {
            impala(impala, i);
            System.out.print("  ");
        }
        System.out.println();
    }

    /**
     *
     * @param impala ImpalJones
     * @param pos Position of ImpalaJones
     *
     * If ImpalaJones is at the position indicated in parameter then it displays
     * "I" otherwise it displays "."
     */
    private static void impala(ImpalaJones impala, int pos) {
        if (impala.getPosition() == pos) {
            System.out.print("I");
        } else {
            System.out.print(".");
        }
    }

    /**
     *
     * @param color Color of the current player
     * @return Color code of the current player, for the foreground and the
     * color code of the background white
     *
     */
    private static String setColor(Color color) {
        String temp = null;
        if (color.equals(Color.RED)) {
            temp = "\033[31m";
        }
        if (color.equals(Color.GREEN)) {
            temp = "\033[32m";
        }
        return temp + "\033[40m";
    }

    /**
     *
     * @return Color code of black, for the foreground and the color code of the
     * background white
     */
    private static String setBlack() {
        return "\033[30m" + "\033[40m";
    }

    /**
     *
     * @return Color code of the background blue
     */
    private static String setBlue() {
        return "\033[46m";
    }
}
