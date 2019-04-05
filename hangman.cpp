/*
  Nguyen Truong Giang - K62UET-CL
  Bộ môn: Tin học cơ sở 4
  Chương trình: Game Hangman 1.0
*/
#include <iostream>
#include <windows.h>

using namespace std;

void playGame();

int main() {
    playGame();
    return 0;
}


void playGame() {
    system("cls");
    //Từ cần đoán
    string guess;
    //Kí tự mỗi lần đoán, lựa chọn
    char letter, choose;
    int wrong = 0;
    bool check;
    //Mảng đồ họa
    string draw[] = {"",
                     " ------   \n"
                     "|      |  \n"
                     "|         \n"
                     "|         \n"
                     "|         \n"
                     "---        \n",
                     " ------    \n"
                     "|      |  \n"
                     "|      o  \n"
                     "|         \n"
                     "|         \n"
                     "---        \n",
                     " ------    \n"
                     "|      |  \n"
                     "|      o  \n"
                     "|      |  \n"
                     "|         \n"
                     "---        \n",
                     " ------    \n"
                     "|      |  \n"
                     "|      o  \n"
                     "|     /|  \n"
                     "|         \n"
                     "---        \n",
                     " ------     \n"
                     "|      |    \n"
                     "|      o    \n"
                     "|     /|\\  \n"
                     "|           \n"
                     "---         \n",
                     " ------      \n"
                     "|      |     \n"
                     "|      o     \n"
                     "|     /|\\   \n"
                     "|     /      \n"
                     "---          \n",
                     " ------      \n"
                     "|      |     \n"
                     "|      o     \n"
                     "|     /|\\   \n"
                     "|     / \\   \n"
                     "---          \n",
                     // Graphics win
                     "     o//   \n"
                     "      |     \n"
                     "     / \\   \n",
                     "     \\o/    \n"
                     "      |     \n"
                     "     / \\   \n",
                     "    _ o _     \n"
                     "      |   \n"
                     "     / \\   \n",
                     "      o     \n"
                     "     /|\\  \n"
                     "     / \\   \n",
                    };
    cout << "Nguyen Truong Giang - SoICT\n"
         << "-----GAME HANGMAN 1.0-----" << endl;
    cout << "Enter word what you want to guess: ";
    cin >> guess;
    //Tạo mảng chứa câu trả lời của bạn
    char copyGuess[guess.length() + 1];
    copyGuess[guess.length()] = '\0';
    system("cls");
    for (int i = 0; i < guess.length(); i++) {
        copyGuess[i] = '-';
    }
    cout << "Guess: " << copyGuess << endl;
    //Yêu cầu đoán kí tự
    while(true) {
        int counter = 0;
        cout << "Please enter a letter: ";
        cin >> letter;
        //So sánh kí tự với từng phần tử của từ khóa
        for (int i = 0; i < guess.length(); i++) {
            if(guess[i] == letter) {
                copyGuess[i] = letter;
                counter++;
            }
        }
        cout << "Guess: " << copyGuess << endl;
        if(counter == 0) {
            wrong++;
            cout << "Wrong!\n" << draw[wrong] << endl;
        }
        if (copyGuess == guess) {
            check = true;
            cout << "Congratulations! You win..." << endl;
            Sleep(2000);
            break;
        } else if (wrong > 6) {
            check = false;
            Sleep(3000);
            break;
        }
    }
    system("cls");
    if(check == true) {
        for (int i = 8; i < 12; i++) {
            cout << "Congratulations! You win..." << endl;
            cout << draw[i];
            Sleep(1500);
            system("cls");
        }
    } else {
        cout << "Oops! You lose the game..." << endl;
    }
    cout << "Do you want play continue? (Y/N)";
    cin >> choose;
    if (choose == 'Y' || choose == 'y') {
        playGame();
    }
}
