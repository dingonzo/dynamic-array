/*
 * unit_tests.cpp
 *

 *
 * Example unit tests framework to test the CharArrayList class.
 *
 */

#include "CharArrayList.h"
#include <cassert>
#include <iostream>
//#include <chrono>
using namespace std;

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* To give an example of thorough testing, we are providing
 * the unit tests below which test the insertAt function. Notice: we have
 * tried to consider all of the different cases insertAt may be
 * called in, and we test insertAt in conjunction with other functions!
 *
 * You should emulate this approach for all functions you define.
 */

// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() {
    
     CharArrayList test_list;
        test_list.insertAt('A', 0);
        assert(test_list.size() == 1);
        assert(test_list.elementAt(0) == 'A');
    
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
    // insertAt for out-of-range index
    test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
    // if insertAt is correctly implemented, a range_error will be thrown,
    // and we will end up here
    range_error_thrown = true;
    error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");

}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
 
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');

}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {

    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
  
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
  
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
 
}

// Tests insertion into front of a larger list
void insertAt_front_large_list() {

        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('y', 0);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<yabcdefgh>>]");

}

// Tests insertion into the back of a larger list
void insertAt_back_large_list() {

        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('x', 8);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(8) == 'x');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<abcdefghx>>]");

}

// Tests insertion into the middle of a larger list
void insertAt_middle_large_list() {
 
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<abczdefgh>>]");

}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {

    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");

}

