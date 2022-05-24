#include "command.h"


Controller *Controller::instance = 0;

int main() 
{
    Controller* controller = Controller::getInstance();

    TurnOnCommand *command = controller->getCommand();

    Light* red = new Light("red");
    Light *green = new Light("green");
    Light *yellow = new Light("yellow");

    red->isOn();

    command->execute(red);

    red->isOn();

    return 0;
}