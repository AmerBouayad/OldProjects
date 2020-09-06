package g42392.tdOOsuite;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Amer
 */
public class Point {

    private double x;
    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    @Override
    public String toString() {
        return "(" + x + "," + y + ')';
    }

    public void move(double deltaX, double deltaY) {
        this.x = this.x + deltaX;
        this.y = this.y + deltaY;
    }

    public double distance(Point other) {
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.y - other.y, 2));
    }

    public Point middle(Point other) {
        Point point = new Point((this.getX() + other.getX()) / 2, (this.getY() + other.getY()) / 2);
        return point;
    }

    public static void main(String[] args) {
        Point point1 = new Point(2, 3);
        Point point2 = new Point(4, 5);
        System.out.println("Point1 : " + point1);
        // System.out.println("x du point1 : " + point1.getX());
        // System.out.println("y du point1 : " + point1.getY());
        System.out.println("Point2 : " + point2);
        // System.out.println("avant move(1, 3) : " + point1);
        // System.out.print("après move(1, 3) : ");
        // point1.move(1, 3);
        // System.out.println(point1);
        System.out.println("Distance entre point1 et point2 : " + point1.distance(point2));
        System.out.println("Milieu du point1 et point 2 : " + point1.middle(point2));

    }

}
