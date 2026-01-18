//
// Created by dingrui on 1/18/26.
//

#include "memento.h"

int main() {
    OriginWord *word1 = new OriginWord("1");
    word1->ShowWord();

    CareTake *careTake = new CareTake();
    careTake->set_memento(word1->saveWord());

    OriginWord *word2 = new OriginWord("2");
    word2->ShowWord();

    OriginWord *word3 = new OriginWord("3");
    word3->ShowWord();

    word1->recoverWord(careTake->get_memento());
    word1->ShowWord();

    delete word1;
    delete word2;
    delete word3;
    delete careTake;
    return 0;
}
