//
// Created by dingrui on 1/14/26.
//

#include "abstract_factory.h"

#include <iostream>

ComputerFrame::ComputerFrame(int pins) : m_pins(pins) {
}

void ComputerFrame::Draw() {
    std::cout << "Computer: " << m_pins << std::endl;
}

MobileFrame::MobileFrame(int pins) : m_pins(pins) {
}

void MobileFrame::Draw() {
    std::cout << "Mobile: " << m_pins << std::endl;
}

HighLayout::HighLayout(int pins) : m_frameAdapterPins(pins) {
}

void HighLayout::InstallFrame() {
    std::cout << "High Layout: " << m_frameAdapterPins << std::endl;
}

LowLayout::LowLayout(int pins) : m_frameAdapterPins(pins) {
}

void LowLayout::InstallFrame() {
    std::cout << "Low Layout: " << this->m_frameAdapterPins << std::endl;
}

FrameApi *Schema1::CreateFrame() {
    return new ComputerFrame(1024);
}

LayoutApi *Schema1::CreateLayout() {
    return new HighLayout(1024);
}

FrameApi *Schema2::CreateFrame() {
    return new MobileFrame(400);
}

LayoutApi *Schema2::CreateLayout() {
    return new LowLayout(400);
}

void GuiEngine::PrepareMaterial(AbstractFactory *p_schema) {
    this->m_pFrame = p_schema->CreateFrame();
    if (this->m_pFrame) {
        this->m_pFrame->Draw();
    }
    this->m_pLayout = p_schema->CreateLayout();
    if (this->m_pLayout) {
        this->m_pLayout->InstallFrame();
    }
}
