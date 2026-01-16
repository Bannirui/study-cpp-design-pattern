//
// Created by dingrui on 1/16/26.
//

#pragma once

#include <vector>
#include <string>

enum PieceColor { BLACK, WHITE };

struct PiecePos {
    int m_x;
    int m_y;

    PiecePos(int x, int y) : m_x(x), m_y(y) {
    }
};

class Piece {
public:
    Piece(PieceColor color, PiecePos pos);

    virtual ~Piece() =0;

    virtual void draw() {
    };

protected:
    PieceColor m_color;
    PiecePos m_pos;
};

class BlackPiece : public Piece {
public:
    BlackPiece(PieceColor color, PiecePos pos);

    ~BlackPiece() override = default;

    void draw() override;
};

class WhitePiece : public Piece {
public:
    WhitePiece(PieceColor color, PiecePos pos);

    ~WhitePiece() override = default;

    void draw() override;
};

class PieceBoard {
public:
    PieceBoard(std::string black, std::string white);

    ~PieceBoard();

    void Clear();

    void SetPiece(PieceColor color, PiecePos pos);

private:
    std::vector<Piece *> m_pieces;
    std::string m_blackName;
    std::string m_whiteName;
};
