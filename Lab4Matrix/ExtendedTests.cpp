//
// Created by Diana Duca on 23.05.2023.
//

#include <assert.h>
#include "Matrix.h"
#include "ExtendedTests.h"
#include <iostream>
#include <exception>

using namespace std;


void testCreate() {
    cout << "Test create" << endl;
    Matrix m(10, 10);
    assert(m.nrLines() == 10);
    assert(m.nrColumns() == 10);
    for (int i = 0; i < m.nrLines(); i++)
        for (int j = 0; j < m.nrColumns(); j++)
            assert(m.element(i, j) == NULL_TELEM);
}

void testModify() {
    cout << "Test modify" << endl;
    Matrix m(10, 10);
    for (int j = 0; j < m.nrColumns(); j++)
        m.modify(4, j, 3);
    for (int i = 0; i < m.nrLines(); i++)
        for (int j = 0; j < m.nrColumns(); j++)
            if (i == 4)
                assert(m.element(i, j) == 3);
            else
                assert(m.element(i, j) == NULL_TELEM);
}

void testQuantity() {
    cout << "Test quantity" << endl;
    Matrix m(200, 300);
    for (int i = m.nrLines() / 2; i < m.nrLines(); i++) {
        for (int j = 0; j <= m.nrColumns() / 2; j++)
        {
            int v1 = j;
            int v2 = m.nrColumns() - v1 - 1;
            if (i % 2 == 0 && v1 % 2 == 0)
                m.modify(i, v1, i*v1);
            else
            if (v1 % 3 == 0)
                m.modify(i, v1, i + v1);
            if (i % 2 == 0 && v2 % 2 == 0)
                m.modify(i, v2, i*v2);
            else
            if (v2 % 3 == 0)
                m.modify(i, v2, i + v2);
        }
    }
    for (int i = 0; i <= m.nrLines() / 2; i++) {
        for (int j = 0; j <= m.nrColumns() / 2; j++)
        {
            int v1 = j;
            int v2 = m.nrColumns() - v1 - 1;
            if (i % 2 == 0 && v1 % 2 == 0)
                m.modify(i, v1, i*v1);
            else
            if (v1 % 3 == 0)
                m.modify(i, v1, i + v1);
            if (i % 2 == 0 && v2 % 2 == 0)
                m.modify(i, v2, i*v2);
            else
            if (v2 % 3 == 0)
                m.modify(i, v2, i + v2);
        }
    }
    for (int i = 0; i < m.nrLines(); i++)
        for (int j = 0; j < m.nrColumns(); j++)
            if (i % 2 == 0 && j % 2 == 0)
                assert(m.element(i, j) == i * j);
            else
            if (j % 3 == 0)
                assert(m.element(i, j) == i + j);
            else assert(m.element(i, j) == NULL_TELEM);
}

void testExceptions() {
    cout << "Test exceptions" << endl;
    Matrix m(10, 10);
    try {
        m.element(-10, 0);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {
        m.modify(12, 0, 1);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {
        assert(m.nrLines());
    }
    catch (exception&) {
        assert(false);
    }
}

void testMix() {
    cout << "Test mix" << endl;
    int size = 2000;
    Matrix m(size/2, size);
    for (int i = 0; i < size/2; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                m.modify(i, j, 11);
            }
            else if (i == 100 * j) {
                m.modify(i, j, 111);
            }
            else if ((i + j) % 1111 == 0) {
                m.modify(i, j, 1111);
            }
        }
    }

    for (int i = 0; i < size/2; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                TElem old = m.modify(i, j, NULL_TELEM);
                assert(old == 11);
            }
            else if (i == 100 * j) {
                TElem old = m.modify(i, j, -111);
                assert(old == 111);
            }
            else if ((i + j) % 1111 == 3) {
                m.modify(i, j, 1);
            }
        }
    }
    for (int i = 0; i < size/2; i++) {
        for (int j = 0; j < size; j++) {
            TElem e = m.element(i, j);
            if (i == j) {
                assert(e == NULL_TELEM);
            }
            else if (i == 100 * j) {
                assert(e == -111);
            }
            else if ((i + j) % 1111 == 3) {
                assert(e == 1);
            }
            else if ((i + j) % 1111 == 0) {
                assert(e == 1111);
            }
            else {
                assert(e == NULL_TELEM);
            }
        }
    }

}
void testPositionOf() {
    cout << "Test positionOf" << endl;
    Matrix m(3, 3);

    //Empty matrix
    assert(m.positionOf(5) == std::make_pair(-1, -1));

    //Matrix with a single element
    m.modify(1, 1, 5);
    assert(m.positionOf(5) == std::make_pair(1, 1));

    //Matrix with multiple elements
    m.modify(0, 2, 10);
    m.modify(2, 1, 7);
    assert(m.positionOf(10) == std::make_pair(0, 2));
    assert(m.positionOf(7) == std::make_pair(2, 1));
    assert(m.positionOf(3) == std::make_pair(-1, -1)); // Element not in the matrix

    //Matrix with repeated elements
    m.modify(1, 2, 5);
    assert(m.positionOf(5) == std::make_pair(1, 1) || m.positionOf(5) == std::make_pair(1, 2));

}

void testAllExtended() {
        testPositionOf();
        testCreate();
        testModify();
        testQuantity();
        testMix();
        testExceptions();

}
