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

#include <QStylePlugin>
#include <QProxyStyle>
#include <QPalette>


class PalettedStyle : public QProxyStyle{
	private:
		QPalette palette;
		
	public:
		PalettedStyle();
		virtual QPalette standardPalette() const override
			{ return palette; }
		virtual void polish( QPalette& pal ) override{ pal = palette; }
};

class QtPalettorPlugin: public QStylePlugin{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "names.json")
	
	public:
		QtPalettorPlugin( QObject* parent=0 ) : QStylePlugin( parent ) { }
		QStyle* create( const QString &key );
};