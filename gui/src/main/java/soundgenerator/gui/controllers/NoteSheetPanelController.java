/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package soundgenerator.gui.controllers;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.ResourceBundle;
import javafx.animation.TranslateTransition;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;
import javafx.util.Pair;
import soundgenerator.component.StaveCanvas;
import soundgenerator.object.Composer;
import soundgenerator.object.MusicNote;
/**
 * FXML Controller class
 *
 * @author ibrahim
 */
public class NoteSheetPanelController implements Initializable {

    @FXML
    private BorderPane noteSheetPanel;
    @FXML
    private AnchorPane leftPanel;
    @FXML
    private Button saveFileButton;
    @FXML
    private Button composeFileButton;
    @FXML
    private Label leftPanelShowLabel;
    @FXML
    private Label addStaveLabel;
    @FXML
    private BorderPane rightPanel;
    
    FXMLLoader editor;
    
    boolean slideLeftPanelToLeft;
    @FXML
    private MenuItem menuItemOpen;
    @FXML
    private MenuItem menuItemSaveAs;
    @FXML
    private MenuItem menuItemClose;
    @FXML
    private MenuItem MenuItemAbout;
    @FXML
    private MenuItem menuItemQuit;
    @FXML
    private MenuItem menuItemdefaultTheme;
    @FXML
    private MenuItem menuItemnightyBlueTheme;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {

        try {
            // TODO7
            slideLeftPanelToLeft=true;
            
            editor=new FXMLLoader(getClass().getClassLoader().getResource("soundgenerator/gui/noteEditor.fxml"));
            
            BorderPane p=(BorderPane) editor.load();
            
            rightPanel.setCenter(p);
            
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(e.hashCode());
        }
    }    


    @FXML
    private void leftPanelShowLabelClicked(MouseEvent event) {
        TranslateTransition slide=new TranslateTransition();
        slide.setDuration(javafx.util.Duration.millis(300));
        
        slide.setNode(noteSheetPanel);
        
        if (slideLeftPanelToLeft) {
        slide.setToX(-leftPanel.getPrefWidth());
        slideLeftPanelToLeft=false;
        }else{
            slide.setToX(0);
            slideLeftPanelToLeft=true;
        }
        slide.play();
        
        
    }

    @FXML
    private void addStaveLabelClicked(MouseEvent event) {
        NoteEditorController c=editor.getController();
        c.addStave();
        
    }

