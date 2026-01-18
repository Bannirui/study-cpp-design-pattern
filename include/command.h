//
// Created by dingrui on 1/18/26.
//

#pragma once

#include <iostream>

// device
class Light {
public:
    Light() = default;

    ~Light() = default;

    void On() {
        std::cout << "light on" << std::endl;
    }

    void Off() {
        std::cout << "light off" << std::endl;
    }
};

class Command {
public:
    virtual void execute() = 0;

    virtual void undo() = 0;

    virtual ~Command() = default;

protected:
    Command() = default;
};

// device command
class LightOnCommand : public Command {
public:
    explicit LightOnCommand(Light *p) : m_light(p) {
    }

    ~LightOnCommand() override {
        if (this->m_light) {
            delete this->m_light;
            this->m_light = nullptr;
        }
    }

    void execute() override {
        if (this->m_light) {
            this->m_light->On();
        }
    }

    void undo() override {
        if (this->m_light) {
            this->m_light->Off();
        }
    }

private:
    Light *m_light{nullptr};
};

class LightOffCommand : public Command {
public:
    explicit LightOffCommand(Light *p) : m_light(p) {
    }

    ~LightOffCommand() override {
        if (this->m_light) {
            delete this->m_light;
            this->m_light = nullptr;
        }
    }

    void execute() override {
        if (this->m_light) {
            this->m_light->Off();
        }
    }

    void undo() override {
        if (this->m_light) {
            this->m_light->On();
        }
    }

private:
    Light *m_light{nullptr};
};

class UndoCommand : public Command {
public:
    void execute() override {
    }

    void undo() override {
    };
};

// invoker
class SimpleRemoteControl {
public:
    void set_command(Command *p) {
        this->m_command = p;
    }

    ~SimpleRemoteControl() {
        if (this->m_command) {
            delete this->m_command;
            this->m_command = nullptr;
        }
    }

    void Click() {
        if (this->m_command) {
            this->m_command->execute();
            this->m_undoCommand = this->m_command;
        }
    }

    void Undo() {
        if (this->m_undoCommand) {
            this->m_undoCommand->undo();
        }
    }

private:
    Command *m_command{nullptr};
    Command *m_undoCommand{nullptr};
};
