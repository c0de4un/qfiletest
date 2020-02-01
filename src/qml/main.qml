import QtQuick 2.12
import QtQuick.Window 2.12 // ApplicationWindow
import QtQuick.Controls 2.12 // SplitView
import QtQuick.Dialogs 1.2 // Dialog

// Main Window
ApplicationWindow {

    // ------------------------------------------------------------------------

    // ID
    id: mainWindow_id
    // Visibility
    visible: true
    // Width
    width: 640
    // Height
    height: 480
    // Title
    title: "QFileTest"
    // Name (used due to id can't be used as string).
    property string name: "mainWindow"

    // ------------------------------------------------------------------------

    /**
      * Called to show file-open dialog.
    **/
    function showFileOpenDialog() {

        if ( !openFileDialog_id.visible )
            openFileDialog_id.open();

    }

    /**
      * Called when file selected.
      *
      * @param fileUrl - file path.
    **/
    function openFile( fileUrl ) {

        // Show file location using text-field.

        //

    }

    // ------------------------------------------------------------------------

    // Menu [QtQuickControls 2.5]
    menuBar: MenuBar {

        // File
        Menu {

            // Title
            title: qsTr("File")

            // Open
            MenuItem {
                // Text
                text: qsTr("Open")
                //Action
                onTriggered: showFileOpenDialog();
            }
            // Quit
            MenuItem {
                // Text
                text: qsTr("Quit")
                // Action
                onTriggered: Qt.quit();
            } /// Quit

        } /// File

    }
    /// Menu

    // File-Path TextBox
    TextEdit {
        id: filePath_txtBox_id
        x: 6
        y: 10
        width: 554
        height: 40
        text: qsTr("Text Edit")
        font.family: "Courier New"
        font.pixelSize: 12
    } /// File-Path TextBox

    // Browse File
    Button {
        id: browseFile_btn_id
        x: 581
        y: 10
        width: 45
        height: 40
        text: qsTr("...")
        font.bold: true
        font.family: "Courier New"
        font.pointSize: 12
    } /// Browse File

    // Check Result.
    Text {
        id: result_txtbox_id
        x: 6
        y: 64
        width: 464
        height: 175
        text: qsTr("Result")
        font.pixelSize: 12
    } /// Check Result.

    // Check Button
    Button {
        id: check_btn_id
        x: 486
        y: 117
        text: qsTr("Check")
    } /// Check Button

    // Algorithms-ComboBox
    ComboBox {
        // ID
        id: algorithms_cb_id
        // Location
        x: 486
        y: 64
        // Index
        currentIndex: 0
        // Data
        model: ListModel {
            id: algorithms_cb_model_id
            ListElement { text: "CRC" }
        }
    } /// Algorithm-ComboBox

    // Open FileDialog
    FileDialog {

        // ID
        id: openFileDialog_id
        // Title
        title: qsTr("Please select the file")
        // Default Path
        folder: shortcuts.home
        // Filters
        nameFilters: [ "RSS (*.rss *.xml)", "Text (*.txt *.doc *.docx *odt)", "Images (*.jpg *.png *.gif *.bmp)", "Video (*.avi *.mp4 *.mkv)", "Audio (*.mp3 *.mp4 *.ac3 *.wav *.flac)", "Data (*.xls *.xml *.dat *.bat)", "Application (*.dll *.o *.lib *.exe *.sh)", "All Files (*)" ]
        // Modality
        modality: Qt.Dialog
        // Visibility
        visible: false
        // Multi-Selection
        selectMultiple: false
        // Select Exisitin
        selectExisting: true
        // File-Only
        selectFolder: false
        // OnAccepted
        onAccepted: openFile( openFileDialog_id.fileUrl )
        // OnRejected
        //onRejected: openFileDialog_id.close( )

    } /// Open FileDialog

    // ------------------------------------------------------------------------

} /// Main Window
