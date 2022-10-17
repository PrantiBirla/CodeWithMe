#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    map<int,int>s;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        s[a[i]]++;
	    }
	    int l=0;
	    for(int i=0;i<n;i++){
	        if(l<s[a[i]]){
	            l=s[a[i]];
	        }
	    }
	    cout<<n-l<<endl;
	  }  
	
	return 0;
}
