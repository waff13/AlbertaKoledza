#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int RANGE = 5;
int lastOne = 4;

string getRandomWord() {
    
    string dictionary[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    int selected = (rand() % (RANGE + 1));
    cout << "Range = " << RANGE << " and selected = " << selected << endl;
    string result = dictionary[selected];
    string temp = dictionary[selected];
    dictionary[selected] = dictionary[lastOne];
    dictionary[lastOne] = temp;


    
    //cout << "Return result is " << result << endl;
    cout << "Array after element move:" << endl;
    //cout << "Now range = " << RANGE << " and selected = " << selected << endl;
    for (int i = 0; i < 5; i++) {
        cout << dictionary[i] + ", ";
    }
    cout << endl;
    RANGE --;
    lastOne--;
    
    return result;
}

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
	
	string hidden = "barbeque";
    cout << hidden << endl;
    int size = hidden.length();
    for (int i = 0; i < size; i++) {
        cout << '.';
    }
    cout << endl;
    
    /*char userInput;
    string s10 = "........"
    while (userInput != 0) {
        userInput = getch();
        
        while (hidden.find(userInput) != string::npos) {
		s10.replace(hidden.find(userInput), 1, '.');
	}
        
    }*/
    
    string str = "javatpoint";  
    int a = str.find('a');
    cout << "a = " << a << endl;
    
    string rwar = "qwerwererer";
    //string rwar = "eeeee"; // used for test
    char userZInput = 'e';
    //string result = "";
    int result[20];
    int counter = 0;
    int length = rwar.length();
    cout << "Length is " << length << endl;
    for (int i = 0, j = 0; i < length; i++) {
        if (rwar[i]==userZInput) {
            //result = result + to_string(i) + ",";
            result[j] = i;
            counter++;
            j++;
        }
    }
    //cout << "Result string: " << result << endl;
    
    string output = "..........."; // construct this string using the size of an initial word
    //string output = "....."; // used for test
    if (counter == 0) {
        cout << "No such letter! -1 point" << endl;
    } else {
        string foooo;
        foooo.replace(0, 1, 1, userZInput);
        for (int i = 0; i < counter; i++){
            cout << "Position of letter " << userZInput << ": " << result[i] << endl;
            output.replace(result[i], 1, foooo);
            //output.replace(3, 1, "z");    <- works, note that z is in "" ("z"; a string).
        }
    }
    cout << "Output line: " << output << endl;
    
    // check if the word is guessed
    if (output.find(".") != string::npos){
        cout << "There are some . left" << endl;
    } else {
        cout << "The word is guessed entirely!" << endl;
    }
    
    cout << "01: "<< getRandomWord() << endl;
    cout << endl;
    cout << "02: "<< getRandomWord() << endl;
    cout << endl;
    cout << "03: "<< getRandomWord() << endl;
    cout << endl;
    cout << "04: "<< getRandomWord() << endl;
    cout << endl;
    cout << "05: "<< getRandomWord() << endl;
    
	/*char c;
	while(c!=48)
	{
		c=getch();
		cout << c << ": " << (int)c << endl;
	}*/
	
	return 0;
}
