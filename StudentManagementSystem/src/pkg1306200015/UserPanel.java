/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author Mustafa
 */
public class UserPanel implements ActionListener{
    int count = 0;
    JLabel label1;
    
    JFrame frame;
    JPanel panel;
    
    UserPanel(User s) {
        frame = new JFrame();
        panel = new JPanel();
        
        label1 = new JLabel("Welcome");
        label1.setBounds(100, 80, 80, 25);
        
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);
        frame.setTitle("Login");
       
        
        panel.setLayout(null);
        panel.add(label1);
        
        frame.setResizable(false);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == label1) {
            System.out.println("0");
        }
    }
}
