//
// Created by dingrui on 1/18/26.
//
#include "chain_of_responsibility.h"

int main() {
    Handler *projectManager = new ProjectManager;
    Handler *director = new DirectorManager;
    Handler *ceo = new CEO;

    projectManager->set_next(director);
    director->set_next(ceo);

    projectManager->handle(128);
    projectManager->handle(512);
    projectManager->handle(1024);

    delete projectManager;
    delete director;
    delete ceo;

    return 0;
}
