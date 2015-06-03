import QtQuick 1.0
import "openUrlExternally_lib.js" as Test

Item {
    Component.onCompleted: Test.loadTest();

    property bool testFile
    onTestFileChanged: Test.loadFile();
}
