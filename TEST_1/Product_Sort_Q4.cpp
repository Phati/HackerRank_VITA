#include <iostream>
#include <vector>
using namespace std;


vector<int> sort_items(vector<int> items)
{
	int n=items.size(); //find the size of the items 
	
    int n2=n;// assign it to another variable as the value of n wil change in unique arrray loop

    vector <int> a(n); // this array will b used to find unique array
    
    vector <int> send(n);// this will be the final array to be returned


//copy all values from items to array a
    for(int x=0;x<n;x++)
    {
        a[x]=items[x];
    }
   
   //loop control variables
    int i,j,r;
   
   // this is the unique array algorithm 
   //a new unique array is derived from array a
   //and the size of array a will decrease hence n will also reduce
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                for(r=j;r<n-1;r++)
                a[r]=a[r+1];
                j--;
                n--;
            }
        }
    }


   // temporary counter is used 
    int tc;
    
    //create another array of same size as the number of  unique  elements that will store the occurances of these elements in the items array
    
    vector<int> index(n);
    // count the occurance of the unique elements and store it in tbe index array
    for(i=0;i<n;i++)
    {
        tc=0;
        for(j=0;j<n2;j++)
        {
            if(a[i]==items[j])
            tc++;
        }

        index[i]=tc;
    }

// sort the elemets of the unique array according to the no. of occurances in the items array
    int temp;
    
//bubble sort both unique array and the index array comparing the indexes
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(index[j]>index[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

                temp=index[j];
                index[j]=index[j+1];
                index[j+1]=temp;  
            }
           
        }
    }
    
    //at this stage we will have elements grouped by indexes sorted by indexes
    //but wont be sorted within the group
    
    // so lets do it
    
    // the last value in the index array will tell max how many times a value has repeated in the items array
    //suppose it is 3 that means the values in the index table are 1,2,3
    //i.e there are values occuring Twice and once as well
    int var=index[n-1];
    
    //so now we will have to find the count of the each value in the index array 
    // that will tell us how many values in items array have occured once, how many twice etc
    
    // suppose  3 values have occured once than those will be grouped together by now 
    // and our intention is to sort them in their group
    
  //  create an array called id to store count of indexes
  
  int id[var];
  
  for(i=0;i<var;i++)
  id[i]=i+1;
  
  int count_index[var];
  
  
     for(i=0;i<var;i++)
    {
        tc=0;
        for(j=0;j<n;j++)
        {
            if(id[i]==index[j])
            tc++;
        }

        count_index[i]=tc;
    }
    
    
    int z;
    int y=0;
    for(i=0;i<var-1;i++)
    {
    	
    	//bubble sort
    	for(z=0;z<count_index[i]-1;z++)
    	{
    		for(j=0;j<count_index[i]-z-1;j++)
    		{
    			 if(a[y+j]>a[j+y+1])
            {
                temp=a[y+j];
                a[y+j]=a[y+j+1];
                a[y+j+1]=temp;
                
            }

    		}
    		
    	}
    	y=y+z+1;
    }






    y=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<index[i];j++)
        {
            send[y++]=a[i];
        }
    }


return send;

}


int main()
{
	int ar_count,i;
	cout<<"Please enter the size of the array"<<endl;
	cin>>ar_count;
	vector<int> items;  // int items[ar_count]
	//vector<vector<int>> items;					// int items[][];
	cout<<"Please enter the elements of the array"<<endl;
	
	int val;
	
	for(i=0;i<ar_count;i++)
	{
		cin>>val;
        items.push_back(val);
	}
	
	vector<int> result=sort_items(items);
	
	
	for(i=0;i<ar_count;i++)
	{
		cout<<items[i]<<"  ";
	}
	
	
	cout<<endl;
	
	
	for(i=0;i<ar_count;i++)
	{
		cout<<result[i]<<"  ";
	}
	
	
	return 0;
}
