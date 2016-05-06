#include <iostream>

#include "Join.h"
#include "Concat.h"
#include "Split.h"

using namespace string_utils;

int main()
{
  std::cout << join(", ", "Anthony", 2, 934.23, 'H') << std::endl;
  // Output: Anthony, 2, 934.23, H
  
  std::cout << concat("Anthony ", std::boolalpha, false, ' ', 23) << std::endl;
  // Output: Anthony false 23
  
  auto words = split("My name is Anthony Bongers", " ");
  std::cout << "The sentence contains " << words.size() << " words." << std::endl;
  // Output: The sentence contains 5 words.
}
