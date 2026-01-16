//
// Created by dingrui on 1/16/26.
//

#include "fly_weight.h"

#include <iostream>

Piece::Piece(PieceColor color, PiecePos pos)
    : m_color(color), m_pos(pos) {
}

BlackPiece::BlackPiece(PieceColor color, PiecePos pos)
    : Piece(color, pos) {
}

void BlackPiece::draw() {
    std::cout << "BlackPiece::draw()" << std::endl;
}

WhitePiece::WhitePiece(PieceColor color, PiecePos pos)
    : Piece(color, pos) {
}

void WhitePiece::draw() {
    std::cout << "WhitePiece::draw()" << std::endl;
}

PieceBoard::PieceBoard(std::string black, std::string white)
    : m_blackName(black), m_whiteName(white) {
}

PieceBoard::~PieceBoard() {
    this->Clear();
}

void PieceBoard::Clear() {
    for (auto it = this->m_pieces.begin(); it != this->m_pieces.end(); ++it) {
        delete *it;
    }
}

void PieceBoard::SetPiece(PieceColor color, PiecePos pos) {
    Piece *p = nullptr;
    if (color == PieceColor::BLACK) {
        p = new BlackPiece(color, pos);
    } else {
        p = new WhitePiece(color, pos);
    }
    std::cout << "cur is " << color << " at " << pos.m_x << " ," << pos.m_y << std::endl;
    this->m_pieces.push_back(p);
}
