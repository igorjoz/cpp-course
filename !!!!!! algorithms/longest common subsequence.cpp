#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    int m = str1.length();
    int n = str2.length();

    // dynamiczne stworzenie dp
    int** dp = new int* [m + 1];
    for (int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }

    // wypelnienie gornej i lewej krawdzi zerami
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;

    // obliczenie dp
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }   
            else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }        
    }
        

    // wyznaczamy LCS
    string sLCS = "";
    int i = m - 1; // start "od konca"
    int j = n - 1;

    while (i >= 0 and j >= 0) {
        if (str1[i] == str2[j]) {
            sLCS = str1[i] + sLCS;
            i--;
            j--;
        }
        else if (dp[i + 1][j] > dp[i][j + 1]) j--;
        else i--;
    }   

    cout << sLCS << ": " << dp[m][n];
}