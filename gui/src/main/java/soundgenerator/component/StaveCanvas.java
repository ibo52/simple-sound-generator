/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package soundgenerator.component;

import javafx.beans.value.ChangeListener;
import javafx.event.EventHandler;
import javafx.geometry.Point2D;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.effect.Light;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import soundgenerator.object.MusicNote;

/**
 *
 * @author ibrahim
 */
public class StaveCanvas extends Canvas {
    
    public int NOTE_ON_A_COL;
    public int NOTE_ON_A_ROW;
    public MusicNote[] noteList;
    Point2D DRAW_ROW_COL;
    int[] snapArea;
    
    public StaveCanvas() {
        
            NOTE_ON_A_ROW=36;
            NOTE_ON_A_COL=11;
            DRAW_ROW_COL=new Point2D(0,0); //x:order of note, y:tone of note
            this.noteList=new MusicNote[NOTE_ON_A_ROW];
            for (int i = 0; i < noteList.length; i++) {
                noteList[i]=new MusicNote();
            }
            snapArea=new int[]{0,0,1,1};
            //--------------------------------
            // Redraw canvas when size changes.
            ChangeListener<Number> resizeListener = (observable, oldValue, newValue) ->{
                var pen=this.getGraphicsContext2D();
                int width=(int)getWidth();
                int height=(int)getHeight();
                int XSnapOffset=(width/NOTE_ON_A_ROW);
                int YSnapOffset=(height/NOTE_ON_A_COL);
                
                pen.clearRect(0, 0, this.getWidth(), this.getHeight());
                for (MusicNote note:this.noteList) {
                    note.setWidth(XSnapOffset);
                    note.setHeight(YSnapOffset);
                }
                paintComponent();
            };
            widthProperty().addListener(resizeListener);
            
            heightProperty().addListener(resizeListener);
            
            this.addEventHandler(MouseEvent.MOUSE_MOVED, eh->{
                Point2D pos=new Point2D(eh.getX(),eh.getY());
                paintComponent();
                drawSnapArea(pos);
            });
            
            this.addEventHandler(MouseEvent.MOUSE_CLICKED, eh->{
                
                if (eh.getButton()==MouseButton.PRIMARY) {
                    
                
                    Point2D pos=new Point2D(eh.getX(),eh.getY());
                    insertNote();
                    
                }else{
                    deleteNote();
                }
                
                paintComponent();
            });
    }
    
        @Override
    public boolean isResizable() {
        return true;
    }
 
    @Override
    public double prefWidth(double height) {
        return getWidth();
    }

    @Override
    public double prefHeight(double width) {
        return getHeight();
    }
    //------------------------------------------
    public void repaint(){
        this.paintComponent();
    }
    private void paintComponent() {
        
        double width = getWidth();
        double height = getHeight();

        var pen=this.getGraphicsContext2D();
        pen.setFill(javafx.scene.paint.Color.RED);
        //draw stave lines
        for (int i = 1; i < 6; i++) {

            pen.strokeLine(0, height*i/((NOTE_ON_A_COL/2)+1), width, height*i/((NOTE_ON_A_COL/2)+1));
        }

        drawNotes(pen);
    }

    public void drawSnapArea(Point2D mousePos){

        int width=(int)getWidth();
        int height=(int)getHeight();

        var pen=getGraphicsContext2D();

        pen.setFill(javafx.scene.paint.Color.RED);

        int XSnapOffset=width/NOTE_ON_A_ROW;
        int YSnapOffset=height/NOTE_ON_A_COL;

        int drawX=(int) (mousePos.getX()/XSnapOffset);
        int drawY=(int) (mousePos.getY()/YSnapOffset);

        DRAW_ROW_COL=new Point2D(drawX,drawY);
        
        drawX*=XSnapOffset;
        drawY*=YSnapOffset;

        if (  snapArea[0]!=drawX || snapArea[1]!=drawY ) {
            // The square is moving, repaint background 
            // over the old square location. 
            pen.clearRect(snapArea[0]-1, snapArea[1]-1, snapArea[2]+2, snapArea[3]+2);

            // Update coordinates.
            snapArea=new int[]{drawX,drawY,XSnapOffset,YSnapOffset};

        }
        // Repaint the square at the new location.
        pen.strokeRect(drawX, drawY, XSnapOffset, YSnapOffset);
    }

    private void insertNote(){
        MusicNote n=new MusicNote(snapArea[0]/snapArea[2],
                snapArea[1]/snapArea[3],
                snapArea[2], snapArea[3]);

        int clean_h=(int)getHeight();

        GraphicsContext pen=getGraphicsContext2D();
        pen.clearRect(snapArea[0], 0, snapArea[2]+1, clean_h+1);

        n.setTone(NOTE_ON_A_COL-1 - (int) DRAW_ROW_COL.getY());

        noteList[(int)DRAW_ROW_COL.getX()]=n;
    }
        
    public void deleteNote(){


        MusicNote n=new MusicNote(0,0,0,0);
        
        int clean_h=(int)getHeight();

        GraphicsContext pen=getGraphicsContext2D();
        pen.clearRect(snapArea[0], 0, snapArea[2]+1, clean_h+1);
        
        noteList[(int)DRAW_ROW_COL.getX()]=n;
        
    }

    private void drawNotes(GraphicsContext g){
        for (int i = 0; i < this.noteList.length; i++) {
            
            if (this.noteList[i].tone==-1) {
                continue;
            }
            this.noteList[i].paintNote(g);
        }
    }   
}
