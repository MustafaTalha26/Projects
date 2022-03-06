/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg1306200015;

/**
 *
 * @author Mustafa
 */
abstract class User {
    String ID;

    public User(String ID) {
        this.ID = ID;
    }
    
    abstract void yazdir();
}