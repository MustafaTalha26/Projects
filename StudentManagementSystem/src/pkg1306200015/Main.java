/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pkg1306200015;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 *
 * @author Mustafa
 */
public class Main {

    public static void main(String[] args) {
        new LoginScreen();
        Reading rd = new Reading("DersKayıtİstekleri.txt");
        String[][] s = rd.istek();
        System.out.println(s[0][1]);
    }
}
