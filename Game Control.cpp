#include"Game Control.h"

//White Board Creation
void CreateWhiteBoard(int P1[][N + 1])
{
	P1[0][0] = NULL;
	int number1 = 1;
	int number2 = 1;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (j == 0 && i != 0)
			{
				P1[i][j] = number1;
				number1++;
			}
			else if (i != 0 && j != 0)
			{
				P1[i][j] = 0;
			}
			else if (i == 0 && j != 0)
			{
				P1[i][j] = number2;
				number2++;
			}
		}
	}
}

//Attacking: White board so as to attack
//Mine: Yourself ship board
void PrintBoard(int Attacking[][N + 1], int Mine[][N + 1])
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << "\t";
				continue;
			}
			cout << setw(3) << Attacking[i][j];
			if (j == 0) cout << "\t";
		}
		cout << "\t\t";
		for (int k = 0; k <= N; k++)
		{
			if (i == 0 && k == 0)
			{
				cout << "\t";
				continue;
			}
			cout << setw(3) << Mine[i][k];
			if (k == 0) cout << "\t";
		}
		cout << endl;
	}
}

//Player = Player white board for attacking
//Opponent = Opponent ship board
void Attack(int Player[][N + 1], int myShipBoard[][N + 1], int Opponent[][N + 1], bool& check)
{
	int x, y;
	//Enter attacking position
	cout << endl;
	cout << " My attacking board" << "\t\t\t\t\t\t" << "My ship board" << endl;
	PrintBoard(Player, myShipBoard);
	cout << "Enter x and y: ";
	cin >> x >> y;
	while (x > N || y > N || x < 1 || y < 1)
	{
		cout << "Wrong x or y, please enter again: " << endl;
		cout << "Enter x and y: ";
		cin >> x >> y;
	}

	//Checking and marking on the board
	Player[x][y] = 1;
	if (Opponent[x][y] != 0)
	{
		cout << "Attack successfully" << endl;
		Sleep(1000);
		Opponent[x][y] = 0;
		Player[x][y] = 2;
	}
	else
	{
		cout << "Missing" << endl;
		cout << "End your turn" << endl;
		Sleep(1000);
		check = false;
	}
	cout << endl;
}

//moi nguoi choi con lai doi
void GamePlay(int ShipMapPlayer1[][N + 1], int ShipMapPlayer2[][N + 1])
{
	//Initializer
	int C1 = 2, C2 = 2;
	bool checkCorrect = true;
	int Player1[N + 1][N + 1];
	int Player2[N + 1][N + 1];
	CreateWhiteBoard(Player1);
	CreateWhiteBoard(Player2);

	//Game processing
	while (C1 != 0 && C2 != 0)
	{
		if (checkCorrect && C1 != 0 && C2 != 0)
		{
			system("CLS");
			cout << "Player 1 turn: " << endl;
		}
		while (checkCorrect && C1 != 0 && C2 != 0)
		{
			Attack(Player1,ShipMapPlayer1, ShipMapPlayer2, checkCorrect);
			if (checkCorrect)
			{
				C2--;
				system("CLS");
				cout << "Player 1: " << endl;
			}
			if (!checkCorrect)
			{
				system("CLS");
				cout << "Player 1: " << endl;
				PrintBoard(Player1, ShipMapPlayer1);
			}
		}
		checkCorrect = true;
		if (checkCorrect && C1 != 0 && C2 != 0)
		{
			system("CLS");
			cout << "Player 2 turn: " << endl;
		}
		while (checkCorrect && C1 != 0 && C2 != 0)
		{
			Attack(Player2, ShipMapPlayer2 , ShipMapPlayer1, checkCorrect);
			if (checkCorrect)
			{
				C1--;
				system("CLS");
				cout << "Player 2: " << endl;
			}
			if (!checkCorrect)
			{
				system("CLS");
				cout << "Player 2: " << endl;
				PrintBoard(Player2, ShipMapPlayer2);
			}
		}
		checkCorrect = true;
		if (C1 == 0)
		{
			PrintBoard(Player2, ShipMapPlayer2);
			cout << "Player 2 is the winner" << endl;
			break;
		}
		if (C2 == 0)
		{
			cout << "Player 1 is the winner" << endl;
			PrintBoard(Player1, ShipMapPlayer1);
			break;
		}
	}
}

void Menu()
{
	//Set up 2 board game
	//White board
	int Mymap[N + 1][N + 1];
	int Opponent[N + 1][N + 1];
	string choice;
	do
	{
		CreateWhiteBoard(Mymap);
		CreateWhiteBoard(Opponent);

		//Ship set up
		Mymap[7][8] = 1;
		Mymap[7][9] = 1;

		Opponent[8][9] = 1;
		Opponent[8][10] = 1;

		//Print out board game
		//PrintBoard(Mymap);
		//PrintBoard(Opponent);

		//GamePlay
		GamePlay(Mymap, Opponent);
		cout << "Do you want to play again ? (Y = Yes, N = No): ";
		cin >> choice;
	} while (choice == "Y");
}
