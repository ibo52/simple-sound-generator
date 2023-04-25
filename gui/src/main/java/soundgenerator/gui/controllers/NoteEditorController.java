/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package soundgenerator.gui.controllers;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ResourceBundle;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.control.Alert;

import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import soundgenerator.object.Composer;
/**
 * FXML Controller class
 *
 * @author ibrahim
 */
public class NoteEditorController implements Initializable {


    @FXML
    private BorderPane HeaderPanel;
    @FXML
    private Label ComposerNameLabel;
    @FXML
    private Label MusicNameLabel;
    @FXML
    private VBox staveContentPanel;
    @FXML
    public BorderPane rootPane;
    /**
     * Initializes the controller class.
     */
    TextField composerNameEditField;
    TextField musicNameEditField;
    @FXML
    private BorderPane stavePanel;
    
    private File SAVE_FILE;
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        try {
            // TODO
            initComponents2();
            
            this.addStave();
            
        } catch (Exception ex) {
            ex.printStackTrace();
            System.exit(ex.hashCode());
        }
        
    }    
    private void initComponents2(){
        
        musicNameEditField=new TextField();
        composerNameEditField=new TextField();
        
        
        musicNameEditField.setFont(this.MusicNameLabel.getFont());
        
        musicNameEditField.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent evt) {

                if(evt.getCode()==KeyCode.ENTER){
                    
                    HeaderPanel.getChildren().remove(musicNameEditField); 
                    MusicNameLabel.setText(musicNameEditField.getText());
                    HeaderPanel.setTop(MusicNameLabel);

                }
            }
            
        });
        
        this.composerNameEditField.setFont(this.MusicNameLabel.getFont());
        this.composerNameEditField.setOnKeyPressed(new EventHandler<KeyEvent>(){
            @Override
            public void handle(KeyEvent evt) {

                if(evt.getCode()==KeyCode.ENTER){
                    
                    HeaderPanel.getChildren().remove(composerNameEditField); 
                    ComposerNameLabel.setText(composerNameEditField.getText());
                    HeaderPanel.setBottom(ComposerNameLabel);

                }
            }
            
        });
    }
    
    
    @FXML
    private void MusicNameLabelMouseClicked(MouseEvent event) {
        this.musicNameEditField.setText(this.MusicNameLabel.getText());
        
        this.HeaderPanel.getChildren().remove(this.MusicNameLabel);        
        this.HeaderPanel.setCenter(this.musicNameEditField);
        
        System.out.println("stvContent:"+this.staveContentPanel.getWidth()+"x"+this.staveContentPanel.getHeight());

        System.out.println("stave"+this.stavePanel.getWidth()+"x"+this.stavePanel.getHeight());
    }

    @FXML
    private void composerNameLabelMouseClicked(MouseEvent event) {
        this.composerNameEditField.setText(this.ComposerNameLabel.getText());
        
        this.HeaderPanel.getChildren().remove(this.ComposerNameLabel);        
        this.HeaderPanel.setBottom(this.composerNameEditField);
    }
    
    public void addStave(){
        
        try {
            // TODO
            
            var fxml=new FXMLLoader(getClass().getClassLoader().getResource("soundgenerator/gui/stavePanel.fxml"));
            Node stave=fxml.load();
            
            stave.setUserData(fxml);//concat controller to node
                                                      //so we can access from it
            
            staveContentPanel.getChildren().add(stave);
            
        } catch (Exception ex) {
            ex.printStackTrace();
            System.exit(ex.hashCode());
        }
    }
    
    public void saveToFile(){
        
        if (this.SAVE_FILE==null) {
            this.saveAs();
        }else{
            
            Composer txtFile=new Composer(this.SAVE_FILE.getPath());
            
            this.staveContentPanel.getChildren().forEach(child->{

                 FXMLLoader fxml = (FXMLLoader) child.getUserData();
                 
                 StavePanelController ctrl=fxml.getController();

                 for (int i = 0; i < ctrl.getCanvas().noteList.length; i++) {

                    txtFile.writeln( ctrl.getCanvas().noteList[i].getTone() );
                }
            });
        }
        
    }
    
    public void saveAs(){
        /*to save musicsheet as a text file*/
        
        FileChooser fc=new FileChooser();
        fc.getExtensionFilters().add(new ExtensionFilter("Text files","*.txt"));
        File saveDirectory;
        String saveName;
        
        if (this.SAVE_FILE==null) {
            saveDirectory=new File(this.getClass().getClassLoader().getResource("").getPath());
            saveName=this.MusicNameLabel.getText();
        }else{
            saveDirectory=new File(this.SAVE_FILE.getParent());
            saveName=this.SAVE_FILE.getName();
        }
        
        fc.setInitialDirectory(saveDirectory );
        fc.setInitialFileName(saveName );
        
        File selection=fc.showSaveDialog(null);
        
        if (selection!=null) {

            String extension=fc.getSelectedExtensionFilter().getExtensions().get(0).substring(1);
            selection=new File(selection.getPath()+extension);
            
            System.out.println("text file save dir:"+selection.getPath());
            System.out.println("name:"+selection.getName());
            
            this.SAVE_FILE=selection;
            
            Composer txtFile=new Composer(this.SAVE_FILE.getPath());
            
            this.staveContentPanel.getChildren().forEach(child->{

                 FXMLLoader fxml = (FXMLLoader) child.getUserData();
                 
                 StavePanelController ctrl=fxml.getController();

                 for (int i = 0; i < ctrl.getCanvas().noteList.length; i++) {

                    txtFile.writeln( ctrl.getCanvas().noteList[i].getTone() );
                }
            });
            txtFile.close();
            System.out.println("saved..");

        }
    }
    
    public void composeFromFile(){
        var inputFile=this.SAVE_FILE;
        
        String saveName;
        File composeDirectory;
        
        if (inputFile==null) {
            Alert alt=new Alert(Alert.AlertType.WARNING);
            alt.setTitle("Compose button: No file");
            alt.setContentText("there is no saved text file to compose. "
            +"Please select or create by \"save\" button");
            alt.showAndWait();
        }else{
            
            Composer c=new Composer(inputFile.getPath(),true);
            c.composeMusic(inputFile.getName().substring(0, inputFile.getName().indexOf(".txt")) );
        }
        
    }
    
    
}
