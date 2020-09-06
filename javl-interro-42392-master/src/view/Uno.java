package view;

import model.*;
import model.UnoException;

/**
 *
 * @author G42392
 */
public class Uno {
    public static void main(String[] args) throws UnoException {
        Game game = new Game();
        while(!game.isOver()){
            displayVisibleCard(game.getVisibleCard());
        }
    }
    
    /**
     * 
     * @param card 
     * 
     * It displays the card given as a parameter with the color followed by the 
     * value
     */
    public static void displayVisibleCard(Card card){
        System.out.println(card.getColor()+ " "+ card.getValue());
    }
   
}
