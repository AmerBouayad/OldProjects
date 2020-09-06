/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package g42392.tdOO;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author g42392
 */
public class MomentTest {

    public MomentTest() {
    }

    /**
     * Test of getHeure method, of class Moment.
     */
    @Test
    public void testGetHeure() {
        Moment instance = new Moment(12, 21, 30);
        int expResult = 12;
        int result = instance.getHeure();
        assertEquals(expResult, result);
    }

    /**
     * Test of getMinute method, of class Moment.
     */
    @Test
    public void testGetMinute() {
        Moment instance = new Moment(12, 21, 30);
        int expResult = 21;
        int result = instance.getMinute();
        assertEquals(expResult, result);
    }

    /**
     * Test of getSeconde method, of class Moment.
     */
    @Test
    public void testGetSeconde() {
        Moment instance = new Moment(12, 21, 30);
        int expResult = 30;
        int result = instance.getSeconde();
        assertEquals(expResult, result);
    }

    /**
     * Test of getHeure method, of class Moment.
     */
    @Test(expected = IllegalArgumentException.class)
    public void testGetHeureIncorrect() {
        Moment instance = new Moment(25, 21, 30);
        int expResult = 25;
        int result = instance.getHeure();
        assertEquals(expResult, result);
    }

    /**
     * Test of getMinute method, of class Moment.
     */
    @Test(expected = IllegalArgumentException.class)

    public void testGetMinuteIncorrect() {
        Moment instance = new Moment(12, 78, 30);
        int expResult = 78;
        int result = instance.getMinute();
        assertEquals(expResult, result);
    }

    /**
     * Test of getSeconde method, of class Moment.
     */
    @Test(expected = IllegalArgumentException.class)
    public void testGetSecondeIncorrect() {
        Moment instance = new Moment(12, 21, -1);
        int expResult = -1;
        int result = instance.getSeconde();
        assertEquals(expResult, result);
    }
    @Test
    public void testCompareToEqual() {
        Moment instance = new Moment(12, 21, 30);
        Moment instance1 = new Moment(12, 21, 30);
        int expResult = 0;
        int result = instance.compareTo(instance1);
        assertEquals(expResult, result);
    }
    @Test
    public void testCompareToBefore() {
        Moment instance = new Moment(12, 21, 30);
        Moment instance1 = new Moment(12, 21, 31);
        int expResult = -1;
        int result = instance.compareTo(instance1);
        assertEquals(expResult, result);
    }
    @Test
    public void testCompareToAfter() {
        Moment instance = new Moment(12, 21, 30);
        Moment instance1 = new Moment(12, 21, 29);
        int expResult = 1;
        int result = instance.compareTo(instance1);
        assertEquals(expResult, result);
    }

}
