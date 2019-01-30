TARGET = qtposition_positionpoll5_3_1_V3-WinEC70Colibri-msvc2008
QT = core positioning

PLUGIN_TYPE = position
PLUGIN_CLASS_NAME = PollPositionPlugin
load(qt_plugin)

SOURCES += \
    qgeoareamonitor_polling.cpp \
    positionpollfactory.cpp

HEADERS += \
    qgeoareamonitor_polling.h \
    positionpollfactory.h

INCLUDEPATH += $$QT.location.includes

OTHER_FILES += \
    plugin.json
