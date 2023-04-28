/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package soundgenerator.object;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

/**
 *
 * @author ibrahim
 */
public class MusicNote {
    private double xPos;
    private double yPos;
    private double width;
    private double height;
    
    public int tone;
    public float duration;
    
    public short octave;
    
    public MusicNote(){
        xPos = 0;
        yPos = 0;
        width = 20;
        height = 40;
        
        this.duration=0.5f;
        this.tone=-1;
        this.octave=1;
    }
    
    public MusicNote(int x, int y, int w, int h){
        xPos = x;
        yPos = y;
        width = w;
        height = h;
        
        this.duration=0.5f;
        this.tone=-1;
        this.octave=1;
    }
    public MusicNote(int x, int y, double w, double h){
        xPos = x;
        yPos = y;
        width = w;
        height = h;
        
        this.duration=0.5f;
        this.tone=-1;
        this.octave=1;
    }
    public MusicNote(int x, int y, int w, int h,float duration, short octave){
        xPos = x;
        yPos = y;
        width = w;
        height = h;
        
        this.tone=-1;
        this.duration=duration;
        this.octave=octave;
    }

    public void setX(int xPos){ 
        this.xPos = xPos;
    }

    public double getX(){
        return xPos;
    }

    public void setY(int yPos){
        this.yPos = yPos;
    }

    public double getY(){
        return yPos;
    }

    public double getWidth(){
        return width;
    }
    public void setWidth(double w){
        this.width=w;
    }

    public double getHeight(){
        return height;
    }
    public void setHeight(double h){
        this.height=h;
    }
    
    public void setTone(int t){
        this.tone=t;
    }
    public void setDuration(float t){
        this.duration=t;
    }
    public String getTone(){
        String[] map={"b","c","d","e","f","g","a","b","c","d","e"};

        String tone="";
        
        if (this.tone>=0 && this.tone<6) {
            tone=String.valueOf(this.octave);
        }else if (this.tone>=6) {
            tone=String.valueOf(this.octave+1);
        }
        else if(this.tone==-1){
            tone=".1";
        }
        if (this.tone>=0 && this.tone<=10) {
            tone=map[this.tone]+tone;
        }
        
        return tone+":"+String.valueOf(this.duration);
        
    }
    public void set(int x , int y, int w, int h){
        this.xPos=x;
        this.yPos=y;
        this.width=w;
        this.height=h;
    }

    public void paintNote(GraphicsContext g){
        g.setFill(Color.BLUE);
        
        double xRelPos=xPos*width;
        double yRelPos=yPos*height;
        g.fillRect(xRelPos,yRelPos,width,height);
        g.strokeLine(xRelPos+width, yRelPos, xRelPos+width, yRelPos-height);
    }
    
}
