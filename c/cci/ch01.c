#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

/* 

  1.1 : Implement an algorithm to determine if a string has all unique characters. 
        What if you cannot use additional data structures?

  1.2 Implement a function void reverse(char* str) in C or C++ which 
      reverses a null- terminated string.

  1.3 Given two strings, write a method to decide if one is a permutation of the other.

  1.4 Write a method to replace all spaces in a string with'%20'. 
      You may assume that the string has sufficient space at the end of the string to 
      hold the additional characters, and that you are given the "true" length of the 
      string. 
      (Note: if implementing in Java, please use a character array so that you can 
      perform this operation in place.)

      EXAMPLE
      Input: "Mr John Smith   " 
      Output: "Mr%20Dohn%20Smith"

  1.5 Implement a method to perform basic string compression using the counts of 
      repeated characters. For example, the string aabcccccaaa would become a2blc5a3. 
      If the "compressed" string would not become smaller than the orig- inal string, 
      your method should return the original string.

  1.6 Given an image represented by an NxN matrix, where each pixel in the image is 
      4 bytes, write a method to rotate the image by 90 degrees. 
      Can you do this in place?

  1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire 
      row and column are set to 0.
*/

// assuming ascii
bool str_has_unique_char(char* s, size_t s_size)
{
  if(!s || !s_size || (s_size > 256)) {   
    // ascii charset space is 256, hence a 
    // larger string has atleast one duplicate
    return false;
  }

  bool char_set[256];
  int i = 0;
  char* c = s;

  memset(char_set, 0, sizeof(char_set)); // init to false
  
  for (i = 0; i < s_size; i++) {
      if (char_set[(int) *c]) {
        return false;
      }

      char_set[(int) *c] = true;
      c++;
  }

  // if we reached end of string without exiting
  return true;
}

typedef struct {
  uint64_t bits[4];
} ba_128;

void ba_reset(ba_128* ba)
{
  assert(ba);
  memset(ba->bits, 0, sizeof(ba->bits));
}

// pos = 0 invalid
// pos = 1 at RHS
// pos = 256 at LHS
bool ba_isset(ba_128* ba, int pos)
{
  assert(ba);
  assert(pos);

  return ( (ba->bits[pos/64] & (1 << (pos%32))) != 0);
}

void ba_set(ba_128* ba, int pos)
{
  assert(ba);
  assert(pos);

  ba->bits[pos/64] |= (1 << (pos%64));
}

void ba_unset(ba_128* ba, int pos)
{
  ba->bits[pos/64] &= ~(1 << (pos%64)); 
}

bool str_has_unique_char_using_bits(char* s, size_t s_size)
{
  if(!s || !s_size || (s_size > 256)) {   
    // ascii charset space is 256, hence a 
    // larger string has atleast one duplicate
    return false;
  }

  ba_128 char_set;
  int i = 0;
  char* c = s;

  ba_reset(&char_set);
  
  for (i = 0; i < s_size; i++) {
    if (ba_isset(&char_set, (*c + 1))) {
      return false;
    }

    ba_set(&char_set, (*c + 1));
    c++;
  }

  // if we reached end of string without exiting
  return true;
}

// global mode for selecting implementation type
typedef enum {
  BITS_VERSION,
  NON_BITS_VERSION
} str_has_unique_char_type;

str_has_unique_char_type g_unique_char_mode = NON_BITS_VERSION;

void test_str_has_unique_char(char* s)
{
  bool ret = false;
  size_t s_size = strlen(s);

  switch(g_unique_char_mode) {
    case NON_BITS_VERSION:
      ret = str_has_unique_char(s, s_size);
      break;
    case BITS_VERSION:
      ret = str_has_unique_char_using_bits(s, s_size);
      break;
  }

  printf("\n%s: %s.", s, ret ? "true" : "false");
}

void ch1_1()
{
  bool ret = false;
  
  printf("\nExample 1.1a: NON BITS VERSION: determine if a string has all unique characters.");

  ret = str_has_unique_char(NULL, 0);
  assert(ret == false);

  ret = str_has_unique_char(NULL, 1);
  assert(ret == false);

  ret = str_has_unique_char("a", 0);
  assert(ret == false);
  

  test_str_has_unique_char("aaa");
  test_str_has_unique_char("abc");
  test_str_has_unique_char("abce12345");

  test_str_has_unique_char("abce12341");
  test_str_has_unique_char("abcde%^&*(");
  test_str_has_unique_char("%abce12%345");

  printf("\n\nExample 1.1b: BITS VERSION: determine if a string has all unique characters.");

  g_unique_char_mode = BITS_VERSION;

  test_str_has_unique_char("aaa");
  test_str_has_unique_char("abc");
  test_str_has_unique_char("abce12345");

  test_str_has_unique_char("abce12341");
  test_str_has_unique_char("abcde%^&*(");
  test_str_has_unique_char("%abce12%345");
}

int main() {
  ch1_1();

  return 0;
}
