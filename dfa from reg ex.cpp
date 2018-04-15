#include<bits/stdc++.h>
using namespace std;
struct nst
{
vector<int> a[2], e;
bool f=0;
};
vector<nst> nfa;
struct dst
{
int a[2] = {-1,-1};
bool f=0;
};
vector<dst> dfa;
stack<int> st;
int nfa_size, dfa_size;
//stringdispregex;
struct nst init_nfa_state;
struct dst init_dfa_state;
void custom_clear() {
for(int i=0; i<100; i++) cout<<endl;
}
string insert_concat(string regexp){
string ret="";
char c,c2;
for(unsigned int i=0; i<regexp.size(); i++){
c=regexp[i];
if(i+1<regexp.size()){
c2=regexp[i+1];
ret+=c;
if(c!='('&&c2!=')'&&c!='+'&&c2!='+'&&c2!='*'){
ret+='.';
}
}
}
ret+=regexp[regexp.size()-1];
return ret;
}
void character(int i)
{
nfa.push_back(init_nfa_state);
nfa.push_back(init_nfa_state);
nfa[nfa_size].a[i].push_back(nfa_size+1);
st.push(nfa_size);
nfa_size++;
st.push(nfa_size);
nfa_size++;
}
void union_()
{
nfa.push_back(init_nfa_state);
nfa.push_back(init_nfa_state);
int d = st.top(); st.pop();
int c = st.top(); st.pop();
int b = st.top(); st.pop();
int a = st.top(); st.pop();
nfa[nfa_size].e.push_back(a);
nfa[nfa_size].e.push_back(c);
nfa[b].e.push_back(nfa_size+1);
nfa[d].e.push_back(nfa_size+1);
st.push(nfa_size);
nfa_size++;
st.push(nfa_size);
nfa_size++;
}
void concatenation()
{
int d = st.top(); st.pop();
int c = st.top(); st.pop();
int b = st.top(); st.pop();
int a = st.top(); st.pop();
nfa[b].e.push_back(c);
st.push(a);
st.push(d);
}
void kleene_star()
{
nfa.push_back(init_nfa_state);
nfa.push_back(init_nfa_state);
int b = st.top();
st.pop();
int a = st.top();
st.pop();
nfa[nfa_size].e.push_back(a);
nfa[nfa_size].e.push_back(nfa_size+1);
nfa[b].e.push_back(a);
nfa[b].e.push_back(nfa_size+1);
st.push(nfa_size);
nfa_size++;
st.push(nfa_size);
nfa_size++;
}
void postfix_to_nfa(string postfix)
{
for(unsigned int i=0; i<postfix.size(); i++)
{
switch(postfix[i])
{
case 'a':
case 'b': character(postfix[i]-'a'); break;
case '*': kleene_star(); break;
case '.': concatenation(); break;
case '+': union_();
}
}
}
int display_nfa()
{
{
char dispregex[20];
int q[20][3],i,j,len,a,b;
for(a=0;a<20;a++)
{
for(b=0;b<3;b++)
{
q[a][b]=0;
}
}
cout<<"Enter a Regular expression: ";
cin>>dispregex;
for(len=0;re[len]!='\0';len++);
i=0;
j=1;
while(i<len)
{
if(re[i]=='a'&& re[i+1]!='/'&& re[i+1]!='+' && re[i+1]!='*')
{
q[j][0]=j+1;
j++;
}
if(re[i]=='b'&& re[i+1]!='/'&& re[i+1]!='+' && re[i+1]!='*')
{
q[j][1]=j+1;
j++;
}
if(re[i]=='e'&& re[i+1]!='/'&& re[i+1]!='+' && re[i+1]!='*')
{
q[j][2]=j+1;
j++;
}
if(re[i]=='a'&& (re[i+1]=='/' || re[i+1]=='+') && re[i+2]=='b')
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][0]=j+1;
j++;
q[j][2]=j+3;
j++;
q[j][1]=j+1;
j++;
q[j][2]=j+1;
j++;
i=i+2;
}
if(re[i]=='b'&& (re[i+1]=='/' || re[i+1]=='+') && re[i+2]=='a')
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][1]=j+1;
j++;
q[j][2]=j+3;
j++;
q[j][0]=j+1;
j++;
q[j][2]=j+1;
j++;
i=i+2;
}
if(re[i]=='a'&& re[i+1]=='*')
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][0]=j+1;
j++;
q[j][2]=((j+1)*10)+(j-1);
j++;
}
if(re[i]=='b'&& re[i+1]=='*')
{
q[j][2]=((j+1)*10)+(j+3);
j++;
q[j][1]=j+1;
j++; 
q[j][2]=((j+1)*10)+(j-1);
j++;
}
if(re[i]==')'&& re[i+1]=='*')
{
q[0][2]=((j+1)*10)+1;
q[j][2]=((j+1)*10)+1;
j++;
}
i++;
}
cout<<"Transition function:";
for(i=0;i<=j;i++)
{
if(q[i][0]!=0)
cout<<"\n q["<<i<<",a]-->"<<q[i][0];
if(q[i][1]!=0)
cout<<"\n q["<<i<<",b]-->"<<q[i][1];
if(q[i][2]!=0)
{
if(q[i][2]<10)
cout<<"\n q["<<i<<",e]-->"<<q[i][2];
else
cout<<"\n q["<<i<<",e]-->"<<q[i][2]/10<<" & "<<q[i][2]%10;
}
}
return 0;
}
}
void print_dfa(){
cout<<endl;
cout<<"NFA TO DFA CONVERSION";
cout<<"\nSTATE\t|\t"<<"a"<<"\t|\t"<<"b"<<"\t|\t"<<"FINAL"<<"\t|"<<endl;
for(int i=0;i<dfa.size();i++){
cout<<i<<"\t|\t"<<dfa[i].a[0]<<"\t|\t"<<dfa[i].a[1]<<"\t|\t"<<dfa[i].f<<"\t|"<<endl;
}
}
void epsilon_closure(int state,set<int>&si){
for(unsigned int i=0;i<nfa[state].e.size();i++){
if(si.count(nfa[state].e[i])==0){
si.insert(nfa[state].e[i]);
epsilon_closure(nfa[state].e[i],si);
}
}
}
set<int> state_change(int c,set<int>&si){
set<int> temp;
if(c==1){
for (std::set<int>::iterator it=si.begin(); it!=si.end(); ++it){
for(unsigned int j=0;j<nfa[*it].a[0].size();j++){
temp.insert(nfa[*it].a[0][j]);
}
}
}
else{
for (std::set<int>::iterator it=si.begin(); it!=si.end(); ++it){
for(unsigned int j=0;j<nfa[*it].a[1].size();j++){
temp.insert(nfa[*it].a[1][j]);
}
}
}
return temp;
}
void nfa_to_dfa(set<int>&si,queue<set<int> >&que,int start_state){
map<set<int>, int> mp;
mp[si]=-1;
set<int> temp1;
set<int> temp2;
int ct=0;
si.clear();
si.insert(0);
epsilon_closure(start_state,si);
if(mp.count(si)==0){
mp[si]=ct++;
que.push(si);
}
int p=0;
bool f1=false;
while(que.size()!=0){
dfa.push_back(init_dfa_state);
si.empty();
si=que.front();
f1=false;
for (set<int>::iterator it=si.begin(); it!=si.end(); ++it){
if(nfa[*it].f==true)
f1=true;
}
dfa[p].f=f1;
temp1=state_change(1,si);
si=temp1;
for (set<int>::iterator it=si.begin(); it!=si.end(); ++it){
epsilon_closure(*it,si);
}
if(mp.count(si)==0){
mp[si]=ct++;
que.push(si);
dfa[p].a[0]=ct-1;
}
else{
dfa[p].a[0]=mp.find(si)->second;
}
temp1.clear();
si=que.front();
temp2=state_change(2,si);
si=temp2;
for(set<int>::iterator it=si.begin(); it!=si.end(); ++it){
            epsilon_closure(*it,si);
        }
        if(mp.count(si)==0){
            mp[si]=ct++;
            que.push(si);
            dfa[p].a[1]=ct-1;
        }
        else{
            dfa[p].a[1]=mp.find(si)->second;
        }
        temp2.clear();
        que.pop();
        p++;
    }
    for(int i=0;i<p;i++){
        if(dfa[i].a[0]==-1)dfa[i].a[0]=p;
        if(dfa[i].a[1]==-1)dfa[i].a[1]=p;
    }
    dfa.push_back(init_dfa_state);
    dfa[p].a[0]=p;
    dfa[p].a[1]=p;
    //cout<<p<<endl;
}


