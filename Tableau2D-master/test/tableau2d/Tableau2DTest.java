/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tableau2d;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Amer
 */
public class Tableau2DTest {

    /**
     * Test of proportionNuls method, of class Tableau2D.
     */
    @Test
    public void testProportionNuls() {
        int[][] tab = {{1, 2, 0, 6, 0}, {0, 3, 5, 0, 9}};
        double expResult = 0.4;
        double result = Tableau2D.proportionNuls(tab);
        assertEquals(expResult, result, 0);

    }

    /**
     * Test of proportionNuls method, of class Tableau2D.
     */
    @Test
    public void testProportionNuls2() {
        int[][] tab = {{1, 2, 3, 6, 4}, {1, 3, 5, 1, 9}};
        double expResult = 0;
        double result = Tableau2D.proportionNuls(tab);
        assertEquals(expResult, result, 0);

    }

    /**
     * Test of proportionNuls method, of class Tableau2D.
     */
    @Test
    public void testProportionNuls3() {
        int[][] tab = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
        double expResult = 1;
        double result = Tableau2D.proportionNuls(tab);
        assertEquals(expResult, result, 0);

    }

    /**
     * Test of tousPositifs method, of class Tableau2D.
     */
    @Test
    public void testTousPositifs() {
        int[][] tab = {{1, 2, 3, 4, 5}, {0, 1, 2, 3, 4}};
        boolean expResult = false;
        boolean result = Tableau2D.tousPositifs(tab);
        assertEquals(expResult, result);

    }

    /**
     * Test of tousPositifs method, of class Tableau2D.
     */
    @Test
    public void testTousPositifs2() {
        int[][] tab = {{1, 2, 3, 4, -1}, {1, 1, 2, 3, 4}};
        boolean expResult = false;
        boolean result = Tableau2D.tousPositifs(tab);
        assertEquals(expResult, result);

    }

    /**
     * Test of tousPositifs method, of class Tableau2D.
     */
    @Test
    public void testTousPositifs3() {
        int[][] tab = {{1, 2, 3, 4, 5}, {1, 1, 2, 3, 4}};
        boolean expResult = true;
        boolean result = Tableau2D.tousPositifs(tab);
        assertEquals(expResult, result);

    }

    /**
     * Test of estCarreMagique method, of class Tableau2D.
     */
    @Test(expected = IllegalArgumentException.class)
    public void testEstCarreMagique() {
        int[][] tab = {
            {1, 2, 3, 4, 5}, 
            {1, 1, 2, 3, 4}};
        boolean expResult = false;
        boolean result = Tableau2D.estCarreMagique(tab);
        assertEquals(expResult, result);

    }

    /**
     * Test of estCarreMagique method, of class Tableau2D.
     */
    @Test
    public void testEstCarreMagique2() {
        int[][] tab = {
            {1, 1, 3},
            {3, 1, 1},
            {1, 1, 3}};
        boolean expResult = false;
        boolean result = Tableau2D.estCarreMagique(tab);
        assertEquals(expResult, result);

    }
    
    /**
     * Test of estCarreMagique method, of class Tableau2D.
     */
    @Test
    public void testEstCarreMagique3() {
        int[][] tab = {
            {2, 7, 6},
            {9, 5, 1},
            {4, 3, 8},};
        boolean expResult = true;
        boolean result = Tableau2D.estCarreMagique(tab);
    }

}
