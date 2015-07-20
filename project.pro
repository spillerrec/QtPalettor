TARGET  = $$qtLibraryTarget(QtPalettor)
TEMPLATE = lib
CONFIG += plugin c++14
QT += widgets

SOURCES = src/QtPalettorPlugin.cpp
HEADERS = src/QtPalettorPlugin.hpp