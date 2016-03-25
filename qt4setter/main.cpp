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


QString makeSetting( QPalette palette, QPalette::ColorGroup group ){
	QString out;
	
	out += palette.color( group, QPalette::WindowText      ).name() + ",";
	out += palette.color( group, QPalette::Button          ).name() + ",";
	out += palette.color( group, QPalette::Light           ).name() + ",";
	out += palette.color( group, QPalette::Midlight        ).name() + ",";
	out += palette.color( group, QPalette::Dark            ).name() + ",";
	out += palette.color( group, QPalette::Mid             ).name() + ",";
	out += palette.color( group, QPalette::Text            ).name() + ",";
	out += palette.color( group, QPalette::BrightText      ).name() + ",";
	out += palette.color( group, QPalette::ButtonText      ).name() + ",";
	out += palette.color( group, QPalette::Base            ).name() + ",";
	out += palette.color( group, QPalette::Window          ).name() + ",";
	out += palette.color( group, QPalette::Shadow          ).name() + ",";
	out += palette.color( group, QPalette::Highlight       ).name() + ",";
	out += palette.color( group, QPalette::HighlightedText ).name() + ",";
	out += palette.color( group, QPalette::Link            ).name() + ",";
	out += palette.color( group, QPalette::LinkVisited     ).name() + ",";
	out += palette.color( group, QPalette::AlternateBase   ).name() + ",";
	out += palette.color( group, QPalette::Window          ).name() + ","; //TODO: This is something else!
	out += palette.color( group, QPalette::ToolTipBase     ).name() + ",";
	out += palette.color( group, QPalette::ToolTipText     ).name();
	
	return out;
}

int main( int argc, char* argv[] ) {
	//Get palette, requires event processing to have taken place
	QApplication app( argc, argv );
	QCoreApplication::processEvents();
	auto palette = QApplication::palette();
	
	QSettings settings( QDir::homePath() + "/.config/Trolltech.conf", QSettings::NativeFormat );
	settings.setValue( "Qt/Palette/active"  , makeSetting( palette, QPalette::Active   ) );
	settings.setValue( "Qt/Palette/inactive", makeSetting( palette, QPalette::Inactive ) );
	settings.setValue( "Qt/Palette/disabled", makeSetting( palette, QPalette::Disabled ) );
	
	return 0;
}
