import Qt.test 1.0

MyQmlObject {
    property int c1: 0
    property int c2: c1

    onBasicSignal: c2 = 13
}
