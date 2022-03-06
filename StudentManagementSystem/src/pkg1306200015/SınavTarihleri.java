/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import static javax.swing.JOptionPane.showMessageDialog;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.border.Border;

/**
 *
 * @author Mustafa
 */
public class SınavTarihleri {
    JPanel panel;
    JPanel gün1;
    JPanel gün2;
    JPanel gün3;
    JPanel gün4;
    JPanel gün5;
    JComboBox box;
    JComboBox index;
    JTextField field1;
    JTextField field2;
    JLabel label1;
    JLabel label2;
    JButton button;
    Border border;
    
    SınavTarihleri(Teacher tc) {
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        border = BorderFactory.createLineBorder(Color.black,3);

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
        
        String[] indexnumbers = new String[15];
        for(int x = 0; x < 15; x++) {
            int sayı = x + 1;
            indexnumbers[x] = Integer.toString(sayı);
        }
        index = new JComboBox(indexnumbers);
        index.setBounds(500, 100, 60, 30);
        
        button = new JButton("Ekle");
        button.setBounds(600, 100, 80, 30);
        button.setFocusable(false);
        class AL implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == button) {
                    Reading rds = new Reading("Sınavlar.txt");
                    Writer wt = new Writer("Sınavlar.txt");
                    String[][] sınavindex = rds.sınav();
                    if(sınavindex.length == 0) {
                        wt.Write(box.getSelectedItem().toString()+"/"+index.getSelectedItem().toString());
                        showMessageDialog(null, "Kaydedildi");
                    }
                    else {
                        int check = 0;
                        for(int x = 0; x < sınavindex.length; x++) {
                            if(box.getSelectedItem().toString().equals(sınavindex[x][0])) {
                                showMessageDialog(null, "Sınav zaten belirlendi");
                                check = 1;
                            }
                            if(index.getSelectedItem().toString().equals(sınavindex[x][1])) {
                                showMessageDialog(null, "İndex dolu");
                                check = 1;
                            }
                            
                        }
                        if(check == 0){
                                wt.Write(box.getSelectedItem().toString()+"/"+index.getSelectedItem().toString());
                                showMessageDialog(null, "Kaydedildi");
                        }
                        check = 0;
                    }
                }
            }      
        }
        AL al =new AL();
        button.addActionListener(al);
        gün1 = new JPanel();
        gün1.setBorder(border);
        gün1.setBounds(80, 250, 160, 300);
        gün1.setBackground(new Color(240,240,250));
        gün2 = new JPanel();
        gün2.setBorder(border);
        gün2.setBounds(240, 250, 160, 300);
        gün2.setBackground(new Color(240,240,250));
        gün3 = new JPanel();
        gün3.setBorder(border);
        gün3.setBounds(400, 250, 160, 300);
        gün3.setBackground(new Color(240,240,250));
        gün4 = new JPanel();
        gün4.setBorder(border);
        gün4.setBounds(560, 250, 160, 300);
        gün4.setBackground(new Color(240,240,250));
        gün5 = new JPanel();
        gün5.setBorder(border);
        gün5.setBounds(720, 250, 160, 300);
        gün5.setBackground(new Color(240,240,250));
        
        panel.add(button);
        panel.add(box);
        panel.add(index);
        panel.add(gün1);
        panel.add(gün2);
        panel.add(gün3);
        panel.add(gün4);
        panel.add(gün5);
    }  
}
