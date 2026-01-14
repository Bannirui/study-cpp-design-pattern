//
// Created by dingrui on 1/14/26.
//
#include "ioc.h"

int main() {
    IocContainer<ICar> carIoc;
    carIoc.RegisterType<Bus>("bus");
    carIoc.RegisterType<Track>("track");

    std::shared_ptr<ICar> bus = carIoc.ResolveShard("bus");
    bus->test();
    std::shared_ptr<ICar> track = carIoc.ResolveShard("track");
    track->test();
    return 0;
}
