/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.table.TableColumnModel;

/**
 *
 * @author Mustafa
 */
interface eklenecek {
    
}

public class Duyurular {
    JPanel panel;
    
    JTextArea field1;
    JTextArea field2;
    JTextArea field3;
    JTextArea field4;
    
    JLabel label1;
    JLabel label2;
    JLabel label3;
    JLabel label4;
    
    
    
    Duyurular() {
        Reading rd = new Reading("Duyurular.txt");
        Duyuru[] dy = rd.duyurugetir();
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        
        label1 = new JLabel();
        label1.setBounds(600, 164, 100, 30);
        
        label2 = new JLabel();
        label2.setBounds(600, 304, 100, 30);
        
        label3 = new JLabel();
        label3.setBounds(600, 444, 100, 30);
        
        label4 = new JLabel();
        label4.setBounds(600, 584, 100, 30);
        
        
        
        field1 = new JTextArea();
        field1.setBounds(100, 60, 600, 100);
        if(dy[0] != null) {
            for(int x = 0; x < dy[0].acıklama.length; x++) {
                if(dy[0].acıklama[x] != null) {
                    field1.append(dy[0].acıklama[x]);
                    field1.append("\n");
                }
            } 
            if(dy[0].kimden != null) {
                label1.setText(dy[0].kimden);
            }
        }
        field1.setEditable(false);
        field1.setFont(field1.getFont().deriveFont(14f));
        
        field2 = new JTextArea();
        field2.setBounds(100, 200, 600, 100);
        if(dy[1] != null) {
            for(int x = 0; x < dy[1].acıklama.length; x++) {
                if(dy[1].acıklama[x] != null) {
                    field2.append(dy[1].acıklama[x]);
                    field2.append("\n");
                }
            }
            if(dy[1].kimden != null) {
                label2.setText(dy[1].kimden);
            }
        }
        field2.setEditable(false);
        field2.setFont(field2.getFont().deriveFont(14f));
        
        field3 = new JTextArea();
        field3.setBounds(100, 340, 600, 100);
        if(dy[2] != null) {
            for(int x = 0; x < dy[2].acıklama.length; x++) {
                if(dy[2].acıklama[x] != null) {
                    field3.append(dy[2].acıklama[x]);
                    field3.append("\n");
                }
            } 
            if(dy[2].kimden != null) {
                label3.setText(dy[2].kimden);
            }
        }
        field3.setEditable(false);
        field3.setFont(field3.getFont().deriveFont(14f));
        
        field4 = new JTextArea();
        field4.setBounds(100, 480, 600, 100);
        if(dy[3] != null) {
            for(int x = 0; x < dy[3].acıklama.length; x++) {
                if(dy[3].acıklama[x] != null) {
                    field4.append(dy[3].acıklama[x]);
                    field4.append("\n");
                }
            } 
            if(dy[3].kimden != null) {
                label4.setText(dy[3].kimden);
            }
        }
        field4.setEditable(false);
        field4.setFont(field4.getFont().deriveFont(14f));
        
        panel.add(field1);
        panel.add(field2);
        panel.add(field3);
        panel.add(field4);
        panel.add(label1);
        panel.add(label2);
        panel.add(label3);
        panel.add(label4);
    }
}
