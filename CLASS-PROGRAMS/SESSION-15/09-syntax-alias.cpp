int n; 

const int * const p = &n; 

/* p is a const pointer to const int*/

int n; // n is an int 

int* ptr;   // ptr is a pointer to int 

const int* ptr;  // ptr is a pointer const int 

int const* ptr;   // ptr is a pointer to const int 

int const* const ptr = &n; // ptr is const pointer to const int 