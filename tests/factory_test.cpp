//
// Created by dingrui on 1/14/26.
//

#include "factory.h"

int main() {
    ExportOperate *p1 = new ExportTxtOperate;
    p1->exportData();
    ExportOperate *p2 = new ExportDBOperate;
    p2->exportData();
    return 0;
}
