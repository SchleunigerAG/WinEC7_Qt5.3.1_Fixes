import QtQuick 2.0
import Qt.test.fallbackBindingsItem 1.0

Item {
    property bool success: false

    property FallbackBindingsType foo: FallbackBindingsType {}
    property var test: foo.test

    Component.onCompleted: success = (test == 100)
}
