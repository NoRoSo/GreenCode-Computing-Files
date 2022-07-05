
#include<bits/stdc++.h>
using namespace std;

int distinctSubstring(string str)
{
    // Put all distinct substring in a HashSet
    set<string> result ;

    // List All Substrings
    for (int i = 0; i <= str.length(); i++)
    {
        for (int j = 1; j <= str.length()-i; j++)
        {
            // Add each substring in Set
            result.insert(str.substr(i, j));
        }
    }

    // Return size of the HashSet
    return result.size();
}

int main()
{
    int n; cin >> n; //getting the length of string (it's never used in this question)
    string str;
    cin >> str;

    cout << (distinctSubstring(str));
}
