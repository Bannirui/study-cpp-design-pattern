//
// Created by dingrui on 1/18/26.
//

#include "bridge.h"

int main() {
    IOS *pWin = new CWindows;
    IOS *pLinux = new CLinux;

    IComputer *pLenvo = new CLenvo;
    pLenvo->Install(pWin);
    pLenvo->Install(pLinux);

    IComputer *pDell = new CDell;
    pDell->Install(pLinux);
    return 0;
}
