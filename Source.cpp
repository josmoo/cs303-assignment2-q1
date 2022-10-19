#include "Header.h"

using namespace std;

const string INPUT_FILE_NAME = "input.txt";
int main() {
	//setup. not in a seperate function because we will only setup once
	ifstream inFile;
	inFile.open("input.txt");
	int arrsize = 0;
	int* arr = new int[arrsize];
	while (inFile.good()) {//while there's still stuff to read in
		int inputInt;
		inFile >> inputInt;//read in
		appendInt(arr, arrsize, inputInt);//add to array
	}

	
	printArray(arr, arrsize);
	userAppendInt(arr, arrsize);
	int newValue;
	userReplaceValue(arr, arrsize, newValue);
	userAppendInt(arr, arrsize);
	userReplaceValue(arr, arrsize, newValue);


	//just random testing stuff
	
	//cout << "\nadding an int of value 77 to the end of the array\n";
	//appendInt(arr, arrsize, 77);
	//cout << "\nfinding index of first instance of value 10 (expecting 0)\n";
	//cout << findValue(arr, arrsize, 10);
	//cout << "\nfinding index of first instance of value 77 (expecting 100)\n";
	//cout << findValue(arr, arrsize, 77);
	//cout << "\nremoving index 100 from the array\n";
	//removeInt(arr, arrsize, 100);
	//cout << "\nfinding index of first instance of value 77 (expecting -1)\n";
	//cout << findValue(arr, arrsize, 77);
	//cout << "\nreplacing value in index 0 with 77(expecting a return value of 10(old value))\n";
	//cout << replaceValue(arr, arrsize, 0, 77);
	//cout << "\nfinding index of first instance of value 77 (expecting 0)\n";
	//cout << findValue(arr, arrsize, 77);




	return 0;
}


int findValue(int* &arr, const int &arrsize, const int &val) {
	for (int i = 0; i < arrsize; i++) { //for each value in the array...
		if (arr[i] == val) return i; //.. if the value matches the value at index, return that index
	}
	return -1; //if we didn't find it return -1
}

int replaceValue(int* &arr, const int& arrsize, const int& index, const int& newValue){
	if (index >= arrsize) return -1; //if it's out of bounds, return -1

	int oldValue = arr[index]; //save old value... (1)
	arr[index] = newValue; //put new value in specified index
	
	return oldValue; //(1)...so that we can return it
}

void appendInt(int* &intarr, int& arrsize, const int& val) {
	int* newarr = new int[arrsize + 1]; //make a new array of size + 1 (because we will be adding an int to it)
	for (int i = 0; i < arrsize; i++) { //and then copy everything to that array
		newarr[i] = intarr[i];

	}
	newarr[arrsize] = val; //put the int to append in the last value
	arrsize++;//update array size counter
	delete[] intarr; //delete old array
	intarr = newarr; //update the array passed in
}

//yes i know this is an awful way to do it so much so that i dont even want to comment it
int removeInt(int*& intarr, int& arrsize, const int& index) {
	if (index >= arrsize) { 
		return -1; //prevent array out of bounds
	}
	int* newarr = new int[arrsize - 1]; //make a new array of size - 1 (because we will be removing an int from it)
	int adjustment = 0; //to take into consideration that there is a variable we're not adding to the new array
	for (int i = 0; i < arrsize; i++) { 
		if (i == index) { //now that we've gotten to the int we're removing, 
			adjustment = -1; //take into consideration that we've now skipped a variable in the array
		}
		else{
			newarr[i+adjustment] = intarr[i]; //copy with adjustment
		}
	}
	arrsize--; //update the array counter
	delete[] intarr; //delete old array
	intarr = newarr; //update the array passed in
	return 0;
}

void printArray(int*& arr, const int& arrsize) {//just prints the array 
	for (int i = 0; i < arrsize; i++) {
		cout << arr[i] << endl;
	}
}

int getUserInt() {
	int result;
	cout << "Please enter the integer: " << endl;
	cin >> result;
	if (cin.fail()) { //if invalid input
		cin.clear();
		cin.ignore(1000, '\n');
		throw runtime_error("Invalid input recieved, you must enter an integer.");
	}
	return result;
}

int userReplaceValue(int*& arr, const int& arrsize, int& newValue) {
	int index;
	cout << "What index of the array would you like to replace?  ";
	try {
		index = getUserInt();
		cout << "What is the value that you would like to place at that index?  ";
		newValue = getUserInt();
		if (index < 0) { //array out of bounds 1
			throw runtime_error("Invalid input, arrays index from 0.");
		}
		if (index >= arrsize) { //array oob 2
			throw runtime_error("Invalid input, the index you requested is too large.");
		}
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		return -1;
	}
	return replaceValue(arr, arrsize, index, newValue);
}

void userAppendInt(int*& arr, int& arrsize) {
	int val;
	cout << "What integer would you like to append?  ";
	try {
		val = getUserInt();
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		return;
	}
	appendInt(arr, arrsize, val);
}