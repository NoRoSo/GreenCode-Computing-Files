#include<bits/stdc++.h>
using namespace std;


int main()
 {
     int cases, caseNum = 1; cin >> cases;

     while(cases--){
        cout << "CASE #" << (caseNum++) << ": ";

        int has[100000] = {0}; //memoization
        vector<pair<int,int> > v1,v2;
        v1.empty(); v2.empty();
        int arr[4]; // getting input
        for(int i=0;i<4;i++)
            cin >> arr[i];

        //we sort the array
        sort(arr,arr+4);

        int a=arr[0];
        int b=arr[1];
        int c=arr[2];
        int d=arr[3];

        //it is doing XOR for all possible combinations of a and b.
        for(int i=1;i<=a;i++){
            for(int j=i;j<=b;j++){
                int xr=i ^ j;
                v1.push_back({j,xr}); //adds them to compare them to the other vector.
            }
        }

        int tc=0;
        for(int i=1;i<=c;i++){
            for(int j=i;j<=d;j++){
                tc++;
                int xr=i ^j;
                v2.push_back({i,xr});
            }
        }

        sort(v2.begin(),v2.end()); //sorts them in ascending order to make the comparisons easier, and it makes one of the later calculations work.
        sort(v1.begin(),v1.end());

        long long int ans=0;

        // hashing
        int len=v2.size();
        for(int i=0;i<len;i++){
            has[v2[i].second]++;
        }

        //checking how many don't equal 0
        int start=0;
        int sz=v1.size();
        for(int i=0;i<sz;i++){
            int xr=v1[i].second;
            int tag=v1[i].first;

            while(v2[start].first<tag){
                has[v2[start].second]--;
                start++;
                tc--;
            }
            ans+=tc-has[xr]; //this subtracts the total number of combinations(tc) with how many were 0's, which leave us with the number of solutions.
        }
        cout<<ans<<endl;
     }
 }
