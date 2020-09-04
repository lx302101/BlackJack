#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {

	int choose;
    int sum = 0;
    bool isSame;
	
	std::vector<std::string> number = {"1","2","3","4","5","6","7","8","9","10","J","Q","K"} ;
    std::vector<std::string> symbol = {"Hearts","Diamonds","Clubs","Spades"};

	std::vector<int> usedNum;
    std::vector<int> usedSuit;


	std::cout << "Do you want to play blackjack?" << std::endl;
	std::cout << "1. Yes \n" << "2. No" << std::endl;
	std::cin >> choose;

	if (choose == 2) {
		std::cout << "See you next time!" << std::endl;
		exit (EXIT_SUCCESS);
    }

    while (choose==1) {
        int choice1, choice2;
        isSame = false;

        srand(time(0));
        choice1 = rand() % 13;
        choice2 = rand() % 4;

        for (int j = 0; j < usedNum.size(); ++j) { //if card is same as before (both number and suit) break for loop and set isSame to true
            if ((choice1 == usedNum[j]) && (choice2 == usedSuit[j])) {
            isSame = true; 
            break;
            }
        }

        if (isSame == true) { //if card is same then rerun while loop
            continue;
        }

        usedNum.push_back(choice1); //Put numbers and suit combination in used vector
        usedSuit.push_back(choice2);

        std::cout << "You recieved the " << number[choice1] << " of " << symbol[choice2] << std::endl;

        choice1 += 1; //jack, queen, king have value of 10
        if (choice1>10) {
			choice1 = 10;
	    }
	    sum += choice1;

        if (sum > 21) { //adding up numbers
            std::cout << "You went past 21! You Lose." << std::endl;
            exit (EXIT_SUCCESS);
        }
		
	    std::cout << "Do you want to keep going?" << std::endl;
	    std::cout << "1. Yes \n" << "2. No" << std::endl;
	    std::cin >> choose; //continue until player says no
    }

    int sum2 = 0;
    srand(time(0));
    for (int i = 0; sum >= sum2; ++i) {
        int comp1, comp2; //computer choice
        isSame = false;

        comp1 = rand() % 13;
        comp2 = rand() % 4;

		for (int j = 0; j < usedNum.size(); ++j) {
            if ((comp1 == usedNum[j]) && (comp2 == usedSuit[j])) {
            isSame = true;
            break;
            }
        }

        if (isSame == true) {
            continue;
        }

        for (int j = 0; j < usedNum.size(); ++j) {
            if ((comp1 == usedNum[j]) && (comp2 == usedSuit[j])) {
            isSame = true;
            break;
            }
        }

        if (isSame == true) {
            continue;
        }

        usedNum.push_back(comp1);
        usedSuit.push_back(comp2);
        
        std::cout << "Computer Draws " << number[comp1] << " of " << symbol[comp2] << std::endl;
        comp1 += 1;
        if (comp1 > 10) {
			comp1 = 10;
	    }
        sum2 += comp1;
    }
        
    if (sum2 > 21) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "Game Over. You Lose." << std::endl;
    }

    return 0;
}
