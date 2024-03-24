#include <iostream>
#include <string>
using namespace std;

string mergeLettersAlternatively(string word1, string word2){
    string result = "";
    int i = 0;
    do{
        if(i < word1.length()){
            result += word1[i];
        }
        if(i < word2.length()){
            result+= word2[i];
        }
        i++;
    }while(i < word1.length() || i < word2.length());
    return result;
}

int main(){
    string w1, w2;
    cin >> w1 >> w2;

    cout << "Merged alternatively: ";
    cout << mergeLettersAlternatively(w1, w2) << endl;
}
