#include<iostream>
using namespace std;
//#include<conio.h>
struct node
{
 int data;
 node *next;
}*head,*x,*ptr=NULL;
void addatlast()
{
int n,y,i=0;
cout<<"\nenter the no of elements  to be inserted";
cin>>n;

while(i<n)
{
node *temp;
temp=new node;
cout<<"\ndata:";
cin>>y;
temp->data=y;
temp->next=NULL;
if(ptr==NULL)
{
head=temp;
ptr=temp;
head->next=ptr;
}
else
{
ptr->next=temp;
ptr=temp;
}
i++;
}

}
void display()
{
x=head;
while(x!=NULL)
{
cout<<x->data<<"-->";
x=x->next;
}
}
void addatposition()
{
int y,n,i=0;
node *temp;
temp=new node;
cout<<"\ndata:";
cin>>y;
temp->data=y;
if(ptr==NULL)
{
head=temp;
ptr=temp;
head->next=ptr;
}
else
{
cout<<"\nenter the position";
cin>>n;
x=head;
while(i< n-2)
{
x=x->next;
i++;
}
temp->next=x->next;
x->next=temp;
}
display();
}

void del()
{
int n,i=0;
node *temp;
temp=new node;
cout<<"\nenter the position for deletion";
cin>>n;
x=head;
while(i < n-2)
{
x=x->next;
i++;
}
temp=x->next;
x->next=temp->next;
delete temp;
display();
}
int main()
{
char ch;
int c;
cout<<"\a";
do
{
cout<<"1.ADD AT LAST\n2.ADD AT POSITION\n3.DISPLAY\n4.DELETE\n";
cout<<"choice";
cin>>c;
switch(c)
{
case 1:addatlast();
     display();
break;
case 2:addatposition();
      break;
case 3:display();
       break;
case 4:del();
       break;
}
cout<<"\nwish to continue??";
cin>>ch;
}
while(ch=='y');
}
