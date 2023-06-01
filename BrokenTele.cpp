#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int a[N];
	    int h[N] = {0};
	    for(int i=0; i<N; i++)
	        cin>>a[i];
        int c = 0;
        for(int i=0; i<N; i++)
        {
            if(i!=(N-1) && a[i]!= a[i+1])
            {
                h[i] = 1;
                h[i+1] = 1;
            }
        }
        for(int i=0; i<N; i++)
            if(h[i] == 1)
              c++;
        cout<<c<<endl;
	}
	return 0;
}

