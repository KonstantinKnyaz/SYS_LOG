#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;

int file();

int main()
{
	setlocale(LC_ALL, "Russian");

	string pass[] = { "Key666", "LoG222", "fUn9" }, user_log, user_in;
	string log[] = { "Cpp", "Admin", "User" };
	bool login = false;
	int rat = 3;

tryA:
	cout << "Введите логин: ";
	cin >> user_log;
	cout << "Введите пароль: ";
	cin >> user_in;

	for (int i = 0; i < 3; i++) {
		if (log[i] == user_log && pass[i] == user_in) {
			login = true;
			cout << "Вход выполнен" << endl;
		}
	}

	if (!login && rat == 3) {
		cout << "Логин или пароль не верны, осталось 2 попытки!" << endl;
		rat--;
		goto tryA;
	}
	else if (!login && rat == 2) {
		cout << "Логин или пароль не верны, осталась 1 попытка!" << endl;
		rat--;
		goto tryA;
	}
	else if (!login && rat == 1) {
		cout << "Логин или пароль не верны, попыток не осталось!" << endl;
		rat--;
	}

	if (login == true)
		file();

	return 0;

}

int file() {

	ofstream file;
	string file_name;
	char text[100];
	cout << "Введите название файла: ";
	cin >> file_name;

	file.open(file_name, ofstream::app);

	if (file.is_open()) {
		cout << "Введите текст: ";
		cin.get();
		cin.getline(text, sizeof(text));
		file << text << "\n";
	}
	else
		cout << "Файл не был открыт!" << endl;

	file.close();
	return 0;
}