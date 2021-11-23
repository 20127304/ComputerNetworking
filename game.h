#ifndef _GAME_H_
#define _GAME_H_
#include "common.h"
#include "user.h"
class game {
protected:
	vector<vector<int>> ship1;
	vector<vector<int>> ship2;
	user a;
	user b;
public:
	game(user& a, user& b) {
		this->a = a;
		this->b = b;
	}
	game() = default;
	vector<vector<int>> getShipInfo(user a) {
		return a.shipInfo();
	}
	void loadShip() {
		ship1 = getShipInfo(a);
		ship2 = getShipInfo(b);
	}
	void display() {

	}
};

class sever {
private:
	//int size;
	vector<user> onlineUser;
	vector<user> allUser;
public:
	void listOnlineUser() {
		for (auto& x : onlineUser) {
			cout << x.getName() << endl;
		}
	}
	void loadOnlineUserFromFile() {
		// 1 file toàn bộ user và 1 file user đang online, trên 1 
		//dòng lưu đầy đủ thông tin user đó, vì chưa biết user gồm những gì nên chưa làm đoạn này
		// load file user đang online 
	}
	void startGame(user& a, user& b) {
		game g(a,b);
		g.loadShip();

	}
	void sendRequest(user&a, user &b) {
		bool isAccept = b.getRequest(a);
		if (!isAccept) {
			// phản hồi lại cho client 1
		}
		else {
			startGame(a, b);
		}
	}

};

#endif // !_GAME_H_
