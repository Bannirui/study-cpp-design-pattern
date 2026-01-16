//
// Created by dingrui on 1/16/26.
//

#include "fly_weight.h"

#include <iostream>

Piece::Piece(PieceColor color)
    : m_color(color) {
}

BlackPiece::BlackPiece(PieceColor color)
    : Piece(color) {
}

void BlackPiece::draw() {
    std::cout << "BlackPiece::draw()" << std::endl;
}

WhitePiece::WhitePiece(PieceColor color)
    : Piece(color) {
}

void WhitePiece::draw() {
    std::cout << "WhitePiece::draw()" << std::endl;
}

PieceBoard::PieceBoard(std::string black, std::string white)
    : m_blackName(black), m_whiteName(white), m_pBlack(nullptr), m_pWhite(nullptr) {
}

PieceBoard::~PieceBoard() {
    this->Clear();
}

void PieceBoard::Clear() {
    if (!this->m_pBlack) {
        delete this->m_pBlack;
    }
    if (!this->m_pWhite) {
        delete this->m_pWhite;
    }
}

void PieceBoard::SetPiece(PieceColor color, PiecePos pos) {
    if (color == PieceColor::BLACK) {
        if (!this->m_pBlack) {
            this->m_pBlack = new BlackPiece(color);
        }
        this->m_pBlack->draw();
    } else {
        if (!this->m_pWhite) {
            this->m_pWhite = new WhitePiece(color);
        }
        this->m_pWhite->draw();
    }
    std::cout << "cur is " << color << " at " << pos.m_x << " ," << pos.m_y << std::endl;
    this->m_pieces.push_back(pos);
}
