/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;

/**
 *
 * @author Mustafa
 */

interface cando {
    String[][] getString();
    Student[] settleStudents();
    Teacher[] settleTeachers();
    Derslik[] hepsi();
    String[][] istek();
    Duyuru[] duyurugetir();
}

public class Reading implements cando{
    static int CountOfItems = 0;
    public int count = 0;
    String filename;

    public Reading(String filename) {
        this.filename = filename;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   { 
                count++;              
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
    }
    
    public static int getCountOfItems() {
        return CountOfItems;
    }
    public int getCount() {
        return this.count;
    }
    
    @Override
    public String[][] getString() {
        String[][] list = new String[this.count][10];
        int top = 0;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   {
                strLine = strLine + '/';
                String word = "";
                int tetris = 0;
                for(int z = 0; z < strLine.length(); z++) {
                    if(strLine.charAt(z) != '/') {
                        word += strLine.charAt(z);
                    }
                    if(strLine.charAt(z) == '/') {
                        list[top][tetris] = word;
                        tetris++;
                        word = "";
                    }
                }
                top++;
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return list;
    }
    
    @Override
    public Student[] settleStudents() {
        Student[] list = new Student[this.count];
        int top = 0;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   {
                strLine = strLine + '/';
                String word = "";
                int tetris = 1;
                list[top] = new Student("");
                for(int z = 0; z < strLine.length(); z++) {
                    if(strLine.charAt(z) != '/') {
                        word += strLine.charAt(z);
                    }
                    if(strLine.charAt(z) == '/') {
                        
                        switch(tetris) {   
                            case 1:
                                list[top].ID = word;
                                break;
                            case 2:
                                list[top].Name = word;
                                break;
                            case 3:
                                list[top].Surname = word;
                                break;
                            case 4:
                                list[top].Password = word;
                                break;
                            case 5:
                                list[top].Gender = word;
                                break;
                            case 6:
                                list[top].Birth = word;
                                break;
                            case 7:
                                list[top].StudentID = word;
                                break;
                        }
                        tetris++;
                        word = "";
                    }
                }
                top++;
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return list;
    }
    
    @Override    
    public Teacher[] settleTeachers() {
        Teacher[] list = new Teacher[this.count];
        int top = 0;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   {
                strLine = strLine + '/';
                String word = "";
                int tetris = 1;
                list[top] = new Teacher("");
                for(int z = 0; z < strLine.length(); z++) {
                    if(strLine.charAt(z) != '/') {
                        word += strLine.charAt(z);
                    }
                    if(strLine.charAt(z) == '/') {
                        
                        switch(tetris) {   
                            case 1:
                                list[top].ID = word;
                                break;
                            case 2:
                                list[top].Name = word;
                                break;
                            case 3:
                                list[top].Surname = word;
                                break;
                            case 4:
                                list[top].Password = word;
                                break;
                            case 5:
                                list[top].Gender = word;
                                break;
                            case 6:
                                list[top].Birth = word;
                                break;
                            case 7:
                                list[top].StudentID = word;
                                break;
                        }
                        tetris++;
                        word = "";
                    }
                }
                top++;
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return list;
    }
    
    //prototip
    public Derslik Classed() {
        Derslik derslik = new Derslik(" ");
        derslik.st = new Student[100];
        int ösayisi = 0;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            int ders2 = 0;
            int d = 0;
            while ((strLine = br.readLine()) != null)   {
                if(strLine.equals("Ders:") && ders2 == 0) {
                    derslik = new Derslik(br.readLine());
                    System.out.println(derslik.ders);
                    ders2++;
                }
                if(strLine.equals("OG:")){
                    Reading reader = new Reading("Teachers.txt");
                    Teacher[] tc = reader.settleTeachers();
                    for(int x = 0; x < tc.length; x++) {
                        if(tc[x].StudentID.equals(br.readLine())) {
                            derslik.OG = tc[x];
                        }
                    }
                }
                if(strLine.equals("ST:")){
                    d = 1;
                }
                if(d == 1) {
                    Reading reader = new Reading("Students.txt");
                    Student[] st = reader.settleStudents();
                    for(int x = 0; x < st.length; x++) {
                        if(st[x].StudentID.equals(strLine)) {
                            derslik.st[ösayisi] = st[x];
                            System.out.println(derslik.st[ösayisi].StudentID);
                            ösayisi++;
                        }
                    }
                } 
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return derslik;
    }
    
    @Override
    public Derslik[] hepsi() {
        Derslik[] all = new Derslik[100];
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            int countofd = 0;
            int step = 0;
            int countS = 0;
            int not = 0;
            while ((strLine = br.readLine()) != null)   {
                if(strLine.equals("Ders:") && step == 0) {
                    all[countofd] = new Derslik(br.readLine());
                    step = 1;
                }
                if(step == 1 && strLine.equals("OG:")) {
                    step = 2;
                }
                if(step == 2 && !strLine.equals("OG:")) {
                    step = 3;
                }
                if(step == 3) {
                    step = 4;
                    Reading rd = new Reading("Teachers.txt");
                    Teacher[] tc = rd.settleTeachers();
                    for(int x = 0; x < tc.length; x++) {
                        if(strLine.equals(tc[x].StudentID)) {
                            all[countofd].OG = tc[x];
                        }
                    }
                }
                if(step == 4 && strLine.equals("ST:")) {
                    step = 5;
                }
                if(step == 5 && !strLine.equals("ST:")) {
                    step = 6;
                }
                if(step == 6) {
                    if(strLine.equals("NOT:")) {
                        step = 7;
                    }
                    if(step == 6) {
                        Reading rd = new Reading("Students.txt");
                        Student[] st = rd.settleStudents();
                        for(int x = 0; x < st.length; x++) {
                            if(st[x].StudentID.equals(strLine)) {
                                all[countofd].st[countS] = st[x];
                                countS++;
                            }
                        }
                    }
                }
                if(step == 7 && !strLine.equals("NOT:")) {
                    if(strLine.equals(".")) {
                        step = 8;
                    }
                    if(step == 7) {
                        all[countofd].not[not] = strLine;
                        not++;
                    }
                }
                if(step == 8) {
                    countofd++;
                    countS = 0;
                    not = 0;
                    step = 0;
                }
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return all;
    }
    
    @Override
    public String[][] istek() {
        String[][] list = new String[this.count][2];
        int top = 0;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   {
                strLine = strLine + '+';
                String word = "";
                int tetris = 0;
                for(int z = 0; z < strLine.length(); z++) {
                    if(strLine.charAt(z) != '+') {
                        word += strLine.charAt(z);
                    }
                    if(strLine.charAt(z) == '+') {
                        list[top][tetris] = word;
                        tetris++;
                        word = "";
                    }
                }
                top++;
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return list;
    }
    
    @Override
    public Duyuru[] duyurugetir() {
        int top = 0;
        Duyuru[] duyurular = new Duyuru[6];
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            int step = 0;
            int ac = 0;
            while ((strLine = br.readLine()) != null)   {
                if(strLine.equals("Duyuru:") && step == 0) {
                    step = 1;
                }
                if(step == 1) {
                    duyurular[top] = new Duyuru();
                    duyurular[top].kimden = br.readLine();
                    step = 2;
                }
                if(step == 2 && strLine.equals("Açıklama:")) {
                    step = 3;
                }
                if(step == 3 && !strLine.equals("Açıklama:")) {
                    if(strLine.equals(".")) {
                        step = 4;
                    }
                    if(step == 3) {
                        duyurular[top].acıklama[ac] = strLine;
                        ac++;
                    }
                }
                if(step == 4) {
                    ac = 0;
                    step = 0;
                    top++;
                }
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return duyurular;
    }
    public String[][] sınav() {
        String[][] list = new String[this.count][2];
        int top = 0;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   {
                strLine = strLine + '/';
                String word = "";
                int tetris = 0;
                for(int z = 0; z < strLine.length(); z++) {
                    if(strLine.charAt(z) != '/') {
                        word += strLine.charAt(z);
                    }
                    if(strLine.charAt(z) == '/') {
                        list[top][tetris] = word;
                        tetris++;
                        word = "";
                    }
                }
                top++;
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return list;
    }
    
    public EklentiDegerleri[] yenigetir() {
        EklentiDegerleri[] ed = new EklentiDegerleri[this.count];
        int top = 0;
        try{
            FileInputStream fstream = new FileInputStream("Eklenti.txt");
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   {
                ed[top] = new EklentiDegerleri();
                strLine = strLine + '/';
                String word = "";
                int tetris = 0;
                for(int z = 0; z < strLine.length(); z++) {
                    if(strLine.charAt(z) != '/') {
                        word += strLine.charAt(z);
                    }
                    if(strLine.charAt(z) == '/' && tetris == 0) {
                        ed[top].Ders = word;
                        tetris++;
                        word = "";
                    }
                    else if(strLine.charAt(z) == '/' && tetris == 1) {
                        ed[top].Og = word;
                        tetris++;
                        word = "";
                    }
                    else if(strLine.charAt(z) == '/' && tetris == 2) {
                        ed[top].Not = word;
                        tetris++;
                        word = "";
                    }
                }
                top++;
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return ed;
    }
    
    public String[][] dersprogramıgetir() {
        String[][] list = new String[this.count][5];
        int top = 0;
        try{
            FileInputStream fstream = new FileInputStream(filename);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            while ((strLine = br.readLine()) != null)   {
                strLine = strLine + '/';
                String word = "";
                int tetris = 0;
                for(int z = 0; z < strLine.length(); z++) {
                    if(strLine.charAt(z) != '/') {
                        word += strLine.charAt(z);
                    }
                    if(strLine.charAt(z) == '/') {
                        list[top][tetris] = word;
                        tetris++;
                        word = "";
                    }
                }
                top++;
            }
        }
        catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
        return list;
    }
}


