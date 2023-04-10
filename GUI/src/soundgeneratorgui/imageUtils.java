/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package soundgeneratorgui;

import java.awt.Dimension;
import java.awt.Image;
import javax.swing.ImageIcon;

/**
 *
 * @author ibrahim
 */
public class imageUtils {
    
    public static ImageIcon resize(ImageIcon img,Dimension size){
        Image temp=img.getImage().getScaledInstance((int)size.getWidth(),
                (int)size.getHeight(), java.awt.Image.SCALE_SMOOTH);
        
        return new ImageIcon(temp);
    }
    
    public static ImageIcon resize(Image img,Dimension size){
        
        Image temp=img.getScaledInstance((int)size.getWidth(),
                (int)size.getHeight(), java.awt.Image.SCALE_SMOOTH);
        
        return new ImageIcon(temp);
    }
    
}
