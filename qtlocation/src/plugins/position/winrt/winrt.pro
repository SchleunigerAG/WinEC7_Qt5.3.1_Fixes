TARGET = qtposition_winrt5_3_1_V3-WinEC70Colibri-msvc2008
QT = core positioning

PLUGIN_TYPE = position
load(qt_plugin)

INCLUDEPATH += $$QT.location.includes

SOURCES += qgeopositioninfosource_winrt.cpp \
    qgeopositioninfosourcefactory_winrt.cpp
HEADERS += qgeopositioninfosource_winrt_p.h \
    qgeopositioninfosourcefactory_winrt.h

OTHER_FILES += \
    plugin.json
