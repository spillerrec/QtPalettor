/*	This file is part of QtPalettor.

	QtPalettor is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	QtPalettor is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with QtPalettor.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QApplication>
#include <QColor>
#include <QDir>
#include <QPalette>
#include <QSettings>
#include <string>

/*
QPalette::WindowText     
QPalette::Button         
QPalette::Light          
QPalette::Midlight       
QPalette::Dark           
QPalette::Mid            
QPalette::Text           
QPalette::BrightText     
QPalette::ButtonText     
QPalette::Base           
QPalette::Window         
QPalette::Shadow         
QPalette::Highlight      
QPalette::HighlightedText
QPalette::Link
QPalette::LinkVisited
QPalette::AlternateBase
QPalette::Window
QPalette::ToolTipBase
QPalette::ToolTipText
*/

void writeColor( QFile& file, const char* name, QColor color ){
	file.write( name );
	file.write( "=" );
	
	auto toText = [&](int value){
		file.write( std::to_string( value ).c_str() );
		file.write( " " );
	};
	toText( color.red()   );
	toText( color.green() );
	toText( color.blue()  );
	file.write( "\n" );
}


int main( int argc, char* argv[] ) {
	//Get palette, requires event processing to have taken place
	QApplication app( argc, argv );
	QCoreApplication::processEvents();
	auto palette = QApplication::palette();
	
	QFile f( "QtWineTheme.theme" );
	if( !f.open( QIODevice::WriteOnly ) )
		qFatal( "Failed to open output file" );
	
	f.write( "[Theme]\n" );
	f.write( "DisplayName=Converted from Qt5\n\n" );
	
	f.write( "[Control Panel\\Colors]\n" );
	writeColor( f, "ActiveTitle"          , palette.color( QPalette::Text ) );
	writeColor( f, "Background"           , palette.color( QPalette::Base ) );
	writeColor( f, "Hilight"              , palette.color( QPalette::Highlight ) );
	writeColor( f, "HilightText"          , palette.color( QPalette::HighlightedText ) );
	writeColor( f, "TitleText"            , palette.color( QPalette::Text ) );
	writeColor( f, "Window"               , palette.color( QPalette::Window ) );
	writeColor( f, "WindowText"           , palette.color( QPalette::Text ) );
	writeColor( f, "Scrollbar"            , palette.color( QPalette::Base ) );
	writeColor( f, "InactiveTitle"        , palette.color( QPalette::Text ) ); //TODO
	writeColor( f, "Menu"                 , palette.color( QPalette::Base ) );
	writeColor( f, "WindowFrame"          , palette.color( QPalette::Base ) );
	writeColor( f, "MenuText"             , palette.color( QPalette::Text ) );
	writeColor( f, "ActiveBorder"         , palette.color( QPalette::Base ) );
	writeColor( f, "InactiveBorder"       , palette.color( QPalette::Base ) );
	writeColor( f, "AppWorkspace"         , palette.color( QPalette::Base ) );
	writeColor( f, "ButtonFace"           , palette.color( QPalette::Base ) );
	writeColor( f, "ButtonShadow"         , palette.color( QPalette::Shadow ) );
	writeColor( f, "GrayText"             , palette.color( QPalette::Base ) );
	writeColor( f, "ButtonText"           , palette.color( QPalette::Text ) );
	writeColor( f, "InactiveTitleText"    , palette.color( QPalette::Text ) ); //TODO
	writeColor( f, "ButtonHilight"        , palette.color( QPalette::Highlight ) );
	writeColor( f, "ButtonDkShadow"       , palette.color( QPalette::Dark ) );
	writeColor( f, "ButtonLight"          , palette.color( QPalette::Light ) );
	writeColor( f, "InfoText"             , palette.color( QPalette::ToolTipText ) );
	writeColor( f, "InfoWindow"           , palette.color( QPalette::ToolTipBase ) );
	writeColor( f, "GradientActiveTitle"  , palette.color( QPalette::Text ) );
	writeColor( f, "GradientInactiveTitle", palette.color( QPalette::Text ) ); //TODO
	f.write( "\n" );
	
	f.write( "[Control Panel\\Desktop]\n" );
	f.write( "Wallpaper=%WinDir%\\web\\wallpaper\\Windows\\img0.jpg\n" );
	f.write( "TileWallpaper=0\n" );
	f.write( "WallpaperStyle=2\n" );
	f.write( "\n" );
	
	f.write( "[VisualStyles]\n" );
	f.write( "ColorStyle=NormalColor\n" );
	f.write( "Size=NormalSize\n" );
	f.write( "\n" );
	
	f.write( "[MasterThemeSelector]\n" );
	f.write( "MTSM=DABJDKT\n" );
	
	
	return 0;
}
