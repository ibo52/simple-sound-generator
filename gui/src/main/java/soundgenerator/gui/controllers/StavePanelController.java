/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package soundgenerator.gui.controllers;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.beans.InvalidationListener;
import javafx.beans.Observable;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Point2D;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;

import javafx.scene.control.Button;
import javafx.scene.effect.Light.Point;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
/**
 * FXML Controller class
 *
 * @author ibrahim
 */
import soundgenerator.object.MusicNote;
import soundgenerator.component.StaveCanvas;
public class StavePanelController implements Initializable {


    @FXML
    private BorderPane rootPane;
    
    private StaveCanvas canvas2;
    /**
     * Initializes the controller class.
     */
    
    int NOTE_ON_A_ROW;
    int NOTE_ON_A_COL;
    MusicNote[] noteList;
    Point DRAW_ROW_COL;
    int[] snapArea;
    @FXML
    private BorderPane canvasPane;
    @FXML
    private Button deleteStaveButton;
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        NOTE_ON_A_ROW=36;
        NOTE_ON_A_COL=11;
        DRAW_ROW_COL=new Point(); //x:order of note, y:tone of note
        DRAW_ROW_COL.setX(0);DRAW_ROW_COL.setY(0);
        this.noteList=new MusicNote[NOTE_ON_A_ROW];
        for (int i = 0; i < this.noteList.length; i++) {
            this.noteList[i]=new MusicNote();
        }
        
        snapArea=new int[4];
        
        
        canvas2=new StaveCanvas();
        canvas2.widthProperty().bind(canvasPane.widthProperty());
        canvas2.heightProperty().bind(canvasPane.heightProperty());
        canvasPane.setCenter(canvas2);
    }
    
    public StaveCanvas getCanvas(){
        return this.canvas2;
    }

    @FXML
    private void deleteStaveButtonClicked(MouseEvent event) {
        VBox p=(VBox)this.rootPane.getParent();
        p.getChildren().remove(this.rootPane);
        
    }
    
}
