import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 400
    height: 200
    title: qsTr("Hello World")

    ListView {
        id:lView
        anchors.fill: parent

        model: DeathList

        orientation: ListView.Vertical

        delegate: Rectangle {
            color: modelData.dead ? "darkred" : "white"

            width: lView.width
            height: 50

            Text {
                id:nameField
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: modelData.name
                color: modelData.dead ? "white" : "black"
                width: contentWidth
            }

            Text {
                anchors.left: nameField.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                text: modelData.age + qsTr("years old")
                color: modelData.dead ? "white" : "black"
                width: contentWidth
            }

            CheckBox {
                text: qsTr("is dead ?")
                anchors.right: parent.right
                anchors.top:parent.top
                anchors.bottom: parent.bottom
                checked: modelData.dead
                onCheckedChanged: modelData.dead = checked
            }
        }
    }
}
