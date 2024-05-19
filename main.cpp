#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> customSplit(string str, char separator) {
    int startIndex = 0, endIndex = 0;
    vector<string> strings;
    for (int i = 0; i <= str.size(); i++) {

        // If we reached the end of the word or the end of the input.
        if (str[i]==separator || i==str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex-startIndex);
            strings.push_back(temp);
            startIndex = endIndex+1;
        }
    }

    return strings;
}

/**
 * https://cplusplus.com/forum/beginner/151894/
 * @author JLBorges
 * @param stm
 * @return
 */
string stream_as_string( istream& stm )
{
    string str ;
    char c;
    while (stm.get(c)) {
        str += c;
    }
    return str;
}

int main()
{
    // Step 0: Open the input file (not needed for when transferring to main code)
    ifstream kisekaeFile("forms/KKL106.txt");

    // Step 0.1: Read file contents into string
    string kisekaeCode;

    // Step 1: Split code into a vector of strings.
    vector<string> splitCode = customSplit(kisekaeCode, '_');

    // Step 2: Parse the pieces
    cout << "Hello, World!" << endl;
    return 0;
}

