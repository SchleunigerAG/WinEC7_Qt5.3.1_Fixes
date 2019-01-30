TARGET = qsqloci5_3_1_V3-WinEC70Colibri-msvc2008

SOURCES = main.cpp
OTHER_FILES += oci.json
include(../../../sql/drivers/oci/qsql_oci.pri)

PLUGIN_CLASS_NAME = QOCIDriverPlugin
include(../qsqldriverbase.pri)
