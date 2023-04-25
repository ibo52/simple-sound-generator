/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package soundgenerator.gui.controllers;

import java.io.IOException;
import java.net.URL;
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
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Background;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
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
        
        Label contentText=new Label(
        "Create notesheets and compose.\n"
        +"Copyright © Halil Ibrahim Mut\n"
        +"This program comes with absolutely no warranty.\n"
        +"Program source: www.github.com/ibo52\n\n"
        +"          CREDITS\n"
        +"GUI: ibo52(Halil Ibrahim Mut)\n"
        +"Sound Generator: ibo52(Halil Ibrahim Mut)\n");
        
        contentText.setFont(javafx.scene.text.Font.font("Times New Roman",18));
        contentText.setWrapText(true);
        
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

}
