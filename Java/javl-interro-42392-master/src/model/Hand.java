package model;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author G42392
 *
 * The hand of a player is composed by some cards
 */
public class Hand {

    private final List<Card> cards;

    /**
     * At the beginning, there is no cards in the hand of a players
     */
    public Hand() {
        this.cards = new ArrayList<>();
    }

    /**
     *
     * @return true if the current player's hand is empty
     */
    public boolean isEmpty() {
        return this.cards.isEmpty();
    }

    /**
     *
     * @return The size of the current player's card list
     */
    public int size() {
        return this.cards.size();
    }

    /**
     *
     * @param card Card that has a value and color
     *
     * Adds a card in the current player's card list
     */
    public void addCard(Card card) {
        this.cards.add(card);
    }

    /**
     *
     * @param pos Integer that gives the position of a card in the list
     * @return the card that can be found at the given position
     */
    public Card seeCard(int pos) {
        return this.cards.get(pos);
    }

    /**
     *
     * @param pos Integer that gives the position of a card in the list
     * @return the card that can be found at the given position and removes it
     * from the card list of the current player
     */
    public Card removeCard(int pos) {
        Card card = this.cards.get(pos);
        this.cards.remove(pos);
        return card;
    }

}
