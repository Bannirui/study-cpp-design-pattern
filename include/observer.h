//
// Created by dingrui on 1/18/26.
//

#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

class Observer {
public:
    virtual void Update(std::string temp, std::string humi) =0;

    virtual ~Observer() = default;

protected:
    Observer() = default;
};

class Subject {
public:
    virtual void RegisterObserver(Observer *obj) =0;

    virtual void RemoveObserver(Observer *obj) =0;

    virtual void NotifyObserver() =0;

protected:
    Subject() = default;
};

class WeatherData : public Subject {
public:
    WeatherData() : m_temp(""), m_humi("") {
    }

    WeatherData(std::string temp, std::string humi) : m_temp(temp), m_humi(humi) {
    }

    ~WeatherData() {
        if (!this->m_observers.empty()) {
            for (auto x: this->m_observers) {
                delete x;
            }
        }
    }

    void RegisterObserver(Observer *obj) override {
        this->m_observers.push_back(obj);
    }

    void RemoveObserver(Observer *obj) override {
        if (auto it = std::find(this->m_observers.begin(), this->m_observers.end(), obj);
            it != this->m_observers.end()) {
            this->m_observers.erase(it);
        }
    }

    void NotifyObserver() override {
        for (auto x: this->m_observers) {
            x->Update(this->m_temp, this->m_humi);
        }
    }

    void Set_Data(std::string temp, std::string humi) {
        this->m_temp = temp;
        this->m_humi = humi;
        this->NotifyObserver();
    }

private:
    std::vector<Observer *> m_observers;
    std::string m_temp;
    std::string m_humi;
};


class PCDisplay : public Observer {
public:
    PCDisplay(WeatherData *p) {
        this->m_pWeatherData = p;
        this->m_pWeatherData->RegisterObserver(this);
    }

    void Update(std::string temp, std::string humi) override {
        std::cout << "PC get temp=" << temp << ", humi=" << humi << std::endl;
    }

private:
    WeatherData *m_pWeatherData;
};

class MobileDisplay : public Observer {
public:
    MobileDisplay(WeatherData *p) {
        this->m_pWeatherData = p;
        this->m_pWeatherData->RegisterObserver(this);
    }

    void Update(std::string temp, std::string humi) override {
        std::cout << "Mobile get temp=" << temp << ", humi=" << humi << std::endl;
    }

private:
    WeatherData *m_pWeatherData;
};
