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
    @FXML
    private BorderPane canvasPane;
    @FXML
    private Button deleteStaveButton;
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        canvas2=new StaveCanvas();
        canvas2.widthProperty().bind(canvasPane.widthProperty());
        canvas2.heightProperty().bind(canvasPane.heightProperty());
        
        canvasPane.setCenter(canvas2);
        
    }
    public void setCanvas(StaveCanvas canvas){
        this.canvas2=canvas;
        canvas2.widthProperty().bind(canvasPane.widthProperty());
        canvas2.heightProperty().bind(canvasPane.heightProperty());
        canvasPane.setCenter(canvas2);
    }
    
    public StaveCanvas getCanvas(){
        return this.canvas2;
    }
    public BorderPane getCanvasPane(){
        return this.canvasPane;
    }
    public BorderPane getRootPane(){
        return this.rootPane;
    }

    @FXML
    private void deleteStaveButtonClicked(MouseEvent event) {
        VBox p=(VBox)this.rootPane.getParent();
        p.getChildren().remove(this.rootPane);
        
    }
    
}
