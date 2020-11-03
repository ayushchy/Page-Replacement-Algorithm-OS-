#include <iostream>
using namespace std;
int main()
{
	int i, j, n, f, k,index;
	double miss = 0;
	double pg_flt;
	cout<<"\n Enter the number of pages : ";
	cin>>n;
	cout<<"\n Enter number of frames : ";
	cin>>f;
	int page[n],frame[f],flag;
	cout<<"\n Enter pages : ";
	for(i=0; i<n; i++)
	{
		cin>>page[i];
	}
	for(i=0; i<f; i++)
	{
		frame[i] = -1;
	
	}


	j=0;
	for(i=0; i<n; i++)
	{
		
	    flag = 0;
	    for(k=0; k<f; k++)
	    	if(frame[k]==page[i])
	    		flag = 1;
	    if (flag==0)
	    {
        	frame[j]=page[i];
            j=(j+1)%f;
            miss++;
            cout<<"\n Content of Frame : ";
	
		    for(k = 0; k < f; k++)
			{
		        cout<<"\t"<<frame[k];
		    }
	    } 
	}
    cout<<"\n";
	pg_flt = miss/n;
	cout<<"\n Page Fault is "<<pg_flt;
	return 0;
	}
