/*
 *  CharArrayList.h
 *  Edgar Gonzalez
 *  2026-01-28
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  FILE PURPOSE HERE
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H
#include <string>
#include <chrono>

class CharArrayList {  
    public:
                              
        CharArrayList();     
        // Default Constructor
        CharArrayList(char c);   
        // Constructor for single character
        CharArrayList(char arr[], int size);  
        // Constructor for array of characters
        CharArrayList(const CharArrayList &other);    
        // Copy Constructor
        ~CharArrayList();  
        //Deconstructor
        
        CharArrayList& operator=(const CharArrayList &other); 
        //Assignment Operator overload  
        void clear();               
        //Clears the CharArrayList
        bool isEmpty() const;     
        //Checks if the CharArrayList is empty
        int size() const;    
        //Returns the number of elements in the CharArrayList
        char first() const;      
        //Returns the first element in the CharArrayList
        char last() const;         
        //Returns the last element in the CharArrayList
        char elementAt(int index) const; 
        //Returns the element at a specified index
        std::string toString() const;  
        //String representation of CharArrayList
        std::string toReverseString() const;    
        //String representation of CharArrayList in reverse order
        void pushAtBack(char c);  
        //Adds a character to the back of the CharArrayList
        void pushAtFront(char c);   
        //Adds a character to the front of the Char
        void insertAt(char c, int index);  
        //Inserts a character at a specified index
        void insertInOrder(char c);  
        //Inserts a character in order (assuming the list is sorted)    
        void popFromFront();   
        //Removes the first character from the CharArrayList
        void popFromBack();   
        //Removes the last character from the CharArrayList
        void removeAt(int index);       
        //Removes the character at a specified index
        void replaceAt(char c, int index);   
        //Replaces the character at a specified index with a new character   
        void concatenate(const CharArrayList *other); 
        //Concatenates another CharArrayList 


    private:
        int capacity;   
        //maximum number of elements the CharArrayList can hold
        int numItems;   
        //number of elements in the CharArrayList
        char* data;     
        //pointer to dynamic array of characters
        void ensureCapacity(); 
        //doubles the capacity of the CharArrayList when needed
};
#endif
