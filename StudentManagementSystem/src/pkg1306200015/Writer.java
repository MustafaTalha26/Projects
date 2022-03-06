/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

import java.io.FileWriter;
import java.io.PrintWriter;

/**
 *
 * @author Mustafa
 */

interface writeactions {
   void Write(String text);
}
public class Writer implements writeactions{
    String file;
    Writer(String file) {
        this.file = file;
    }
    
    @Override
    public void Write(String text) {
        try {
            FileWriter fw = new FileWriter(file,true);
            PrintWriter out = new PrintWriter(fw);
            out.println(text);
            out.close();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
