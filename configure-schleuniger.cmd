echo off
echo --------------------------------------------------------------------------------
echo WARNING: This batch file must be executed with the VISUAL STUDIO 2008 CONSOLE!!!
echo --------------------------------------------------------------------------------
pause
echo --------------------------------------------------------------------------------
echo Have you checked the correct directory name (Qt-Version, infix:VX, Platform) ?
echo %CD%
echo --------------------------------------------------------------------------------
pause
configure -prefix %CD%/qtbase -platform win32-msvc2008 -xplatform wince70colibri-armv4i-msvc2008 -qtlibinfix 5_3_1_V2-WinEC70Colibri-msvc2008 -qt-style-windows -ltcg -no-openssl -no-gif -no-libjpeg -no-accessibility -opengl es2 -opensource -confirm-license -skip qtactiveqt -skip qtmultimedia -skip qtwinextras -skip qttools -nomake examples -nomake tests
