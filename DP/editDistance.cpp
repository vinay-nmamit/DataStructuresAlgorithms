#include<iostream>
#include<vector>
#include<string>
using namespace std;

int editDistance(string str1, string str2){
    int m = str1.size();
    int n = str2.size();

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[n][m];
}

int main(){
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);

    cout << editDistance(str1, str2) << endl;

    return 0;
}