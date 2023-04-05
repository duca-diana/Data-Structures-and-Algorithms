#include "Set.h"
#include "SetITerator.h"

Set::Set() {
    this->nrElems=0;
    this->capacity = 10;
    this->elements = new TElem[this->capacity];
}

//best case theta(1)
//worst case theta(n)
//total complexity: o(n)
bool Set::add(TElem elem) {
	//TODO - Implementation
    if (search(elem))
        return false;

    if (this->nrElems == this->capacity){
        //resize
        this->capacity *= 2;
        TElem* newElements = new TElem[this->capacity];
        for (int i = 0; i < this->nrElems; i++)
        {
            newElements[i] = this->elements[i];
        }
        delete[](this->elements);
        this->elements = newElements;
    }

    if(this->nrElems == 0){
        this->elements[nrElems] = elem;
        this->nrElems++;
        return true;
    } else if (this->nrElems == 1){
            this->elements[nrElems] = elem;
            this->nrElems++;
            return true;
        }
    else {
        this->elements[nrElems]=elem;
        this->nrElems++;
        return true;
    }
}



//best case theta(nr_elements)
//worst case theta(nr_elements)
//total complexity: o(n)
bool Set::remove(TElem elem) {
	//TODO - Implementation
    if (!search(elem)){
        return false;
    } else {
        int index=0;
        for (int i = 0; i<this->nrElems;i++){
            if (this->elements[i] == elem){
                index = i;
                i=this->nrElems;
            }
        }
        for (int i = index; i<this->nrElems-1;i++){
            this->elements[i] = this->elements[i+1];
        }
        this->nrElems--;
        return true;
    }
}
//theta(n)
bool Set::search(TElem elem) const {
	//TODO - Implementation
    bool exists=false;
    for(int i=0;i<nrElems;i++)
        if(this->elements[i]==elem)
            exists=true;

	return exists;
}

//theta(1)
int Set::size() const {
	//TODO - Implementation
	return this->nrElems;
}

//theta(1)
bool Set::isEmpty() const {
	//TODO - Implementation
    return (this->nrElems == 0);
}

//best case theta(2*nr_elements)
//worst case theta(2*nr_elements)
//total complexity: o(2*n)
void Set::empty() {
    for(int i=nrElems-1;i>=0;i--){
        this->remove(elements[i]);
    }
//    delete[] this->elements;
//    this->nrElems=0;
}

//theta(1)
Set::~Set() {
	//TODO - Implementation
    delete[] this->elements;
}


//theta(1)
SetIterator Set::iterator() const {
	return SetIterator(*this);
}



