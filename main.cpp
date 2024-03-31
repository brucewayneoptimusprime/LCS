#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string LCS(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i =1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }

            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }


    string result;
    int i = m;
    int j = n;

    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            result = s1[i-1]+result;
            i--;
            j--;

        }

        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;

        }

        else
        {
            j--;
        }
    }

    return result;
}






int main()
{
    string s1;
    cout << "String 1:";
    cin >> s1;


    string s2;
    cout << "String 2:";
    cin >> s2;


    string answer = LCS(s1,s2);
    cout << "The longest length of lCS: " <<answer.size()<<endl;
    cout << "LCS: " << answer << endl;

    return 0;
}
