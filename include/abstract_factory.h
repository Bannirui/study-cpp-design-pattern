//
// Created by dingrui on 1/14/26.
//

#pragma once

#include <iostream>

class FrameApi {
public:
    virtual void Draw() =0;

protected:
    FrameApi() = default;
};

class LayoutApi {
public:
    virtual void InstallFrame() =0;

protected:
    LayoutApi() = default;
};

class ComputerFrame : public FrameApi {
public:
    ComputerFrame(int pins) : m_pins(pins) {
    }

    void Draw() override {
        std::cout << "Computer: " << m_pins << std::endl;
    }

private:
    int m_pins;
};

class MobileFrame : public FrameApi {
public:
    MobileFrame(int pins) : m_pins(pins) {
    }

    void Draw() override {
        std::cout << "Mobile: " << m_pins << std::endl;
    }

private:
    int m_pins;
};

class HighLayout : public LayoutApi {
public:
    HighLayout(int pins) : m_frameAdapterPins(pins) {
    }

    void InstallFrame() override {
        std::cout << "High Layout: " << m_frameAdapterPins << std::endl;
    }

private:
    int m_frameAdapterPins;
};

class LowLayout : public LayoutApi {
public:
    LowLayout(int pins) : m_frameAdapterPins(pins) {
    }

    void InstallFrame() override {
        std::cout << "Low Layout: " << m_frameAdapterPins << std::endl;
    }

private:
    int m_frameAdapterPins;
};

class AbstractFactory {
public:
    virtual FrameApi *CreateFrame() = 0;

    virtual LayoutApi *CreateLayout() =0;

protected:
    AbstractFactory() = default;
};

class Schema1 : public AbstractFactory {
public:
    FrameApi *CreateFrame() override {
        return new ComputerFrame(1024);
    }

    LayoutApi *CreateLayout() override {
        return new HighLayout(1024);
    }
};

class Schema2 : public AbstractFactory {
public:
    FrameApi *CreateFrame() override {
        return new MobileFrame(400);
    }

    LayoutApi *CreateLayout() override {
        return new LowLayout(400);
    }
};

class GuiEngine {
public:
    void PrepareMaterial(AbstractFactory *p_schema) {
        this->m_pFrame = p_schema->CreateFrame();
        if (this->m_pFrame) {
            this->m_pFrame->Draw();
        }
        this->m_pLayout = p_schema->CreateLayout();
        if (this->m_pLayout) {
            this->m_pLayout->InstallFrame();
        }
    }

private:
    FrameApi *m_pFrame;
    LayoutApi *m_pLayout;
};
