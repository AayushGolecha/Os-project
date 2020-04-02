#include<stdio.h>
struct process
{
	int ProcessID,BurstTime,ArrivalTime,Priority,WaitTime;
};
int TotalTime,Burst_Time=0;
int Total=-1,i=-1; 
struct process Queue[100],Result[100],Swap;
int process_create()
{
	int n;
	printf("Enter the Number of Processes:");
	scanf("%d",&n);
	return n;
}
void Execute()
{
	if(Total>=0)
	{
		int Wait,j;
		if(Burst_Time!=0 && Queue[0].BurstTime!=0)
		{
			Queue[0].BurstTime--;
			Burst_Time--;
			Queue[0].Priority++;
			Queue[0].ArrivalTime=TotalTime+1;
			TotalTime++;	
			for(Wait=1;Wait<=Total;Wait++)
			{
				Queue[Wait].Priority+=2;
				Queue[Wait].WaitTime=++Queue[Wait].WaitTime;
			}
		}
		if(Queue[0].BurstTime==0)
		{
			i++;
			Result[i]=Queue[0];
			for(Wait=0;Wait<Total;Wait++)
			{
				Queue[Wait]=Queue[Wait+1];
			}
			Total--;
		}
		for(Wait=0;Wait<Total;Wait++)
		{
			for(j=0;j<Total;j++)
			{
				if(Queue[Wait].Priority<=Queue[j].Priority)
				{
					Swap=Queue[Wait];
					Queue[Wait]=Queue[j];
					Queue[j]=Swap;
				}
			}
		}
		if(Queue[0].Priority<=Queue[1].Priority && Total>=1)
		{
			Swap=Queue[0];
			for(Wait=0;Wait<Total;Wait++)
			{
				Queue[Wait]=Queue[Wait+1];
			}
			Queue[Total]=Swap;
		}
	}
}
int main()
{
	int l,j,n=process_create(),Count=0;
	struct process pcreate[n];
	for(l=0;l<n;l++)
	{
		pcreate[l].ProcessID=l+1;
		printf("\nEnter the arrival time of process[%d]: ",l+1);
		scanf("%d",&pcreate[l].ArrivalTime);
		printf("\nEnter the burst time of process[%d]: ",l+1);
		scanf("%d",&pcreate[l].BurstTime);
		pcreate[l].Priority=0;
		pcreate[l].WaitTime=0;
		Burst_Time=Burst_Time+pcreate[l].BurstTime;
	}
	for(l=0;l<n;l++)
	{
		for(j=0;j<n;j++)
		{
		if(pcreate[l].ArrivalTime<pcreate[j].ArrivalTime)
		{
			Swap=pcreate[l];
			pcreate[l]=pcreate[j];
			pcreate[j]=Swap;
		}
		if(pcreate[l].ArrivalTime==pcreate[j].ArrivalTime)
		{
			if(pcreate[l].BurstTime<=pcreate[j].BurstTime)
			{
			Swap=pcreate[l];
			pcreate[l]=pcreate[j];
			pcreate[j]=Swap;
			}
	 	}
	    }
}
printf("Values Entered:\n");
	printf("----------------------Process Table------------------------- \n");
	printf(" ProcessID             Arrival Time               ServiceTime\n");
	for(l=0;l<n;l++)
	{
	printf("    %d            	       %d                         %d\n",pcreate[l].ProcessID,pcreate[l].ArrivalTime,pcreate[l].BurstTime );
	}
	TotalTime=pcreate[0].ArrivalTime;
	for(j=pcreate[0].ArrivalTime;j<=pcreate[n-1].ArrivalTime;j++)
	{
		for(l=0;l<n;l++)
		{
			if(pcreate[l].ArrivalTime==j && Count!=n)
			{
				Total++;
				Queue[Total]=pcreate[l];
				Count++;
			}
			if(Count==n)
				break;
		}
		Execute();
		TotalTime++;
	    while(Burst_Time!=0 && Count==n)
	{
		Execute();
		TotalTime++;
	}
	if(Count==n)
		break;
	}
	printf("PROCESS IN ORDER OF THEIR COMPLETION:\n\n");
	printf("-----------------------------------FINAL TABLE------------------------------------- \n");
	printf("    PROCESS ID          ARRIVAL TIME             SERVICE TIME          WAITING TIME\n");
	for(l=0;l<n;l++)
	{
		for(j=0;j<n;j++)
		{
			if(Result[l].ProcessID==pcreate[j].ProcessID)
			{
	    printf("  	%d                  %d                        %d                     %d\n",Result[l].ProcessID,pcreate[j].ArrivalTime,pcreate[j].BurstTime,Result[l].WaitTime);
			    break;
			}
		}
	}
}	

