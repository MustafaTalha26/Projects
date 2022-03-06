/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

/**
 *
 * @author Mustafa
 */
public class Student extends User{
    String Name;
    String Surname;
    String Password;
    String Gender;
    String Birth;
    String StudentID;

    public Student(String ID) {
        super(ID);
    }
 
    @Override
    void yazdir() {
        System.out.println(StudentID+ " "+Name+ " "+ Surname+ " "+ Password+ " "+ Gender+ " "+ Birth);
    }
    
}
