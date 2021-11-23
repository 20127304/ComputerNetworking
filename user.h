#ifndef _USER_H_
#define _USER_H_
#include "common.h"
class user {
protected:
	//vector<vector<int>> ship;
	int ship[15][15];
	string name;
	string password;
public:
	string getName();
	void uploadShip(string file) {
		ifstream fin;
		fin.open("user1_ship.txt"); // thay thành cái file để upload
		if (fin.is_open()) {
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {
					fin>>ship[i][j];
				}
			}
		}
		else {
			cout << "can not open file storing ship" << endl;
		}
	}
	vector<vector<int>> shipInfo() {
		vector<vector<int>> tem0;
		vector<int> tem1;
		int r = 0;

		while (r < 15) {
			for (int i = 0; i < 15; i++) {
				tem1.push_back(ship[r][i]);
			}
			tem0.push_back(tem1);
			r++;
		}
		return tem0;
	}

	bool getRequest(user &a) {
		cout << "you have a request to a game from " << a.getName() << endl;
		cout << "do you join game?(Y/N)" << endl;
		cin.ignore(1000,'\n');
		char c;
		cin >> c;
		if (tolower(c) == 'y') {
			return true;
		}
		else return false;
	}
	void start_game() {
		//listOnlineUser
		//
		//
		//
	}
	void createRoom(int roomID, string user_name) {
		// send request tới sever
	}
	user& operator=(const user& b) {
	
	}
};

#endif // !_USER_H_
