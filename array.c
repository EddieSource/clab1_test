#include <stdio.h>
#include <assert.h>

#include "ptr.h"
#include "stdbool.h"

// Return the sum of all elements in the given array.  The array
// "arr" has "n" elements.  We must explicitly pass in the array size
// because C array does not contain size information.
//
// Here, we use pointer "arr", which points to the first element of array, 
// to represent the array.  One can also write the function's signature as
// int array_sum(int array[], int n)
int array_sum(int *arr, int n)
{
  // TODO: Your code here.
  int sum = 0;  //initialize a sum value
  for (int i = 0; i < n; ++i) {
    sum += arr[i];   //add each element to the sum value
 }
  return sum; 
}

// Copy the first n elements of array "src" into array "dst".
// We assume caller has already allocated an array 
// of at least n elements as "dst".
void array_cpy(int *dst, int *src, int n)
{
  // TODO: Your code here.
  for (int i = 0; i < n; ++i) {
    dst[i] = src[i]; //copy each item from src to dst
 }
}

// bubble_sort implements the bubble sort algorithm.
// https://en.wikipedia.org/wiki/Bubble_sort
// It is given an integer array "arr" of "n" elements. 
// Upon return, the integer array should contain the sorted numbers
// in increasing order. 
// You should use swap_int function you've already implemented in ptr.c 
// when implementing bubble_sort (that's why we included ptr.h here)
void bubble_sort(int *arr, int n)
{
  // TODO: Your code here.
  bool swapped; 
  do {
    swapped = false;  
    for (int i = 1; i < n; i++) {
      if (arr[i-1] > arr[i]) {
         int* p1 = &arr[i-1]; 
         int* p2 = &arr[i]; 
         swap_int(p1,p2);
         swapped = true;  
       }
     }
   } while(swapped); 

}

//arr is a 4 byte array containing an integer in big endian format,
//i.e. arr[0] has the most significant byte...
//Convert the integer to little endian and return the converted int.
int big_to_little_endian(char *arr)
{
  // TODO: Your code here.
  char temp = arr[0]; 
  arr[0] = arr[3]; 
  arr[3] = temp;
  temp = arr[1]; 
  arr[1] = arr[2]; 
  arr[2] = temp; 
  return *((int*)arr); 
}

