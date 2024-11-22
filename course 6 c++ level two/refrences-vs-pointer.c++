// Reference vs. Pointer in C++

// Reference
// - Must be initialized at declaration
// - Cannot be reassigned
// - Implicit dereferencing
// - Always refers to a valid object
// - Safer and more convenient for working with objects

// Pointer
// - Can be initialized to an address or nullptr
// - Can be assigned to a different address
// - Explicit dereferencing using *
// - Can point to nothing (nullptr)
// - Greater flexibility and control over memory management

// Example:
// int x = 10;

// Reference
// int& y = x; // y is a reference to x
// y = 20; // Modifying y also changes x

// Pointer
// int* p = &x; // p points to the address of x
// *p = 20; // Modifying the value pointed to by p changes x
// p = nullptr; // p now points to nothing