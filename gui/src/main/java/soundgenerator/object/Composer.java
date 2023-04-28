/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package soundgenerator.object;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextArea;
import javafx.util.Pair;

/**
 *
 * @author ibrahim
 */
public class Composer {
    public File file;
    private FileWriter Writer;
    private BufferedReader Reader;

    private boolean append;
    public int OCTAVE_OF_READ_FILE;
    
    public Composer(String path){
        this.initialize(path, false);
        
    }
    
    public Composer(String path,boolean readMode){
        this.initialize(path, readMode);
    }
    
    private void initialize(String path,boolean b){
        OCTAVE_OF_READ_FILE=1;
        
        try{
            this.file=new File(path);

            if (file.createNewFile()) {

                System.out.println("File created:"+file.getName());
            }else{
                System.out.println("File exists:"+file.getName());
            }
        
            this.Writer=new FileWriter(file,b);
            this.Reader=new BufferedReader(new FileReader(file));
            
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
    
    public List<Pair<String,Float>> readToBuffer(){
        
        String line=null;
        List<Pair<String,Float>> noteMap = null;
        try {
            noteMap=new ArrayList<Pair<String,Float>>();
            
            //read octave info first
            line=this.Reader.readLine();
            OCTAVE_OF_READ_FILE=Integer.valueOf(line.replaceAll(";OCTAVE:", ""));
            
            while( (line=this.Reader.readLine())!=null ){
                String[] split=line.split(":");
                
                noteMap.add(  new Pair(split[0], Float.valueOf(split[1]) )  );
                
            }
        } catch (IOException ex) {
            System.out.println("read Error occured:");
            ex.printStackTrace();
        }
        
        return noteMap;
    }
    
    public void composeMusic(String musicName){
        //open music.txt file to compose
        
        
        Runtime rt=Runtime.getRuntime();
        
        String exec_path="/home/ibrahim/Desktop/TLauncher-2.83/kırmançee/simple-sound-generator/sound_generator/bin/generator";
        
        File mscPath=new File(new File("").getAbsolutePath()+"/Composed Musics/");
        //if path does not exist, create one
        if (!mscPath.exists()) {
            if(!mscPath.mkdir()){
                System.out.println("path does not exists");
                System.out.println("and make directory process did not work");
                System.out.println("try manually create directory");
                System.out.println("Exiting.");
                System.exit(0);
            }
        }
        
        File out_=new File(mscPath.getAbsolutePath()+"/"+musicName);
        try {
            Process p=rt.exec(new String[]
            {exec_path,
            "-i",this.file.getAbsolutePath(),
            "-o",out_.getAbsolutePath()});
            
            BufferedReader br=new BufferedReader(new InputStreamReader(p.getInputStream()));
            
            
            Alert alert=new Alert(AlertType.INFORMATION);
            alert.getDialogPane().setGraphic(new javafx.scene.image.ImageView(new javafx.scene.image.Image(this.getClass().getClassLoader().getResourceAsStream("soundgenerator/gui/icons/logo.png"),100,100,false,false) ));
            alert.setTitle("exec sound generator");
            alert.setHeaderText("Process outputs");
            
            TextArea contentText=new TextArea("");
            contentText.setWrapText(true);
            contentText.setEditable(false);
            
            alert.getDialogPane().setContent(contentText);
            alert.setResizable(true);
            
            
            String terminalOutput;
            
            while( (terminalOutput=br.readLine())!=null  ){
                contentText.appendText(terminalOutput+"\n");
            }
            
            alert.showAndWait();
            
        
        } catch (IOException ex) {
            Alert alert=new Alert(AlertType.ERROR);
            alert.setTitle("Exception occured when exec sound generator");
            alert.setContentText(ex.getMessage());
            alert.showAndWait();
            
            ex.printStackTrace();
        }
    }
}
