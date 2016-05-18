#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void display(string);
void isVowel(string, int);
int main() {
	string input = "";
	int vowel = 0;
	
	cout << "Please enter a string (-1 to exit): ";
	cin >> input;
	while (input != "-1"){
		vowel = 0;
		for (int i = 0; i < input.length(); i += 1) {
			string chunk = input.substr(i,1);
			transform(chunk.begin(), chunk.end(), chunk.begin(), ::toupper);

			if (chunk == "A" || chunk == "E" || chunk == "I" || chunk == "O" || chunk == "U" || chunk == "Y") {
				if(vowel == 0 && i != 0){
					isVowel(input, i);
					i = input.length();
				}
				if(i == 0){
					display(input);
					i = input.length();
				}
				vowel = 1;
			}//end if
		}
		if(vowel == 0){
			display(input);
		}
		
		cout << "Please enter a string (-1 to exit): ";
		cin >> input;
	}	
	
	return 0;
}
void display(string word){
	cout << word << "-way" <<'\n';
}
void isVowel(string word, int location){
	string split = word.substr(location, word.length());
	word = word.substr(0, location);
	cout << split << "-" << word << "ay" <<'\n';
}
