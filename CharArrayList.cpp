/*
 *  CharArrayList.cpp
 *  Edgar Gonzalez
 *  2026-01-28
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  FILE PURPOSE HERE
 *
 */

#include "CharArrayList.h"
#include <iostream>
using namespace std;


/*  
 * name:     CharArrayList default constructor
 * purpose:   initialize an empty CharArrayList
 * arguments: none
 * returns:   none
 * effects:   initializes capacity to 0, numItems to 0, and data to nullptr
*/
CharArrayList::CharArrayList() : capacity(0), numItems(0), data(nullptr) {}
    
/*  
 * name:      CharArrayList single character constructor
 * purpose:   initialize a CharArrayList with a single character
 * arguments: a character to add to the CharArrayList
 * returns:   the letter A 
 * effects:   initializes capacity and numItems to 1, allocates memory for data,
 *            and stores the character in data[0]
*/
CharArrayList::CharArrayList(char c) : capacity(1), numItems(1) {
    
    data = new char[capacity];          // allocate heap memory for a single . 
    data[0] = c;                        // store the character in the array, 
}

/*
    *  name:     CharArrayList array constructor
    * purpose:   initialize a CharArrayList with an array of characters
    * arguments: an array of characters and the size of the array
    * returns:   none  
    * effects:   tbd
*/
CharArrayList::CharArrayList(char arr[], int size) : capacity(size), numItems
(size) {
    data = new char[capacity];          
    // DEEP COPY: allocate heap memory for the array of characters
    for (int i = 0; i < size; i++) {    
    // copy each character from the input array to data
            data[i] = arr[i];
        } 
}  
  
/*
 * name:     CharArrayList copy constructor
 * purpose:   create a deep copy of another CharArrayList
 * arguments: a reference to another CharArrayList
 * returns:   none  
 * effects:   allocates new memory for data and copies the contents of the 
 * other CharArrayList
*/
CharArrayList::CharArrayList(const CharArrayList &other) :
    capacity(other.capacity), numItems(other.numItems),
    data(new char[capacity]) 
{          
    // allocate heap memory for the array of characters
    for (int i = 0; i < numItems; i++) {    
        // copy each character from the other CharArrayList to data
        data[i] = other.data[i];
    } 
}

/* 
 * name:      CharArrayList destructor
 * purpose:   free memory associated with the CharArrayList
 * arguments: none
 * returns:   none  
 * effects:   frees the memory allocated for data
*/
CharArrayList::~CharArrayList() {}

/*
 * name:      CharArrayList assignment operator overload
 * purpose:   assign the contents of another CharArrayList to this 
 * CharArrayList
 * arguments: a reference to another CharArrayList
 * returns:   a reference to this CharArrayList
 * effects:   frees existing memory, allocates new memory, and copies 
 * contents of other CharArrayList
*/
CharArrayList& CharArrayList::operator=(const CharArrayList &other) {
    if (this == &other) {           // self-assignment check    
        return *this;               // if assigning to self, do nothing
    }
    delete[] data;                      // This 'recycles' (releases) 
    capacity = other.capacity;          // copy capacity from other
    numItems = other.numItems;          // copy numItems from other
    data = new char[capacity];          // allocate new heap memory
    for (int i = 0; i < numItems; i++) {  // copy each character
        data[i] = other.data[i];           // DEEP COPY
    }               
    return *this;
}

/*
* name:      clear function
* purpose:   to clear the CharArrayList
* arguments: none
* returns:   none  
* effects:   sets numItems to 0
*/
void CharArrayList::clear() {
    numItems = 0;   // set number of items to 0 
}

/*
 * name:      isEmpty function
 * purpose:   to check if the CharArrayList is empty
 * arguments: none
 * returns:   true if empty, false otherwise  
 * effects:   it was tested and returned correctly
*/
bool CharArrayList::isEmpty() const {
    return numItems == 0;
}   

/*
  * name:      size function 
  * purpose:   to return the number of elements in the CharArrayList
  * arguments: none
  * returns:   number of elements in the CharArrayList  
  * effects:   After testing, it returned the correct size and printed clear 
  * test 
  * passed!
*/
int CharArrayList::size() const {
    return numItems;
}

/*
 * name:      first function
 * purpose:   to return the first element in the CharArrayList
 * arguments: none
 * returns:   the first element in the CharArrayList  
 * effects:   it was tested and returned the correct first element and gave 
 * the correct error message when empty
*/
char CharArrayList::first() const {
    if (isEmpty()) {
        throw std::range_error("cannot get first of empty ArrayList");
    }
    return data[0];
}

/*
* name:      last function
* purpose:   to return the last element in the CharArrayList
* arguments: none
* returns:   the last element in the CharArrayList  
* effects:   it was tested and returned the correct last element and gave the 
*correct 
*error message when empty
*/  
char CharArrayList::last() const {
    if (isEmpty()) {
        throw std::range_error("cannot get last of empty ArrayList");
    }
    return data[numItems - 1];
}

/*
 * name:      elementAt function
 * purpose:   to return the element at a specified index
 * arguments: an index
 * returns:   the element at the specified index  
 * effects:   it was tested and returned the correct element and gave the 
 * correct error message for out-of-range index
*/
char CharArrayList::elementAt(int index) const {
    if (index < 0 || index >= numItems) {
        throw std::range_error("index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + ")");
    }
    return data[index];
}

/* name:      Tostring function 
 * purpose:   to be used for debugging purposes
 * arguments: for loop to iterate through the CharArrayList
 * returns:   a string representation of the CharArrayList 
 * effects:   it was tested and returned the correct string representation
*/
std::string CharArrayList::toString() const {
    std::string result = "[CharArrayList of size " + std::to_string(numItems) 
    + " <<";
    for (int i = 0; i < numItems; i++) {
        result += data[i];
    }
    result += ">>]";
    return result;
}

