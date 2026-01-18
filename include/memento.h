//
// Created by dingrui on 1/18/26.
//

#pragma once

#include <iostream>
#include <string>

class OriginWord;

class Memento {
    Memento(std::string word) : m_word(word) {
    }

private:
    friend class OriginWord;
    std::string get_word() const { return this->m_word; }
    std::string m_word;
};

class OriginWord {
public:
    OriginWord(std::string word) : m_word(word) {
    }

    void ShowWord() {
        std::cout << this->m_word << std::endl;
    }

    Memento *saveWord() {
        return new Memento(this->m_word);
    }

    void recoverWord(Memento *memento) {
        this->m_word = memento->get_word();
        std::cout << "recover word: " << this->m_word << std::endl;
    }

private:
    std::string m_word;
};

class CareTake {
public:
    Memento *get_memento() const {
        return this->m_memento;
    }

    void set_memento(Memento *memento) {
        this->m_memento = memento;
    }

private:
    Memento *m_memento;
};
