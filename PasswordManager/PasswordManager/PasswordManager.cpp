#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

string encryptAndDecrypt(string data, char key) {
	string output = data;
	for (int i = 0; i < data.length(); i++) {
		output[i] = data[i] ^ key;
	}
	return output;
}

void saveToFile(string site, string pass, char key) {
	string encryptedPassword = encryptAndDecrypt(pass, key);
	ofstream file("data.txt", ios::app);
	if(file.is_open()){
		file << site << " " << encryptedPassword << '\n';
		file.close();
		cout << "data is save";
	}
}

void readFromFile(char key) {
	ifstream file("data.txt");
	string site, encryptedPassword;
	cout << "your passwords:\n";
	while (file >> site >> encryptedPassword) {
		string decryptedPassword = encryptAndDecrypt(encryptedPassword, key);
		cout << "site: " << site << '\n' << "password: " << decryptedPassword << '\n';
	}
	file.close();
}

int main() {
	char key = 'K';
	short choise;
	cout << "Welcome to password manager!\n1.New password\n2.Show all\nYour choise: ";
	cin >> choise;
	system("cls");
	if (choise == 1) {
		string site, password;
		cout << "site: "; cin >> site;
		cout << "password: "; cin >> password;
		saveToFile(site, password, key);
	}
	else {
		readFromFile(key);
	}
}