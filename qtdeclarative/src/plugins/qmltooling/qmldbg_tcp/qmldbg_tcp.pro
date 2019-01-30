TARGET = qmldbg_tcp5_3_1_V3-WinEC70Colibri-msvc2008
QT = qml-private

PLUGIN_TYPE = qmltooling
PLUGIN_CLASS_NAME = QTcpServerConnection
load(qt_plugin)

include(qmldbg_tcp.pri)
