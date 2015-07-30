# QtPalettor
QtPalettor makes it possible to custimize the color palette for existing Qt5 themes and change the overall look, without having to fine-tune every little fine detail which Qt style sheets quickly requires you to do.

### Instalation
Compile by running:

    qmake && make
    
Manual installation is required for now. The resulting libQtPalettor.dll/so needs to be placed in your Qt installation plugin folder, more specifically "[QTDIR]/plugins/style/".
Once installed the style is avaliable under the name "QtPalettor" (case-insensitive). See your desktop enviroment for how to change the default Qt5 theme, otherwise if it is not managed by your DE you can specify it by setting the enviroment variable "QT_STYLE_OVERRIDE" to "QtPalettor".

### Configuration
By default the theme will look exactly like the "Fusion" theme. To change the apperance you need to edit the configuration by hand. This depends on your platform, but on Linux this is done by editing the file "$HOME/.config/spillerrec/QtPalettor.conf" which is in a INI like format. (Create it if it does not exist.)

A very simple configuration could look like the following:

    theme = Fusion
    
    [Active]
    Text = #FFF
    ButtonText = #ABABAB
    
    [Disabled]
    Text = #AAA

The theme which will have its colors modified is specified by the key "theme".
Three groups of colors exists, "Active" for the normal colors, "Inactive" which is used in certain cases when a different widget is active, and "Disabled" for widgets which are not enabled. Each color setting can be specified in all groups.

These color settings are currently available:
- Window
- WindowText
- Base
- AlternateBase
- ToolTipBase
- ToolTipText
- Text
- Button
- ButtonText
- BrightText
- Link
- Light
- Midlight
- Dark
- Mid
- Shadow
- Highlight
- HighlightedText

For details of each color setting, see: http://doc.qt.io/qt-5/qpalette.html#ColorRole-enum