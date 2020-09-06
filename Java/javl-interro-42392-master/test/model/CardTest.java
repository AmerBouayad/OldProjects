package model;

import org.junit.Test;

/**
 *
 * @author G42392
 */
public class CardTest {

    /**
     * @exception UnoException when the value isn't between 0 and 9
     */
    @Test(expected = UnoException.class)
    public void testGetColorError_1() throws UnoException {
        Card cardError = new Card(Color.BLUE, 10);
    }

    /**
     * @exception UnoException when the value isn't between 0 and 9
     */
    @Test(expected = UnoException.class)
    public void testGetColorError_2() throws UnoException {
        Card cardError = new Card(Color.BLUE, -1);
    }
    
    /**
     * Valid creation of a card
     */
    @Test
    public void testGetColor() throws UnoException {
        Card card = new Card(Color.BLUE, 0);
    }
    

}
