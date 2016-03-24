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

#include "QtPalettorPlugin.hpp"

#include <QPalette>
#include <QSettings>
#include <QStyleFactory>

#include <vector>
#include <utility>

PalettedStyle::PalettedStyle() : QProxyStyle() {
	QSettings settings( "spillerrec", "QtPalettor" );
	
	//Get base theme
	auto theme_name = settings.value( "theme", "Fusion" ).toString();
	setBaseStyle( QStyleFactory::create(theme_name) );
	palette = proxy()->standardPalette();
	
	//Iterating over the settings key and ColorGroup
	std::vector<std::pair<QString,QPalette::ColorGroup>> groups( {
			{"Active/",   QPalette::Active}
		,	{"Inactive/", QPalette::Inactive}
		,	{"Disabled/", QPalette::Disabled}
		} );
	
	for( auto group : groups ){
		//Change the palette color if specified
		auto set = [&]( auto pal, QString name ){
				auto value = settings.value( group.first + name );
				if( value.isValid() )
					palette.setColor( group.second, pal, value.value<QColor>() );
			};
		
		set( QPalette::Window,          "Window"          );
		set( QPalette::Background,      "Background"      );
		set( QPalette::WindowText,      "WindowText"      );
		set( QPalette::Base,            "Base"            );
		set( QPalette::AlternateBase,   "AlternateBase"   );
		set( QPalette::ToolTipBase,     "ToolTipBase"     );
		set( QPalette::ToolTipText,     "ToolTipText"     );
		set( QPalette::Text,            "Text"            );
		set( QPalette::Button,          "Button"          );
		set( QPalette::ButtonText,      "ButtonText"      );
		set( QPalette::BrightText,      "BrightText"      );
		set( QPalette::Link,            "Link"            );
		set( QPalette::LinkVisited,     "LinkVisited"     );
		
		set( QPalette::Light,           "Light"           );
		set( QPalette::Midlight,        "Midlight"        );
		set( QPalette::Mid,             "Mid"             );
		set( QPalette::Dark,            "Dark"            );
		set( QPalette::Shadow,          "Shadow"          );
		
		set( QPalette::Highlight,       "Highlight"       );
		set( QPalette::HighlightedText, "HighlightedText" );
	}
}

QStyle* QtPalettorPlugin::create( const QString& key ){
	return key.toLower()=="qtpalettor" ? new PalettedStyle() : nullptr;
}
