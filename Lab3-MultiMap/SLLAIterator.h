//
// Created by Diana Duca on 23.05.2023.
//

#ifndef MULTIMAP_SLLAITERATOR_H
#define MULTIMAP_SLLAITERATOR_H

#pragma once
#include "../../CLionProjects/Lab3-MultiMap/SLLA.h"

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
class SLLAIterator {
private:
    //Constructor receives a reference of the container.
    SLLAIterator(const SLLA& c);

    //contains a reference of the container it iterates over
    const SLLA& c;
    /* representation specific for the iterator*/
    int currentKey;
    int elementsIterated;
    friend class SLLA;
public:

    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;

};

#endif //MULTIMAP_SLLAITERATOR_H
