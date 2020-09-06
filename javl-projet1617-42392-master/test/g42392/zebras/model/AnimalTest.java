package g42392.zebras.model;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author G42392
 *
 * Tests of action method, of class Animal.
 */
public class AnimalTest {

    final Animal gazelle = new Animal(Color.GREEN, Species.GAZELLE);
    final Animal lion = new Animal(Color.RED, Species.LION);
    final Animal zebra = new Animal(Color.GREEN, Species.ZEBRA);

    @Test
    public void testAction_Gazelle_Lion() {
        gazelle.action(lion);
        AnimalState expResult = AnimalState.HIDDEN;
        AnimalState result = gazelle.getState();
        assertEquals(expResult, result);
    }

    @Test
    public void testAction_Lion_Gazelle() {
        lion.action(gazelle);
        AnimalState expResult = AnimalState.RUN;
        AnimalState result = gazelle.getState();
        assertEquals(expResult, result);
    }

    @Test
    public void testAction_Zebra_Lion() {
        zebra.action(lion);
        AnimalState expResult = AnimalState.HIDDEN;
        AnimalState result = zebra.getState();
        assertEquals(expResult, result);
    }

    @Test
    public void testAction_Lion_Zebra() {
        lion.action(zebra);
        AnimalState expResult = AnimalState.HIDDEN;
        AnimalState result = zebra.getState();
        assertEquals(expResult, result);
    }

    @Test
    public void testAction_Lion_State() {
        lion.action(zebra);
        AnimalState expResult = AnimalState.REST;
        AnimalState result = lion.getState();
        assertEquals(expResult, result);
    }
}
