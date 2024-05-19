#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> customSplit(string str, char separator)
{
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


int main()
{
    string filePath = "../forms/KKL106.txt";
    // Step 0: Open the input file
    ifstream kisekaeFile(filePath);

    // Error check for if file exists
    if (!kisekaeFile.is_open()) {
        cerr << "Unable to open file: " << filePath << endl;
        return 1;
    }

    // Step 0.1: Read file contents into string stream
    stringstream buffer;
    buffer << kisekaeFile.rdbuf();

    // Step 0.2: Convert sstream to string
    string kisekaeCode = buffer.str();
    cout << "Code: " << kisekaeCode << endl << endl << endl;

    // Step 0.3: Close the file
    kisekaeFile.close();

    // Step 1: Split code into a vector of strings.
    vector<string> splitCode = customSplit(kisekaeCode, '_');

    // Step 2: Parse the strings
    for (auto item : splitCode) {
        // Error Check
        cout << item << endl;

    }

    return 0;
}

