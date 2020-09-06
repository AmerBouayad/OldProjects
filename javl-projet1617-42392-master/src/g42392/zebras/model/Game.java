package g42392.zebras.model;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author G42392
 *
 * Managing Gameplay and Exception Launches of the Game
 */
public class Game implements Model {

    private final List<Player> players;
    private Reserve reserve;
    private ImpalaJones impala;
    private Pieces pieces;
    private GameStatus status;
    private int turn;
    private Player inauguration;

    /**
     * A game has players, a reserve, a list of pieces to play, a state of play
     * and the guardian, ImpalaJones
     *
     * All attributes are instantiated to their initial value
     */
    public Game() {
        this.players = new ArrayList<>();
        this.players.add(new Player(Color.GREEN));
        this.players.add(new Player(Color.RED));
        this.reserve = new Reserve();
        this.impala = new ImpalaJones();
        this.pieces = new Pieces();
        this.status = GameStatus.INIT;
    }

    @Override
    public void start() {
        this.reserve = new Reserve();
        this.impala = new ImpalaJones();
        this.pieces = new Pieces();
        this.status = GameStatus.INIT;
        this.turn = 0;
        this.inauguration = null;
    }

    @Override
    public void setImpalaJonesFirstPosition(int position) {
        if (!this.status.equals(GameStatus.INIT)) {
            throw new GameException("GameStatus INIT excepted to start the game !");
        } else if (position > 21 || position < 0) {
            throw new GameException("ImpalaJones doit se trouver entre la "
                    + "position 0 et 21 !");
        }
        impala.init(position);
        this.status = GameStatus.ANIMAL;
        turn++;
    }

    @Override
    public void putAnimal(Coordinates position, Species species) {
        if (!this.status.equals(GameStatus.ANIMAL)) {
            throw new GameException("GameStatus ANIMAL excepted to put an animal !");
        } else if (!this.impala.valid(position)) {
            throw new GameException("ImpalaJones ne peut pas accèder à cette position !");
        } else if (!this.reserve.isFree(position)) {
            throw new GameException("Cette position est déjà occupée !");
        } else if (this.getNb(species) == 0) {
            throw new GameException("Cette espèce n'est plus disponible dans votre stock !");
        }
        this.reserve.put(this.pieces.getAnimal(this.getCurrentColor(), species), position);
        this.status = GameStatus.IMPALA;
        stateAnimal(position);
        if (this.inauguration == null && this.reserve.getSector(position).isFull()) {
            this.inauguration = this.players.get(turn % 2);
        }
        scorePlayers();
    }

    /**
     * Refreshes the score of the 2 players and adds 5 bonus points to the first
     * player who has completed a sector
     */
    private void scorePlayers() {
        if (this.inauguration == null) {
            this.players.get(0).setScore(this.getScore(this.players.get(0).getColor()));
            this.players.get(1).setScore(this.getScore(this.players.get(1).getColor()));
        } else {
            int score;
            for (int i = 0; i < this.players.size(); i++) {
                if (this.inauguration.getColor() == this.players.get(i).getColor()) {
                    score = this.getScore(this.players.get(i).getColor()) + 5;
                } else {
                    score = this.getScore(this.players.get(i).getColor());
                }
                this.players.get(i).setScore(score);
            }
        }
    }

    /**
     *
     * @param position Coordinates of the current animal
     *
     * It changes the state of adjacent animals or the current animal if
     * necessary and if an adjacent animal's status is RUN, he'll come back in
     * the list of available pawns and his status becomes REST
     */
    private void stateAnimal(Coordinates position) {
        final Animal beast = this.reserve.getAnimal(position);
        List<Coordinates> adjacentsPos = this.reserve.getAdjacents(position);
        for (int i = 0; i < adjacentsPos.size(); i++) {
            if (reserve.getAnimal(adjacentsPos.get(i)) != null) {
                beast.action(reserve.getAnimal(adjacentsPos.get(i)));
                if (reserve.getAnimal(adjacentsPos.get(i)).getState()
                        == AnimalState.RUN) {
                    reserve.getAnimal(adjacentsPos.get(i)).setState(AnimalState.REST);
                    this.pieces.put(this.reserve.remove(adjacentsPos.get(i)));
                }
            }
        }
    }

    @Override
    public void moveImpalaJones(int distance) {
        if (!this.status.equals(GameStatus.IMPALA)) {
            throw new GameException("GameStatus IMPALA excepted to move ImpalaJones !");
        } else if (this.impala.findFirst(reserve) > 3) {
            this.impala.move(impala.findFirst(reserve));
        } else {
            if (distance > 3 || distance < 1) {
                throw new GameException("Le déplacement doit être compris entre 1 et 3 !");
            } else if (!this.impala.checkMove(this.reserve, distance)) {
                throw new GameException("Déplacement invalide → ligne/colonne remplie !");
            }
            this.impala.move(distance);
        }
        this.status = GameStatus.ANIMAL;
        turn++;
        if (!this.pieces.hasAvailable(getCurrentColor())) {
            turn++;
        }
    }

    @Override
    public boolean isOver() {
        return !this.pieces.hasAvailable();
    }

    @Override
    public GameStatus getStatus() {
        return this.status;
    }

    @Override
    public Color getCurrentColor() {
        return this.players.get(turn % 2).getColor();
    }

    @Override
    public List<Player> getPlayers() {
        return this.players;
    }

    @Override
    public Reserve getReserve() {
        return this.reserve;
    }

    @Override
    public int getNb(Species species) {
        return this.pieces.getNbAnimals(this.getCurrentColor(), species);
    }

    @Override
    public ImpalaJones getImpalaJones() {
        return this.impala;
    }

    @Override
    public int getScore(Color color) {
        return this.reserve.getScore(color);
    }
}
