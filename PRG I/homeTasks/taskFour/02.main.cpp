#include <iostream>
#include <string>

using namespace std;

int main()
{
    string words[3] = {"one", "two", "three"};
	
	for (int i = 0; i < 3; i++) {
		cout << words[i] << endl;
	}
	
	cout << "First letters: " << words[0][0] << words[1][0] << words[2][0] << endl;
	
	// pa vienai burtai - izmantojam getch()
	
	string s1;
	
	cout << "Input line: " << endl;
	getline(cin, s1);
	
	while (s1.find("  ") != string::npos) {
		s1.replace(s1.find("  "), 2, " ");
	}
	
	if (s1[0] == ' ') {
		s1.replace(0, 1, "");
	}
	
	if (s1[s1.length()-1] == ' ') {
		s1.replace(s1.length(), 1, "");
	}
	
	cout << s1 << endl;
	
    return 0;
}
