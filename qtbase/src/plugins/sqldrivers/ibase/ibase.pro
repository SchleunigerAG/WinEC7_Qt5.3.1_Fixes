TARGET = qsqlibase5_3_1_V3-WinEC70Colibri-msvc2008

SOURCES = main.cpp
OTHER_FILES += ibase.json
include(../../../sql/drivers/ibase/qsql_ibase.pri)

PLUGIN_CLASS_NAME = QIBaseDriverPlugin
include(../qsqldriverbase.pri)
