package model;

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

/**
 *
 * @author G42392
 *
 * A game has a deck that is a list of cards, 4 players, a visible card and a
 * current player
 */
public class Game {

    private final List<Card> deck;
    private final Hand players[][];
    private int currentPlayer;
    private Card visibleCard;

    /**
     *
     * Initialization of a game you must complete the deck and mix it
     *
     * Assigns the cards to the players, choose the first player
     *
     * @throws UnoException if the value of a card isn't between 0 and 9
     */
    public Game() throws UnoException {
        this.currentPlayer = 0;
        this.deck = new ArrayList<>();
        for (Color color : Color.values()) {
            for (int i = 0; i < 10; i++) {
                this.deck.add(new Card(color, i));
            }
        }
        Collections.shuffle(this.deck);
        this.visibleCard = this.deck.get(0);
        this.deck.remove(0);
        this.players = new Hand[4][7];
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 8; j++) {
                this.players[i][j].removeCard(j);
            }
        }
    }

    /**
     *
     * @return the list of players, hands
     */
    public Hand[][] getPlayers() {
        return players;
    }

    /**
     *
     * @return The current player
     */
    public int getCurrentPlayer() {
        return currentPlayer;
    }

    /**
     *
     * @return The visible card
     */
    public Card getVisibleCard() {
        return visibleCard;
    }

    /**
     *
     * @param card Puts this card face up
     */
    public void setVisibleCard(Card card) {
        this.visibleCard = card;
    }

    /**
     *
     * @return The first card of the deck by removing it from the deck
     * @throws UnoException if the deck is empty
     */
    public Card getCard() throws UnoException {
        if (this.deck.isEmpty()) {
            throw new UnoException("Le deck est vide !");
        }
        Card card = this.deck.get(0);
        this.deck.remove(0);
        return card;
    }

    /**
     * Changes the current player to the next player
     */
    public void nextPlayer() {
        this.currentPlayer = (this.currentPlayer + 1) % 4;
    }

    /**
     * 
     * @return true if the game is over
     */
    public boolean isOver() {
        boolean isEmpty = true;
        while (isEmpty) {
            for (int i = 0; i < this.players.length; i++) {
                int j = 0;
                while (isEmpty || j < this.players[i].length) {
                    isEmpty = this.players[i][j] == null;
                    j++;
                }
            }

        }
        return (this.deck.isEmpty() || isEmpty);
    }
}
