//
// Created by dingrui on 1/16/26.
//

#include "fly_weight.h"

int main() {
    PieceBoard board("AA", "BB");
    board.SetPiece(PieceColor::BLACK, PiecePos(1, 2));
    board.SetPiece(PieceColor::BLACK, PiecePos(11, 22));
    board.SetPiece(PieceColor::WHITE, PiecePos(1111, 222));
    board.SetPiece(PieceColor::BLACK, PiecePos(1111, 2222));
    board.SetPiece(PieceColor::WHITE, PiecePos(132, 22222));
    return 0;
}
