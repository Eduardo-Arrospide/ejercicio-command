#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>

class Device
{
public:
    bool turnedOn = false;
    friend class TurnOnCommand;
};

class Light: public Device
{
    std::string color;
public:
    Light() = default;
    explicit Light(std::string _color): color(_color){}

    void isOn()
    {
        std::cout << this->turnedOn;
    }

    friend class TurnOnCommand;
};


class Fan : public Device
{
    int intensity; // (1, 2, 3) 
public: 
    Fan() = default;
    explicit Fan(int _intensity) : intensity(_intensity) {}

    friend class TurnOnCommand;
};

class Command 
{
public:
    virtual void execute(Device* device) = 0;
};

class TurnOnCommand: public Command
{
public:
    void execute(Device* device) override 
    {
        device->turnedOn = !device->turnedOn;
    }
};




class Controller 
{
    static Controller* instance;
    TurnOnCommand *command;

    Controller()
    {
        command = new TurnOnCommand();
    }

public:
    static Controller* getInstance()
    {
        if (instance == nullptr)
            instance = new Controller();
        return instance;
    }

    TurnOnCommand *getCommand() { return command; }
};


#endif