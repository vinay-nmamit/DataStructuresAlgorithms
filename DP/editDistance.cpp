#include <iostream>
#include <string>
#include <vector>

int min(int x, int y, int z) {
    return std::min(std::min(x, y), z);
}

int edit_distance(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> D(m + 1, std::vector<int>(n + 1));

    for (size_t i{1}; i <= m; ++i) {
        D.at(i).at(0) = i;
    }

    for (size_t j{1}; j <= n; ++j) {
        D.at(0).at(j) = j;
    }

    for (size_t i{1}; i <= m; ++i) {
        for (size_t j{1}; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                D.at(i).at(j) = D.at(i - 1).at(j - 1);
            } else {
                D.at(i).at(j) = 1 + min(D.at(i - 1).at(j), D.at(i).at(j - 1), D.at(i - 1).at(j - 1));
            }
        }
    }

    return D.at(m).at(n);
}

int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}