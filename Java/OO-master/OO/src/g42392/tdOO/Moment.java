/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package g42392.tdOO;

/**
 *
 * @author g42392
 */
public class Moment {

    /**
     * @param args the command line arguments
     */
    private int heure;
    private int minute;
    private int seconde;

    public Moment(int heure, int minute, int seconde) {
        this.heure = heure;
        this.minute = minute;
        this.seconde = seconde;
        if (heure > 23 || heure < 0) {
            throw new IllegalArgumentException("Heure non valide");
        }
        if (minute > 59 || minute < 0) {
            throw new IllegalArgumentException("Minute non valide");
        }
        if (seconde > 59 || seconde < 0) {
            throw new IllegalArgumentException("Seconde non valide");
        }
    }

    public Moment() {
        this.heure = 00;
        this.minute = 00;
        this.seconde = 00;
    }

    public int getHeure() {
        return heure;
    }

    public int getMinute() {
        return minute;
    }

    public int getSeconde() {
        return seconde;
    }

    @Override
    public String toString() {
        return heure + ":" + minute + ":" + seconde;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        return hash;
    }

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
        final Moment other = (Moment) obj;
        if (this.heure != other.heure) {
            return false;
        }
        if (this.minute != other.minute) {
            return false;
        }
        if (this.seconde != other.seconde) {
            return false;
        }
        return true;
    }

    public int toSeconds() {
        return seconde + minute * 60 + heure * 3600;
    }

    int compareTo(Moment obj) {

        if (this.toSeconds() == obj.toSeconds()) {
            return 0;
        } else if (this.toSeconds() < obj.toSeconds()) {
            return -1;
        } else {
            return 1;
        }

    }

    public void BeforeOrAfter(Moment obj) {
        if (this.compareTo(obj) == 0) {
            System.out.println("Le moment : " + this + " est égal au moment : " + obj);
        } else if (this.compareTo(obj) == 1) {
            System.out.println("Le moment : " + this + " vient après le moment : " + obj);
        } else {
            System.out.println("Le moment : " + this + " vient avant le moment : " + obj);
        }
    }
}
