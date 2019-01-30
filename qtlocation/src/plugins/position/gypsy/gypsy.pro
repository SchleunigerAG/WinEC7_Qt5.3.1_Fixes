TARGET = qtposition_gypsy5_3_1_V3-WinEC70Colibri-msvc2008
QT = core positioning

PLUGIN_TYPE = position
PLUGIN_CLASS_NAME = GypsyPositionPlugin
load(qt_plugin)

HEADERS += \
    qgeosatelliteinfosource_gypsy_p.h \
    qgeopositioninfosourcefactory_gypsy.h

SOURCES += \
    qgeosatelliteinfosource_gypsy.cpp \
    qgeopositioninfosourcefactory_gypsy.cpp

INCLUDEPATH += $$QT.location.includes

CONFIG += link_pkgconfig
PKGCONFIG += gypsy gconf-2.0

OTHER_FILES += \
    plugin.json
