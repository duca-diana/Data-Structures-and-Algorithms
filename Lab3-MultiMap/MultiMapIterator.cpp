#include "MultiMapIterator.h"
#include "../../CLionProjects/Lab3-MultiMap/MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    this->currentPosition = c.elements->getHead();
    this->count = 0;
    this->size =c.elements->getSize();
    //theta(1)
}

TElem MultiMapIterator::getCurrent() const{
    if (this->valid() == false)
        throw std::invalid_argument("");
    return this->col.elements->elements[this->currentPosition];
    //theta(1)
}

bool MultiMapIterator::valid() const {
    if (this->size == 0)
        return false;
    if (this->count != this->size)
        return true;
    return false;
}

void MultiMapIterator::next() {
    if (this->valid() == false)
        throw std::invalid_argument("");
    this->currentPosition = this->col.elements->getNext()[this->currentPosition];
    this->count++;
    //theta(1)
}

void MultiMapIterator::first() {
    this->currentPosition = this->col.elements->getHead();
    this->count = 0;
    this->size = this->col.elements->getSize();
}

