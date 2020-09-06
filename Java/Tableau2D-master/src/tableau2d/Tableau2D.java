/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tableau2d;

/**
 *
 * @author Amer
 */
public class Tableau2D {

    public static void afficher(int tab[][]) {
        for (int y = 0; y < tab.length; y++) {

            System.out.print("[");
            for (int i = 0; i < tab[y].length; i++) {
                if (i == tab[y].length - 1) {
                    System.out.print(tab[y][i]);
                } else {
                    System.out.print(tab[y][i] + ", ");
                }
            }
            System.out.println("]");
        }
    }

    public static double proportionNuls(int tab[][]) {
        double cptNul = 0;
        for (int i = 0; i < tab[0].length; i++) {
            if (tab[0][i] == 0) {
                cptNul++;
            }
        }
        for (int i = 0; i < tab[1].length; i++) {
            if (tab[1][i] == 0) {
                cptNul++;
            }
        }
        int taille = tab[0].length + tab[1].length;
        return (cptNul / taille);
    }

    public static boolean tousPositifs(int tab[][]) {
        for (int i = 0; i < tab[0].length; i++) {
            if (tab[0][i] <= 0) {
                return false;
            }
        }
        for (int i = 0; i < tab[1].length; i++) {
            if (tab[1][i] <= 0) {
                return false;
            }
        }
        return true;
    }

    public static boolean estCarreMagique(int tab[][]) {
        int cptRow = 0;
        int cptColumn = 0;
        int row1 = 0;
        int cptDiag = 0;

        for (int j = 0; j < tab[0].length; j++) {
            row1 = row1 + tab[0][j];
        }
        for (int i = 0; i < tab.length; i++) {
            if (tab[i].length != tab.length) {
                throw new IllegalArgumentException("Ceci n'est pas un carré !");
            }
            for (int j = 0; j < tab[i].length; j++) {
                cptRow = cptRow + tab[i][j];
                cptColumn = cptColumn + tab[j][i];
            }
            if (row1 != cptRow || row1 != cptColumn) {
                return false;
            }
            cptRow = 0;
            cptColumn = 0;

        }
        for (int i = 0; i < tab.length; i++) {
            cptDiag = cptDiag + tab[i][i];
        }
        if (row1 != cptDiag) {
            return false;
        }
        cptDiag = 0;
        for (int i = tab.length - 1; i >= 0; i--) {
            cptDiag = cptDiag + tab[i][i];
        }
        if (row1 != cptDiag) {
            return false;
        }
        cptDiag = 0;

        return true;
    }

    public static void swapRows(int tab[][], int nb1, int nb2) {
        
        int otherTab[] = null;

        otherTab = tab[nb1];
        tab[nb1] = tab[nb2];
        tab[nb2] = otherTab;


    }

    public static int[][] trianglePascal(int n) {

        if (n <= 0) {
            throw new IllegalArgumentException("Erreur, n est doit être strictement positif");
        }
        n--;
        int[][] tab = new int[n + 1][n + 1];

        int otherTab[] = {};
        for (int z = 0; z < n; z++) {
            for (int q = 0; q < z; q++) {

                otherTab = new int[z + 1];

                tab[z] = new int[otherTab.length];

                tab[z][q] = otherTab[z];
                for (int i = 0; i <= otherTab.length; i++) {
                    tab[i][0] = 1;
                }
                for (int i = 1; i <= otherTab.length; i++) {
                    tab[i][i] = 1;
                }
                for (int j = 2; j <= otherTab.length; j++) {
                    for (int k = 1; k <= j - 1; k++) {
                        tab[j][k] = tab[j - 1][k] + tab[j - 1][k - 1];
                    }
                }
            }
        }

        tab[0] = new int[1];
        tab[0][0] = 1;
        if (n == 1) {
            tab[1] = new int[2];
            tab[1][0] = 1;
            tab[1][1] = 1;
        }

        return tab;
    }
}