    @FXML
    private void saveFileButtonClicked(MouseEvent event) {
        try {

            NoteEditorController ctrl=editor.getController();
            ctrl.saveToFile();
            
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        
    }

    @FXML
    private void composeFileButton(MouseEvent event) {
        NoteEditorController ctrl=this.editor.getController();
        ctrl.composeFromFile();
    }

    @FXML
    private void menuItemSaveAsClicked(ActionEvent event) {
        try {
            NoteEditorController ctrl=editor.getController();
            ctrl.saveAs();
            
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @FXML
    private void menuItemCloseClicked(ActionEvent event) {
        
        Alert a=new Alert(AlertType.CONFIRMATION);
        a.setTitle("Quit Program");
        a.setContentText("Are you Sure To Close NoteSheet?  "
        +"Unsaved Sheets will be lost.");
        
        a.showAndWait().ifPresent(button->{
            if (button==ButtonType.OK) {

                try {

                slideLeftPanelToLeft=true;

                editor=new FXMLLoader(getClass().getClassLoader().getResource("soundgenerator/gui/noteEditor.fxml"));

                BorderPane p=(BorderPane) editor.load();

                rightPanel.setCenter(p);

                } catch (IOException e) {
                    e.printStackTrace();
                    System.exit(e.hashCode());
                }

            }
        });
    }

    @FXML
    private void menuItemQuitClicked(ActionEvent event) {
        
        Alert approveQuit=new Alert(AlertType.CONFIRMATION);
        approveQuit.setTitle("Quit Program");
        approveQuit.setContentText("Are you Sure To Quit?  "
        +"Unsaved Sheets will be lost.");
        approveQuit.showAndWait().ifPresent(button->{
        if (button==ButtonType.OK) {
            javafx.stage.Stage stage=(javafx.stage.Stage)this.noteSheetPanel.getScene().getWindow();
            stage.close();
        }/*
        else if (button==ButtonType.CANCEL) {
        }*/
        });
    }

    @FXML
    private void MenuItemAboutClicked(ActionEvent event) {
        Alert aboutDialog=new Alert(AlertType.INFORMATION);
        aboutDialog.setTitle("About Sound Composer");
        aboutDialog.setHeaderText("Simple Sound Composer");
        aboutDialog.getDialogPane().setGraphic(new javafx.scene.image.ImageView(new javafx.scene.image.Image(this.getClass().getClassLoader().getResourceAsStream("soundgenerator/gui/icons/logo.png"),100,100,false,false) ));
        //System.out.println("abıut id:"+aboutDialog.getDialogPane().toString());
        TextArea contentText=new TextArea(
        "Create notesheets and compose.\n"
        +"Copyright © Halil Ibrahim Mut\n"
        +"This program comes with absolutely no warranty.\n"
        +"Program source: github.com/ibo52/simple-sound-generator\n\n"
        +"          CREDITS\n"
        +"GUI Model: ibo52(Halil Ibrahim Mut)\n"
        +"GUI View: ibo52(Halil Ibrahim Mut)\n"
        +"GUI Controller: ibo52(Halil Ibrahim Mut)\n"
        +"Sound Generator: ibo52(Halil Ibrahim Mut)\n");
        
        contentText.setFont(javafx.scene.text.Font.font("Times New Roman",18));
        contentText.setWrapText(true);
        contentText.setEditable(false);
        
        aboutDialog.getDialogPane().setContent(contentText);
        aboutDialog.setResizable(true);
        aboutDialog.showAndWait();
    }

    @FXML
    private void menuItemdefaultThemeClicked(ActionEvent event) {
        javafx.scene.Scene scene=this.noteSheetPanel.getScene();
        scene.getStylesheets().clear();
        scene.getStylesheets().add(this.getClass().getClassLoader().getResource("soundgenerator/gui/stylesheets/default-application.css").toExternalForm());
    }

    @FXML
    private void menuItemnightyBlueThemeClicked(ActionEvent event) {
        javafx.scene.Scene scene=this.noteSheetPanel.getScene();
        scene.getStylesheets().clear();
        scene.getStylesheets().add(this.getClass().getClassLoader().getResource("soundgenerator/gui/stylesheets/dark-mode.css").toExternalForm());

    }

    @FXML
    private void menuItemOpenClicked(ActionEvent event) {
        
        FileChooser fc=new FileChooser();
        fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("Text files","*.txt"));
        File openDirectory=new File(new File("").getAbsolutePath()+"/Note Sheets");
        
        fc.setInitialDirectory(openDirectory );
        
        File selection=fc.showOpenDialog(null);
        
        if (selection!=null) {
            //process opened file
            Composer c=new Composer(selection.getPath(),true);
            
            //buffer the file
            List<Pair<String,Float>> buffer=c.readToBuffer();
            
            List<Pair<String,Integer>> noteMap=new ArrayList<Pair<String,Integer>>();
            int octave=c.OCTAVE_OF_READ_FILE;
            
            for (int i = 0; i < 11; i++) {
                String[] n={"b","c","d","e","f","g","a","b","c","d","e"};
                if (i<6) {
                    
                    noteMap.add( new Pair(  n[i]+Integer.toString(octave), i  ) );
                }else{
                    noteMap.add( new Pair(  n[i]+Integer.toString(octave+1), i  ) );
                }   
            }
            
            //clean editor, insert stave(s) from new file
            NoteEditorController editorCtrl=editor.getController();
            editorCtrl.removeAllStaves();

            //sketch graph of staves according to buffer context
            for (int i = 0; !buffer.isEmpty(); i++) {
                
                //stavePanel content
                var fxml=new FXMLLoader(getClass().getClassLoader().getResource("soundgenerator/gui/stavePanel.fxml"));
                Node stave=null;
                StavePanelController staveCtrl=null;
                
                try {
                    stave = fxml.load();
                    staveCtrl=fxml.getController();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
                
                StaveCanvas canvas=new StaveCanvas();
                
                canvas.widthProperty().bind(staveCtrl.getCanvasPane().widthProperty());
                canvas.heightProperty().bind(staveCtrl.getCanvasPane().heightProperty());

                MusicNote[] noteList=new MusicNote[canvas.NOTE_ON_A_ROW];
                
                //every StaveCanvas includes [canvas.NOTE_ON_A_ROW] notes. 
                for (int j = 0; j <noteList.length; j++) {
                    Pair pair=buffer.get(0); //pop element 
                    buffer.remove(pair);     //from buffer
                    
                    String note=(String)pair.getKey();
                    float duration=(float)pair.getValue();
                    
                    //graphics coordinates of music note over canvas
                    double width=600;//canvas.getWidth();
                    double height=100;canvas.getHeight();
                    double XSnapOffset=width/canvas.NOTE_ON_A_ROW;
                    double YSnapOffset=height/canvas.NOTE_ON_A_COL;

                    int drawX=j;
                    int drawY=-1;
                    
                    for (Pair p:noteMap) {
                        if (note.equals(p.getKey())) {
                            drawY=canvas.NOTE_ON_A_COL-1-(int)p.getValue();
                            break;
                        }
                    }

                    MusicNote n=new MusicNote(drawX,drawY,XSnapOffset,YSnapOffset);
                    
                    if (drawY==-1) {
                        n.setTone(-1);
                    }
                    n.setDuration(duration);
                    n.setTone(c.OCTAVE_OF_READ_FILE);
                    noteList[j]=n;
                    
                }
                canvas.noteList=noteList;
                
                //********************
                stave.setUserData(fxml);   //concat controller to node
                                             //so we can access from it

                staveCtrl.setCanvas(canvas);
             
                editorCtrl=this.editor.getController();
                VBox staveContentPanel=(VBox)editorCtrl.getStaveContentPanel();
                staveContentPanel.getChildren().add(stave);
            }
            editorCtrl.setSaveFile(selection);//concat path to controller savePath
        }
    }

}
