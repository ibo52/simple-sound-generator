package soundgenerator.gui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import javafx.scene.image.Image;

/**
 * JavaFX App
 */
public class App extends Application {

    private static Scene scene;

    @Override
    public void start(Stage stage) throws IOException {
        try{
            Parent root=loadFXML("noteSheetPanel");
            
        scene = new Scene(root, 960, 540);
        
        scene.getStylesheets().add(this.getClass().getResource("stylesheets/default-application.css").toExternalForm());
        //scene.getStylesheets().add(this.getClass().getResource("stylesheets/dark-mode.css").toExternalForm());
        stage.setScene(scene);
        stage.getIcons().add( new Image(this.getClass().getResourceAsStream("icons/logo.png")) );
        
        stage.show();

        }catch(Exception e){
            System.out.println("Error :"+e.getCause());
            e.printStackTrace();System.exit(e.hashCode());
        }
    }

    static void setRoot(String fxml) throws IOException {
        scene.setRoot(loadFXML(fxml));
    }

    private static Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }

    public static void main(String[] args) {
        launch();
    }

}