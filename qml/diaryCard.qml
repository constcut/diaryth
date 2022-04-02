import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.4 as Quick1

Item {

    id: diaryCardItem


    Component.onCompleted:
    {
        cardName.text = cardEngine.getCardName()
        cardDescription.text =  cardEngine.getCardDescription()
        groupsNames.model = cardEngine.getAllGroupsNames()
        fieldsNames.model = cardEngine.getAllGroupFields(groupsNames.currentText)

        var allFields = cardEngine.getAllGroupFields(groupsNames.currentText)
        console.log("Test fields sequence ", allFields)
    }

    ColumnLayout
    {
        spacing: 10
        y: 40
        x: 40

        RowLayout
        {
            spacing: 10

            Text {
                id: cardName
            }

            Text {
                id: cardDescription
            }

            Text {
                text: "Group: "
            }

            ComboBox {
                id: groupsNames
                implicitWidth: 200
            }

            Text {
                text: "Field: "
            }

            ComboBox {
                id: fieldsNames
            }
        }
    }


    function keyboardEventSend(key, mode) {
        //Заглушка обработки клавиш
    }

}