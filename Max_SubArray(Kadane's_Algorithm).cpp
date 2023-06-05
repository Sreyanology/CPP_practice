#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int max_ans = INT_MIN;
    int max_it = 0;
    for(int i=0; i<nums.size(); i++)
    {
       max_it = max_it + nums[i];
       if(max_ans < max_it)
         max_ans = max_it;
       if(max_it < 0)
         max_it = 0;
    }
    cout<<max_ans<<endl;
    return 0;
}

