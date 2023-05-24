//
// Created by Diana Duca on 23.05.2023.
//

#ifndef LAB4MATRIX_MATRIX_H
#define LAB4MATRIX_MATRIX_H
#pragma once
#include <utility>
typedef int TElem;
#define NULL_TELEM 0

struct Node {
    int line;
    int column;
    TElem value;
    Node* next;//pointer to the next node in the list
};

class Matrix {
private:
    int nrL;
    int nrC;
    int size;
    int cap;//capacity of the hash table
    Node **chain;//an array of pointers to nodes, representing the hash table
    void resize();

public:
    //constructor
    Matrix(int nrLines, int nrCols);

    //returns the number of lines
    int nrLines() const;

    //returns the number of columns
    int nrColumns() const;

    //returns the element from line i and column j (indexing starts from 0)
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem element(int i, int j) const;

    //modifies the value from line i and column j
    //returns the previous value from the position
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem modify(int i, int j, TElem e);

    //returns the position of element elem from the Matrix (as a line, column pair).
    // If elem occurs multiple times, any position where it appears is fine. If elem is not in the Matrix, return the pair <-1, -1>.
    std::pair<int,int> positionOf(TElem elem) const;
};



#endif //LAB4MATRIX_MATRIX_H
