// input checker probE - ECNA2015

#include <iostream>
using namespace std;

int main(){

  int n,m,s,t;
  int r,c;

  cin>>n>>m>>s>>t;
	if(n<1||n>100) { cout<<"n too big"; return 1; }
        if(m<0||m>n*(n-1)/2) { cout<<"m too large"; return 2; }
        if(s<0||s>=n) {cout<<"s too large"; return 3;}
        if(t<0||t>=10) {cout<<"t too large"; return 4;}

    for (int i=0;i<m;i++){
      cin>>r>>c;
      if (r<0 || c<0 || r>=n || c>=n) { cout<<"r or c out of bounds"; return 5;}
    }
    cout<<endl;

return 42;
}

