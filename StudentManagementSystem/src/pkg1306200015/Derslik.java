/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

/**
 *
 * @author Mustafa
 */
public class Derslik {
    String ders;
    Teacher OG;
    Student[] st;
    String[] not;
    Derslik(String ders) {
        this.ders = ders;
        st = new Student[100];
        not = new String[100];
    }
    
    void derss() {
        System.out.println(ders);
    }
}
