#include<iostream>
#include<string>
using namespace std;


char ch;
char a[5]={'a','e','i','o','u'};

char& change(char &c)
{
	static int i=0;
	c=a[i++];
	return ch;
}

int main()
{
	
	ch=change(ch);
	int count=0;
	string s;
	cout<<"Enter a string"<<endl;
	cin>>s;
	
	int len=s.length();
	
	for(int i=0;i<len;i++)
	{
		if(ch==s[i])
		{
			count++;
			ch=change(ch);
		}
	}
	
	int k=0,l=0; 
	string s2;
	if(count==5)
	{
		for(int i=0;i<len;i++)
		{
			if(s[i]==a[k])
			{
				
				s2+=s[i];
			}
			
			else if(s[i]==a[k+1])
			{
				s2+=s[i];
				k++;
			}
		}
		
		cout<<"length of substring is "<<s2.length()<<endl;
	}
	
	else 
	{
		cout<<"length of substring is 0 "<<endl;
	}
	
	
	
	return 0;
	
}
