/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tableau2d;
import static tableau2d.Tableau2D.proportionNuls;


/**
 *
 * @author Amer
 */
public class MainProportionsNuls {
    public static void main(String[] args) {
         int tab1 [][] = { {0,2,4,6,8},{1,3,5,0,9} };
         System.out.println(proportionNuls(tab1)*100+"% de 0");
    }
}
