/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.border.Border;

/**
 *
 * @author Mustafa
 */
public class Lactos {
    ImageIcon anon;
    JFrame frame;
    JPanel panel2;
    JPanel panel3;
    JPanel panel4;
    JPanel panel5;
    JTabbedPane pane;
    BilgiPanel bilgipaneli;
    NotPanel notpanel;
    DersSecimi secim;
    Duyurular duyurupanel;
    OdevPanel ödevpanel;
    SınavTarihleri sınavpanel;
    NotGirisEklenti notgiris;
    DersProgramı dersprogramı;
    
    Border border;
    
    JLabel label1;
    JLabel label2;
    JLabel label3;
    
    
    JButton cıkıs;
    JButton bilgi;
    JButton not;
    JButton ders;
    JButton duyuru;
    JButton notgirisbuton;
    JButton dersprogram;
    
    public Lactos(Student st) {
        frame = new JFrame("Panel");
        frame.setSize(1200, 700);
        frame.setLayout(new BorderLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        anon = new ImageIcon("anony.png");  
        Image image = anon.getImage().getScaledInstance(100, 100, Image.SCALE_SMOOTH);
        anon = new ImageIcon(image);
        
        label1 = new JLabel("");
        label1.setBounds(50, 20, 100, 100);
        label1.setIcon(anon);
        
        label2 = new JLabel(st.Name+ " " +st.Surname);
        label2.setBounds(30, 120, 160, 25);
        
        label3 = new JLabel(st.StudentID);
        label3.setBounds(30, 140, 160, 25);
        
        cıkıs = new JButton("Çıkış");
        cıkıs.setBounds(60, 170, 80, 25);
        class AL implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == cıkıs) {
                    frame.dispose();
                }
                if(e.getSource() == bilgi) {
                    pane.setSelectedIndex(0);
                }
                if(e.getSource() == not) {
                    pane.setSelectedIndex(1);
                }
                if(e.getSource() == ders) {
                    pane.setSelectedIndex(2);
                }
                if(e.getSource() == duyuru) {
                    pane.setSelectedIndex(3);
                }
                if(e.getSource() == dersprogram) {
                    pane.setSelectedIndex(4);
                }
            }      
        }
        AL actionlistener = new AL();
        cıkıs.addActionListener(actionlistener);
        cıkıs.setFocusable(false);
        
        not = new JButton("Notlar");
        not.setBounds(40, 120, 120, 30);
        not.addActionListener(actionlistener);
        not.setFocusable(false);
        
        dersprogram = new JButton("Ders Programı");
        dersprogram.setBounds(40, 160, 120, 30);
        dersprogram.addActionListener(actionlistener);
        dersprogram.setFocusable(false);
        
        ders = new JButton("Ders Seçimi");
        ders.setBounds(40, 80, 120, 30);
        ders.addActionListener(actionlistener);
        ders.setFocusable(false);
        
        duyuru = new JButton("Duyurular");
        duyuru.setBounds(40, 40, 120, 30);
        duyuru.addActionListener(actionlistener);
        duyuru.setFocusable(false);
        
        bilgi = new JButton("Bilgilerim");
        bilgi.setBounds(48, 200, 104, 25);
        bilgi.addActionListener(actionlistener);
        bilgi.setFocusable(false);   
        
        border = BorderFactory.createLineBorder(Color.black,3);
        panel2 = new JPanel();
        panel3 = new JPanel();
        panel4 = new JPanel();
        panel5 = new JPanel();
        pane = new JTabbedPane();
        pane.setTabLayoutPolicy(JTabbedPane.SCROLL_TAB_LAYOUT);
        
        panel2.setBackground(new Color(180,180,220));
        panel3.setBackground(new Color(180,180,220));
        panel4.setBackground(new Color(180,180,220));
        panel5.setBackground(new Color(240,240,250));
        pane.setBackground(new Color(240,240,250));
        
        panel3.setPreferredSize(new Dimension(100,100));
        panel3.setPreferredSize(new Dimension(100,250));
        panel4.setPreferredSize(new Dimension(200,100));
        panel5.setPreferredSize(new Dimension(100,100));
        
        panel4.setLayout(new BorderLayout());
        
        panel3.setLayout(null);
        panel3.add(label1);
        panel3.add(label2);
        panel3.add(label3);
        panel3.add(cıkıs);
        panel3.add(bilgi);
        panel3.setBorder(border);
        
        panel2.setLayout(null);
        panel2.add(not);
        panel2.add(ders);
        panel2.add(duyuru);
        panel2.add(dersprogram);
        
        panel5.setLayout(null);
        bilgipaneli = new BilgiPanel(st);
        notpanel = new NotPanel(st);
        secim = new DersSecimi(st);
        dersprogramı = new DersProgramı();
        duyurupanel = new Duyurular();
        pane.setBounds(0, -24, 1200, 700);
        panel5.add(pane,BorderLayout.CENTER);
        pane.add(bilgipaneli.panel);
        pane.add(notpanel.panel);
        pane.add(secim.panel);
        pane.add(duyurupanel.panel);
        pane.add(dersprogramı.panel);
        
        panel4.add(panel2,BorderLayout.CENTER);
        panel4.add(panel3,BorderLayout.NORTH);
        
        frame.add(panel4,BorderLayout.WEST);
        frame.add(panel5,BorderLayout.CENTER);
        frame.setResizable(false);
        frame.setVisible(true); 
    }
    
    public Lactos(Teacher tc) {
        frame = new JFrame("Panel");
        frame.setSize(1200, 700);
        frame.setLayout(new BorderLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        anon = new ImageIcon("anony.png");  
        Image image = anon.getImage().getScaledInstance(100, 100, Image.SCALE_SMOOTH);
        anon = new ImageIcon(image);
        
        label1 = new JLabel("");
        label1.setBounds(50, 20, 100, 100);
        label1.setIcon(anon);
        
        label2 = new JLabel(tc.Name+ " " +tc.Surname);
        label2.setBounds(30, 120, 160, 25);
        
        label3 = new JLabel(tc.StudentID);
        label3.setBounds(30, 140, 160, 25);
        
        cıkıs = new JButton("Çıkış");
        cıkıs.setBounds(60, 170, 80, 25);
        class AL implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(e.getSource() == cıkıs) {
                    frame.dispose();
                }
                if(e.getSource() == bilgi) {
                    pane.setSelectedIndex(0);
                }
                if(e.getSource() == not) {
                    pane.setSelectedIndex(3);
                }
                if(e.getSource() == ders) {
                    pane.setSelectedIndex(2);
                }
                if(e.getSource() == duyuru) {
                    pane.setSelectedIndex(1);
                }
                if(e.getSource() == notgirisbuton) {
                    pane.setSelectedIndex(4);
                }
                if(e.getSource() == dersprogram) {
                    pane.setSelectedIndex(5);
                }
            }      
        }
        AL actionlistener = new AL();
        cıkıs.addActionListener(actionlistener);
        cıkıs.setFocusable(false);
        
        not = new JButton("Sınav Tarihleri");
        not.setBounds(40, 120, 120, 30);
        not.addActionListener(actionlistener);
        not.setFocusable(false);
        
        dersprogram = new JButton("Ders Programı");
        dersprogram.setBounds(40, 200, 120, 30);
        dersprogram.addActionListener(actionlistener);
        dersprogram.setFocusable(false);
        
        notgirisbuton = new JButton("Not Giriş");
        notgirisbuton.setBounds(40, 160, 120, 30);
        notgirisbuton.addActionListener(actionlistener);
        notgirisbuton.setFocusable(false);
        
        ders = new JButton("Ödev Tanımla");
        ders.setBounds(40, 80, 120, 30);
        ders.addActionListener(actionlistener);
        ders.setFocusable(false);
        
        duyuru = new JButton("Duyurular");
        duyuru.setBounds(40, 40, 120, 30);
        duyuru.addActionListener(actionlistener);
        duyuru.setFocusable(false);
        
        bilgi = new JButton("Bilgilerim");
        bilgi.setBounds(48, 200, 104, 25);
        bilgi.addActionListener(actionlistener);
        bilgi.setFocusable(false);   
        
        border = BorderFactory.createLineBorder(Color.black,3);
        panel2 = new JPanel();
        panel3 = new JPanel();
        panel4 = new JPanel();
        panel5 = new JPanel();
        pane = new JTabbedPane();
        pane.setTabLayoutPolicy(JTabbedPane.SCROLL_TAB_LAYOUT);
        
        panel2.setBackground(new Color(180,180,220));
        panel3.setBackground(new Color(180,180,220));
        panel4.setBackground(new Color(180,180,220));
        panel5.setBackground(new Color(240,240,250));
        pane.setBackground(new Color(240,240,250));
        
        panel3.setPreferredSize(new Dimension(100,100));
        panel3.setPreferredSize(new Dimension(100,250));
        panel4.setPreferredSize(new Dimension(200,100));
        panel5.setPreferredSize(new Dimension(100,100));
        
        panel4.setLayout(new BorderLayout());
        
        panel3.setLayout(null);
        panel3.add(label1);
        panel3.add(label2);
        panel3.add(label3);
        panel3.add(cıkıs);
        panel3.add(bilgi);
        panel3.setBorder(border);
        
        panel2.setLayout(null);
        panel2.add(not);
        panel2.add(ders);
        panel2.add(duyuru);
        panel2.add(notgirisbuton);
        panel2.add(dersprogram);
        
        panel5.setLayout(null);
        bilgipaneli = new BilgiPanel(tc);
        duyurupanel = new Duyurular();
        ödevpanel = new OdevPanel(tc);
        sınavpanel = new SınavTarihleri(tc);
        notgiris = new NotGirisEklenti();
        dersprogramı = new DersProgramı();
        pane.setBounds(0, -24, 1200, 700);
        panel5.add(pane,BorderLayout.CENTER);
        pane.add(bilgipaneli.panel);
        pane.add(duyurupanel.panel);
        pane.add(ödevpanel.panel);
        pane.add(sınavpanel.panel);
        pane.add(notgiris.panel);
        pane.add(dersprogramı.panel);
        
        panel4.add(panel2,BorderLayout.CENTER);
        panel4.add(panel3,BorderLayout.NORTH);
        
        frame.add(panel4,BorderLayout.WEST);
        frame.add(panel5,BorderLayout.CENTER);
        frame.setResizable(false);
        frame.setVisible(true); 
    }
}
