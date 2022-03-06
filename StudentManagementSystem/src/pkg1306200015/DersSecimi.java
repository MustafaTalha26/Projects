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
import static javax.swing.JOptionPane.showMessageDialog;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JRadioButton;
import javax.swing.table.TableColumnModel;

/**
 *
 * @author Mustafa
 */
public class DersSecimi {
    JPanel panel;
    JComboBox combobox;
    JButton button;
    JTable table;
    TableColumnModel columnModel;
    DersSecimi(Student kisi) {
        panel = new JPanel();
        panel.setBackground(new Color(240,240,250));
        panel.setLayout(null); 
        panel.setVisible(false);
        
        Reading rd = new Reading("Dersler.txt");
        Derslik[] ds = rd.hepsi();
        int toplamDers = 0;
        String[] columns = new String[] {" ", "Öğretim Görevilisi"," ", "Ders" };   
        for(int x = 0; x < ds.length; x++) {
            if(ds[x] != null) {
                toplamDers++;
            }
        }
        String[][] sonuclar = new String[toplamDers][4];
        String[] önceki = new String[toplamDers];
        int basitsayi = 1;
        for(int x = 0; x < ds.length; x++) {
            if(ds[x] != null) {
                sonuclar[x][0] = basitsayi + ".";
                basitsayi++;
                sonuclar[x][3] = ds[x].ders;
                önceki[x] = ds[x].ders;
                sonuclar[x][1] = ds[x].OG.Name + " " +ds[x].OG.Surname;
            }
        }
        
        combobox = new JComboBox(önceki);
        combobox.setBounds(500, 600, 300, 30);
        
        button = new JButton("Ekle");
        button.setBounds(840, 600, 100, 30);
        
        table = new JTable(sonuclar,columns);
        table.setBackground(new Color(240,240,250));
        table.setBounds(60, 100, 900, 400);
        table.setRowHeight(40);
        table.setRowMargin(20);
        table.setEnabled(false);
        columnModel = table.getColumnModel();
        columnModel.getColumn(0).setPreferredWidth(20);
        columnModel.getColumn(1).setPreferredWidth(200);
        columnModel.getColumn(2).setPreferredWidth(100);
        columnModel.getColumn(3).setPreferredWidth(300);
        panel.add(table);
        panel.add(combobox);
        panel.add(button);
        button.setFocusable(false);
        class AL implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == button) {
                    Reading reader = new Reading("DersKayıtİstekleri.txt");
                    String[][] istekler = reader.istek();
                    int check = 0;
                    for(int c = 0; c < istekler.length; c++) {
                        if(istekler[c][0] != null) {
                            if(istekler[c][0].equals(kisi.StudentID)) {
                                if(istekler[c][1].equals(combobox.getSelectedItem())) {
                                    check = 2;
                                }
                            }
                        }
                    }
                    for(int x = 0; x < ds.length; x++) {
                        if(ds[x] != null) {
                            if(combobox.getSelectedItem().equals(ds[x].ders)) {
                                for(int c = 0; c < ds[x].st.length; c++) {
                                    if(ds[x].st[c] != null) {
                                        if(ds[x].st[c].StudentID.equals(kisi.StudentID)) {
                                            check = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if(check == 2) {
                        showMessageDialog(null, "Danışman onayı bekleniyor!");
                    }
                    if(check == 1) {
                        showMessageDialog(null, "Bu derse zaten eklisiniz!");
                    }
                    if(check == 0) {
                        Writer wt = new Writer("DersKayıtİstekleri.txt");
                        wt.Write(kisi.StudentID +"+"+combobox.getSelectedItem());
                        showMessageDialog(null, "Kaydedildi!");
                    }
                }
            }      
        }
        AL actionlistener = new AL();
        button.addActionListener(actionlistener);
    }
}