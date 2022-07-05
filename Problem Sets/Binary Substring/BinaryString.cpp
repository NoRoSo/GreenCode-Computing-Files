#include<bits/stdc++.h>

using namespace std;

bool isSubSequence(string str1,string str2)

{

    int j=0;

    for(int i=0;i<str2.size();i++)

    {

        if(str1[j]==str2[i])

        j++;

        if(j==str1.size())

        return true;

    }

    return false;

}



string generatePrintBinary(string str)

{

    queue<string>q;

    q.push("1");

    while(true)

    {

        string s1=q.front();

        q.pop();

        if(isSubSequence(s1,str)==false)

        return s1;

        string s2=s1;

        q.push(s1.append("0"));

        q.push(s2.append("1"));

    }

}



int main()

{

    long long int t;

    cin>>t;

    while(t--)

    {

        string str;

        cin>>str;

        int flag=0;

        for(int i=0;i<str.size();i++)

        {

            if(str[i]=='0')

            flag=1;

        }

        if(flag==0)

        cout << "0" << endl;

        else

        cout << generatePrintBinary(str) << endl;

    }

    return 0;

}

// using namespace std;
// #include <bits/stdc++.h>

// #define ll long long
// #define ld long double
// #define cmpl complex<long double>
// extern const int MAXN = (int)1e6;
// int dp1[MAXN + 2], dp2[MAXN + 2];
// int v1[MAXN], v2[MAXN];

// void sol() {
//   string s;
//   cin >> s;
//   ll n = s.length();
//   int lp = -1;
//   for (int i = 0; i < s.length(); ++i) {
//     if (s[i] == '0') {
//       for (int j = lp + 1; j <= i; ++j)
//         v1[j] = i;
//       lp = i;
//     }
//   }
//   for (int i = lp + 1; i < n; ++i)
//     v1[i] = n;

//   if (v1[0] == n) {
//     cout << "0\n";
//     return;
//   }

//   lp = -1;
//   for (int i = 0; i < n; ++i) {
//     if (s[i] == '1') {
//       for (int j = lp + 1; j <= i; ++j)
//         v2[j] = i;
//       lp = i;
//     }
//   }
//   for (int i = lp + 1; i < n; ++i)
//     v2[i] = n;

//   dp1[n] = dp1[n + 1] = 0;
//   dp2[n] = dp2[n + 1] = 0;
//   for (int i = n - 1; i >= 0; --i) {
//     dp1[i] = dp1[i + 1];
//     if (s[i] == '0' && v2[i] < n)
//       dp1[i] = max(dp1[i], dp1[v2[i] + 1] + 1);
//     if (s[i] == '1' && v1[i] < n)
//       dp1[i] = max(dp1[i], dp1[v1[i] + 1] + 1);
//     dp2[i] = dp2[i + 1];
//     if (v2[i] < n)
//       dp2[i] = max(dp2[i], dp1[v2[i] + 1] + 1);
//   }

//   int len = dp2[0] + 1;
//   int curind = v2[0] + 1;
//   string ans = "1";
//   for (int i = 1; i < len; ++i) {
//     if (curind >= n) {
//       ans.push_back('0');
//       continue;
//     }
//     if (v1[curind] >= n) {
//       ans.push_back('0');
//       curind = v1[curind] + 1;
//       continue;
//     }
//     if (dp1[v1[curind] + 1] < len - i - 1) {
//       ans.push_back('0');
//       curind = v1[curind] + 1;
//     } else {
//       ans.push_back('1');
//       curind = v2[curind] + 1;
//     }
//   }

//   cout << ans << '\n';
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     int t; cin>> t;
//     while(t--){
//         sol();
//     }
//     return 0;
// }
