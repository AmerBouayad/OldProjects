package g42392.zebras.view;

import g42392.zebras.model.*;
import java.util.Scanner;

/**
 *
 * @author G42392
 *
 * Interactions with the user
 */
public class User {

    private static final Scanner keyboard = new Scanner(System.in);
    private static final String MSG_INIT = "Veuillez entrer la position de "
            + "départ d'Impala Jones (de 0 à 21) : ";
    private static final String MSG_IMPALA = "Veuillez entrer la distance "
            + "qu'Impala Jones doit parcourir (de 1 à 3) : ";
    private static final String MSG_ERROR = "► ERREUR : Ceci n'est pas un "
            + "entier ! ◄";

    /**
     *
     * @return An integer
     *
     * It requests to enter a value until it's an integer and it displays an
     * error message followed by the given message as a parameter
     *
     */
    public static int posImpala() {
        return value(MSG_INIT);
    }

    /**
     *
     * @param game Game that is currently played that contains a reserve and
     * ImpalaJones who moves around this reserve
     *
     * @return An integer
     *
     * It requests to enter a value until it's an integer if the ImpalaJones
     * finds an empty box for a displacement of up to 3 positions otherwise it
     * returns 0 without asking the user for the move because it is done
     * automatically
     *
     */
    public static int moveImpala(Model game) {
        int pos = 0;
        if (game.getImpalaJones().findFirst(game.getReserve()) <= 3) {
            pos = value(MSG_IMPALA);
        }
        return pos;
    }

    /**
     *
     * @param impala ImpalaJones of the reserve
     * @return The coordinates of a position included in the reserve
     *
     * The user just enters the row if ImpalaJones is above or below the reserve
     * and the column is the position of ImpalaJones
     *
     * Otherwise the user just enters the column because the row will be the
     * position of ImpalaJones
     *
     * It requests to enter a position until it does not exceed the reserve
     */
    public static Coordinates posAnimal(ImpalaJones impala) {
        boolean isGood = false;
        Coordinates pos = null;
        int x = -1;
        int y = -1;
        while (isGood == false) {
            if (impala.isUp() || impala.isDown()) {
                x = value("Veuillez entrer la ligne : ");
                y = impala.getColumn() + 1;
            } else if (impala.isLeft() || impala.isRight()) {
                x = impala.getRow() + 1;
                y = value("Veuillez entrer la colonne : ");
            }
            pos = new Coordinates(x - 1, y - 1);
            isGood = (x >= 1 && x <= 5) && (y >= 1 && y <= 6);
            if (!isGood) {
                System.out.println("► ERREUR : Position non comprise dans la"
                        + " réserve ! ◄");
            }
        }
        return pos;
    }

    /**
     *
     * @param msg The string msg is displayed
     *
     * @return An integer
     *
     * It requests to enter a value until it's an integer and it displays an
     * error message followed by the given message as a parameter
     */
    private static int value(String msg) {
        System.out.print(msg);
        while (!keyboard.hasNextInt()) {
            System.out.println(MSG_ERROR);
            System.out.print(msg);
            keyboard.next();
        }
        return keyboard.nextInt();
    }

    /**
     *
     * @return the species of type Species that the user entered in string
     *
     * Transforms a Species into a string and checks the equality with the
     * string, just the first character that the user entered
     */
    public static Species species() {
        Species beast = null;
        boolean found = false;
        while (found == false) {
            System.out.print("Veuillez entrer l'espèce de l'animal : ");
            String catAnimal = keyboard.next();
            for (Species species : Species.values()) {
                if (species.toString().charAt(0) == catAnimal.toUpperCase().charAt(0)) {
                    beast = species;
                    found = true;
                }
            }
            if (!found) {
                System.out.println("► ERREUR : Cette espèce n'existe pas ! ◄");
            }
        }
        return beast;
    }
}
