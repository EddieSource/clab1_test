#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

#include "panic_cond.h"
#include "bitfloat.h"
#include "ptr.h"
#include "array.h"

void TestBitFloat()
{
  printf("---Start testing bitfloat.c\n");  

  printf("      get_bit_at_pos...");
  unsigned int n = 1;
  for (int p = 0; p< sizeof(n)*8; p++) {
    int r = get_bit_at_pos(n, p);
    panic_cond(r==1, "Bit at pos %d of int %x should be 1 (returned %d)",
        p, n, r);

    r = get_bit_at_pos(~n, p);
    panic_cond(r==0, "Bit at pos %d of int %x should be 0 (returned %d)",
        p, n, r);
    n = n << 1;
  }
  printf("passed\n");

  printf("      set_bit_at_pos...");
  n = 0;
  for (int p = 0; p < sizeof(n)*8; p++) {
    int r = set_bit_at_pos(n, p);
    panic_cond(r == (n<<1)+1,
        "Setting bit at pos %d of int %x should be %x (returned %x)",
        p, n, (n<<1)+1, r);

    n = (n << 1) + 1;
  }
  printf("passed\n");

  printf("      get_most_significant_byte...");
  n = 0x01020304;
  for (int i = 0; i < sizeof(n); i++) {
    char r = get_most_significant_byte(n);
    panic_cond(r == i+1, 
        "Most significant byte of %x should be %x (returned %x)",
        n, i+1, r);
    n = n << 8;
  }
  printf("passed\n");


  printf("      sum_overflowed...");
  n = 1;
  for (int i = 0; i < sizeof(n)*8; i++) {
    bool r = sum_overflowed(n, n+1);
    if (i < (sizeof(n)*8-2)) {
      panic_cond(r == false,
        "sum of %d and %d is %d, which did not overflow (returned %d)",
        n, n+1, n+n+1,r);
    } else {
      panic_cond(r == true,
        "sum of %d and %d is %d, which overflowed (returned %d)",
        n, n+1, n+n+1,r);
    }
    n = n << 1;
  }
  printf("passed\n");

  printf("      get_exponent_field...");
  float bf = 1.0, sf = 1.0;
  for (int i = 0; i < 20; i++) {
    float f = bf * 1.5;
    unsigned char r = get_exponent_field(f);
    panic_cond(r == i+127,
        "float %f (bit pattern %x) exponent should be %x (returned %x)",
        f, *(int *)&f, i, r);
    bf = bf * 2.0;

    sf = sf / 2.0;
    f = -1*sf * 1.5;
    r = get_exponent_field(f);
    panic_cond(r == (-1)*(i+1)+127,
        "float %f (bit pattern %x) exponent should be %x (returned %x)",
        f, *(int *)&f, (-1)*(i+1)+127, r);
  }
  printf("passed\n");

  printf("---Test bitfloat.c Passed\n");  
}

void TestPtr()
{
  printf("---Start testing ptr.c\n");  

  printf("      set_to_five...");
  int v = 0;
  set_to_five(&v);
  panic_cond(v == 5, "x=%d, after set_to_five v should be %d instead of %d",
      0, 5, v);
  printf("passed\n");

  printf("      initialize_ptr...");
  long *p = (long *)1;
  initialize_ptr((void *)&p);
  panic_cond(p == NULL, "p=%p, after initialize_ptr p should be %p instead of %p",
      1, NULL, p);
  printf("passed\n");

  printf("      swap_int...");
  int x = 1; 
  int y = 2;
  swap_int(&x, &y);
  panic_cond(x==2&&y==1, 
      "x=%d y=%d, after swap_int x,y should be %d,%d (instead of %d,%d)", 
      1, 2, 2, 1, x, y);
  swap_int(&x, &y);
  panic_cond(x==1&&y==2, 
      "x=%d y=%d, after swap_int x,y should be %d,%d (instead of %d,%d)",
      2, 1, 1, 2, x, y);
  printf("passed\n");

  printf("---Test ptr.c Passed\n");  
}

void TestArray()
{
  printf("---Start testing array.c\n");  

  printf("      array_sum...");
  int a[10] = {10,9,8,7,6,5,4,3,2,1};
  int sum = 55;
  for (int i = 0; i < 10; i++) {
    int r = array_sum(a+i, 10-i);
    panic_cond(r == sum, "array_sum of the last %d elements of {10,9,8,7,6,5,4,3,2,1}\
        should be %d instead of %d", 10-i, sum, r);
    sum -= a[i];
  }
  printf("passed\n");

  printf("      array_cpy...");
  int d[10];
  bzero(d, sizeof(int)*10);
  array_cpy(d+1, a+1, 8);
  for (int i = 0; i < 10; i++) {
    if (i > 0 && i < 9) {
      panic_cond(d[i] == a[i], 
          "after array_cpy, d[%d] should be %d (instead of %d)", i, a[i], d[i]);
    } else {
      panic_cond(d[i] == 0, 
          "after array_cpy, d[%d] should be unchanged 0 (instead of %d)", i, d[i]);
    }
  }
  printf("passed\n");

  printf("      bubble_sort...");
  bubble_sort(a, 10);
  for (int i = 0; i < 9; i++) {
    panic_cond(a[i] <= a[i+1], 
        "after bubble_sort, a[%d] <= a[%d] should be true but is not (%d, %d)",
        i, i+1, a[i], a[i+1]);
  }
  printf("passed\n");

  printf("      big_to_little_endian...");
  char x[4] = {0x0, 0x1, 0x2, 0x3};
  int y = big_to_little_endian(x);
  panic_cond(y == 0x00010203, "0x03020100 after big_to_little_endian should be 0x00010203\
        instead of %08x", y);
  printf("passed\n");

  printf("---Test array.c Passed\n");  

}

int main(int argc, char **argv)
{
  TestBitFloat();
  TestPtr();
  TestArray();

}
