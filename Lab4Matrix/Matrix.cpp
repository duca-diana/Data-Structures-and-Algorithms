//
// Created by Diana Duca on 23.05.2023.
//

#include "Matrix.h"
#include <exception>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols) : nrL{ nrLines }, nrC{ nrCols } {
    size = 0;
    cap = 10;
    chain = new Node * [cap];
    for (int i = 0; i < 10; i++)
        chain[i] = NULL;
}
//Theta(cap)

int Matrix::nrLines() const {
    return nrL;
}
//Theta(1)

int Matrix::nrColumns() const {
    return nrC;
}
//Theta(1)

TElem Matrix::element(int i, int j) const {
    if (i >= nrL || j >= nrC || i < 0 || j < 0)
        throw exception();
    int key = (i * j) % cap;
    Node* temp = chain[key];
    while (temp) {
        if (temp->line == i && temp->column == j)
            return temp->value;
        temp = temp->next;
    }
    return NULL_TELEM;
}
//BC: Theta(1)
//WC: Theta(cap)

TElem Matrix::modify(int i, int j, TElem e) {
    TElem old = NULL_TELEM;
    if (i >= nrL || j >= nrC || i < 0 || j < 0)
        throw exception();
    if ((float)size / (float)cap > 0.7)
        resize();
    Node* newNode = new Node();
    newNode->line = i;
    newNode->column = j;
    newNode->value = e;
    newNode->next = NULL;
    int key = (i * j) % cap;
    if (chain[key] == NULL)
        chain[key] = newNode;
    else {
        Node* temp = chain[key];
        while (temp->next && (temp->line != i || temp->column != j))
            temp = temp->next;
        if (temp->line == i && temp->column == j) {
            old = temp->value;
            temp->value = e;
        }
        else
            temp->next = newNode;
    }
    return old;
}
//BC: Theta(1)
//WC: Theta(cap)

void Matrix::resize() {
    Node** newChain = new Node * [cap * 2];
    for (int i = 0; i < cap * 2; i++)
        newChain[i] = NULL;
    int oldCap = cap;
    cap = cap * 2;
    for (int i = 0; i < oldCap; i++) {
        Node* temp = chain[i];
        while (temp) {
            auto prev = temp;
            int key = (temp->line * temp->column) % cap;
            Node* newNode = new Node;
            newNode->line = temp->line;
            newNode->column = temp->column;
            newNode->value = temp->value;
            newNode->next = newChain[key];
            temp = temp->next;
            delete prev;
        }
    }
    delete[]chain;
    chain = newChain;
}

std::pair<int, int> Matrix::positionOf(TElem elem) const {
    for (int i = 0; i < cap; i++) {
        Node* temp = chain[i];
        while (temp) {
            if (temp->value == elem)
                return std::make_pair(temp->line, temp->column);
            temp = temp->next;
        }
    }
    return std::make_pair(-1, -1); // If elem is not found, return <-1, -1>
}
//Th(cap)