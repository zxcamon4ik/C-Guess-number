#include <iostream>
#include <random>

// Function to generate a random integer in the range [1, 100]
int generateRandomInt() {
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<> distrib(1, 100);
    return distrib(gen);
}

// Function to generate a random integer in the range [1, 1,000,000] (hard mode)
int generateRandomIntHard() {
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<> distrib(1, 1000000);
    return distrib(gen);
}

// Function to generate a random integer in a custom range [f_num, s_num]
int generateRandomIntCustom(int f_num, int s_num) {
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<> distrib(f_num, s_num);
    return distrib(gen);
}

// Function to get the user's guess
int userUI() {
    int guess;
    std::cin >> guess;
    return guess;
}

// Function for the classic game mode
void Classic_mode(int guess, int random_int, int n_try) {
    while (n_try >= 1) {
        if (guess == random_int) {
            std::cout << "You won!" << std::endl;
            break;
        } else {
            n_try--;
            if (random_int > guess) {
                std::cout << "\nThe number is higher than your guess"
                          << "\nTries left: " << n_try << std::endl;
            } else {
                std::cout << "\nThe number is lower than your guess"
                          << "\nTries left: " << n_try << std::endl;
            }
        }
        if (n_try > 0) {
            guess = userUI();
        } else {
            std::cout << "You lost!\n"
                      << "Right number is: " << random_int << std::endl;
        }
    }
}

// Function to display the user menu
[[noreturn]] void userMenu() {
    while (true) {
        int choose;
        std::cout << "Menu:\n1. Classic mode\n2. Custom\n3. Hardcore\n4. Guide\n";
        std::cin >> choose;

        if (choose == 1) {
            while (true) {
                std::cout << "Try to guess the number which is in the range [1, 100]" << std::endl;
                Classic_mode(userUI(), generateRandomInt(), 5);
                int continueChoice;
                std::cout << "Do you want to play again in Classic mode?\n1. Yes\n2. No\n";
                std::cin >> continueChoice;
                if (continueChoice != 1) break;
            }
        } else if (choose == 2) {
            while (true) {
                int f_num, s_num, numOfTries;
                std::cout << "Choose the range of numbers!\nFrom: ";
                std::cin >> f_num;
                std::cout << "To: ";
                std::cin >> s_num;
                std::cout << "Number of tries (positive integer above 0): ";
                std::cin >> numOfTries;
                std::cout << "You need to guess number which ∈ [" << f_num << ";" << s_num << "]" << std::endl;
                Classic_mode(userUI(), generateRandomIntCustom(f_num, s_num), numOfTries);
                int continueChoice;
                std::cout << "Do you want to play again in Custom mode?\n1. Yes\n2. No\n";
                std::cin >> continueChoice;
                if (continueChoice != 1) break;
            }
        } else if (choose == 3) {
            while (true) {
                std::cout << "Try to guess the number which is in the range [1, 1,000,000]" << std::endl;
                Classic_mode(userUI(), generateRandomIntHard(), 1);
                int continueChoice;
                std::cout << "Do you want to play again in Hardcore mode?\n1. Yes\n2. No\n";
                std::cin >> continueChoice;
                if (continueChoice != 1) break;
            }
        } else if (choose == 4) {
            std::cout << "Guide:\n";
            std::cout << "1. Classic mode: Try to guess a number between 1 and 100 within 5 tries.\n";
            std::cout << "2. Custom mode: Set a custom range and number of tries to guess the number.\n";
            std::cout << "3. Hardcore mode: Try to guess a number between 1 and 1,000,000 with only 1 try.\n";
            std::cout << "4. To make a guess, simply enter your number when prompted.\n";
            std::cout << "5. After each guess, you'll be told whether the target number is higher or lower than your guess.\n";
            std::cout << "6. The game will keep running until you either win or run out of tries.\n";
        } else {
            std::cout << "Invalid request, try again" << std::endl;
        }

        int choose2;
        std::cout << "\n1.Menu\n2.Exit\n";
        std::cin >> choose2;
        if (choose2 == 1) {
            continue;
        } else if (choose2 == 2) {
            continue;
        } else {
            break;
        }
    }
}

// Main function
int main() {
    userMenu();
}