/* name:      toReverseString function 
 * purpose:   to be used for debugging purposes
 * arguments: for loop to iterate through the CharArrayList in reverse order
 * returns:   a string representation of the CharArrayList in reverse order
 * effects:   it was tested and returned the correct reverse string 
 * representation
*/
std::string CharArrayList::toReverseString() const {
    std::string result = "[CharArrayList of size " + std::to_string(numItems) 
    + " <<";
    for (int i = numItems - 1; i >= 0; i--) {
        result += data[i];
    }
    result += ">>]";
    return result;
}

/*
 * name:      pushAtBack function 
 * purpose:   to add a character to the back of the CharArrayList
 * arguments: a character to add to the back
 * returns:    the letter with the character added at the back
 * effects:   after testing, it added the character correctly at the back
*/
void CharArrayList::pushAtBack(char c) {
    ensureCapacity();               // ensure there is enough capacity
    data[numItems] = c;             // add the character at the back
    numItems++;                     // increment the number of items
}

/*
 * name:      pushAtFront function 
 * purpose:   to add a character to the front of the CharArrayList
 * arguments: a character to add
 * returns:   the letter with the character added at the front 
 * effects:   after testing, it added the character correctly at the front
*/
void CharArrayList::pushAtFront(char c) {
    ensureCapacity();
    for (int i = numItems; i > 0; i--) {
        data[i] = data[i - 1];
    }
    data[0] = c;
    numItems++;
}        

/*
    * name:      insertAt function 
    * purpose:   to insert a character at a specified index
    * arguments: a character and an index
    * returns:   a letter with the character inserted at the specified index
    * effects:   after testing, it inserted the character correctly at the 
    * specified index
    *
*/
void CharArrayList::insertAt(char c, int index) {
    // 1. Range Check
    if (index < 0 || index > numItems) {
        throw std::range_error("index (" + std::to_string(index) 
        + ") not in range [0.." + std::to_string(numItems) + "]");
    } 
    // 2. Ensure Capacity
    ensureCapacity();
    // 3. Shift elements to the right
    for (int i = numItems; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = c;
    numItems++;
}

/*
    * name:      insertInOrder function 
    * purpose:   to insert a character in order (assuming the list is sorted)
    * arguments: a character to insert
    * returns:   a list with the character inserted in order 
    * effects:     after testing, it inserted the character correctly in order
*/
void CharArrayList::insertInOrder(char c) {
    // find the correct index to insert the character
    int index = 0;
    while (index < numItems && data[index] < c) {
        index++;
    }
    // insert the character at the found index
    insertAt(c, index);
}   

/*
 * name:      popFromFront function 
 * purpose:   to remove the first character from the CharArrayList
 * arguments: none
 * returns:   none  
 * effects:   after testing, it removed the first character correctly
*/
void CharArrayList::popFromFront() {
    if (isEmpty()) {
        throw std::range_error("cannot pop from empty ArrayList");
    }       
    for (int i = 0; i < numItems - 1; i++) {
        data[i] = data[i + 1]; // shift elements to the left
    }
    numItems--;
}

/*
 * name:      popFromBack function 
 * purpose:   to remove the last character from the CharArrayList
 * arguments: none
 * returns:   none  
 * effects:   after testing, it removed the last character correctly
*/
void CharArrayList::popFromBack() {
    if (isEmpty()) {
        throw std::range_error("cannot pop from empty ArrayList");
    }
    numItems--;
}   

/*
 * name:      removeAt function 
 * purpose:   to remove the character at a specified index
 * arguments: an index
 * returns:   none  
 * effects:   after testing, it removed the character at the 
 * specified index correctly
*/
void CharArrayList::removeAt(int index) {
    if (index < 0 || index >= numItems) {       
        throw std::range_error("index (" + std::to_string(index)
        + ") not in range [0.." + std::to_string(numItems) + ")");
    }
    for (int i = index; i < numItems - 1; i++) {
        data[i] = data[i + 1]; // shift elements to the left
    }
    numItems--;
}   

/*
 * name:      replaceAt function 
 * purpose:   to replace the character at a specified index with a 
 * new character
 * arguments: a character and an index
 * returns:   none  
 * effects:   after testing, it replaced the character at the 
 * specified index correctly
*/
void CharArrayList::replaceAt(char c, int index) {          
    if (index < 0 || index >= numItems) {       
        throw std::range_error("index (" + std::to_string(index) 
        + ") not in range [0.." + std::to_string(numItems) + ")");
    }
    data[index] = c; // replace the character at the specified index
}           

/*
 * name:      concatenate function 
 * purpose:   to concatenate another CharArrayList to the end of 
 * this CharArrayList
 * arguments: a reference to another CharArrayList
 * returns:   none  
 * effects:   after testing, it concatenated the other 
 * CharArrayList correctly
*/
void CharArrayList::concatenate(const CharArrayList *other) {
    int sizeToAdd = other->numItems;
    while (this->numItems + sizeToAdd > this->capacity) {
        ensureCapacity();
    }
    for (int i = 0; i < sizeToAdd; i++) {
        this->pushAtBack(other->data[i]);
    }
}
     

/*
 * name:      ensureCapacity function 
 * purpose:   to double the capacity of the CharArrayList when needed
 * arguments: none
 * returns:   none  
 * effects:   doubles the capacity of the CharArrayList and 
 * reallocates memory
*/
void CharArrayList::ensureCapacity() {
    if (numItems >= capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;    
        char* newData = new char[newCapacity];
        for (int i = 0; i < numItems; i++) {            
            newData[i] = data[i];
        }           
        delete[] data;
        data = newData;
        capacity = newCapacity;     
    }               
}       
