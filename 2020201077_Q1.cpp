#include<bits/stdc++.h>
using namespace std;


        int priority(char c)
{
if(c=='+' || c=='-')
 return 1;
else if(c == '*' || c=='/' || c=='%')
return 2;
return 0;
}
int main()
{
string str;
cout<<"Enter the expression"<<endl;
cin>>str;

int top1 = -1;
int top= -1;

string arr[100000] = {"\0"};
char brr[1000] = "";


for(int i = 0;i<str.length();i++){
	if((str[i]>='0'&& str[i]<='9') || str[i] == '.'){
		string res="";
		while((str[i]>='0' && str[i]<='9')||str[i] == '.'){
			res+=str[i];
			i++;
		}
		i--;
		arr[++top] = res;
	}
	else if(top1==-1 || str[i] == '(')
		brr[++top1] = str[i];

	else if(str[i] == ')'){
		while(brr[top1]!='('){
			string res = "";
			res+=brr[top1];
			arr[++top]=res;
			brr[top1]='\0';
			top1--;
		}
		top1--;
	}
	else if(priority(str[i])>priority(brr[top1])){
		string res="";
		res+=str[i];
		brr[++top1] = str[i];
	}
	else if(priority (str[i])<=priority(brr[top1])){
		while(top1>-1 && priority(brr[top1])>=priority(str[i])){
			string res = "";
			res+=brr[top1];
			brr[top1] = '\0';
			arr[++top] = res;
			top1--;
		}
		brr[++top1] = str[i];
	}
}
while(top1>-1){
	string res="";
	res = brr[top1];
	brr[top1] = '\0';
	arr[++top] = res;
	top1--;}

double crr[10000] = {0};
int i = 0;int j = -1;
while(arr[i] != "\0")
{
if(arr[i] != "*" && arr[i] != "%" && arr[i] != "-" && arr[i] != "+" && arr[i] != "/")
{
crr[++j] = stod(arr[i]);
i++;
}
else if(arr[i] == "*")
{
double d = crr[j];
crr[j] = 0;
j--;
double c = crr[j];
crr[j] = d*c; 
i++;
}
else if (arr[i] == "/")
{
double d = crr[j];
crr[j] = 0;
j--;
double c = crr[j];
if(d==0)
{
cout<<"Wrong Expression"<<endl;
return 0;}
crr[j] = (double)c/d;
i++;
}
else if(arr[i] == "-")
{
double d = crr[j];
crr[j] = 0;
j--;
double c = crr[j];
crr[j] = c-d;
i++;
}
else if(arr[i] == "+")
{
double d = crr[j];
crr[j] = 0;
j--;
double c = crr[j];
crr[j] = c+d;
i++;
}
else if(arr[i] == "%")
{
double d = crr[j];
crr[j] = 0;
j--;
double c = crr[j];
if(d==0)
{
cout<<"Wrong Expression:"<<endl;
return 0;}
crr[j] = (double)((long long int)c%(long long int)d);
i++;
}
}


cout<<setprecision(5)<<fixed<<crr[j]<<endl;
return 0;
}
