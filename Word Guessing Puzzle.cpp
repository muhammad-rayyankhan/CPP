#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <string>
#include <algorithm> // For shuffle
#include <thread>    // For sleep_for
#include <chrono>    // For chrono literals

using namespace std;

void blinkingPlayButton() {
    for (int i = 0; i < 3; i++) {  // Blinking effect
        cout << "\n\n  ** Press 'P' to Play **" << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\r                          \r" << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "\n  ** Press 'P' to Play **" << endl;
}

string getJumbledWord(const string& word) {
    string jumbled = word;
    random_shuffle(jumbled.begin(), jumbled.end());
    return jumbled;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    string words[] = {"computer", "programming", "language", "puzzle", "keyboard"};
    string hints[] = {
        "An electronic device used for processing data.",
        "The process of writing code.",
        "A system of communication using symbols.",
        "A game or problem testing knowledge.",
        "An input device with keys."
    };
    int score = 0;
    char choice;

    blinkingPlayButton();

    cin >> choice;
    if (choice == 'P' || choice == 'p') {
        bool playAgain = true;
        while (playAgain) {
            int index = rand() % 5;  // Choose a random word
            string word = words[index];
            string jumbled = getJumbledWord(word);
            string guess;
            bool guessedCorrectly = false;

            cout << "\nUnscramble this word: " << jumbled << endl;
            cout << "Type 'hint' for a hint or enter your guess: ";
            cin >> guess;

            if (guess == "hint") {
                cout << "Hint: " << hints[index] << endl;
                cout << "Try again: ";
                cin >> guess;
            }

            if (guess == word) {
                cout << "Correct! You've earned a point.\n";
                score++;
                guessedCorrectly = true;
            } else {
                cout << "Sorry, the correct word was: " << word << endl;
            }

            cout << "\nYour score: " << score << endl;
            cout << "Play again? (y/n): ";
            cin >> choice;
            playAgain = (choice == 'y' || choice == 'Y');
        }
    }

    cout << "\nThanks for playing! Your final score: " << score << endl;
    return 0;
}
