#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char b[20][20];
int n,i,j,k,l,m,o,p,c,d,e,f;
cout<<"\n enter the no of productions";
cin>>n;
cout<<"\n enter the productions";
for(i=0;i<n;i++)
 {
  cin>>b[i];
 }
cout<<"\n The closure of th given grammar is";
p=3;
c=0;
for(i=0;i<n;i++)
{
 l=strlen(b[i]);
 for(k=0,e=0;e<l-3;e++)
 {
  for(f=0;f<3;f++)
  {
   cout<<b[i][f];
  }
  for(j=0;j<l-3;j++)
  {
   if(k==c&&j==c)
    {
     cout<<".";
     c++;
    }
    cout<<b[i][j+3];
  }
 k++;
 cout<<"\n";
}
 c=0;
 }
}
