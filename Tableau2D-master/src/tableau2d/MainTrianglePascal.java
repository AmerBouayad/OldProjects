/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tableau2d;

import static tableau2d.Tableau2D.afficher;
import static tableau2d.Tableau2D.trianglePascal;

/**
 *
 * @author Amer
 */
public class MainTrianglePascal {

    public static void main(String[] args) {
        int tab[][] = trianglePascal(15);
        for (int y = 0; y < tab.length; y++) {
            for (int j = tab.length; j > y; j--) {

                System.out.print("    ");
            }
            System.out.print("[");
            for (int i = 0; i < tab[y].length; i++) {
                if (i == tab[y].length - 1) {
                    System.out.print(tab[y][i]);
                } else {
                    System.out.print(tab[y][i] + ",      ");
                }
            }
            System.out.println("]");
        }
    }

}
