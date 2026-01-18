//
// Created by dingrui on 1/18/26.
//

#include "command.h"

int main() {
    SimpleRemoteControl ctl;
    Light *light = new Light();

    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);

    ctl.set_command(lightOn);
    ctl.Click();
    ctl.Undo();

    ctl.set_command(lightOff);
    ctl.Click();
    ctl.Undo();

    return 0;
}
