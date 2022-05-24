#include "command.h"


Controller *Controller::instance = nullptr;

int main() 
{
    Controller* controller = Controller::getInstance();

    TurnOnCommand *command = controller->getCommand();

    Light red("red");
    Light green("green");
    Light yellow("yellow");

    red.isOn();

    command->execute(&red);

    red.isOn();

    return 0;
}