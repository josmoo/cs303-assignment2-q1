#pragma once
#include <utility>
#include <iostream>
#include <fstream>

/**
* searches array for given value and returns the first appearance of that value in the array,
*	or -1 if it's not in the array
*
* @returns				first index of given value in array, or -1 if it wasn't found
* @param int intarr[]		array of ints to search though
* @param int arrsize		size of array
* @param int val			the value to search for
*/
int findValue(int*& arr, const int &arrsize, const int &val);

/**
* puts the given value in the given array for the given index and returns the old value
*
*@returns				 the old value, or -1 if invalid index was passed
*@param int intarr[]		array of ints to modify
*@param int arrsize			size of array
*@param int index			index to put the newValue in
*@param int newValue		value to put in new array
**/
int replaceValue(int*& arr, const int& arrsize, const int& index, const int& newValue);

/**
* adds the specified integer to the end of the array and updates the arrsize by one
*
* @returns				void
* @param int*& intarr		the pointer to the dynamic array
* @param int& arrsize		size of the array
* @param int& val		the value to append at the end of the array
*
**/
void appendInt(int* &intarr, int& arrsize, const int& val);

/**
* removes the integer at a given index.
*
* @returns				0 if success, -1 otherwise
* @param int*& intarr		the pointer to the dynamic array
* @param int& arrsize		size of the array
* @param int& index			the index of the number to remove from the array
* 
**/
int removeInt(int*& intarr, int& arrsize, const int& index);

/**
* prints out array to cout
*
* @returns				void
* @param int*& arr			array to print
* @param int& arrsize		size of array
*/
void printArray(int*& arr, const int& arrsize);