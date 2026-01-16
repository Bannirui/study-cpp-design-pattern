//
// Created by dingrui on 1/16/26.
//

#include "facade.h"

#include <iostream>

void Camera::turnOn() {
    std::cout << "camera turn on" << std::endl;
}

void Camera::turnOff() {
    std::cout << "camera turn off" << std::endl;
}

void Light::turnOn() {
    std::cout << "light turn on" << std::endl;
}

void Light::turnOff() {
    std::cout << "light turn off" << std::endl;
}

void Sensor::active() {
    std::cout << "sensor turn on" << std::endl;
}

void Sensor::inactive() {
    std::cout << "sensor turn off" << std::endl;
}

Facade::Facade() {
    this->m_camera = new Camera();
    this->m_light = new Light();
    this->m_sensor = new Sensor();
}

Facade::~Facade() {
    if (this->m_camera) {
        delete this->m_camera;
    }
    if (this->m_light) {
        delete this->m_light;
    }
    if (this->m_sensor) {
        delete this->m_sensor;
    }
}

void Facade::on() {
    this->m_camera->turnOn();
    this->m_light->turnOn();
    this->m_sensor->active();
}

void Facade::off() {
    this->m_camera->turnOff();
    this->m_light->turnOff();
    this->m_sensor->inactive();
}
