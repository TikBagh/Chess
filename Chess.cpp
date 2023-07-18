#include <iostream>
#include <vector>

enum class PieceType {
    Bishop,
    Knight,
    Queen,
    King
};

enum class PieceColor {
    White,
    Black
};

class ChessPiece {
public:
    PieceType type;
    PieceColor color;

public:
    ChessPiece(PieceType pieceType, PieceColor pieceColor) : type(pieceType), color(pieceColor) {}

    virtual std::vector<std::vector<bool>> getValidMoves(const std::vector<std::vector<ChessPiece*>>& board) const = 0;
};

class Bishop : public ChessPiece {
public:
    Bishop(PieceColor pieceColor) : ChessPiece(PieceType::Bishop, pieceColor) {}

    std::vector<std::vector<bool>> getValidMoves(const std::vector<std::vector<ChessPiece*>>& board) const override {
        std::vector<std::vector<bool>> validMoves(8, std::vector<bool>(8, false));

        int currentRow, currentCol;
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col] == this) {
                    currentRow = row;
                    currentCol = col;
                    break;
                }
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow - i >= 0 && currentCol + i < 8) {
                if (board[currentRow - i][currentCol + i] == nullptr || board[currentRow - i][currentCol + i]->color != color) {
                    validMoves[currentRow - i][currentCol + i] = true;
                    if (board[currentRow - i][currentCol + i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow - i >= 0 && currentCol - i >= 0) {
                if (board[currentRow - i][currentCol - i] == nullptr || board[currentRow - i][currentCol - i]->color != color) {
                    validMoves[currentRow - i][currentCol - i] = true;
                    if (board[currentRow - i][currentCol - i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow + i < 8 && currentCol + i < 8) {
                if (board[currentRow + i][currentCol + i] == nullptr || board[currentRow + i][currentCol + i]->color != color) {
                    validMoves[currentRow + i][currentCol + i] = true;
                    if (board[currentRow + i][currentCol + i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow + i < 8 && currentCol - i >= 0) {
                if (board[currentRow + i][currentCol - i] == nullptr || board[currentRow + i][currentCol - i]->color != color) {
                    validMoves[currentRow + i][currentCol - i] = true;
                    if (board[currentRow + i][currentCol - i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        return validMoves;
    }
};


class Knight : public ChessPiece {
public:
    Knight(PieceColor pieceColor) : ChessPiece(PieceType::Knight, pieceColor) {}

    std::vector<std::vector<bool>> getValidMoves(const std::vector<std::vector<ChessPiece*>>& board) const override {
        std::vector<std::vector<bool>> validMoves(8, std::vector<bool>(8, false));

        int currentRow, currentCol;
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col] == this) {
                    currentRow = row;
                    currentCol = col;
                    break;
                }
            }
        }

        int x[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (int i = 0; i < 8; ++i) {
            int newRow = currentRow + x[i];
            int newCol = currentCol + y[i];
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                if (board[newRow][newCol] == nullptr || board[newRow][newCol]->color != color) {
                    validMoves[newRow][newCol] = true;
                }
            }
        }

        return validMoves;
    }
};

class Queen : public ChessPiece {
public:
    Queen(PieceColor pieceColor) : ChessPiece(PieceType::Queen, pieceColor) {}

    std::vector<std::vector<bool>> getValidMoves(const std::vector<std::vector<ChessPiece*>>& board) const override {
        std::vector<std::vector<bool>> validMoves(8, std::vector<bool>(8, false));

        int currentRow, currentCol;
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col] == this) {
                    currentRow = row;
                    currentCol = col;
                    break;
                }
            }
        }

        for (int i = 0; i < 8; ++i) {
            if (i != currentCol) {
                if (board[currentRow][i] == nullptr || board[currentRow][i]->color != color) {
                    validMoves[currentRow][i] = true;
                }
            }
            if (i != currentRow) {
                if (board[i][currentCol] == nullptr || board[i][currentCol]->color != color) {
                    validMoves[i][currentCol] = true;
                }
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow - i >= 0 && currentCol - i >= 0) {
                if (board[currentRow - i][currentCol - i] == nullptr || board[currentRow - i][currentCol - i]->color != color) {
                    validMoves[currentRow - i][currentCol - i] = true;
                    if (board[currentRow - i][currentCol - i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow - i >= 0 && currentCol + i < 8) {
                if (board[currentRow - i][currentCol + i] == nullptr || board[currentRow - i][currentCol + i]->color != color) {
                    validMoves[currentRow - i][currentCol + i] = true;
                    if (board[currentRow - i][currentCol + i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow + i < 8 && currentCol - i >= 0) {
                if (board[currentRow + i][currentCol - i] == nullptr || board[currentRow + i][currentCol - i]->color != color) {
                    validMoves[currentRow + i][currentCol - i] = true;
                    if (board[currentRow + i][currentCol - i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        for (int i = 1; i < 8; ++i) {
            if (currentRow + i < 8 && currentCol + i < 8) {
                if (board[currentRow + i][currentCol + i] == nullptr || board[currentRow + i][currentCol + i]->color != color) {
                    validMoves[currentRow + i][currentCol + i] = true;
                    if (board[currentRow + i][currentCol + i] != nullptr)
                        break;
                }
                else
                    break;
            }
        }

        return validMoves;
    }
};

class King : public ChessPiece {
public:
    King(PieceColor pieceColor) : ChessPiece(PieceType::King, pieceColor) {}

    std::vector<std::vector<bool>> getValidMoves(const std::vector<std::vector<ChessPiece*>>& board) const override {
        std::vector<std::vector<bool>> validMoves(8, std::vector<bool>(8, false));

        int currentRow, currentCol;
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (board[row][col] == this) {
                    currentRow = row;
                    currentCol = col;
                    break;
                }
            }
        }

        int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

        for (int i = 0; i < 8; ++i) {
            int newRow = currentRow + x[i];
            int newCol = currentCol + y[i];
            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                if (board[newRow][newCol] == nullptr || board[newRow][newCol]->color != color) {
                    validMoves[newRow][newCol] = true;
                }
            }
        }

        return validMoves;
    }
};


class Matrix {
public:
    std::vector<std::vector<ChessPiece*>> board;

    Matrix() {
        board.resize(8, std::vector<ChessPiece*>(8, nullptr));
    }

    void addPiece(int row, int col, ChessPiece* piece) {
        board[row][col] = piece;
    }

    void displayBoard() const {
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if ((row + col) % 2 == 0) {
                    std::cout << "W";
                }
                else {
                    std::cout << "B";
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::vector<bool>> getAllValidMoves() const {
        std::vector<std::vector<bool>> allValidMoves(8, std::vector<bool>(8, false));

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                ChessPiece* piece = board[row][col];
                if (piece != nullptr) {
                    std::vector<std::vector<bool>> validMoves = piece->getValidMoves(board);
                    for (int i = 0; i < 8; ++i) {
                        for (int j = 0; j < 8; ++j) {
                          if (validMoves[i][j]) {
                                allValidMoves[i][j] = true;
                          }
                        }
                    }
                }
            }
        }

        return allValidMoves;
    }

    void displayValidMoves(const std::vector<std::vector<bool>>& validMoves) const {
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                std::cout << (validMoves[row][col] ? "1" : "0") << " ";
            }
            std::cout << std::endl;
        }
    }
};

class ChessGame {
private:
    Matrix board;

public:
    void start() {
          Bishop* bishop = new Bishop(PieceColor::White);
          Knight* knight = new Knight(PieceColor::White);
          Queen* queen = new Queen(PieceColor::White);
          King* WhiteKing = new King(PieceColor::White);
        


        board.addPiece(4, 4, bishop);
        board.addPiece(2, 2, knight);
        board.addPiece(1, 4, queen); 
        board.addPiece(2, 4, WhiteKing);
        

        board.displayBoard();
        std::cout << std::endl;

        std::vector<std::vector<bool>> allValidMoves = board.getAllValidMoves();

        std::cout << "Valid moves for all pieces:" << std::endl;
        board.displayValidMoves(allValidMoves);
    }
};

int main() {
    ChessGame game;
    game.start();

    return 0;
}