/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import static javax.swing.JOptionPane.showMessageDialog;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class RegisterScreen implements ActionListener{
    JTextField ID;
    JTextField Name;
    JTextField Surname;
    JTextField Birthday;
    JPasswordField Password;
    JComboBox Gender;
    
    JLabel lid;
    JLabel lname;
    JLabel lsurname;
    JLabel lbirthday;
    JLabel lgender;
    JLabel pass1;
    
    JFrame frame;
    JPanel panel;
    JButton login;
    JButton button;
    RegisterScreen() {
        String[] genders = new String[2];
        genders[0] = new String("Male");
        genders[1] = new String("Female");
        frame = new JFrame();
        panel = new JPanel();
        panel.setBackground(new Color(180,180,220));
        
        frame.setSize(700, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);
        frame.setTitle("Register");
        
        button = new JButton("Register");
        button.setBounds(380,250,100,30);
        button.setFocusable(false);
        button.addActionListener(this);
        
        lname = new JLabel("Name: ");
        lname.setBounds(100,70,120,25);
        lsurname = new JLabel("Surname: ");
        lsurname.setBounds(100,130,120,25);
        pass1 = new JLabel("Password: ");
        pass1.setBounds(100, 190, 120, 25);
        
        Name = new JTextField(25);
        Name.setBounds(180, 70, 100, 25);
        Surname = new JTextField(25);
        Surname.setBounds(180, 130, 100, 25);
        Password = new JPasswordField(25);
        Password.setBounds(180, 190, 100, 25);
        
        lid = new JLabel("ID number: ");
        lid.setBounds(300, 70, 120, 30);
        lgender = new JLabel("Gender: ");
        lgender.setBounds(300, 130, 120, 30);
        lbirthday = new JLabel("Date of Birth: ");
        lbirthday.setBounds(300,190,120,30);
        
        ID = new JTextField(30);
        ID.setBounds(420, 70, 100, 25);
        Gender = new JComboBox(genders);
        Gender.setBounds(420, 130, 100, 25);
        Birthday = new JTextField("gg.aa.yyyy",30);
        Birthday.setBounds(420, 190, 100, 25);
        
        class AL implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == Name) {
                    Surname.requestFocus();
                }
                if(e.getSource() == Surname) {
                    Password.requestFocus();
                }
                if(e.getSource() == Password) {
                    ID.requestFocus();
                }
                if(e.getSource() == ID) {
                    Gender.requestFocus();
                }
                if(e.getSource() == Gender) {
                    Birthday.requestFocus();
                }
                if(e.getSource() == Birthday) {
                    Reading reader = new Reading("Students.txt");
                    Student[] st = reader.settleStudents();
                    int check = 0;
                    for(int x = 0; x < st.length; x++) {
                        if(st[x].ID.equals(ID.getText())) {
                            showMessageDialog(null, "There is already an account like this");
                            check = 1;
                        }
                    }
                    if(check == 0) {
                        Writer wt = new Writer("Students.txt");
                        String gender;
                        if(Gender.getSelectedItem().toString().equals("Male")) {
                            gender = "M";
                        }
                        else {
                            gender = "F";
                        }
                        Random rand = new Random();
                        int x = rand.nextInt(99);
                        if(x < 10) {
                            x *= 10;
                        }
                        x*=10000;
                        int c = rand.nextInt(99);
                        if(c < 10) {
                            c *= 10;
                        }
                        x = x + c;
                        wt.Write(ID.getText()+"/"+Name.getText()+"/"+Surname.getText()+"/"+Password.getText()+"/"+gender+"/"+Birthday.getText()+"/"+"1306"+x);
                        showMessageDialog(null, "Success");
                        new LoginScreen();
                        frame.dispose();
                    }
                }
            }
        }
        AL al = new AL();
        Name.addActionListener(al);
        Surname.addActionListener(al);
        Password.addActionListener(al);
        ID.addActionListener(al);
        Gender.addActionListener(al);
        Birthday.addActionListener(al);
        
        panel.setLayout(null);
        panel.add(lsurname);
        panel.add(lname);
        panel.add(Name);
        panel.add(Surname);
        panel.add(lbirthday);
        panel.add(Password);
        panel.add(ID);
        panel.add(Birthday);
        panel.add(lgender);
        panel.add(pass1);
        panel.add(lid);
        panel.add(Gender);
        panel.add(button);
        
        frame.setResizable(false);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == button) {
            Reading reader = new Reading("Students.txt");
            Student[] st = reader.settleStudents();
            int check = 0;
            for(int x = 0; x < st.length; x++) {
                if(st[x].ID.equals(ID.getText())) {
                    showMessageDialog(null, "There is already an account like this");
                    check = 1;
                }
            }
            if(check == 0) {
                Writer wt = new Writer("Students.txt");
                String gender;
                if(Gender.getSelectedItem().toString().equals("Male")) {
                    gender = "M";
                }
                else {
                    gender = "F";
                }
                Random rand = new Random();
                int x = rand.nextInt(99);
                if(x < 10) {
                     x *= 10;
                }
                x*=10000;
                int c = rand.nextInt(99);
                if(c < 10) {
                    c *= 10;
                }
                x = x + c;
                wt.Write(ID.getText()+"/"+Name.getText()+"/"+Surname.getText()+"/"+Password.getText()+"/"+gender+"/"+Birthday.getText()+"/"+"1306"+x);
                showMessageDialog(null, "Success");
                new LoginScreen();
                frame.dispose();
            }
        }
    }
}
