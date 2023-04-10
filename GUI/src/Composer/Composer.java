/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Composer;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ibrahim
 */
public class Composer {
    public File file;
    private FileWriter Writer;
    private FileReader Reader;
    private boolean append;
    
    public Composer(String path){
        this.initialize(path, false);
        
    }
    
    public Composer(String path,boolean b){
        this.initialize(path, b);
    }
    
    private void initialize(String path,boolean b){
        try{
            this.file=new File(path+".txt");

            if (file.createNewFile()) {

                System.out.println("File created:"+file.getName());
            }else{
                System.out.println("File exists:"+file.getName());
            }
        
            this.Writer=new FileWriter(file,b);
            this.Reader=new FileReader(file);
            //this.Reader=new FileReader(file);
            
        }catch(IOException ex){
            System.out.println("Error occured:");
            ex.printStackTrace();
        }
    }
    
    public void write(String s){
        try {
            this.Writer.write(s);
            this.Writer.flush();
        } catch (IOException ex) {
            System.out.println("write Error occured:");
            ex.printStackTrace();
        }
    }
    public void writeln(String s){
        this.write(s+"\n");
    }
    
    public void read(){
        try {
            this.Reader.read();
            this.Reader.close();
        } catch (IOException ex) {
            System.out.println("read Error occured:");
            ex.printStackTrace();
        }
    }
    public void close(){
        try {
            this.Writer.close();
            this.Reader.close();
        } catch (IOException ex) {
            System.out.println("close Error occured:");
            ex.printStackTrace();
        }
        
    }
    public String getPath(){
        return this.file.getAbsolutePath();
    }
    
    
    
}
