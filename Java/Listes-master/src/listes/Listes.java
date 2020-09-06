package listes;

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Listes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        List list = new ArrayList<>();
        list.add(42);
        list.add(54);
        list.set(1, 44);
        list.add(1, 43);
        System.out.println(list);
        List list2 = new ArrayList<>();
        list2.add(36);
        list2.add(45);
        list2.add(15);
        System.out.println(list2);
//        concatenation(list, list2);
        
        List list3 = new ArrayList<>();
        list3 = fusion(list, list2);
        System.out.println("fusion : "+list3);
        System.out.println(list3);
        extremes(list3);
        System.out.println(list3);
        
        List<Integer> list4 = new ArrayList <>();
        list4.add(15);
        list4.add(15);
        list4.add(15);
        list4.add(16);
        list4.add(18);
        list4.add(19);
        list4.add(19);
        System.out.println("List4 : " +list4);
        suppDoublons(list4);
        System.out.println("suppDoublons : "+list4);

//        list.remove(list.size()-1);
//        list.remove(new Integer(42));
//        list.removeAll(list);
    }

    public static int sommeList(List<Integer> list) {
        int somme = 0;
        for (int i = 0; i < list.size(); i++) {
            somme = somme + list.get(i);
        }
        return somme;
    }

    public static void concatenation(List list1, List list2) {
        list1.addAll(list2);
    }

    public static void extremes(List<Integer> list) {
        list.remove(Collections.max(list));
        list.remove(Collections.min(list));
    }

    public static List fusion(List list1, List list2) {
        List list3 = new ArrayList<>();
        list3.addAll(list1);
        list3.addAll(list2);
        Collections.sort(list3);
        return list3;
    }
    
    public static void suppDoublons(List<Integer> list){
         for (int i = 0; i < list.size()-1; i++) { 
             if (list.get(i).equals(list.get(i+1))) {
                 list.remove(i+1);
                 i--;
             }
        }
    }

}
