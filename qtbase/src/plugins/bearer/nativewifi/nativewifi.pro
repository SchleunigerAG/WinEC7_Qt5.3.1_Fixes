TARGET = qnativewifibearer5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = bearer
PLUGIN_CLASS_NAME = QNativeWifiEnginePlugin
load(qt_plugin)

QT = core-private network-private

HEADERS += qnativewifiengine.h \
           platformdefs.h \
           ../qnetworksession_impl.h \
           ../qbearerengine_impl.h

SOURCES += main.cpp \
           qnativewifiengine.cpp \
           ../qnetworksession_impl.cpp

OTHER_FILES += nativewifi.json
