TARGET = qsqlmysql5_3_1_V3-WinEC70Colibri-msvc2008

SOURCES = main.cpp
OTHER_FILES += mysql.json
include(../../../sql/drivers/mysql/qsql_mysql.pri)

PLUGIN_CLASS_NAME = QMYSQLDriverPlugin
include(../qsqldriverbase.pri)
