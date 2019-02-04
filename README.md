# WinEC7_Qt5.3.1_Fixes
Summary of the changes done by Schleuniger:

5.3.1-V3-WinEC70Colibri-msvc2008
- resolve NOMINMAX compiler error in QDateTime (QTBUG-31469)
- add "#define _CRT_BANNED_DEPRECATE( x )" in files to resolve wince sdk compiler errors
- add missing "#include "windows.h"" to fix compile errors
- add KDAB fix for Gesture handling (no multi touch support)
- add infix for plugin dlls
- fix font handling to be able to load a font from filesystem
- fix for creating screenshots

All changes in existing files are marked with the following banner:
CHANGES SCHLEUNIGER AG, DATE START
xxx
CHANGES SCHLEUNIGER AG, DATE END
