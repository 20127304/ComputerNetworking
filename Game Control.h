#pragma once
#include<iostream>
#include<iomanip>
#include<windows.h>
const int N = 15;

using namespace std;

void CreateWhiteBoard(int P1[][N + 1]);
void PrintBoard(int Attacking[][N + 1], int Mine[][N + 1]);
void Attack(int Player[][N + 1], int myShipBoard[][N + 1], int Opponent[][N + 1], bool& check);
void GamePlay(int ShipMapPlayer1[][N + 1], int ShipMapPlayer2[][N + 1]);
void Menu();