#include<iostream>
#include<ctype.h>
#include<cstring>
using namespace std;
int main()
{
int i,j,k,n,top=0,col,row;
char stack[50],opt[10][10][10];
char ter[20],ip[20];
for(i=0;i<10;i++)
{
stack[i]=NULL;
ip[i]=NULL;
for(j=0;j<10;j++)
{
opt[i][j][1]=NULL;
}
}
cout<<"\n\n\t The productions used are:\n\t";
cout<<"E->E+E/E*E/E-E/(E)/a\n\tE->E/E\n\tE->a/b/c/d.../z\n";
cout<<"\n Enter the no of terminals";
cin>>n;
cout<<"Enter the terminals\n";
for(i=0;i<n;i++)
cin>>ter[i];
cout<<"Input Value For Precedence Table\n";
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cout<<"Precedence value between ("<<ter[i]<<","<<ter[j]<<"):";
cin>>opt[i][j];
}
}
cout<<"\n OPERATOR PRECEDENCE TABLE\n";
for(i=0;i<n;i++)
{
cout<<"\t"<<ter[i];
}
cout<<"\n";
for(i=0;i<n;i++)
{
cout<<"\n"<<ter[i];
for(j=0;j<n;j++)
{
cout<<"\t"<<opt[i][j][0];
}
}
stack[top]='$';
cout<<"\n Enter the input string with $:";
cin>>ip;
i=0;
cout<<"\n STACK\t\t\tInputString\t\tACTION\n";
cout<<"\n"<<stack<<"\t\t\t"<<ip<<"\t\t\t";
while(i<=strlen(ip))
{
for(k=0;k<n;k++)
{
if(stack[top]==ter[k])
col=k;
if(ip[i]==ter[k])
row=k;
}
if((stack[top]=='$')&&(ip[i]=='$'))
{
cout<<"String is Accepted\n";
break;
}
else if((opt[col][row][0]=='<')||(opt[col][row][0]=='='))
{
stack[++top]=opt[col][row][0];
stack[++top]=ip[i];
cout<<ip[i]<<" "<<"Shifted";
i++;
}
else
{
if(opt[col][row][0]=='>')
{
while(stack[top]!='<')
{
top--;
}
top=top-1;
cout<<"Reduced";
}
else
{
cout<<"\n String is not Accepted";
break;
}
}
cout<<"\n";
for(k=0;k<=top;k++)
{
cout<<stack[k];
}
cout<<"\t\t\t";
for(k=i;k<strlen(ip);k++)
{
cout<<ip[k];
}
cout<<"\t\t\t";
}
return 0;
}

