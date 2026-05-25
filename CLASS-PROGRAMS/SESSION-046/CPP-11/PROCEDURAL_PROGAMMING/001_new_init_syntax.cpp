#include <iostream>

int n11 = 100; 		// data definition statement, normal initialization 
int n14(100); 		// data definition statement, normal initialization
int n12 = {100}; 	// data definition statement, list initialization 
int n13{100}; 		// data definition statement, list initialization 
 
double d_num = 34634435.345352; 

int n21 = d_num; 	// ok, possible data loss 
int n22(d_num); 	// ok, possible data loss 

int n23{d_num}; 		// not ok. compile time error 
int n24 = {d_num}; 	// not ok. compile time error 

int main(){

	return 0; 
}

/* 
    char c = 'A'; 
    int n = 100; 

    Date D(8, 3, 2026); 
    int n(100);

    TypeName ObjectName(Required initialization data); 

    int arr[5] = {}; 

    std::vector<int> v{100, 200, 300, 400}; 

*/