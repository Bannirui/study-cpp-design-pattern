//
// Created by dingrui on 1/14/26.
//

#pragma once

// interface
class FrameApi {
public:
    virtual void Draw() =0;

protected:
    FrameApi() = default;
};

class ComputerFrame : public FrameApi {
public:
    ComputerFrame(int pins);

    void Draw() override;

private:
    int m_pins;
};

class MobileFrame : public FrameApi {
public:
    MobileFrame(int pins);

    void Draw() override;

private:
    int m_pins;
};

// interface
class LayoutApi {
public:
    virtual void InstallFrame() =0;

protected:
    LayoutApi() = default;
};


class HighLayout : public LayoutApi {
public:
    HighLayout(int pins);

    void InstallFrame() override;

private:
    int m_frameAdapterPins;
};

class LowLayout : public LayoutApi {
public:
    LowLayout(int pins);

    void InstallFrame() override;

private:
    int m_frameAdapterPins;
};

// combine multiple products
class AbstractFactory {
public:
    virtual FrameApi *CreateFrame() = 0;

    virtual LayoutApi *CreateLayout() =0;

protected:
    AbstractFactory() = default;
};

// the product schema
class Schema1 : public AbstractFactory {
public:
    FrameApi *CreateFrame() override;

    LayoutApi *CreateLayout() override;
};

class Schema2 : public AbstractFactory {
public:
    FrameApi *CreateFrame();

    LayoutApi *CreateLayout();
};

class GuiEngine {
public:
    void PrepareMaterial(AbstractFactory *p_schema);

private:
    FrameApi *m_pFrame;
    LayoutApi *m_pLayout;
};
