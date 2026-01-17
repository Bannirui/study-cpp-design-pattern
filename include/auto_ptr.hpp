//
// Created by dingrui on 1/17/26.
//

#pragma once
#include <cstddef>
#include <iostream>

template<class T>
class AutoPtr;

template<class T>
class RefPtr {
    friend class AutoPtr<T>;

private:
    RefPtr(T *p);

    virtual ~RefPtr();

private:
    T *m_ptr;
    std::size_t m_refCount;
};

template<class T>
RefPtr<T>::RefPtr(T *p) {
    this->m_ptr = p;
    this->m_refCount = 1;
    std::cout << "RefPtr::Constructor" << std::endl;
}

template<class T>
RefPtr<T>::~RefPtr() {
    std::cout << "RefPtr::Destructor" << std::endl;
    if (this->m_ptr) {
        delete this->m_ptr;
        this->m_refCount = 0;
    }
    this->m_ptr = nullptr;
}

template<class T>
class AutoPtr {
public:
    AutoPtr();

    AutoPtr(T *p);

    AutoPtr(const AutoPtr<T> &p);

    ~AutoPtr();

    AutoPtr<T> &operator=(const AutoPtr<T> &other);

    T &operator*();

    T *operator->();

private:
    RefPtr<T> *m_refPtr;
};

template<class T>
AutoPtr<T>::AutoPtr() {
    std::cout << "AutoPtr::AutoPtr()" << std::endl;
    this->m_refPtr = nullptr;
}

template<class T>
AutoPtr<T>::AutoPtr(T *p) {
    std::cout << "AutoPtr::AutoPtr()" << std::endl;
    this->m_refPtr = new RefPtr<T>(p);
}

template<class T>
AutoPtr<T>::AutoPtr(const AutoPtr<T> &p) {
    std::cout << "AutoPtr::AutoPtr(const AutoPtr<T> &p)" << std::endl;
    this->m_refPtr = p.m_refPtr;
    ++(this->m_refPtr->m_refCount);
}

template<class T>
AutoPtr<T>::~AutoPtr() {
    std::cout << "AutoPtr::~AutoPtr()" << std::endl;
    if ((--this->m_refPtr->m_refCount) == 0) {
        std::cout << "delete the object" << std::endl;
        delete this->m_refPtr;
    }
}

template<class T>
AutoPtr<T> &AutoPtr<T>::operator=(const AutoPtr<T> &other) {
    ++(other.m_refPtr->m_refCount);
    if (this->m_refPtr) {
        if ((--this->m_refPtr->m_refCount) == 0) {
            delete this->m_refPtr;
        }
    }
    this->m_refPtr = other.m_refPtr;
    std::cout << "AutoPtr::AutoPtr(const AutoPtr<T> &other) ref_cnt=" << this->m_refPtr->m_refCount << std::endl;
    return *this;
}

template<class T>
T &AutoPtr<T>::operator*() {
    return *(this->m_refPtr->m_ptr);
}

template<class T>
T *AutoPtr<T>::operator->() {
    return this->m_refPtr->m_ptr;
}
