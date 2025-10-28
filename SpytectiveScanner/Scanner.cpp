#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <unordered_set>
using namespace std;

//Spytective keywords
unordered_set<string> keywords = {
    "motive", "crime_scene", "report", "trigger",
    "investigate", "fallback", "resist", "expose",
    "truth", "alibi"
};

//Spytective data types
unordered_set<string> dataTypes = {
    "fine", "evidence", "briberry", "intent"
};

//Operators 
unordered_set<string> operators = {
    "=", "+", "-", "*", "/", "<", ">", "==", "!="
};

//Symbols
unordered_set<string> symbols = {
    "{", "}", "(", ")", ";", "->>"
};

//Function to check token type
string getTokenType(const string& token) {
    if (token.empty()) return "";

    if (keywords.count(token)) return "Keyword";
    if (dataTypes.count(token)) return "Data Type";
    if (operators.count(token)) return "Operator";
    if (symbols.count(token)) return "Symbol";
    if (regex_match(token, regex("[0-9]+"))) return "Number";
    if (regex_match(token, regex("\".*\""))) return "String";
    if (regex_match(token, regex("[a-zA-Z_][a-zA-Z0-9_]*"))) return "Identifier";

    return "Unknown";
}


int main() {
    ifstream file("spytectiveExampleFile.txt");
    if (!file.is_open()) {
        cerr << "Error: Cannot open source file.\n";
        return 1;
    }

    string line;
    int lineNumber = 0;

    cout << "=== Spytective Lexical Scanner ===\n\n";

    while (getline(file, line)) {
        lineNumber++;

        // Skip comments
        if (line.find("->>") == 0) continue;

        // Split by space or punctuation
        regex tokenRegex("([a-zA-Z_][a-zA-Z0-9_]*|->>|==|!=|[=+\\-*/<>(){};]|\"[^\"]*\"|[0-9]+)");
        auto words_begin = sregex_iterator(line.begin(), line.end(), tokenRegex);
        auto words_end = sregex_iterator();

        for (auto it = words_begin; it != words_end; ++it) {
            string token = it->str();
            string type = getTokenType(token);
            if (!type.empty())
                cout << "Line " << lineNumber << ":  " << token << "\t=> " << type << endl;
        }
    }

    file.close();
    return 0;
}