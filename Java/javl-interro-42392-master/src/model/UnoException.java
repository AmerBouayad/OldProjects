package model;

/**
 *
 * @author G42392
 * 
 * Exceptions of the game Uno
 */
public class UnoException extends Exception {

    /**
     * Creates a new instance of <code>UnoException</code> without detail
     * message.
     */
    public UnoException() {
    }

    /**
     * Constructs an instance of <code>UnoException</code> with the specified
     * detail message.
     *
     * @param msg the detail message.
     */
    public UnoException(String msg) {
        super(msg);
    }
}
