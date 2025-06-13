#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <cstring>

#define isdelim(c) (isspace((c)) || ispunct((c)))
using namespace std;

string substrings(string str, string substr) 
{
    int count = 0;

    for (int i = 0; i < str.size(); i++)
        if (str.substr(i, substr.size()) == substr)
        {
            count++; 
            i += substr.size() - 1;
        }
    return substr + "-" + to_string(count);
}

int main()
{
	string words,line;

    ifstream in("Text.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "File reading error!" << endl;
        exit(0);
    }
    in.close();

	cout << "\nEnter your letter combinations: " << endl;
	getline(cin, words);
    
    vector<string> str2;
    istringstream is(words);
    string temp;
    while (is >> temp)
        str2.push_back(temp);

    cout << endl;
    for (vector<string>::iterator it = str2.begin(); it != str2.end(); ++it)
    {
        cout << substrings(line, *it) << endl;
    }
}