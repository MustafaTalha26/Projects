/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import javax.swing.JPanel;

/**
 *
 * @author Mustafa
 */
interface gösteri {
    Student[] gönder(Derslik ds);
}

public class StudentGoster implements gösteri{
    JPanel panel;
    public StudentGoster() {
        
    }
    
    @Override
    public Student[] gönder(Derslik ds) {
        return ds.st;
    }
}
