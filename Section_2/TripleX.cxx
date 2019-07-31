#include <iostream>

int main()
{
  std::cout << "You are a secret agent decoding a secrect message...";
  std::cout << std::endl;
  std::cout << "Enter the correct code to continue...";
  std::cout << std::endl << std::endl;

  const int Message = 4;
  int Mask = 0xf;

  int Complement = Message ^ Mask;

  std::cout << "+ The message is: " << Message;
  std::cout << std::endl;

  int PlayerGuess;
  
  Mask << 4;
  Mask += 0xf;

  return 0;
}