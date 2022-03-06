/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

/**
 *
 * @author Mustafa
 */
public class LoginScreen implements ActionListener{
    JLabel label1;
    JLabel label2;
    JLabel success;
    
    JTextField userText;
    JPasswordField userText2;
    
    JButton register;
    JButton button;
    JFrame frame;
    JPanel panel;
    
    LoginScreen() {
        frame = new JFrame();
        panel = new JPanel();
        button = new JButton("Login");
        register = new JButton("Register");
        
        success = new JLabel("");
        success.setBounds(200,120,80,25);
        label1 = new JLabel("User: ");
        label1.setBounds(100, 60, 80, 25);
        label2 = new JLabel("Password: ");
        label2.setBounds(100, 90, 80, 25);
        
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);
        frame.setTitle("Login");
        
        button.setBounds(100, 120, 80, 25);
        button.addActionListener(this);
        button.setFocusable(false);
        
        register.setBounds(140, 170, 100, 25);
        register.addActionListener(this);
        register.setFocusable(false);
        
        userText = new JTextField(20);
        userText.setBounds(200,60,80,25);
        userText2 = new JPasswordField(20);
        userText2.setBounds(200,90,80,25);
        class AL implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == userText2) {
                    String used = userText.getText();
                    String passed = userText2.getText();
                    Reading read = new Reading("Teachers.txt");
                    Teacher[] tc = read.settleTeachers();
                    Reading reader = new Reading("Students.txt");
                    Student[] st = reader.settleStudents();
                    int check = 0;
                    for(int x = 0; x < tc.length; x++) {
                        if(used.equals(tc[x].ID) && passed.equals(tc[x].Password)) {
                            System.out.println("Success2");
                            check = 1;
                            new Lactos(tc[x]);
                            frame.dispose();
                        }
                    }
                    if(check == 0) {
                        for(int x = 0; x < st.length; x++) {
                            if(used.equals(st[x].ID) && passed.equals(st[x].Password)) {
                                System.out.println("Success1");
                                check = 1;
                                new Lactos(st[x]);
                                frame.dispose();
                            }
                        }
                    }
                    if(check == 0) {
                        success.setText("Failure");
                        userText.setText("");
                        userText2.setText("");
                        userText.requestFocus();
                    }
                }
                if(e.getSource()== userText) {
                    userText2.requestFocus();
                }
            }      
        }
        AL nef = new AL();
        userText.addActionListener(nef);
        userText2.addActionListener(nef);
        
        panel.setLayout(null);
        panel.add(label1);
        panel.add(label2);
        panel.add(userText);
        panel.add(userText2);
        panel.add(button);
        panel.add(register);
        panel.add(success);
        panel.setBackground(new Color(180,180,220));
        
        frame.setResizable(false);
        frame.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == button) {
            String used = userText.getText();
            String passed = userText2.getText();
            Reading reader = new Reading("Students.txt");
            Student[] st = reader.settleStudents();
            int check = 0;
            for(int x = 0; x < st.length; x++) {
                if(used.equals(st[x].ID) && passed.equals(st[x].Password)) {
                    System.out.println("Success");
                    check = 1;
                    new Lactos(st[x]);
                    frame.dispose();
                }
            }
            if(check == 0) {
                success.setText("Failure");
                userText.setText("");
                userText2.setText("");
                userText.requestFocus();
            }
        }
        if(e.getSource() == register) {
            new RegisterScreen();
            frame.dispose();
        }
    }
}