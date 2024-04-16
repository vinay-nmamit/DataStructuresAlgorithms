#include <bits/stdc++.h>
using namespace std;

int Lcs(string x, string y, int m, int n){
    if(m == 0 || n == 0){
        return 0;
    }
    if(x[m-1] == y[n-1]){
        return 1 + Lcs(x, y, m-1, n-1);
    } else {
        return max(Lcs(x,y,m-1,n), Lcs(x,y,m,n-1));
    }
}

int main(){
    string x, y;
    cin >> x >> y;

    int m = x.size();
    int n = y.size();

    cout << "Longest common subsequence is: " << Lcs(x, y, m, n) << endl;

    return 0;
}