void print_menu(){
    cout<<"\n---------------------------------------\n";
    cout<<"Input Regex: "<<dispregex<<endl<<endl;
    cout<<"1. NFA\n";
    cout<<"2. Intermediate DFA\n";
    cout<<"Press any other key to exit...\n\n";
}


int main()
{
    custom_clear();
    string regexp,postfix;
    cout<<"Enter Regular Expression: ";
    cin>>regexp;
    dispregex=regexp;
    regexp=insert_concat(regexp);
   // postfix = regexp_to_postfix(regexp);
    //cout<<"Postfix Expression: "<<postfix<<endl;
    //postfix_to_nfa(postfix);

    int final_state=st.top();st.pop();
    int start_state=st.top();st.pop();
    nfa[final_state].f=1;

    set<int> si;
    queue<set<int> > que;
    nfa_to_dfa(si,que,start_state);

    cout<<endl<<endl;



    getchar();
    custom_clear();


    while(1){
        print_menu();
        char choice;
        choice=getchar();
        custom_clear();

        switch(choice) {
        case '1':
            display_nfa();
            getchar();
            break;
        case '2':
            print_dfa();
            getchar();
            break;
        default:
            exit(EXIT_SUCCESS);
        }
    }
    cout<<endl<<endl;
    cout<<"Enter string : ";
    string input;
    cin.ignore();
    getline(cin,input);
    int curr_state,next_state;

    return 0;
}
