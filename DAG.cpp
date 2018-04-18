#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int n,l,pt[10],left[10],right[10],i,c,d,e,p=0;
char ex[10],label[10],only[10];
cout<<"\n Enter the expression";
cin>>ex;
l=strlen(ex);
for(int m=0;m<l;m++)
{
if (ex[m]!=')' && ex[m]!='(')
only[p++]=ex[m];
else
ex[m]='\0';
}
l=p;
for(int k=0;k<l;k++)
ex[k]=only[k];
int j=0;
for(int i=0;i<l;i++)
{
if(ex[i]=='a'||ex[i]=='b'||ex[i]=='c'||ex[i]=='d')
{
label[j]=ex[i];
left[j]=0;
right[j]=0;
pt[j]=j;
j++;
}
}
c=j;
e=j;
//cout<<"\n"<<"\tptr\t\tleft\t\tright\t\tlabel";
for(i=0;i<c;i++)
{
cout<<"\n"<<"\t"<< pt[i]<<"\t "<<left[i]<<"\t"<<right[i]<<"\t"<<label[i];
}
for(i=0;i<l;i++)
{
if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/')
{
label[c]=ex[i];
left[c]=pt[i-1];
right[c]=pt[i];
pt[c]=c;
c++;
}
}
d=c;
for(i=e;i<d;i++)
{
cout<<"\n"<<"\t"<< pt[i]<<"\t "<<left[i]<<"\t"<<right[i]<<"\t"<<label[i]<<"\n";
}
}


