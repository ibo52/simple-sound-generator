/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package soundgenerator.object;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

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
            this.file=new File(path);

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
    
    public void composeMusic(String musicName){
        //open music.txt file to compose
        
        
        Runtime rt=Runtime.getRuntime();
        
        String exec_path="/home/ibrahim/Desktop/TLauncher-2.83/kırmançee/simple-sound-generator/sound_generator/bin/generator";
        
        
        try {
            Process p=rt.exec(exec_path+" -i "
                    +this.file.getCanonicalPath()+" -o "+musicName);
            java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(p.getInputStream()));
            
            
            String threadTerminalOut;
            
            System.out.println("Run sound_generator.cpp program\n-------------------------");
            while( (threadTerminalOut=br.readLine())!=null  ){
                System.out.println(threadTerminalOut);
            }System.out.println("-------------------------");
        
        } catch (IOException ex) {
            Alert alert=new Alert(AlertType.ERROR);
            alert.setTitle("Exception occured when exec sound generator");
            alert.setContentText(ex.getMessage());
            alert.showAndWait();
            
            ex.printStackTrace();
        }
    }
    
    
    
}
