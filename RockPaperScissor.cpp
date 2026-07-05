#include <iostream>
#include <cstdlib>
#include <ctime>
enum RPS {
	Rock = 1, Paper = 2, Scissor = 3
};
int RandomNumber(int From ,int To) {
	int Number;
	Number = rand() % (To - From + 1) + From;
	return Number;
}
using namespace std;
int RoundsNumber() {
	cout << "How Many Rounds You Want To Play?\n";
	int rounds;
	cin >> rounds;
	cout << endl;
	return rounds;
}
RPS userchoice() {
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		return RPS::Rock;
	case 2:
		return RPS::Paper;
	case 3:
		return RPS::Scissor;


	}
}
void Results(int rounds, int& playerchoice, int& computerchoice, int& playerscore, int& computerscore, int &draw) {
	
	if (playerchoice == 3 && computerchoice == 2) {
		playerscore++;
		cout << "Round Winner : " << "[ PLAYER1 WINNER ]" << endl;
		system("color 27");
	}
	else if (playerchoice == 3 && computerchoice == 1) {
		computerscore++;
		cout << "Round Winner : " << "[ COMPUTER WINNER ]" << endl;
		system("color 4F");
	}
	else if (playerchoice == 2 && computerchoice == 3) {
		computerscore++;
		cout << "Round Winner : " << "[ COMPUTER WINNER ]" << endl;
		system("color 4F");
	}
	else if (playerchoice == 2 && computerchoice == 1) {
		playerscore++;
		cout << "Round Winner : " << "[ PLAYER1 WINNER ]" << endl;
		system("color 27");
	}
	else if (playerchoice == 1 && computerchoice == 3) {
		playerscore++;
		cout << "Round Winner : " << "[ PLAYER1 WINNER ]" << endl;
		system("color 27");
	}
	else if (playerchoice == 1 && computerchoice == 2) {
		computerscore++;
		cout << "Round Winner : " << "[ COMPUTER WINNER ]" << endl;
		system("color 4F");//system("color 27");
	}
	else if (playerchoice == computerchoice) {
		cout << "Round Winner : " << "[ NO WINNER ]" << endl;
		system("color 60");
		draw++;
	}

}
void playingrounds(int rounds, int& playerscore, int& computerscore,int &draw) {
	for (int i = 1; i <= rounds; i++) {
		cout << "Round" << "[ " << i << " ]" << "Begins" << endl;
		cout << "Your Choise:  [1] Rock , [2] Paper , [3] Scissor ?\n";
		int playerchoise=userchoice();
		cout << endl;
		cout << "_______________________________ Round " << i << " ___________________________" << endl;
		cout << "PLayer Choise : ";
		if (playerchoise == 1)
			cout << "Rock\n";
		else if (playerchoise == 2)
			cout << "Paper\n";
		else if (playerchoise == 3)
			cout << "Scissor\n";
		cout << "Computer Choise : ";
		int computerchoise = RandomNumber(1,3);
		if (computerchoise == 1)
			cout << "Rock\n";
		else if (computerchoise == 2)
			cout << "Paper\n";
		else if (computerchoise == 3)
			cout << "Scissor\n";
		Results( rounds,playerchoise,computerchoise,playerscore,computerscore,draw);
	}
}

void gameresults(int rounds,int  playerscore, int computerscore,int draw) {
		cout << "_____________________________________________________________________________________\n";
		cout << "\t\t\t +++\t\t GAME OVER \t\t+++\n";
		cout << "_________________________________[ GAME RESULTS ]______________________________________\n";
		cout << "GAME ROUNDS : " << rounds<<endl;
		cout << "PLAYER 1 WON TIMES : " << playerscore<<endl;
		cout << "COMPUTER WON TIMES : " << computerscore<<endl;
		cout << "DRAW TIMES : " << draw<<endl;
		cout << "FINAL WINNER : ";
		if (playerscore > computerscore)
			cout << "PlAYER 1 IS THE WINNER\n";
		else
			cout << "COMPUTER IS THE WINNER\n";
	
	cout << "_____________________________________________________________________________________\n";
	

}
int main()
{
	srand((unsigned)time(NULL));
	int again;
	do {
		int draw = 0;
		int playerchoice = 0;
		int computerchoice = 0;
		int playerscore = 0;
		int computerscore = 0;
		int NumberOfRounds = RoundsNumber();
		playingrounds(NumberOfRounds, playerscore, computerscore, draw);
		gameresults(NumberOfRounds, playerscore, computerscore, draw);
		cout << "DO YOU WANT TO PLAY AGAIN?1/0\n";
		cin >> again;
		cout << endl;
	} while (again != 0);
	return 0;
}