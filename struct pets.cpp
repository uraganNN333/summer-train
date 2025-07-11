#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;
/*struct Pets {
	string owner;
	string type;
	string nickname;
	int age;
};
Pets p1;
vector <Pets> p;
p.push_back({ "Ваня","Рыбка","Бобик",20 });
p.push_back({ "Игнат","Собака","Ебик",10 });
for (int i = 0; i < p.size(); i++) {
	cout << p[i].owner << " " << p[i].type << " " << p[i].nickname << " " << p[i].age << "\n";
}
}*/

struct Pets {
	string owner;
	string type;
	string nickname;
	int age;
};
void info(ifstream& data, string line) {
	while (getline(data, line)) {
		cout << line << endl;
	}
}
void Base(vector <Pets>&p,ifstream& data) {
	string line;
	while (getline(data, line)) {
		stringstream ss(line);
		string owner, type, nickname, ageStr;
		getline(ss, owner, ',');
		getline(ss, type, ',');
		getline(ss, nickname, ',');
		getline(ss, ageStr, ',');

		int age = stoi(ageStr);

		p.push_back({ owner,type,nickname,age });

	}
}
void CountPetsTypePerOwner(vector<Pets>& p) {
	map<string, map<string, int>> countDict;

	for (int i = 0; i < p.size(); i++) {
		countDict[p[i].owner][p[i].type]++;
	}

	map<string, map<string, int>> countDict;

	map<string, map<string, int>>::iterator ownerIt;
	for (ownerIt = countDict.begin(); ownerIt != countDict.end(); ++ownerIt) {
		string owner = ownerIt->first;
		map<string, int>& types = ownerIt->second;

		map<string, int>::iterator typeIt;
		for (typeIt = types.begin(); typeIt != types.end(); ++typeIt) {
			cout << owner << " — " << typeIt->first << ": " << typeIt->second << "\n";
		}
	}
}
void TypeAnimal(vector<Pets>& p,string targetOwner) {
	set<string> seenNicknames;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].owner == targetOwner) {
			if (seenNicknames.find(p[i].nickname) == seenNicknames.end()) {
				seenNicknames.insert(p[i].nickname);
				cout << p[i].type << " - ";
				if (p[i].nickname.empty()) {
					cout << "без прозвища";
				}
				else {
					cout << p[i].nickname;
				}
			}
			cout << "\n";
		}
	}
		
}
int CountTypePerNickname(vector<Pets>& p, string& cnickname,string& ctype) {
	int count = 0;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].nickname == cnickname and p[i].type == ctype) {
			count++;
		}
	}
	return count;
}

void CountTypePerNickname(vector<Pets>& p, string targetNickname) {
	set<string> uniqueTypes;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].nickname == targetNickname) {
			uniqueTypes.insert(p[i].type);
		}
	}
	cout << "Кличку \"" << targetNickname << "\" носят " << uniqueTypes.size() << " вида(ов) животных.\n";
}

void TypePerYO(vector<Pets>& p) {
	map<string, vector<int>> typeToAges;

	for (int i = 0; i < p.size(); i++) {
		typeToAges[p[i].type].push_back(p[i].age);
	}

	for (auto it = typeToAges.begin(); it != typeToAges.end(); ++it) {
		if (!it->second.empty()) {
			int minAge = *min_element(it->second.begin(), it->second.end());
			int maxAge = *max_element(it->second.begin(), it->second.end());
			cout << it->first << ": возраст от " << minAge << " до " << maxAge << "\n";
		}
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	ifstream data("input.txt");
	string line;
	vector <Pets> p;

	if (!data.is_open()) {
		cout << "Не удалось открыть файл!\n";
		return 1;
	}

	Base(p, data);

	int choice;
	while (true) {
		cout << "\n=== Меню запросов ===\n";
		cout << "1 — Кол-во видов животных у владельцев\n";
		cout << "2 — Все питомцы по владельцу\n";
		cout << "3 — Сколько видов животных носят кличку\n";
		cout << "4 — Диапазон возраста по виду\n";
		cout << "0 — Выход\n";
		cout << "Выберите действие: ";
		cin >> choice;
		cin.ignore();

		if (choice == 0) break;

		if (choice == 1) {
			CountPetsTypePerOwner(p);
		}
		else if (choice == 2) {
			string targetOwner;
			cout << "Введите имя владельца: ";
			getline(cin, targetOwner);
			TypeAnimal(p, targetOwner);
		}
		else if (choice == 3) {
			string targetNickname;
			cout << "Введите кличку: ";
			getline(cin, targetNickname);
			CountTypePerNickname(p, targetNickname);
		}
		else if (choice == 4) {
			TypePerYO(p);
		}
		else {
			cout << "Некорректный ввод.\n";
		}
	}

	return 0;
}

	