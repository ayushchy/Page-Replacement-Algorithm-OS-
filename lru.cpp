#include <iostream>
using namespace std;
int minimum(int a[],int m)
{
	int min=a[0],ind;
	for(int i=0;i<m;i++)
	{
		if(a[i]<min)
		{
		
		 min = a[i];
		 ind = i;
    	}
	}
	
	return ind;
}

int main()
{
	int i, j, n, f, k,index;
	double miss = 0;
	double pg_flt;
	cout<<"\n Enter the number of pages : ";
	cin>>n;
	
	cout<<"\n Enter number of frames : ";
	cin>>f;
	
	int page[n],frame[f],time[f],pos;
	int counter = 0;
	int flag1,flag2;
	
	cout<<"\n Enter pages : ";
	for(i=0; i<n; i++)
	{
		cin>>page[i];
	}
	for(i = 0; i < f; ++i)
	{
        frame[i] = -1;
    }
    
    for(i = 0; i < n; i++)
	{
        flag1 = flag2 = 0;
        
        for(j = 0; j < f; j++)
		{
            if(frame[j] == page[i])
			{
                counter++;
                time[j] = counter;
                   flag1 = flag2 = 1;
                   break;
            }
        }
        
        if(flag1 == 0)
		{
            for(j = 0; j < f; ++j)
			{
                if(frame[j] == -1)
				{
                    counter++;
                    miss++;
                    frame[j] = page[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
		{
            pos = minimum(time, f);
            counter++;
            miss++;
            frame[pos] = page[i];
            time[pos] = counter;
        }
        cout<<"\n Contents of Frames : ";
        for(j = 0; j < f; j++)
		{
            cout<<" "<<frame[j];
        }
        cout<<"\n";
   }
	pg_flt = miss/n;
	cout<<"\n Page Fault is = "<<pg_flt;
}
