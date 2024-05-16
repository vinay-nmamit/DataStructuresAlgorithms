// convert a given string to its lower case 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ToLowerCase(const string& str){
    string result = str;
    for( auto&c : result){
        c = tolower(c);
    }

    return result;
}

int main(){
    string str;
    getline(cin, str);

    string result = ToLowerCase(str);
    cout << result;
}