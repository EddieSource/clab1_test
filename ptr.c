#include <stdio.h>
#include <assert.h>

// Assign the value of 5 to the integer variable pointed to by ptr.
//
// This should only take one line of code!
void set_to_five(int *ptr)
{
  // TODO: Your code here.
  *ptr = 5;
}

// Assign NULL value to the pointer variable pointed to by dp.
// Since dp points to a pointer variable, its type is a double pointer 
// indicated by two stars ** in the type name.
//
// This should only take one line of code!
void initialize_ptr(void **dp)
{
  // TODO: Your code here.
  *dp = NULL; 

}

// Swap the values of two int variables, 
// pointed to by x and y, respectively.
void swap_int(char *xp, char *yp)
{
  // TODO: Your code here.
  char temp = *xp; 
  *xp = *yp; 
  *yp = temp; 
}
