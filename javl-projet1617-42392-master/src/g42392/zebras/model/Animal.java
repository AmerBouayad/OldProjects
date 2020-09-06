package g42392.zebras.model;

import java.util.Objects;

/**
 * @author G42392
 *
 * An animal is a pawn and has a color and a species
 */
public class Animal {

    private final Species species;
    private final Color color;
    private AnimalState state;

    /**
     * @param color Color of the animal
     * @param species Species of the animal
     *
     * An animal has a color and a species
     */
    public Animal(Color color, Species species) {
        this.species = species;
        this.color = color;
        this.state = AnimalState.REST;
    }

    /**
     * @return the species of an animal
     */
    public Species getSpecies() {
        return species;
    }

    /**
     * @return the color an animal
     */
    public Color getColor() {
        return color;
    }

    /**
     *
     * @return the hash code of an Animal
     */
    @Override
    public int hashCode() {
        int hash = 3;
        hash = 43 * hash + Objects.hashCode(this.species);
        hash = 43 * hash + Objects.hashCode(this.color);
        return hash;
    }

    /**
     *
     * @param obj
     * @return true if 2 animals are equal
     */
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Animal other = (Animal) obj;
        if (this.species != other.species) {
            return false;
        }
        return this.color == other.color;
    }

    /**
     *
     * @return The state of the current animal
     */
    public AnimalState getState() {
        return state;
    }

    /**
     *
     * @param state The state of the current animal
     *
     * Alters the state of the current animal by the state entered as a
     * parameter
     */
    public void setState(AnimalState state) {
        this.state = state;
    }

    /**
     *
     * @param other Animal that will be compare to the current animal
     *
     * The state of a zebra and a gazelle changes if this animal is next to a
     * lion
     */
    public void action(Animal other) {
        if (this.getSpecies() == Species.LION
                && other.getSpecies() == Species.ZEBRA) {
            other.setState(AnimalState.HIDDEN);
        } else if (this.getSpecies() == Species.ZEBRA
                && other.getSpecies() == Species.LION) {
            this.setState(AnimalState.HIDDEN);
        } else if (this.getSpecies() == Species.LION
                && other.getSpecies() == Species.GAZELLE) {
            other.setState(AnimalState.RUN);
        } else if (this.getSpecies() == Species.GAZELLE
                && other.getSpecies() == Species.LION) {
            this.setState(AnimalState.HIDDEN);
        }
    }

    /**
     *
     * @return The value of an animal or 0 if the animal's state is hidden
     */
    public int getValue() {
        int value = this.getSpecies().getValue();
        if (this.getState() == AnimalState.HIDDEN) {
            value = 0;
        }
        return value;
    }
}
