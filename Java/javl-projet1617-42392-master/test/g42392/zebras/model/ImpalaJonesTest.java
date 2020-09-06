package g42392.zebras.model;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author G42392
 *
 * Tests of the different methods of the class ImpalaJones
 */
public class ImpalaJonesTest {

    final Animal animal = new Animal(Color.GREEN, Species.CROCODILE);
    final ImpalaJones impala = new ImpalaJones();
    final Reserve reserve = new Reserve();

    @Test
    public void testInit() {
        impala.init(10);
        int expResult = 10;
        int result = impala.getPosition();
        assertEquals(expResult, result);
    }

    @Test
    public void testMove() {
        impala.init(17);
        int distance = 7;
        int expResult = 2;
        impala.move(distance);
        int result = impala.getPosition();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsUpTrue() {
        impala.init(2);
        boolean expResult = true;
        boolean result = impala.isUp();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsUpFalse() {
        impala.init(10);
        boolean expResult = false;
        boolean result = impala.isUp();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsDownTrue() {
        impala.init(11);
        boolean expResult = true;
        boolean result = impala.isDown();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsDownFalse() {
        impala.init(10);
        boolean expResult = false;
        boolean result = impala.isDown();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsLeftTrue() {
        impala.init(21);
        boolean expResult = true;
        boolean result = impala.isLeft();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsLeftFalse() {
        impala.init(0);
        boolean expResult = false;
        boolean result = impala.isLeft();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsRightTrue() {
        impala.init(6);
        boolean expResult = true;
        boolean result = impala.isRight();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsRightFalse() {
        impala.init(0);
        boolean expResult = false;
        boolean result = impala.isRight();
        assertEquals(expResult, result);
    }

    @Test
    public void testGetColumn() {
        impala.init(15);
        int expResult = 1;
        int result = impala.getColumn();
        assertEquals(expResult, result);
    }

    @Test
    public void testGetRow() {
        impala.init(21);
        int expResult = 0;
        int result = impala.getRow();
        assertEquals(expResult, result);
    }

    @Test
    public void testCheckMoveFalse() {
        int distance = 22;
        for (int i = 0; i < 6; i++) {
            Coordinates pos = new Coordinates(0, i);
            reserve.put(animal, pos);
        }
        boolean expResult = false;
        boolean result = impala.checkMove(reserve, distance);
        assertEquals(expResult, result);
    }

    @Test
    public void testCheckMoveTrue() {
        int distance = 22;
        boolean expResult = true;
        boolean result = impala.checkMove(reserve, distance);
        assertEquals(expResult, result);
    }

    @Test
    public void testCheckMoveFalse2() {
        int distance = 1;
        for (int i = 0; i < 5; i++) {
            Coordinates pos = new Coordinates(i, 0);
            reserve.put(animal, pos);
        }
        boolean expResult = false;
        boolean result = impala.checkMove(reserve, distance);
        assertEquals(expResult, result);

    }

    @Test
    public void testCheckMoveTrue2() {
        int distance = 1;
        for (int i = 1; i < 5; i++) {
            Coordinates pos = new Coordinates(i, 0);
            reserve.put(animal, pos);
        }
        boolean expResult = true;
        boolean result = impala.checkMove(reserve, distance);
        assertEquals(expResult, result);
    }

    @Test
    public void testValid() {
        Coordinates pos = new Coordinates(2, 3);
        impala.init(13);
        boolean expResult = true;
        boolean result = impala.valid(pos);
        assertEquals(expResult, result);
    }

    /**
     * testFindFirst when the rows and columns : 0 and 1 are filled
     */
    @Test
    public void testFindFirst() {
        impala.init(19);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {
                Coordinates pos = new Coordinates(j, i);
                reserve.put(animal, pos);
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 6; j++) {
                Coordinates pos = new Coordinates(i, j);
                reserve.put(animal, pos);
            }
        }
        int expResult = 5;
        int result = impala.findFirst(reserve);
        assertEquals(expResult, result);
    }

    @Test
    public void testFindFirst_notFilled() {
        impala.init(0);
        for (int i = 0; i < 4; i++) {
            Coordinates pos = new Coordinates(i, 1);
            reserve.put(animal, pos);
        }
        int expResult = 1;
        int result = impala.findFirst(reserve);
        assertEquals(expResult, result);
    }

    @Test
    public void testFindFirst_ReserveFulfilled() {
        impala.init(0);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                Coordinates pos = new Coordinates(i, j);
                reserve.put(animal, pos);
            }
        }
        int expResult = -1;
        int result = impala.findFirst(reserve);
        assertEquals(expResult, result);
    }
}
