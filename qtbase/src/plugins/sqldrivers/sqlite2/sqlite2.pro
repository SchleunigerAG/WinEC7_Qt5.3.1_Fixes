TARGET = qsqlite25_3_1_V3-WinEC70Colibri-msvc2008

SOURCES = smain.cpp
OTHER_FILES += sqlite2.json
include(../../../sql/drivers/sqlite2/qsql_sqlite2.pri)

PLUGIN_CLASS_NAME = QSQLite2DriverPlugin
include(../qsqldriverbase.pri)
