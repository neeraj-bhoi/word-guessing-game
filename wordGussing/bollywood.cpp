#include <iostream>

#include<ctime>
#include <string>


using namespace std;

const int MAX_TRIES = 5;
int letterFill(char, string, string&);

int main()
{

  string name;
  string yes_or_no;
  char letter;
  int num_of_wrong_guesses = 0, i;

  string word;
  getline (cin, word);

  string unknown = word;

    for(i = 0; i < unknown.length(); i++)
    {
        if(unknown[i] == 'a' || unknown[i] == 'e' || unknown[i] == 'i' ||
           unknown[i] == 'o' || unknown[i] == 'u' || unknown[i] == ' ')
        {
            
        } else {
          unknown[i] = '_';
        }
    }
  
  system("CLS");

  cout << "\n\n Welcome to the guessing game...Guess a country Name"; 
  cout << "\n\n Each letter is represented by a star."; 
  cout << "\n\n You have to type only one letter in one try"; 
  cout << "\n\n You have " << MAX_TRIES << " tries to try and guess the word.";
  cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  
  while (num_of_wrong_guesses < MAX_TRIES)
  {
    cout << endl << endl;
    cout << "\n\n" << unknown;      
    cout << "\n\nGuess a letter: "; 
    cin >> letter;       

    if (letterFill(letter, word, unknown) == 0)
    {
      cout << endl << "\n Whoops! That letter isn't in there!" << endl; 
      num_of_wrong_guesses++; 
    }
    else
    {
      cout << endl << "\n You found a letter! Isn't that exciting!" << endl;
    }
    cout << "\n You have " << MAX_TRIES - num_of_wrong_guesses;
    cout << " guesses left." << endl;
    if (word == unknown)
    {
      cout << word << endl;
      cout << "\n Yeah! You got it!" << endl;
      cout << "\n Would like to play another round of guessing?" << endl;
      cout << "\n Enter yes or no" << endl; 

      cin >> yes_or_no;

      if (yes_or_no == "yes")
      {
        main(); 
      }


      if (yes_or_no == "no")
      {
        cout << "Closing program" << endl;
        return 0;
        
      }
      break;
    }
  }
  if (num_of_wrong_guesses == MAX_TRIES)
  {
    cout << "\n\Sorry, you lose." << endl;
    cout << "\n\The word was " << word << endl;
    cout << "\n\Would like to play another round of guessing?" << endl;
    cout << "\n\Enter yes or no" << endl;

    cin >> yes_or_no;

    if (yes_or_no == "yes")
    {
      main();
    }

    if (yes_or_no == "no")
    {
      cout << "Closing program" << endl;
        return 0;
       
    }

  }
  return 0;
}

int letterFill(char guess, string secretword, string& guessword)
{
  int i;
  int matches = 0;
  int len = secretword.length();
  for (i = 0; i < len; i++)
  {
    if (guess == guessword[i])
      return 0;
    if (guess == secretword[i])
    {
      guessword[i] = guess;
      matches++;
    }
  }
  return matches;
}