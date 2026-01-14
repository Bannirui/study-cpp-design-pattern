//
// Created by dingrui on 1/14/26.
//

#include "abstract_factory.h"

int main() {
    GuiEngine *engine = new GuiEngine();
    engine->PrepareMaterial(new Schema1);
    delete engine;
    return 0;
}
