module soundgenerator.gui {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.base;

    opens soundgenerator.gui to javafx.fxml;
    opens soundgenerator.gui.controllers to javafx.fxml;
    exports soundgenerator.gui;
}
