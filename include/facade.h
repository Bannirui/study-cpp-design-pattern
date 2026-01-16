//
// Created by dingrui on 1/16/26.
//

#pragma once

class Camera {
public:
    void turnOn();

    void turnOff();
};

class Light {
public:
    void turnOn();

    void turnOff();
};

class Sensor {
public:
    void active();

    void inactive();
};

class Facade {
public:
    Facade();
    ~Facade();

    void on();

    void off();

private:
    Camera *m_camera;
    Light *m_light;
    Sensor *m_sensor;
};
