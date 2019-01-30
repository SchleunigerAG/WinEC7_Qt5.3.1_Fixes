TARGET = qtaudio_alsa5_3_1_V3-WinEC70Colibri-msvc2008
QT += multimedia-private

PLUGIN_TYPE = audio
PLUGIN_CLASS_NAME = QAlsaPlugin
load(qt_plugin)

LIBS += -lasound

HEADERS += \
    qalsaplugin.h \
    qalsaaudiodeviceinfo.h \
    qalsaaudioinput.h \
    qalsaaudiooutput.h

SOURCES += \
    qalsaplugin.cpp \
    qalsaaudiodeviceinfo.cpp \
    qalsaaudioinput.cpp \
    qalsaaudiooutput.cpp

OTHER_FILES += \
    alsa.json
