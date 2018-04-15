#define _GNU_SOURCE
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct quadraple
{
int pos;
char op;
char arg1[5];
char arg2[5];
char result[5];
}quad[15];
int n=0;
void assignment(int);
void uminus(int);
void explore();
void codegen(char op[5],int);
char tuple[15][15];
int main(void)
{
FILE *src;
int nRetInd,i;
char str[15];
src=fopen("int.txt","r");
fscanf(src,"%s",str);
while(!feof(src))
{
strcpy(tuple[n++],str);
fscanf(src,"%s",str);
}
cout<<"INPUT:\nIntermediate codes:\n";
for(i=0;i< n;i++)
cout<<tuple[i];
explore();
cout<<"OUTPUT:\n";
cout<<"Quadruple: \n";
cout<<"pos\topr\targ1\targ2\tresult\n";
for(i=0;i< n;i++)
cout<<"\n"<<quad[i].pos<<"\t"<<quad[i].op<<"\t"<<quad[i].arg1<<"\t"<<quad[i].arg2<<"\t"<<quad[i].result;
i=0;
cout<<"\n\ncode generated :\n";
while(i< n)
{
if(quad[i].op=='+')
codegen("ADD",i);
if(quad[i].op=='=')
assignment(i);
if(quad[i].op=='-')
if(!strcmp(quad[i].arg2,"\0"))
uminus(i);
else
codegen("SUB",i);
if(quad[i].op=='*')
codegen("MUL",i);
if(quad[i].op=='/')
codegen("DIV",i);
i++;
}
fclose(src);
return 0;
}
void codegen(char op[5],int t)
{
char str[25];
cout<<"MOV"<<quad[t].arg1<<",R0\n";
cout<<op<<quad[t].arg2<<",R0\n";
cout<<"MOV R0,"<<quad[t].result<<"\n";
}
void assignment(int t)
{
char str[25];
printf("MOV %s,%s\n",quad[t].result,quad[t].arg1);
}
void uminus(int t)
{
char str[25];
cout<<"MOV R0,0\n";
cout<<"SUB "<<quad[t].arg1<<",R0\n";
cout<<"MOV R0,"<<quad[t].result<<"\n";
}
void explore()
{
int i,j,t,t1,t2;
for(i=0;i < n;i++)
{
quad[i].pos=i;
for(j=0,t=0;j < strlen(tuple[i])&&tuple[i][j]!='=';j++)
{
quad[i].result[t++]=tuple[i][j];
}
t1=j;
quad[i].result[t]='\0';
if(tuple[i][j]=='=')
{
quad[i].op='=';
}
if(tuple[i][j+1]=='+'||tuple[i][j+1]=='-'||tuple[i][j+1]=='*'||tuple[i][j+1]=='/')
{
quad[i].op=tuple[i][j+1];
t1=j+1;
}
for(j=t1+1,t=0;j< strlen(tuple[i])&&tuple[i][j]!='+'&&tuple[i][j]!='-'&&tuple[i][j]!='*'&&tuple[i][j]!='/';j++)
{
quad[i].arg1[t++]=tuple[i][j];
}
t2=j;
quad[i].arg1[t]='\0';
if(tuple[i][j]=='+'||tuple[i][j]=='-'||tuple[i][j]=='*'||tuple[i][j]=='/')
{
quad[i].op=tuple[i][j];
}
for(j=t2+1,t=0;j< strlen(tuple[i]);j++)
{
quad[i].arg2[t++]=tuple[i][j];
}
quad[i].arg2[t]='\0';
}
}
