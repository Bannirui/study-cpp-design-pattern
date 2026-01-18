//
// Created by dingrui on 1/19/26.
//

#include "state.h"

int main() {
    DownloadMgr mgr;
    for (int i = 0; i < 6; ++i) {
        mgr.DownLoad("dingrui", "cpp");
    }

    return 0;
}
