package g42392.zebras.model;

import static g42392.zebras.model.Color.GREEN;
import static g42392.zebras.model.Species.GAZELLE;
import static g42392.zebras.model.Species.LION;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author G42392
 *
 * Tests of the different methods of the class Pieces
 */
public class PiecesTest {

    Pieces pieces = new Pieces();

    @Test
    public void testGetAnimal() {
        Animal expResult = new Animal(GREEN, LION);
        Animal result = pieces.getAnimal(GREEN, LION);
        assertEquals(expResult, result);
    }

    @Test
    public void testGetAnimalEmptyList() {
        pieces.emptyList();
        Animal expResult = null;
        Animal result = pieces.getAnimal(GREEN, LION);
        assertEquals(expResult, result);
    }

    @Test
    public void testHasAvailableTrue() {
        boolean expResult = true;
        boolean result = pieces.hasAvailable();
        assertEquals(expResult, result);
    }

    @Test
    public void testHasAvailableFalse() {
        pieces.emptyList();
        boolean expResult = false;
        boolean result = pieces.hasAvailable();
        assertEquals(expResult, result);
    }

    @Test
    public void testGetNbAnimals() {
        int expResult = 6;
        int result = pieces.getNbAnimals(GREEN, GAZELLE);
        assertEquals(expResult, result);
    }

    @Test
    public void testGetNbAnimals_AfterGetAnimal() {
        pieces.getAnimal(GREEN, GAZELLE);
        int expResult = 5;
        int result = pieces.getNbAnimals(GREEN, GAZELLE);
        assertEquals(expResult, result);
    }

    @Test
    public void testHasAvailable_Color_True() {
        pieces.emptyList();
        pieces.put(new Animal(Color.GREEN, Species.CROCODILE));
        boolean expResult = true;
        boolean result = pieces.hasAvailable(Color.GREEN);
        assertEquals(expResult, result);
    }

    @Test
    public void testHasAvailable_Color_False() {
        pieces.emptyList();
        pieces.put(new Animal(Color.RED, Species.CROCODILE));
        boolean expResult = false;
        boolean result = pieces.hasAvailable(Color.GREEN);
        assertEquals(expResult, result);
    }
}
