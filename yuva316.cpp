#include<stdio.h> //header file
#include<conio.h> //header file

void yy(int num,int Remt[10],int Cur_t,int aRT[10], int bST[10]);

main() 
{
	int Proc_num,j,num,CurT,RemProc,indicator,time_quan,wait,tut,aRT[10],bST[10],Remt[10],x=1;
	indicator = 0;
	wait = 0;
	tut = 0;
	printf("enter the no of processes "); 
	scanf("%d",&num);
	RemProc = num;
	
	printf("\nEnter the Arrival time and the Burst time of the Processes\n");
	for(Proc_num = 0;Proc_num < num;Proc_num++) 
	{
		printf("\nProcess P%d\n",Proc_num+1);
		printf("Arrival time = "); 
		scanf("%d",&aRT[Proc_num]);
		printf("Burst time = "); 
		scanf("%d",&bST[Proc_num]); 
		Remt[Proc_num]=bST[Proc_num]; 
	} 
	printf("The details of time quantum are as follows-\n");
	printf("The time quantum for 1st round is 3.\n"); 
	time_quan=3;
	CurT=0;
	for(Proc_num=0;RemProc!=0;) 
	{
		if(Remt[Proc_num]<=time_quan && Remt[Proc_num]>0)
		{ 
			CurT+=Remt[Proc_num]; 
			Remt[Proc_num]=0; 
			indicator=1; 
		} 
		else if(Remt[Proc_num]>0)
		{ 
			Remt[Proc_num]-=time_quan; 
			CurT+=time_quan; 
		} 
		if(Remt[Proc_num]==0 && indicator==1)			
		{ printf("%d",Proc_num);
			RemProc--;				
			printf("P %d",Proc_num+1); 
			printf("\t\t\t%d",CurT-aRT[Proc_num]);
			printf("\t\t\t%d\n",CurT-bST[Proc_num]-aRT[Proc_num]);
			wait+=CurT-aRT[Proc_num]-bST[Proc_num]; 
			tut+=CurT-aRT[Proc_num]; 
			indicator=0; 
                       
		} 
		if(Proc_num==num-1){
			x++;
			if(x==2){
				Proc_num=0;
				time_quan=6;
				
				printf("The time quantum for second round is 6. \n");
			}
			else{
				break;
			}
		}
		else if(CurT >= aRT[Proc_num+1]){
			Proc_num++;
		}
		else{
			Proc_num=0;
		}
	}
	
	yy(num,Remt,CurT,aRT,bST);
	
	return 0;
}


void yy(int num,int Remt[10],int Cur_t,int aRT[10], int bST[10]){
	
	float avg_wait,avg_tut;
    int i,j,n=num,temp,btime[20],Proc_num[20],w_time[20],tut_t[20],total=0,loc;
    
    printf("Third round with least burst time.\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=Remt[i];
        w_time[i]=Cur_t-aRT[i]-btime[i];
		Proc_num[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=Proc_num[i];
        Proc_num[i]=Proc_num[loc];
        Proc_num[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	w_time[i]+=btime[j];
        }
        total+=w_time[i];
    }
 
    avg_wait=(float)total/n;
    total=0;
    printf("\nProcess\t \tBurst Time\t \twaiting Time\t \tTurn around Time");
    for(i=0;i<n;i++)
    {
        tut_t[i]=btime[i]+w_time[i];
        total=total + tut_t[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",Proc_num[i],btime[i],w_time[i],tut_t[i]);
    }
    avg_tut=(float)total/n;
    printf("\n\nAverage waiting time = %f",avg_wait);
    printf("\n Average turnaround time = %f\n",avg_tut);
	
}

