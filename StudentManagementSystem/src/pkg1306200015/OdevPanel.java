/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import static javax.swing.JOptionPane.showMessageDialog;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author Mustafa
 */
public class OdevPanel {
    JPanel panel;
    JComboBox box;
    JTextField field1;
    JTextField field2;
    JLabel label1;
    JLabel label2;
    JButton button;
    
    OdevPanel(Teacher tc) {
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        
        label1 = new JLabel("Dersinizi seçin:");
        label1.setBounds(60, 100, 200, 30);
        label2 = new JLabel("Açıklamanız:");
        label2.setBounds(60, 150, 200, 30);
        
        field1 = new JTextField(30);
        field1.setBounds(200, 150, 500, 30);
        
        field2 = new JTextField(30);
        field2.setBounds(200, 190, 500, 30);
        
        String[] dersler = new String[5];
        int derstop = 0;
        Reading rd = new Reading("Dersler.txt");
        Derslik[] ds = rd.hepsi();
        for(int x = 0; x < ds.length; x++) {
            if(ds[x] != null) {
                if(ds[x].OG.StudentID.equals(tc.StudentID)) {
                    dersler[derstop] = ds[x].ders;
                    derstop++;
                }
            }
        }
        String[] ders = new String[derstop];
        for(int x = 0; x < derstop; x++) {
            ders[x] = dersler[x];
        }
        
        box = new JComboBox(ders);
        box.setBounds(200, 100, 200, 30);
        
        Writer wt = new Writer("Ödevler.txt");
        
        class AL implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == button) {
                    wt.Write(box.getSelectedItem().toString()+"/"+field1.getText());
                    wt.Write(box.getSelectedItem().toString()+"/"+field2.getText());
                    showMessageDialog(null, "Kaydedildi");
                }
            }      
        }
        AL actionlistener = new AL();
        
        button = new JButton("Tanımla");
        button.setBounds(615, 240, 80, 30);
        button.setFocusable(false);
        button.addActionListener(actionlistener);
        
        
        panel.add(box);
        panel.add(label1);
        panel.add(label2);
        panel.add(field1);
        panel.add(field2);
        panel.add(button);
    }
}
