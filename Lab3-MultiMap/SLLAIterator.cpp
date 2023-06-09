//
// Created by Diana Duca on 23.05.2023.
//

#include "SLLAIterator.h"
#include <stdexcept>

SLLAIterator::SLLAIterator(const SLLA& slla) : c(slla) {
    this->currentKey = slla.head;
    this->elementsIterated = 0;
    //theta(1)
}

void SLLAIterator::first() {
    this->currentKey = this->c.head;
    this->elementsIterated = 0;
    //theta(1)
}

void SLLAIterator::next() {
    if (this->valid() == false)
        throw std::invalid_argument("");
    this->currentKey = this->c.next[this->currentKey];
    this->elementsIterated++;
    //theta(1)
}

bool SLLAIterator::valid() const {
    if (this->currentKey == -1)
        return false;
    //if(this->elementsIterated==this->c.size)
    if(this->c.next[this->currentKey]==-1)
        return false;
    return true;
    //theta(1)
}

TElem SLLAIterator::getCurrent() const {
    if (this->valid() == false)
        throw std::invalid_argument("");
    return this->c.elements[this->currentKey];
    //theta(1)
}