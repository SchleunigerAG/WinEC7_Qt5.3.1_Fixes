TARGET = imx6vivantevideonode5_3_1_V3-WinEC70Colibri-msvc2008
QT += multimedia-private qtmultimediaquicktools-private

PLUGIN_TYPE=video/videonode
PLUGIN_EXTENDS = quick
PLUGIN_CLASS_NAME = QSGVivanteVideoNodeFactory
load(qt_plugin)

HEADERS += \
    qsgvivantevideonode.h \
    qsgvivantevideomaterialshader.h \
    qsgvivantevideomaterial.h \
    qsgvivantevideonodefactory.h

SOURCES += \
    qsgvivantevideonode.cpp \
    qsgvivantevideomaterialshader.cpp \
    qsgvivantevideomaterial.cpp \
    qsgvivantevideonodefactory.cpp

OTHER_FILES += \
    imx6.json
