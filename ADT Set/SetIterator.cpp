#include "SetIterator.h"
#include "Set.h"
#include <exception>

using namespace std;
SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
    this->current = 0;
}

//theta(1)
void SetIterator::first() {
	//TODO - Implementation
    this->current = 0;
}

//theta(1)
void SetIterator::next() {
	//TODO - Implementation
    if (!valid()){
        throw exception();
    } else {
        this->current++;
    }
}

//theta(1)
TElem SetIterator::getCurrent()
{
	//TODO - Implementation
    if (!valid()){
        throw exception();
    }
    return this->set.elements[this->current];
	//return NULL_TELEM;
}

//theta(1)
bool SetIterator::valid() const {
	//TODO - Implementation
    return (this->current < this->set.nrElems);
}



