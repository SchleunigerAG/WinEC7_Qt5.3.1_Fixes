mkdir 2>NUL "%CONFIGURATIONBUILDDIR%\bin32\WebKit.resources\inspector"
xcopy /y /d /s /exclude:xcopy.excludes "%ProjectDir%..\inspector\front-end\*" "%CONFIGURATIONBUILDDIR%\bin32\WebKit.resources\inspector"
xcopy /y /d /s /exclude:xcopy.excludes "%CONFIGURATIONBUILDDIR%\obj32\WebCore\DerivedSources\InspectorBackendCommands.js" "%CONFIGURATIONBUILDDIR%\bin32\WebKit.resources\inspector"
mkdir 2>NUL "%CONFIGURATIONBUILDDIR%\bin32\WebKit.resources\en.lproj"
xcopy /y /d /s /exclude:xcopy.excludes "%ProjectDir%..\English.lproj\localizedStrings.js" "%CONFIGURATIONBUILDDIR%\bin32\WebKit.resources\en.lproj"
xcopy /y /d /s /exclude:xcopy.excludes "%ProjectDir%..\English.lproj\Localizable.strings" "%CONFIGURATIONBUILDDIR%\bin32\WebKit.resources\en.lproj"
