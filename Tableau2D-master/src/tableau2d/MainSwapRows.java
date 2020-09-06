/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tableau2d;
import static tableau2d.Tableau2D.swapRows;
import static tableau2d.Tableau2D.afficher;

/**
 *
 * @author Amer
 */
public class MainSwapRows {
    public static void main(String[] args) {
        int[][] tab = {
            {2, 7, 6, 5, 9, 15},
            {9, 5, 1},
            {4},
            {0, 0, 0}};
        
        swapRows(tab,0,2);
        afficher(tab);
        
        
    }
}
