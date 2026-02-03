#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int M = 10;

    vector<string> names = { "Сосиски", "Сир", "Хліб", "Вафлі", "Чай"};
    vector<int> weight = { 3, 4, 2, 3, 1 };
    vector<int> price = { 7, 9, 5, 7, 8 };

    int n = names.size();

    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    dp[i - 1][w - weight[i - 1]] + price[i - 1]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<int> selected;
    int w = M;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i - 1);
            w -= weight[i - 1];
        }
    }

    cout << "Максимальна вартість рюкзака: " << dp[n][M] << "\n";
    cout << "Вибрані предмети:\n";

    for (int i : selected) {
        cout << "- " << names[i]
            << " (вага " << weight[i]
            << " кг, ціна " << price[i] << ")\n";
    }

    return 0;
}

