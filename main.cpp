#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintWrong(vector<char> listOfWrong) {
    cout << "These letters are not in the word: " << endl;
    cout << "( ";
    for (int i = 0; i < listOfWrong.size(); ++i) {
        cout << listOfWrong.at(i) << " ";
    }
    cout << " )" << endl << endl;
}

int main() {
    vector<string> wordsToGuess;
    vector<char> listOfWrong;
    const int WRONG_GUESSES = 8;
    string userName;
    string answer;
    string randomWord;
    string hiddenWord;
    bool userAnswer = true;
    char userGuess;
    string officialGuess;
    int numWrongGuesses = 0;
    int numFoundLetters = 0;
    int totalGuesses = 0;
    int i;

    wordsToGuess.push_back("chimney");
    wordsToGuess.push_back("monotonous");
    wordsToGuess.push_back("electricity");
    wordsToGuess.push_back("abruptly");
    wordsToGuess.push_back("skyscraper");
    wordsToGuess.push_back("cylinder");
    wordsToGuess.push_back("mount");
    wordsToGuess.push_back("hymnal");
    wordsToGuess.push_back("vehicle");
    wordsToGuess.push_back("vaporize");

    cout << "Welcome to the game of HANGMAN!" << endl;
    cout << "Please enter your name: ";
    getline(cin,userName);
    cout << endl;

    cout << "Are you ready to begin? (yes/no)";
    getline (cin,answer);
    cout << endl;

    do {
        if (answer == "yes") {
            randomWord = wordsToGuess[rand() % wordsToGuess.size()];
            cout << "The word you are trying to guess has " << randomWord.size() << " letters." << endl;
            cout << "You can make up to " << WRONG_GUESSES << " incorrect guesses before you lose." << endl;

            hiddenWord = randomWord;

            for (i = 0; i < randomWord.size(); ++i) {
                hiddenWord.replace(i, 1, "_");
            }

            numWrongGuesses = 0;
            numFoundLetters = 0;
            totalGuesses = 0;

            cout << hiddenWord << endl;

            cout << "Guess a letter!";
            cin >> userGuess;
            cout << endl;
            officialGuess = userGuess;

            while (numWrongGuesses < WRONG_GUESSES) {
                totalGuesses = totalGuesses + 1;
                cout << "Your number of guesses: " << totalGuesses << endl;

                for (i = 0; i < randomWord.size(); ++i) {
                    if (userGuess == randomWord.at(i)) {
                        hiddenWord.replace(i, 1, officialGuess.substr(0, 1));
                        numFoundLetters = numFoundLetters + 1;
                    }
                }
                cout << "You have found " << numFoundLetters << "/" << randomWord.size() << " letters." << endl;

                if (randomWord.find(userGuess) == string::npos) {
                    cout << "Sorry, the letter " << userGuess << " is not in the word." << endl;
                    numWrongGuesses = numWrongGuesses + 1;
                    listOfWrong.push_back(userGuess);
                }
                cout << "You have guessed incorrectly " << numWrongGuesses << "/" << WRONG_GUESSES << " time(s)."
                     << endl;

                PrintWrong(listOfWrong);

                if (numWrongGuesses == WRONG_GUESSES) {
                    cout << hiddenWord << endl;
                    cout << "Too bad, " << userName << "! You have guessed incorrectly too many times. You lose!"
                         << endl;
                    cout << "The word was " << randomWord << "." << endl;
                    break;
                }
                if (hiddenWord.find("_") == string::npos) {
                    cout << hiddenWord << endl;
                    cout << "Nice job " << userName << "! You guessed the word correctly!" << endl;
                    cout << "You guessed " << totalGuesses << " times to figure it out." << endl;
                    break;
                }

                cout << hiddenWord << endl;

                cout << "Guess another letter!";
                cin >> userGuess;
                cout << endl;
                officialGuess = userGuess;
            }
            cout << endl;
        }

        cout << "Would you like to play again? (yes/no): ";
        cin >> answer;
        cout << endl;

        listOfWrong.clear();

        if (answer == "no") {
            cout << "Thanks for playing " << userName << "!" << endl;
            userAnswer = false;
        }

    }while(userAnswer);


    return 0;
}

