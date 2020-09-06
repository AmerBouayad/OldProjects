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
public class MainMoment {

    public static void main(String[] args) {
        Moment moment1 = new Moment(23, 15, 58);
        Moment moment2 = new Moment(10, 05, 48);
        Moment moment3 = new Moment(19, 01, 01);
        Moment moment4 = new Moment(23, 15, 58);

        System.out.println("Moment1 : " + moment1.getHeure() + ":" + moment1.getMinute() + ":" + moment1.getSeconde());
        System.out.println("moment1 : " + moment1);
        System.out.println("moment2 : " + moment2);
        System.out.println("moment3 : " + moment3);
        System.out.println("moment1 : " + moment1.toSeconds() + " secondes");
        System.out.println("Comparaison moment1 au moment2 :  " + moment1.compareTo(moment2));
        System.out.println("Comparaison moment2 au moment3 : " + moment2.compareTo(moment3));
        System.out.println("Comparaison moment1 au moment4 :  " + moment1.compareTo(moment4));
        moment1.BeforeOrAfter(moment4);

        Moment compareMoment = moment1;
        Moment compareMoment2 = moment4;
        switch (moment1.compareTo(compareMoment2)) {
            case -1:
                System.out.println("Le moment : "+compareMoment+" vient avant le moment : "+compareMoment2);
                break;
            case 0:
               System.out.println("Le moment : "+compareMoment+" est égal au moment : "+compareMoment2);
                break;
            case 1:
             System.out.println("Le moment : "+compareMoment+" vient après le moment : "+compareMoment2);

                break;
            default:
                System.out.println("Erreur : comparaison non valable !");
        }

    }
}
