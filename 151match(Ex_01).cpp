#include<iostream>
using namespace std;
char s[25],re[25];
int slen,rlen;
void match(char[],char[]);
int main()
{
int i;
char ans;
do
{
cout<<"Enter re";
cin>>re;
cout<<"Enter str";
cin>>s;
match(re,s);
cout<<"\n Do you want to continue";
cin>>ans;
}
while(ans=='Y');
return 0;
}
void match(char re[],char s[])
{
int i,flag;
for(rlen=0;re[rlen]!='\0';rlen++);
for(slen=0;s[slen]!='\0';slen++);
if((re[0]>=65&&re[0]<=90)||(re[0]>=97&&re[0]<=122))
{
if(re[0]==s[0])
{
switch(re[1])
{
case '.':
switch(re[2])
{
case'*':
if(slen!=1)
{
if(re[rlen-1]==s[slen-1])
{
cout<<"Pattern matched";
}
else
{
cout<<"Pattern not matched";
}
}
else
{
cout<<"Pattern not matched";
}
break;
case '+':
if(s[1]!=re[3])
{
if(re[3]==s[slen-1])
{
cout<<"Pattern matched";
}
else
{
cout<<"Pattern not matched";
}
}
break;
default:
if(s[slen-1]==re[rlen-1])
{
if(slen==3)
{
cout<<"Pattern matched";
}
else
cout<<"Pattern not matched";
}
else
{
cout<<"Pattern not matched";
}
break;
}
break;
case '*':
if(re[rlen-1]==s[slen-1])
{
for(i=0;i<=slen-2;i++)
{
if(s[i]==re[0])
{
flag=1;
}
else
{
flag=0;
}
}
if(flag==1)
{
cout<<"Pattern matched";
}
else
{
cout<<"Pattern not matched";
}
}
else
{
cout<<"Pattern not matched";
}
break;
case '+':
if(slen<=2)
{
cout<<"Pattern not matched";
}
else if(re[rlen-1]==s[slen-1])
{
for(i=0;i<slen-2;i++)
{
if(s[i]==re[0])
{
flag=1;
}
else
{
flag=0;
}
}
if(flag==1)
{
cout<<"Pattern matched";
}
else
{
cout<<"Pattern not matched";
}
}
break;
}
}
else
cout<<"Pattern not matched";
}
else
cout<<"EXPRESSION INVALID";
}

