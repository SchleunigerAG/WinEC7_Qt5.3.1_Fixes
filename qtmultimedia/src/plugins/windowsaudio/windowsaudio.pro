TARGET = qtaudio_windows5_3_1_V3-WinEC70Colibri-msvc2008
QT += multimedia-private

PLUGIN_TYPE = audio
PLUGIN_CLASS_NAME = QWindowsAudioPlugin
load(qt_plugin)

LIBS += -lwinmm -lstrmiids -lole32 -loleaut32

HEADERS += \
    qwindowsaudioplugin.h \
    qwindowsaudiodeviceinfo.h \
    qwindowsaudioinput.h \
    qwindowsaudiooutput.h

SOURCES += \
    qwindowsaudioplugin.cpp \
    qwindowsaudiodeviceinfo.cpp \
    qwindowsaudioinput.cpp \
    qwindowsaudiooutput.cpp

OTHER_FILES += \
    windowsaudio.json
