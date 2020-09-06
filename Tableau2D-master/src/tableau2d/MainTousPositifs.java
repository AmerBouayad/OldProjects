/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tableau2d;
import static tableau2d.Tableau2D.tousPositifs;
/**
 *
 * @author Amer
 */
public class MainTousPositifs {
    public static void main(String[] args) {
        int tab1 [][] = { {1,3,4,6,0},{2,3,5,1,9} };
        System.out.println("Tous postitifs : "+tousPositifs(tab1));
    }
}
