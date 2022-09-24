#include <bits/stdc++.h>
using namespace std;

double func(vector<int> &nums1 , vector<int> &nums2){
    int m=nums1.size();
    int n=nums2.size();
    int  n1=m , n2=n;
    int l=0 , r=m;
    // each of both nums array will be left Partition | right partition
    // see mid is at the left_part of partition + 1
    // in both case u can see we are finding the index first element in right partion

    // so our mid is the first element of right partition each of nums1 , nums2

    while(l<=r){
        int mid1=(l+r)/2;
        int mid2=(m+n+1)/2 - mid1;

        int left1=INT_MIN , right1=INT_MAX , left2=INT_MIN , right2=INT_MAX;

        if(mid1>0)
        {
            left1=nums1[mid1-1];
        }
        if(mid2>0)
        {
            left2=nums2[mid2-1];
        }
        if(mid1<m)
        {
            right1=nums1[mid1];
        }
        if(mid2<n)
        {
            right2=nums2[mid2];
        }

        if(left1<=right2 && left2<=right1)
        {
            if((n1+n2)%2!=0)
            {
                double val = (double) max(left1 , left2);
                return val;
            }else{
                return ((max(left1 , left2) + min(right1 , right2))/2.0);
            }
        }else
            if(left1>right2)
            {
                r=mid1-1;
            }else{
                l=mid1+1;
            }
        }
    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    // Median of two sorted array

    //  1, 3 , 4 , 7 , 10 , 12
    //  2 , 3 , 6 , 15

    // Apply binary search in first , total elements will be
    // (n1+n2+1)/2

    int m=nums1.size();
    int n=nums2.size();

    if(m>n){
        return func(nums2 , nums1);
        // condition of finding is such that first one has
        // to be size less than or equal , otherwise it will
        //give index that is not possible in nums2 , index>=n2
    }
        return func(nums1 , nums2);


}

int main(){
    int N, M; cin >> N >> M;

    vector<int> nums1, nums2;
    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        nums1.push_back(temp);
    }

    for(int i = 0; i < M; i++){
        int temp; cin >> temp;
        nums2.push_back(temp);
    }

    cout << findMedianSortedArrays(nums1, nums2) << endl;
}
