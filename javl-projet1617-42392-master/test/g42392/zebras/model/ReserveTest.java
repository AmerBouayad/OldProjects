package g42392.zebras.model;

import org.junit.Test;
import static org.junit.Assert.*;
import static g42392.zebras.model.Color.GREEN;
import static g42392.zebras.model.Color.RED;
import static g42392.zebras.model.Species.LION;
import static g42392.zebras.model.Species.ELEPHANT;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author G42392
 *
 * Tests of the different methods of the class Reserve
 */
public class ReserveTest {

    final Reserve reserve = new Reserve();

    /**
     * test if the method getAnimal gets the chosen animal
     */
    @Test
    public void testGetAnimal1() {
        Coordinates pos = new Coordinates(3, 4);
        Animal animal = new Animal(GREEN, LION);
        reserve.put(animal, pos);
        Animal expResult = animal;
        Animal result = reserve.getAnimal(pos);
        assertEquals(expResult, result);
    }

    /**
     * @exception ArrayIndexOutOfBoundsException when the position of the animal
     * is out of the Reserve
     */
    @Test(expected = ArrayIndexOutOfBoundsException.class)
    public void testGetAnimal2() {
        Coordinates pos = new Coordinates(8, 4);
        Animal animal = new Animal(GREEN, LION);
        reserve.put(animal, pos);
        Animal expResult = animal;
        Animal result = reserve.getAnimal(pos);
        assertEquals(expResult, result);
    }

    /**
     * @exception ArrayIndexOutOfBoundsException when the position of the animal
     * is out of the Reserve
     */
    @Test(expected = ArrayIndexOutOfBoundsException.class)
    public void testPut2() {
        Coordinates pos = new Coordinates(7, 7);
        Animal animal = new Animal(RED, ELEPHANT);
        reserve.put(animal, pos);
        Animal expResult = animal;
        Animal result = reserve.getAnimal(pos);
        assertEquals(expResult, result);
    }

    /**
     * test if the method put adds an animal to the Reserve
     */
    @Test
    public void testPut3() {
        Coordinates pos = new Coordinates(4, 4);
        Animal animal = new Animal(RED, LION);
        reserve.put(animal, pos);
        boolean expResult = false;
        boolean result = reserve.isFree(pos);
        assertEquals(expResult, result);
    }

    /**
     * @exception ArrayIndexOutOfBoundsException when the position of the animal
     * is out of the Reserve
     */
    @Test(expected = ArrayIndexOutOfBoundsException.class)
    public void testPut4() {
        Coordinates pos = new Coordinates(0, 7);
        Animal animal = new Animal(RED, ELEPHANT);
        reserve.put(animal, pos);
        boolean expResult = false;
        boolean result = reserve.isFree(pos);
        assertEquals(expResult, result);
    }

    /**
     * test if the method Put works for all the boxes of the Reserve
     *
     */
    @Test
    public void testIPut5() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                Coordinates pos = new Coordinates(i, j);
                Animal animal = new Animal(RED, ELEPHANT);
                reserve.put(animal, pos);
                Animal expResult = animal;
                Animal result = reserve.getAnimal(pos);
                assertEquals(expResult, result);
            }
        }
    }

    /**
     * test if the method isFree return true when there no animal at a position
     */
    @Test
    public void testIsFree1() {
        Coordinates pos = new Coordinates(0, 0);
        boolean expResult = true;
        boolean result = reserve.isFree(pos);
        assertEquals(expResult, result);
    }

    /**
     * test if the method isFree return false when there is an animal at a
     * position
     */
    @Test
    public void testIsFree2() {
        Coordinates pos = new Coordinates(4, 5);
        Animal animal = new Animal(GREEN, LION);
        reserve.put(animal, pos);
        boolean expResult = false;
        boolean result = reserve.isFree(pos);
        assertEquals(expResult, result);
    }

    /**
     * @exception ArrayIndexOutOfBoundsException when the position of the animal
     * is out of the Reserve
     */
    @Test(expected = ArrayIndexOutOfBoundsException.class)
    public void testIsFree3() {
        Coordinates pos = new Coordinates(7, 4);
        boolean expResult = true;
        boolean result = reserve.isFree(pos);
        assertEquals(expResult, result);
    }

    /**
     * @exception ArrayIndexOutOfBoundsException when the position of the animal
     * is out of the Reserve
     */
    @Test(expected = ArrayIndexOutOfBoundsException.class)
    public void testIsFree4() {
        Coordinates pos = new Coordinates(9, 4);
        Animal animal = new Animal(GREEN, LION);
        reserve.put(animal, pos);
        boolean expResult = false;
        boolean result = reserve.isFree(pos);
        assertEquals(expResult, result);
    }

    /**
     * test if the method isFree returns true for all boxes of the Reserve who
     * are initialized at null
     *
     */
    @Test
    public void testIsFree5() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                Coordinates pos = new Coordinates(i, j);
                boolean expResult = true;
                boolean result = reserve.isFree(pos);
                assertEquals(expResult, result);
            }
        }
    }

    /**
     * test if the method getAdjacents returns the list of adjacent positions
     * for position (0,0)
     */
    @Test
    public void testGetAdjacents1() {
        Coordinates pos = new Coordinates(0, 0);
        List<Coordinates> expResult = new ArrayList<>();
        expResult.add(new Coordinates(1, 0));
        expResult.add(new Coordinates(0, 1));
        List<Coordinates> result = reserve.getAdjacents(pos);
        for (int i = 0; i < result.size() && i < expResult.size(); i++) {
            assertEquals(expResult.get(i), result.get(i));
        }
    }

    /**
     * test if the method getAdjacents returns the list of adjacent positions
     * for position (4,2)
     */
    @Test
    public void testGetAdjacents2() {
        Coordinates pos = new Coordinates(4, 2);
        List<Coordinates> expResult = new ArrayList<>();
        expResult.add(new Coordinates(3, 2));
        expResult.add(new Coordinates(4, 1));
        expResult.add(new Coordinates(4, 3));
        List<Coordinates> result = reserve.getAdjacents(pos);
        for (int i = 0; i < result.size() && i < expResult.size(); i++) {
            assertEquals(expResult.get(i), result.get(i));
        }
    }

    /**
     * test if the method getAdjacents returns the list of adjacent positions
     * for position (2,2)
     */
    @Test
    public void testGetAdjacents3() {
        Coordinates pos = new Coordinates(2, 2);
        List<Coordinates> expResult = new ArrayList<>();
        expResult.add(new Coordinates(1, 2));
        expResult.add(new Coordinates(3, 2));
        expResult.add(new Coordinates(2, 1));
        expResult.add(new Coordinates(2, 3));
        List<Coordinates> result = reserve.getAdjacents(pos);
        for (int i = 0; i < result.size() && i < expResult.size(); i++) {
            assertEquals(expResult.get(i), result.get(i));
        }
    }

    /**
     * Test if the method getSector get the right sector for the position (0,0)
     */
    @Test
    public void testGetSector1() {
        Coordinates pos = new Coordinates(0, 0);
        int expResult = 1;
        int result = reserve.getSector(pos).getNumber();
        assertEquals(expResult, result);
    }

    /**
     * Test if the method getSector get the right sector for the position (4,5)
     */
    @Test
    public void testGetSector2() {
        Coordinates pos = new Coordinates(1, 5);
        int expResult = 4;
        int result = reserve.getSector(pos).getNumber();
        assertEquals(expResult, result);
    }
}
