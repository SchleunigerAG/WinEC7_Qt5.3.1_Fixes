TARGET = qtmedia_audioengine5_3_1_V3-WinEC70Colibri-msvc2008
QT += multimedia-private

PLUGIN_TYPE=mediaservice
PLUGIN_CLASS_NAME = AudioCaptureServicePlugin
load(qt_plugin)

HEADERS += audioencodercontrol.h \
    audiocontainercontrol.h \
    audiomediarecordercontrol.h \
    audioinputselector.h \
    audiocaptureservice.h \
    audiocaptureserviceplugin.h \
    audiocapturesession.h \
    audiocaptureprobecontrol.h

SOURCES += audioencodercontrol.cpp \
    audiocontainercontrol.cpp \
    audiomediarecordercontrol.cpp \
    audioinputselector.cpp \
    audiocaptureservice.cpp \
    audiocaptureserviceplugin.cpp \
    audiocapturesession.cpp \
    audiocaptureprobecontrol.cpp

OTHER_FILES += \
    audiocapture.json
