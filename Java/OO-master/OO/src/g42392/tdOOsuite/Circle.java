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
public class Circle {
    private Point center;
    private double radius;

    public Circle(Point center, double radius) {
        this.center = center;
        this.radius = radius;
        if(radius < 0){
            throw new IllegalArgumentException("Le rayon doit être supérieur à 0");
        }
    }
    
    @Override
    public String toString() {
        return "[center=" + center + ", radius=" + radius + ']';
    }
    

    public Point getCenter() {
        return center;
    }
    public double getRadius() {
        return radius;
    }
    public double surface(){
        return Math.PI*Math.pow(this.getRadius(),2);
    }
    public void move(double deltaX, double deltaY){
        this.center.move(deltaX, deltaY);
        
    } 
    public boolean inCircle(Point other){
        return this.center.distance(other) <= this.radius;
    }
    public boolean intersection(Circle other){
        return this.center.distance(other.center)-other.radius <= this.radius;
    }
    public static Circle createCircle (Point other, Point point){
        Circle cercle = new Circle(other.middle(point), other.distance(point)/2);
        return cercle;
    }
    public static void main(String[] args) {
        Point centre = new Point(2,5);
        Circle cercle1 = new Circle(centre,3);
        Point point1 = new Point(2,5);
        Circle cercle2 = new Circle(point1,4);
        Point point2 = new Point(10,15);
        Circle cercle3 = new Circle(point2,4);
        System.out.print("avant un move(1, 2) : ");
        System.out.println(cercle1);
        System.out.println("La surface du cercle1 est de : "+cercle1.surface());
        System.out.print("après un move(1, 2) : ");
        cercle1.move(1, 2);
        System.out.println(cercle1);
        System.out.println("La surface du cercle1 est de  : "+cercle1.surface());
        System.out.println("Ce point est dans le cercle : "+cercle1.inCircle(point1));
        System.out.println("Ce point est dans le cercle : "+cercle1.inCircle(point2));
        System.out.println("Ce cercle a une intersection : "+cercle1.intersection(cercle2) );
        System.out.println("Ce cercle a une intersection : "+cercle1.intersection(cercle3) );
        System.out.println("centre : "+centre );
        System.out.println("point1 : "+point1);
        System.out.println("Distance : "+centre.distance(point1));
        System.out.println("createCircle(point1,point2) : "+createCircle(centre,point1));
        
       

        
    }
}
