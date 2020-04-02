#include<stdio.h>

struct process
{
      int arr_time,turn_time,status,serv_time, ct, wait_time,p_id,priority;
};

struct process p[10];

int n;

void calculate(int serv_time)
{
	int t = 0, large;
	float wt = 0, tt = 0, awt, att; 

	p[9].priority = -1;
	printf("\nProcess Id\tArrival Time\tService Time\tPriority\tWaiting Time");
	for(t = p[0].arr_time; t < serv_time;)
	{
		large=9;		
		for(int i = 0; i < n; i++)
		{
			if(p[i].arr_time <= t && p[i].status != 1 && p[i].priority > p[large].priority)
			{
				large = i;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			if(i==large)
			{
				p[i].priority+=1;
			}
			else
			{
				p[i].priority+=2;
			}
		}

		t = t + p[large].serv_time;
		p[large].ct = t;
		p[large].wait_time = p[large].ct - p[large].arr_time - p[large].serv_time;
		p[large].turn_time = p[large].ct - p[large].arr_time;
		p[large].status = 1;
		wt = wt + p[large].wait_time;
		tt = tt + p[large].turn_time;
		
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d",p[large].p_id,p[large].arr_time, p[large].serv_time, p[large].priority, p[large].wait_time);
	}


	awt = wt / n;
	att = tt / n;
	printf("\n\nAverage waiting time:\t%f\n", awt);
	printf("Average Turnaround Time:\t%f\n", att);

}

void process_select()
{
      struct process temp;
      for(int i = 0; i < n - 1; i++)
      {
            for(int j = i + 1; j < n; j++)
            {
                  if(p[j].arr_time < p[i].arr_time)
                  {
                        temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                  }
            }
      }
}

int main()
{

      printf("\nEnter Total Number of Processes To Be Created:\t\t");
      scanf("%d", &n);

      int st=0,m=1;

      for(int i = 0; i < n; i++)
      {
            printf("\nEnter the details for Process P%d:\n\n",i+1);
            
            printf("Enter Arrival Time:\t");
            scanf("%d", &p[i].arr_time );
            
	    printf("Enter Service Time:\t");
            scanf("%d", &p[i].serv_time);
       

	    printf("Enter Priority:\t");
            scanf("%d", &p[i].priority);

            p[i].p_id=m;
            m++;

	    p[i].status = 0;
            st = st + p[i].serv_time;
      }
      
      process_select();
      calculate(st);
      return 0;
}
