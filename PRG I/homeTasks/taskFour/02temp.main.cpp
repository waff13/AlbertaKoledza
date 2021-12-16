#include <iostream>
#include <conio.h>

using namespace std;

int POINTSCOUNTER = 0;
int STEPSTOWIN = 5;
bool GAMEOVER = false;

string checkMove(char userInput, string openWord, string dottedWord);


string getRandomWord() {
	string words[] = {"alpha", "bravo", "charlie", "delta", "echo"};
	int selected = (rand() % 5);
	cout << "selected is " << selected << " and the word is "<<  words[selected] << endl;
	
	return words[selected];
	//return "zaazzzaaertaazjhf";
}

int calculatePoints() {
	cout << "Points at start: " << POINTSCOUNTER << endl;
	POINTSCOUNTER = POINTSCOUNTER - 5;
	if (POINTSCOUNTER < 0) {
		POINTSCOUNTER = 0;
	}
	cout << "Points after calculations: " << POINTSCOUNTER << endl;
	return POINTSCOUNTER;
}

string checkMove(char userInput, string openWord, string dottedWord) {
	int result[20];
	int counter = 0;
	int length = openWord.length();
	for (int i = 0, j = 0; i  < length; i++) {
		if (openWord[i] == userInput) {
			result[j] = i;
			counter++;
			j++;
		}
	}
	
	if (counter == 0) {
		cout << "No such letter! -1 point" << endl;
		POINTSCOUNTER++;
		if (POINTSCOUNTER == 10) {
			cout << "Sorry, you have lost!" << endl;
			GAMEOVER = true;
			return 0;
		}
	} else {
		string foo;
		foo.replace(0, 1, 1, userInput);
		for (int i = 0; i < counter; i++){
			//cout << "Position of letter " << userInput << ": " << result[i] << endl;
			dottedWord.replace(result[i], 1, foo);
			//output.replace(3, 1, "z");    <- works, note that z is in "" ("z"; a string).
		}
	}
	//cout << "Output line: " << dottedWord << endl;
	
	if (dottedWord.find(".") == string::npos) {
		if (STEPSTOWIN == 1) {
			cout << "Congratulations, you have won this game!" << endl;
			GAMEOVER = true;
			return 0;
		} else {
			cout << "OK you have guessed this word!" << endl;
			calculatePoints();
			STEPSTOWIN--;
			cout << STEPSTOWIN << " more and victory is yours!" << endl;
		}
	}
	
	return dottedWord;
}

int main() {
	
	// The game stops both for user input 0 and GAMEOVER=true.
	
	/*for (int i = 0; i < 50; i++) {
		int selected = (rand() % 11); // this is random from 0 to 10
		cout << " : " << selected << endl;
	}
	
	GAMEOVER = true;*/
	
	while(!GAMEOVER){
		
		cout << "The game is on! Make your guess or press 0 to exit" << endl;
		string openWord = getRandomWord();
		string dottedWord;
		for (int i = 0; i < openWord.length(); i++) {
			dottedWord.append(".");
		}
		
		cout << "  openWord: " << openWord << endl;
		cout << "dottedWord: " << dottedWord << endl;
		
		char userInput;
		//while(userInput != 48)
		while (dottedWord.find(".") != string::npos) {
			userInput = getch();
			if (userInput == 48) {
				cout << "OK, see you, bye!" << endl;
				GAMEOVER = true;
				return 0;
			}
			//cout << userInput << ": " << (int)userInput << endl;
			dottedWord = checkMove(userInput, openWord, dottedWord);
			cout << "Now -> " << dottedWord << endl;
		}
	}
	
	/*string rwar = "qwerwererer";
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
    cout << "Output line: " << output << endl;*/
	
	
	
	
    return 0;
}




/*#include <iostream>
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
*/

/*#include <iostream>
#include <string>
#include <conio.h>

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
    
    /*char userzInput;
    string s10 = "........"
    while (userzInput != 0) {
        userzInput = getch();
        
        while (hidden.find(userzInput) != string::npos) {
		s10.replace(hidden.find(userzInput), 1, '.');
	}
        
    }*/
    
    /*string str = "javatpoint";  
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
    cout << "05: "<< getRandomWord() << endl;*/
    
	/*char c;
	while(c!=48)
	{
		c=getch();
		cout << c << ": " << (int)c << endl;
	}*/
	
	/*return 0;
}*/
