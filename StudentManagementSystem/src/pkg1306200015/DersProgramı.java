/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.Color;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.table.TableColumnModel;

/**
 *
 * @author Mustafa
 */
public class DersProgramı {
    JPanel panel;
    JTable table;
    TableColumnModel columnModel;
    DersProgramı() {
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        Reading rd = new Reading("DersProgramı.txt");
        String[][] dersprog = rd.dersprogramıgetir();
        String[] names = {"Pazartesi", "Salı", "Çarşamba", "Perşembe", "Cuma"};
        table = new JTable(dersprog,names);
        table.setBounds(100, 160, 800, 400);
        table.setRowHeight(40);
        table.setRowMargin(20);
        table.setEnabled(false);
        table.setBackground(new Color(240,240,250));
        columnModel = table.getColumnModel();
        columnModel.getColumn(0).setPreferredWidth(60);
        columnModel.getColumn(1).setPreferredWidth(60);
        columnModel.getColumn(2).setPreferredWidth(60);
        columnModel.getColumn(3).setPreferredWidth(60);
        columnModel.getColumn(4).setPreferredWidth(60);
        panel.add(table);
    }
}
