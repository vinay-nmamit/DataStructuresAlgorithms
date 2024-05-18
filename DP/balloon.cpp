#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class solution {
    public: 
        void solve(vector<string>& l){
            string word = "balloon";
            for(int i = 0; i < l.size(); i++){
                unordered_map<char, int> mp;
                for(int j = 0; j < l[i].size(); j++){
                    mp[l[i][j]]++;
                }
                int ans = 1e5;
                bool flag = true;
                for(int k = 0; i < word.size(); k++){
                    if(mp.find(word[k]) != mp.end()){
                        int letter = mp[word[k]];
                        if(word[k] == 'l' or word[k] == 'o'){
                            letter = letter / 2;
                        }
                        ans = min(ans,letter);
                    } else {
                        flag = false;
                        cout << 0 << endl;
                        break;
                    }
                }
                if(flag)
                    cout << ans << endl;
            }
        }
};