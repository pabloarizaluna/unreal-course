#include <iostream>
#include <random>

void PrintIntroduction(const int&);
bool PlayGame(const int&);

int main()
{
  bool bLevelComplete;
  int LevelDifficulty = 1;
  const int MaxDifficulty = 5;

  while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
  {
    bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); // Clears any errors
    std::cin.ignore(); // Discards the buffer

    if (bLevelComplete)
      ++LevelDifficulty;
    else
      LevelDifficulty = 1;
  }

  std::cout << "***you've decode all message, now you know everything***";
  std::cout << std::endl;

  return 0;
}

bool PlayGame(const int& Difficulty)
{
  PrintIntroduction(Difficulty);

  int Mask = 0;
  for(int i = 1; i <= Difficulty; i++)
  {
    Mask = Mask << 4;
    Mask += 0xf;
  }

  //Prepare the random number generator
  std::random_device RandomDevice;
  std::mt19937 MersenneTwister(RandomDevice());
  std::uniform_int_distribution<> IntDist(0, Mask);

  const int Message = IntDist(MersenneTwister);  

  int Complement = Message ^ Mask;
  std::cout << "+ The message is: " << Message << std::endl;
  std::cout << "+ The disguise is: " << Mask << std::endl << std::endl;

  int PlayerGuess;
  std::cin >> PlayerGuess;

  bool result = false;
  if (Complement == PlayerGuess)
  {
    result = true;
    std::cout << "You decode The message, for now you still alive" << std::endl;
  }
  else
  {
    std::cout << std::endl;
    std::cout << "++You died cause you didn't know the message++" << std::endl;
    std::cout << "++Try Again++" << std::endl;
  }

  std::cout << std::endl;

  return result;
}

void PrintIntroduction(const int& Difficulty)
{
  std::cout << "You are a secret agent decoding a level " << Difficulty;
  std::cout << " secrect message..." << std::endl;
  std::cout << "Enter the correct code to continue...";
  std::cout << std::endl << std::endl;
}
