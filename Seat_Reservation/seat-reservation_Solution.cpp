
#include<iostream>
#include<string>
using namespace std;

void printsa(char sa[7][5])
{
		int i,j;
		for(i=0;i<7;i++)
	{
		for(j=0;j<5;j++)
		cout<<sa[i][j]<<" ";
		
		cout<<endl;
	}	
}


int check_valid(string a)
{
	int i;
	
	if(a.length()==1 && a=="N" || a=="n")
	return 0;
	
	else if(a.length()!=2 || a[0]<'1' || a[0]>'7' || a[1]<'A' || a[1]>'D')
	{
		
		return 1;
	}
	
	else return 2;	
}

void check_available(string a,char sa[7][5])
{
	int j=a[1];
	j=j-64;
	
	int i=a[0];
	i=i-49;
	
	if (sa[i][j]=='X')
	{
		cout<<"Seat already occupied"<<endl;
		return;	
	}
	
	else
	{
		sa[i][j]='X';
		cout<<"Congrats Seat Reserved for you"<<endl;
		cout<<"Updated Seat status"<<endl;
		printsa(sa);
	}
		
}




int main()
{
	char sa[7][5];
	int i,j;
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j==0)
			sa[i][j]=(49+i);
			
			else
			sa[i][j]=(64+j);
		}
	}
	
	cout<<"Initial Seat arrangements"<<endl;
	printsa(sa);
	
	string a;
	int choice;
	do
	{
		cout<<"Enter a vlaid seat number to check(like 1B) or N to end"<<endl;
		cin>>a;
		
		choice=check_valid(a);
				
		switch(choice)
		{	
			case 1:
				cout<<"Not a valid seat number"<<endl;
				break;
				
			case 2:
				check_available(a,sa);
				break;
				
			default:
				break;
		}
		
	}while(choice);
		
return 0;

}
