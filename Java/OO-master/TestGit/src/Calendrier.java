/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author g42392
 */
public class Calendrier {

    public static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
    }

    public static int daysInMonth(int month, int year) {
        int nbDays = -1;

        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                nbDays = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                nbDays = 30;
                break;
            case 2:
                if (isLeapYear(year)) {
                    nbDays = 29;
                } else {
                    nbDays = 28;
                }
                break;
            default:
                System.out.println("Erreur");

        }
        return nbDays;
    }

    public static String nameMonth(int month) {
        String name;
        switch (month) {
            case 1:
                name = "January ";
                break;
            case 2:
                name = "February ";
                break;
            case 3:
                name = "March ";
                break;
            case 4:
                name = "April ";
                break;
            case 5:
                name = "May ";
                break;
            case 6:
                name = "June ";
                break;
            case 7:
                name = "July ";
                break;
            case 8:
                name = "August ";
                break;
            case 9:
                name = "September ";
                break;
            case 10:
                name = "October ";
                break;
            case 11:
                name = "November ";
                break;
            case 12:
                name = "Décember ";
                break;
            default:
                name = "Not a Valid Month";
                break;
        }
        return name;
    }

    public static void printDay(int day) {
        if (day < 1 || day > 31) {
            throw new IllegalArgumentException("Le jour n'est pas valide !");
        } else if (day > 9) {
            System.out.print(day + "   ");

        } else {
            System.out.print("0" + day + "   ");
        }

    }

    public static int firstDayOfMonth(int month, int year) {
        return util.calendrier.Util.firstDayOfMonth(month, year);
    }

    public static void printCalendar(int month, int year) {
        System.out.println("=================================");
        System.out.println(nameMonth(month) + year);
        System.out.println("=================================");
        System.out.println("MON  TUE  WEB  THU  FRI  SAT  SUN");
        for (int i = 1; i <= firstDayOfMonth(month, year); i++) {
            System.out.print("     ");

        }
        for (int i = firstDayOfMonth(month, year); i < daysInMonth(month, year) + firstDayOfMonth(month, year); i++) {
            if (i % 7 == 0) {
                System.out.println("");
                printDay(i - firstDayOfMonth(month, year) + 1);

            } else {
                printDay(i - firstDayOfMonth(month, year) + 1);

            }
        }
        System.out.println("");
        System.out.println("=================================");

    }

    public static void main(String[] args) {
        printCalendar(1, 1435);
    }
}
