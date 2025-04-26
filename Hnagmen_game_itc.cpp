#include<iostream>
using namespace std;
int main(){
	bool again = false;
	cout << "-------------Best of luck Player 2------------------------------";
	do{
		char dic[1000] = {};
		cout << "\nEnter Word, Sentance or Phases by player 1:";
		cin.getline(dic, 1000);
		if (again){
			cin.getline(dic, 1000);
		}
		int length = 0;
		cout << "\nConvert into small alphabad:";
		for (int l = 0; dic[l] != '\0'; l++){
			length++;
			if (dic[l] >= 'A' && dic[l] <= 'Z'){
				dic[l] = dic[l] + 32;
			}
		}
		cout << "\nThe length of this word or sentance or phases:" << length << endl << endl;
		char find[1000] = {};
		for (int l = 0; l < length; l++){
			if (dic[l] == ' '){
				find[l] = ' ';
			}
			else{
				find[l] = '*';
			}
		}
		bool run = true;
		bool found = false;
		cout << "\nYou Enter only 3 wrong Word:\n";
		char word_guess;
		int chance = 0;
		do{
			for (int l = 0; l < length; l++){
				cout << find[l];
			}
			found = false;
			cout << "\nEnter Word:";
			cin >> word_guess;
			for (int l = 0; l < length; l++){
				if (dic[l] == word_guess){
					find[l] = word_guess;
					found = true;
				}
				else if (find[l] >= 'A' && find[l] <= 'Z' || find[l] >= 'a' && find[l] <= 'z'){
					continue;
				}
				else if (dic[l] == ' '){
					find[l] = ' ';
				}
				else{
					find[l] = '*';
				}
			}
			if (found == false){
				chance++;
				cout << "\nYour guess is Wrong:";
				cout << "\nYou lose " << chance << " chance from 3";
			}
			for (int l = 0; l < length; l++){
				if (find[l] == '*'){
					run = true;
				}
			}
			if (!run){
				break;
			}
			run = false;
		} while (chance != 3);

		cout << "\nThe word is: " << dic << endl << endl;
		if (chance == 3){
			cout << "\nYou lose this game:";
		}
		else{
			cout << "\nYou win this game:";
		}
		cout << "\nPlay again, Press 1, otherwise press any key:";
		cin >> again;
	} while (again);
}