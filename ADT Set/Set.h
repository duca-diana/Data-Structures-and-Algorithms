#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
typedef int TElem;
class SetIterator;

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

    private:
		//TODO - Representation
        //What is an ADT Set? Sets are type of abstract data type that allows you to store a list of UNIQUE values.The sets are unordered and unindexed
        int nrElems;
        int capacity;
        TElem* elements;


    public:
        //implicit constructor
        Set();

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;

        //removes all the elements from the Set
        void empty();

        //return an iterator for the set
        SetIterator iterator() const;

        // destructor
        ~Set();

};





