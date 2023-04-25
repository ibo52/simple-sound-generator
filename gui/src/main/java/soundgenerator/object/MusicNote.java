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
    private int xPos;
    private int yPos;
    private int width;
    private int height;
    
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

    public int getX(){
        return xPos;
    }

    public void setY(int yPos){
        this.yPos = yPos;
    }

    public int getY(){
        return yPos;
    }

    public int getWidth(){
        return width;
    } 

    public int getHeight(){
        return height;
    }
    
    public void setTone(int t){
        this.tone=t;
    }
    public String getTone(){
        String[] map={"b","c","d","e","f","g","a","b","c","d","e"};

        String tone="";
        
        if (this.tone>0 && this.tone<8) {
            tone=String.valueOf(this.octave+1);
        }else if (this.tone==0) {
            tone=String.valueOf(this.octave);
        }
        else if (this.tone>=8) {
            tone=String.valueOf(this.octave+2);
        }else if(this.tone==-1){
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
        g.fillRect(xPos,yPos,width,height);  
        
        g.strokeLine(xPos+width, yPos, xPos+width, yPos-20);
    }
    
}
