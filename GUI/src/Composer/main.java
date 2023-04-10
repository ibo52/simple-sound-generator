/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Composer;

/**
 *
 * @author ibrahim
 */
public class main {
    
    public static void main(String args[]){
        System.out.println("deneme");
        
        Composer c=new Composer("deneme");
        System.out.println(c.file.getAbsoluteFile());
        System.out.println(c.file.getAbsolutePath());
        /*
        c.writeln("deneme kontrol");
        c.writeln("sersera serçave");
        */
        c.close();
        System.out.println("--------------------");
        
        
        
    }
    
}