int main(){    

    // This calls the default constructor
    CharArrayList list1;             
    // This calls the single character constructor
    CharArrayList list2('a');        
    // This calls several character constructor 
    char arr[] = {'A', 'l', 'i', 'c', 'e'};
    CharArrayList list3(arr, 5);
    CharArrayList test_list;

    //Test size() on an empty list
    cout << list1.size() << ",";   // print 0
    // Test size() on a non-empty list
    cout << list2.size() << ",";   // print 1
    // Test size() on a larger non-empty list
    cout << list3.size() << endl;   // print 5
    
    // Test that should print an empty CharArrayList
    cout << list1.toString() << "it's empty!,";
    // Test that should print a CharArrayList  
    cout << list2.toString() << ",";
    // Test that should print a CharArrayList 
    cout << list3.toString() << endl;
    
    // Test that should print an empty CharArrayList 
    cout << list1.toReverseString() << "it's empty!,";
    // Test that should print a CharArrayList with one element 'A'  
    cout << list2.toReverseString() << ",";
    //Test that should print a CharArrayList with reverse elements 

    //Test pushAtBack function
    list1.pushAtBack('X');               
    cout << list1.toString() << ",";     
    // should print [CharArrayList of size 1 <<X>>]
    list2.pushAtBack('T');               
    cout << list2.toString() << ",";      
    // should print [CharArrayList of size 2 <<AT>>]
    list3.pushAtBack('!');               
    cout << list3.toString() << endl;    
    // should print [CharArrayList of size 6 <<Alice!>>]

    list1 = CharArrayList();   // resetting list1 
    list2 = CharArrayList('A'); // resetting list2 
    list3 = CharArrayList(arr, 5); // resetting list3 

    //Test pushAtFront function
    list1.pushAtFront('Y');              
    // pushing 'Y' to the front of list with one element 
    cout << list1.toString() << ",";     
    // shoudl print [CharArrayList of size 1 <<Y>>]
    list2.pushAtFront('B');
    // pushing 'B' to the front of list with one element 'A'              
    cout << list2.toString() << ","; 
    list3.pushAtFront('Z'); 
    // pushing 'Z' to the front of list with elements 'A', 'l', 'i', 'c', 'e'             
    cout << list3.toString() << endl;    

    list1 = CharArrayList();   // resetting list1 
    list2 = CharArrayList('A'); // resetting list2 
    list3 = CharArrayList(arr, 5); // resetting list3 

    // Test first() on an empty list to see if it throws an error
    try {
        std::cout << list1.first() << ",";
    } catch (const std::range_error &e) {
        // This runs if list.first() throws the error
        std::cerr << e.what() << ",";
    }
    // Test first() on a non-empty list
    try{ 
    cout << list3.first() << ","; 
    } catch (const std::range_error &e) {
        std::cerr << e.what() << ",";
    }  

    // Test last() on an empty list to see if it throws an error
    try {
        std::cout << list1.last() << ",";
    } catch (const std::range_error &e) {
        // This runs if list.last() throws the error
        std::cerr << e.what() << ",";
    }
    // Test last() on a non-empty list
    try{
        std::cout << list3.last() << ","; 
    } catch (const std::range_error &e) {
        std::cerr << e.what() << ",";
    }

    // Test elementAt() on an empty list to see if it throws an error
    try {
        std::cout << list1.elementAt(0) << ","; // should throw an error
    } catch (const std::range_error &e) {
        // This runs if list.elementAt() throws the error
        std::cerr << e.what() << ",";
    }
    // Test elementAt() on a non-empty list with a try catch statement
    try{
        std::cout << list3.elementAt(4) << endl; 
    } catch (const std::range_error &e) {
        std::cerr << e.what() << endl;
    }

    //test insertAt function
    list1.insertAt('M', 0);          
    // inserting 'M' at index 0 of empty list
    cout << list1.toString() << ","; 
    list2.insertAt('N', 1);          
    // inserting 'N' at index 1 of list with one element 
    cout << list2.toString() << ","; 
    list3.insertAt('O', 3);          
    // inserting 'O' at index 3 of list with elements 'A', 'l', 'i', 'c', 'e'
    cout << list3.toString() << endl; 
    try {
        list3.insertAt('c', 10);     
        // inserting 'c' at out-of-range index 10
    } catch (const std::range_error &e) {                                   
        std::cerr << e.what() << endl;  
        // This runs if list.elementAt() throws the error
    }

    list1 = CharArrayList();   
    list2 = CharArrayList('A'); 
    list3 = CharArrayList(arr, 5); 

    //InsertInOrder unit tests
    list2.insertInOrder('B');
    cout << list2.toString() << ",";
    list3.insertInOrder('C');
    cout << list3.toString() << endl; 
    // should print [CharArrayList of size 6 <<AClice>>]

    //popFromFront unit tests
    list2.popFromFront();
    cout << list2.toString() << ","; // should print an empty list
    list3.popFromFront();
    cout << list3.toString() << endl;   
    // should print [CharArrayList of size 4 <<lice>>]

    //popFromBack unit tests
    list2.popFromBack();
    cout << list2.toString() << ","; // should print an empty list
    list3.popFromBack();
    cout << list3.toString() << endl;   
    // should print [CharArrayList of size 4 <<lic>>]

    list1 = CharArrayList();     // resetting list1 
    list2 = CharArrayList('A');     // resetting list2 
    list3 = CharArrayList(arr, 5);      // resetting list3 

    //removeAt unit tests
    list2.removeAt(0);
    cout << list2.toString() << ","; // should print an empty list
    list3.removeAt(1);
    cout << list3.toString() << endl;   
    // should print [CharArrayList of size 4 <<Aice>>]

    //replaceAt unit tests
    list2 = CharArrayList('A'); 
    list2.replaceAt('B', 0);
    cout << list2.toString() << ","; 
    // should print [CharArrayList of size 1 <<B>>]
    list3.replaceAt('D', 1);
    cout << list3.toString() << endl;   
    // should print [CharArrayList of size 3 <<Dc>>]
    try {
        list3.replaceAt('E', 5);     
        // replacing at out-of-range index 5
    } catch (const std::range_error &e) {                                   
        std::cerr << e.what() << endl;  
        // This runs if list.elementAt() throws the error
    }   

    list1 = CharArrayList();     // resetting list1 
    list2 = CharArrayList('A');     // resetting list2 
    list3 = CharArrayList(arr, 5);      // resetting list3 

    //concatenate unit tests
    list1.concatenate(&list1);
    cout << list1.toString() << ","; 
    // should print [CharArrayList of size 1 <<A>>]    
    list2.concatenate(&list2);        
    // concatenating list2 with itself
    cout << list2.toString() << ","; 
    // should print [CharArrayList of size 6 <<AAlice>>]
    list3.concatenate(&list3); 
    cout << list3.toString() << endl;   
    // should print [CharArrayList of size 5 <<Alice>>]    
    
    cout << "Running insertAt unit tests... ";
    //Running the insertAt unit tests
    insertAt_empty_correct();
    insertAt_empty_incorrect();
    insertAt_front_singleton_list();
    insertAt_back_singleton_list();
    insertAt_many_elements();           
    insertAt_front_large_list();
    insertAt_back_large_list();
    insertAt_middle_large_list();
    insertAt_nonempty_incorrect();
    std::cout << "passed!" << endl;
  


    // test clear function
    list1.clear();              // clearing an already empty list
    list2.clear();              // clearing a non-empty list
    assert(list1.size() == 0);
    assert(list2.size() == 0);
    cout << "Clear test passed!, ";

    // Test isEmpty() on an empty list
    cout << std::boolalpha << list1.isEmpty() << ","; // should print true 
        //Test isEmpty() on a list that was just cleared
    cout << std::boolalpha << list2.isEmpty() << ","; // should print true
    // Test isEmpty() on a non-empty list
    cout << std::boolalpha << list3.isEmpty() << endl; // should print false    


    return 0;               
    // calling the destructor
}

