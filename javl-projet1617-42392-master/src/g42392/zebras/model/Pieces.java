package g42392.zebras.model;

import java.util.List;
import java.util.ArrayList;

/**
 * @author G42392
 *
 * List of animals that are not yet placed on the Reserve
 */
public class Pieces {

    private final List<Animal> animals;

    /**
     * A list of 30 animals, ready to be used
     */
    public Pieces() {
        animals = new ArrayList<>();
        for (Color color : Color.values()) {
            addAnimals(6, color, Species.GAZELLE);
            addAnimals(5, color, Species.ZEBRA);
            addAnimals(1, color, Species.LION);
            addAnimals(1, color, Species.ELEPHANT);
            addAnimals(2, color, Species.CROCODILE);
        }
    }

    /**
     * @param nb how much times we add an animal to the list
     * @param color Color of the animal
     * @param species Species of the animal
     *
     * Adds nb times an Animal in the list of Animal
     */
    private void addAnimals(int nb, Color color, Species species) {
        for (int i = 0; i < nb; i++) {
            animals.add(new Animal(color, species));
        }
    }

    /**
     *
     * @param color
     * @param species
     * @return an animal with the color and the species given in parameters to
     * place it on the Reserve
     *
     * Remove the animal from the list of available animals
     */
    public Animal getAnimal(Color color, Species species) {
        Animal beast = null;
        Animal animal = new Animal(color, species);
        if (animals.remove(animal)) {
            beast = animal;
        }
        return beast;
    }

    /**
     *
     * @return true if the list isn't empty
     */
    public boolean hasAvailable() {
        return !(animals.isEmpty());
    }

    /**
     *
     * @param color
     * @param species
     * @return the number of times the animal with the color and species entered
     * in parameters is still available in the list
     *
     */
    public int getNbAnimals(Color color, Species species) {
        Animal animal = new Animal(color, species);
        int cpt = 0;
        for (int i = 0; i < this.animals.size(); i++) {
            if (this.animals.get(i).equals(animal)) {
                cpt++;
            }
        }
        return cpt;
    }

    /**
     * Empty the entire list, used only for the class test
     */
    public void emptyList() {
        this.animals.removeAll(animals);
    }

    /**
     *
     * @param animal The animal comes back to the list of available animals to
     * play
     */
    public void put(Animal animal) {
        this.animals.add(animal);
    }

    /**
     *
     * @param color Color of the animal
     * @return true if there is still at least 1 animal with the color given as
     * a parameter
     */
    public boolean hasAvailable(Color color) {
        boolean notEmpty = false;
        for (Species species : Species.values()) {
            notEmpty = this.getNbAnimals(color, species) > 0;
            if (notEmpty == true) {
                break;
            }
        }
        return notEmpty;
    }
}
