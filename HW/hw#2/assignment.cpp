#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
	string name;
public:
	void writeName(string name) { this->name = name; }
	string getName() { return name; }
};

class GamblingGame {
	Player player[2];
public:
	void gamestart();
	bool turn(string name);
	~GamblingGame();
};

bool GamblingGame::turn(string name) {
	string enter;
	cout << name << ":<Enter>";

	while (1) {
		char enter;
		cin.get(enter);

		if (enter == '\n')
			break;
	}

	int randomN[3] = {0};

	for (int i = 0; i < 3; i++) {
		randomN[i] = rand() % 3;
	}

	cout << "\t\t" << randomN[0] << '\t' << randomN[1] << '\t' << randomN[2] << '\t';
	if (randomN[0] == randomN[1] && randomN[1] == randomN[2])
		return 1;
	else
		return 0;
}

void GamblingGame::gamestart() {
	srand((unsigned)time(NULL));
	cout << "***** ���� ������ �����մϴ�. *****" << endl;
	string name;
	cout << "ù��° ���� �̸�>>";
	cin >> name;
	player[0].writeName(name);
	cout << "�ι�° ���� �̸�>>";
	cin >> name;
	player[1].writeName(name);
	cin.ignore();

	int end = 0;
	while (1) {
		for (int i = 0; i < 2; i++) {
			if ( turn(player[i].getName()) ) {
				cout << player[i].getName() << "�� �¸�!!!" << endl;
				end = 1;
				break;
			}
			else
				cout << "�ƽ�����!" << endl;
		}
		if (end == 1)
			break;
	}
}



GamblingGame::~GamblingGame() {

}

int main(void) {

	GamblingGame game;
	game.gamestart();

	return 0;
}