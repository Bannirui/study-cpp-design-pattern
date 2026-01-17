//
// Created by dingrui on 1/17/26.
//

#pragma once

#include <list>
#include <string>
#include <iostream>

// component
class IFile {
public:
    virtual ~IFile() = default;

    virtual void display() =0;

    virtual int add(IFile *pFile) =0;

    virtual int remove(IFile *pFile) =0;

    virtual std::list<IFile *> *GetChild() =0;

protected:
    IFile() = default;
};

// leaf
class File : public IFile {
public:
    File(std::string name) : m_name(name) {
    }

    ~File() override = default;

    void display() override {
        std::cout << this->m_name << std::endl;
    };

    int add(IFile *pFile) override { return -1; };

    int remove(IFile *pFile) override { return -1; };

    std::list<IFile *> *GetChild() override {
        return nullptr;
    };

private:
    std::string m_name;
};

// directory
class Directory : public IFile {
public:
    Directory(std::string name) : m_name(name) {
        this->m_children = new std::list<IFile *>();
    }

    ~Directory() override {
        delete this->m_children;
    };

    void display() override {
        std::cout << this->m_name << std::endl;
    };

    int add(IFile *pFile) override {
        this->m_children->push_back(pFile);
        return 0;
    };

    int remove(IFile *pFile) override {
        this->m_children->remove(pFile);
        return 0;
    };

    std::list<IFile *> *GetChild() override { return this->m_children; };

private:
    std::string m_name;
    std::list<IFile *> *m_children;
};

void showTree(IFile *root, int level) {
    if (!root) {
        return;
    }
    for (int i = 0; i < level; ++i) {
        std::cout << "\t";
    }
    root->display();
    std::list<IFile *> *children = root->GetChild();
    if (children) {
        for (auto it = children->begin(); it != children->end(); ++it) {
            if (!(*it)->GetChild()) {
                // file
                for (int i = 0; i < level; ++i) {
                    std::cout << "\t";
                }
                (*it)->display();
            } else {
                // directory
                showTree(*it, level + 1);
            }
        }
    }
}
