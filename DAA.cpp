#include <iostream>
#include <vector>
#include <thread> // for sleep
#include <chrono> // for sleep

using namespace std;

vector<string> generatePattern(int n) {  //geenrate 0000, 1000, 1100, 1110 for n=4
    vector<string> pattern(n);

    for (int i = 0; i < n; ++i) {
        pattern[i] = string(i, '1') + string(n - i, '0');
    }

    return pattern;
}

vector<char> Guess(int n) {
    vector<string> questionarray = generatePattern(n);
    vector<char> OurGuess(n);
    vector<int> AnswersToQuestions(n);
    char b;

    cout << "\nI will ask you " << n << " questions now" << endl;;
    for (int i = 0; i < n; i++) {
        cout << "\n\tIs your string: " << questionarray[i] << "? (y/n)" << endl;;
        cout << "-> ";
        cin >> b ;
        cout << endl;
        if (b != 'y') {
            cout << "\tTell me how many bits are at their correct index? Be honest ;)  :  ";
            cin >> AnswersToQuestions[i];
        }
        else {
            return questionarray[i];
        }
    }

    // Compare answers to identify each bit
    for (int i = 0; i < n - 1; i++) {
        if (AnswersToQuestions[i] < AnswersToQuestions[i + 1]) {
            OurGuess[i] = '1';
        }
        else {
            OurGuess[i] = '0';
        }
    }

    // Determine the last bit
    int TotalZeroesCorrectlyIdentified = 0;
    for (int i = 0; i < n - 1; i++) {
        if (OurGuess[i] == '0') {
            TotalZeroesCorrectlyIdentified++;
        }
    }
    if (TotalZeroesCorrectlyIdentified == AnswersToQuestions[0]) {
        OurGuess[n - 1] = '1';
    }
    else {
        OurGuess[n - 1] = '0';
    }
    return OurGuess;
}

int main() {
    int n;
    char c;
    cout << "\t\t\t\t\t~WELCOME!!!~";
    cout << "\n\t\t\t~We can guess the string on your mind! in n tries! or even less than n!~\n";
    cout << endl;
    cout << "    What's the length of the string you'll want me to guess? ";
    cin >> n;



    vector<char> myguess = Guess(n);
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"<<endl;
    cout << "Performing magic with logic and maths ...." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    cout << "Gathering data" << endl;
    this_thread::sleep_for(chrono::seconds(2));

    cout << "Compiling data...." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    cout << "\nI guessed this: ";
    for (int i = 0; i < n; i++) {
        cout << myguess[i] << " ";
    }

    cout << "\nWas I right? [y/n] ";
    cin >> c;
    if (c == 'y' || c == 'Y') {
        cout << "Yess! Good game" << endl;
    }
    else {
        cout << "Aww :( It's okay, we can play again!" << endl;
    }
}
