/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.table.TableColumnModel;



public class NotPanel {
    JPanel panel;
    JLabel label1;
    
    JTable table;
    TableColumnModel columnModel;
    NotPanel(Student kisi) {
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        
        String[] columns = new String[] { "Ders"," ", "Not" };  
        int toplamders = 0;
        Reading rd = new Reading("Eklenti.txt");
        EklentiDegerleri[] ed = rd.yenigetir();
        for(int x = 0; x < ed.length; x++) {
            if(kisi.StudentID.equals(ed[x].Og)) {
                toplamders++;
            }
        }
        String[][] sonuclar = new String[toplamders][3];
        int top = 0;
        for(int x = 0; x < ed.length; x++) {
            if(kisi.StudentID.equals(ed[x].Og)) {
                sonuclar[top][0] = ed[x].Ders;
                sonuclar[top][2] = ed[x].Not;
                top++;
            }
        }
        table = new JTable(sonuclar,columns);
        table.setBackground(new Color(240,240,250));
        table.setBounds(60, 100, 900, 600);
        table.setRowHeight(40);
        table.setRowMargin(20);
        table.setEnabled(false);
        columnModel = table.getColumnModel();
        columnModel.getColumn(0).setPreferredWidth(300);
        columnModel.getColumn(1).setPreferredWidth(500);
        columnModel.getColumn(2).setPreferredWidth(100);
        panel.add(table);
    }
}
