#include "../../CLionProjects/Lab3-MultiMap/MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
    this->elements = new SLLA;
    //theta(1)
}

MultiMap::~MultiMap() {
    delete this->elements;
    //theta(1)
}

void MultiMap::add(TKey c, TValue v) {
    auto pair = make_pair(c, v);
    this->elements->add(pair);
    //O(n)
}

bool MultiMap::remove(TKey c, TValue v) {
    auto pair = make_pair(c, v);
    std::vector<TValue> values = this->search(c);
    if (values.size() == 0)
        return false;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] == v) {
            this->elements->remove(pair);
            return true;
        }
    }
    return false;
    //theta(n)
}

vector<TValue> MultiMap::search(TKey c) const {
    vector<TValue> elems;
    return this->elements->searchValue(c);
    //theta(n)
}

int MultiMap::size() const {
    return this->elements->getSize();
    //theta(1)
}

bool MultiMap::isEmpty() const {
    return this->elements->isEmpty();
    //theta(1)
}

MultiMapIterator MultiMap::iterator() const {
    return MultiMapIterator(*this);
    //theta(1)
}

int MultiMap::addIfNotPresent(MultiMap &m) {
    int addedPairs = 0;
    MultiMapIterator it = m.iterator();
    while (it.valid()) {
        TElem pair = it.getCurrent();
        // Check if the key is already present in the MultiMap
        vector<TValue> values = this->search(pair.first);
        bool keyExists = false;
        for (const auto& value : values) {
            if (value == pair.first) {
                keyExists = true;
                break;
            }
        }

        if (!keyExists) {
            this->add(pair.first, pair.second);
            addedPairs++;
        }

        it.next();
    }
    return addedPairs;
}
