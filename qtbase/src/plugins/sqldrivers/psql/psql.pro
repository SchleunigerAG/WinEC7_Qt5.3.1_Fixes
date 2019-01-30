TARGET = qsqlpsql5_3_1_V3-WinEC70Colibri-msvc2008

SOURCES = main.cpp
OTHER_FILES += psql.json
include(../../../sql/drivers/psql/qsql_psql.pri)

PLUGIN_CLASS_NAME = QPSQLDriverPlugin
include(../qsqldriverbase.pri)
