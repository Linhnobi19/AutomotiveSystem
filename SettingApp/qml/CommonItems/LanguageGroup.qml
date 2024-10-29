import QtQuick 2.15

Item {
    id: group
    property var selectedButton: null

    function selectButton(button){
        if (selectedButton && selectedButton !== button) {
            selectedButton.checked = false
        }
        selectedButton = button
    }
}
