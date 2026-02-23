# Dynamic_Array
 [![C/C++ CI](https://github.com/dingonzo/dynamic-array/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/dingonzo/dynamic-array/actions/workflows/c-cpp.yml)

# Testing & Validation
This repository includes a dedicated test suite.
* **Memory Safety:** Verified the "Big Three" (Destructor, Copy Constructor, Assignment Operator) for deep copy integrity.
* **Edge Cases:** Tested operations on empty lists, single-element arrays, and index-out-of-bounds.
* **Dynamic Growth:** Validated `ensureCapacity()` during high-volume data insertion.
* **Functional Integrity:** Confirmed `insertInOrder` and `concatenate` maintain correct data positioning.
* **Valgrind Verified:** All operations (insertions, deletions, and copies) have been profiled using Valgrind
* to ensure zero memory leaks and no invalid memory accesses.

