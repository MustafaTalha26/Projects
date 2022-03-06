/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author Mustafa
 */
public class BilgiPanel {
    JPanel panel;
    
    JLabel Name;
    JLabel Surname;
    JLabel ID;
    JLabel Gender;
    JLabel Birth;
    JLabel SID;
    
    
    JTextField name;
    JTextField surname;
    JTextField id;
    JTextField gender;
    JTextField birth;
    JTextField sid;
    BilgiPanel(Student kisi) {
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        
        Name = new JLabel("İsim: ");
        Name.setBounds(100, 200, 80, 20);
        Surname = new JLabel("Soyisim: ");
        Surname.setBounds(100, 250, 80, 20);
        ID = new JLabel("ID: ");
        ID.setBounds(100, 300, 80, 20);
        Gender = new JLabel("Gender: ");
        Gender.setBounds(450, 200, 80, 20);
        Birth = new JLabel("Birth: ");
        Birth.setBounds(450, 250, 80, 20);
        SID = new JLabel("Student ID: ");
        SID.setBounds(450, 300, 80, 20);
        
        name = new JTextField(kisi.Name);
        name.setBounds(200, 200, 120, 20);
        surname = new JTextField(kisi.Surname);
        surname.setBounds(200, 250, 120, 20);
        id = new JTextField(kisi.ID);
        id.setBounds(200, 300, 120, 20);
        gender = new JTextField(kisi.Gender);
        gender.setBounds(550, 200, 120, 20);
        birth = new JTextField(kisi.Birth);
        birth.setBounds(550, 250, 120, 20);
        sid = new JTextField(kisi.StudentID);
        sid.setBounds(550, 300, 120, 20);
        
        panel.add(Name);
        panel.add(Surname);
        panel.add(ID);
        panel.add(Gender);
        panel.add(Birth);
        panel.add(SID);
        panel.add(name);
        panel.add(surname);
        panel.add(id);
        panel.add(gender);
        panel.add(birth);
        panel.add(sid);
        panel.setVisible(false);
    }
    BilgiPanel(Teacher kisi) {
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        
        Name = new JLabel("İsim: ");
        Name.setBounds(100, 200, 80, 20);
        Surname = new JLabel("Soyisim: ");
        Surname.setBounds(100, 250, 80, 20);
        ID = new JLabel("ID: ");
        ID.setBounds(100, 300, 80, 20);
        Gender = new JLabel("Gender: ");
        Gender.setBounds(450, 200, 80, 20);
        Birth = new JLabel("Birth: ");
        Birth.setBounds(450, 250, 80, 20);
        SID = new JLabel("Student ID: ");
        SID.setBounds(450, 300, 80, 20);
        
        name = new JTextField(kisi.Name);
        name.setBounds(200, 200, 120, 20);
        surname = new JTextField(kisi.Surname);
        surname.setBounds(200, 250, 120, 20);
        id = new JTextField(kisi.ID);
        id.setBounds(200, 300, 120, 20);
        gender = new JTextField(kisi.Gender);
        gender.setBounds(550, 200, 120, 20);
        birth = new JTextField(kisi.Birth);
        birth.setBounds(550, 250, 120, 20);
        sid = new JTextField(kisi.StudentID);
        sid.setBounds(550, 300, 120, 20);
        
        panel.add(Name);
        panel.add(Surname);
        panel.add(ID);
        panel.add(Gender);
        panel.add(Birth);
        panel.add(SID);
        panel.add(name);
        panel.add(surname);
        panel.add(id);
        panel.add(gender);
        panel.add(birth);
        panel.add(sid);
        panel.setVisible(false);
    }
    
}
