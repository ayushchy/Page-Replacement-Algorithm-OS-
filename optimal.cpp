#include<iostream>
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
	int page[n],frame[f],flag1,flag2,flag3,temp[f],pos,max;
	cout<<"\n Enter pages : ";
	for(i=0; i<n; i++)
	{
		cin>>page[i];
	}


	for(i=0; i<f; i++)
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
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0)
		{
            for(j = 0; j < f; j++)
			{
                if(frame[j] == -1)
				{
                    miss++;
                    frame[j] = page[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
		{
            flag3 =0;
            
            for(j = 0; j < f; j++)
			{
                temp[j] = -1;
                
                for(k = i + 1; k < n; k++)
				{
                    if(frame[j] == page[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            
            for(j = 0; j < f; j++)
			{
                if(temp[j] == -1)
				{
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            
            if(flag3 ==0){
                max = temp[0];
                pos = 0;
                 for(j = 1; j < f; j++)
				{
                    if(temp[j] > max)
					{
                        max = temp[j];
                        pos = j;
                    }
                }                
            }   
            frame[pos] = page[i];
            miss++;
        }
        cout<<"\nContents of frame : ";
        for(j = 0; j < f; j++)
		{
			
            cout<<" "<<frame[j];
        }
        
        cout<<"\n";
    }    
    pg_flt = miss/n;
    cout<<"\nPage fault is :"<<pg_flt;
}
