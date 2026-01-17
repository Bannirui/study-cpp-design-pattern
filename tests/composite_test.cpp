//
// Created by dingrui on 1/17/26.
//

#include "composite.h"

int main() {
    Directory *root = new Directory("home");
    Directory *pDir1 = new Directory("user");
    Directory *pDir2 = new Directory("dingrui");

    File *pf1 = new File("1.txt");
    File *pf2 = new File("2.txt");
    File *pf3 = new File("3.txt");

    root->add(pDir1);
    root->add(pf1);

    root->add(pf2);
    root->add(pDir2);
    pDir2->add(pf3);

    showTree(root, 0);
    return 0;
}
