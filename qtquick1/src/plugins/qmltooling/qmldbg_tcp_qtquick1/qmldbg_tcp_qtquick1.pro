TARGET = qmldbg_tcp_qtdeclarative5_3_1_V3-WinEC70Colibri-msvc2008
QT       += declarative declarative-private network

PLUGIN_TYPE = qml1tooling
PLUGIN_CLASS_NAME = QTcpServerConnection
load(qt_plugin)

SOURCES += \
    qtcpserverconnection.cpp

HEADERS += \
    qtcpserverconnection.h

OTHER_FILES += qtcpserverconnection.json
