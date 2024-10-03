#include "Parser.h"

// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> Parser::Parse(const string& InString, const string& InSeparator) const
{
    string str(InString);
    string separator(InSeparator);
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = str.find(separator)) != string::npos)
    {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + separator.length());
    }
    tokens.push_back(str);

    return tokens;
}