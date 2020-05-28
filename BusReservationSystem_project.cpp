#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
#include<string.h>
using namespace std;

static int p=0;

class a{
	private:
		char busno[10],drivern[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	
	public:
		void enterdetails();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];

void a::enterdetails()
{
	cout<<"Enter the bus no. :";
	cin>>bus[p].busno;
	
	cout<<"\nEnter drivers name :";
	cin>>bus[p].drivern;
	
	cout<<"\nArrival time :";
	cin>>bus[p].arrival;
	
	cout<<"\nDeparture time :";
	cin>>bus[p].depart;
	
	cout<<"\nFrom :";
	cin>>bus[p].from;
	
	cout<<"\nTo :";
	cin>>bus[p].to;
	
	bus[p].empty();
	p++;
}
void a::allotment()
{
	int seat;
	char number[5];
	top:
	cout<<"\nEnter bus no. :";
	cin>>number;
	
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busno,number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"\nSeat number :";
		cin>>seat;
		
	if(seat>32)
		cout<<"\nThere are only 32 seats in the bus!!!";
		
	else{
		  if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
		  {
		  	cout<<"\nEnter passenger name :";
		  	cin>>bus[n].seat[seat/4][(seat%4)-1];
		  	break;
		  }
		  
		else
		cout<<"\nThe seat is alrady taken :\n";  
		  
		}
	}
	if(n>p)
	{
		cout<<"Enter the correct bus no. \n";
		goto top;
		
	}
}

void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}

void a::show()
{
	int n;
	char number[5];
	
	cout<<"\nEnter the bus no. :";
	cin>>number;
	
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busno,number)==0)
		break;
	}
	
	while(n<=p)
	{
		
		cout<<"Bus no. :\t"<<bus[n].busno<<"\nDriver name :\t"<<bus[n].drivern
		   <<"\nArrival time :\t"<<bus[n].arrival<<"\nDeparture time :\t"<<bus[n].depart
		   <<"\nFrom :\t\t"<<bus[n].from<<"\nTo :\t\t"<<bus[n].to<<"\n";
		   
		
	bus[0].position(n);
	int a=1;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			a++;
		  if(strcmp(bus[n].seat[i][j],"Empty")!=0)
		  
		  cout<<"\nThe seat no. "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";	
		}
		   }
		   break;	   
	}
	if(n>p)
	cout<<"\nEnter the bus no. correctly ";
}
void a::position(int l)
{
	int p=0,s=0;
	
	for(int i=0;i<8;i++)
	{
		cout<<endl;
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				
				cout.fill(' ');
				cout<<s<<" .";
				
				cout.width(10);
				cout.fill(' ');
				
				cout<<bus[l].seat[i][j];
				p++;
			}
			else{
				cout.width(5);
				
				cout.fill(' ');
				cout<<s<<" .";
				
				cout.width(10);
				cout.fill(' ');
				
				cout<<bus[l].seat[i][j];
			
			}
		}
	}
	cout<<"\nThere are "<<p<<" seats empty in bus no. :"<<bus[l].busno;
}
void a::avail()
{
	for(int n=0;n<p;n++)
	{
	
		
			cout<<"Bus no. :\t"<<bus[n].busno<<"\nDriver name :\t"<<bus[n].drivern
		   <<"\nArrival time :\t"<<bus[n].arrival<<"\nDeparture time :\t"<<bus[n].depart
		   <<"\nFrom :\t\t"<<bus[n].from<<"\nTo :\t\t"<<bus[n].to<<"\n";
		
		}
}

int main()
{
	system("cls");
	int w;
	while(1)
	{
		
		cout<<"\n\n\n\n";
		cout<<"\t\t\t1.Install\n\t\t\t"
		<<"2.Reservation\n\t\t\t"
		<<"3.Show\n\t\t\t"
		<<"4.Buses Available \n\t\t\t"
		<<"5.Exit";
		
		cout<<"\n\t\t\tEnter your choice :";
		cin>>w;
		
	switch(w)
	{
		case 1:
			bus[p].enterdetails();
			break;
			
		case 2:
		    bus[p].allotment();
			break;
			
		case 3:
		    bus[0].show();
			break;
			
		case 4:
		    bus[0].avail();
			break;
			
		case 5:
		    exit(0);				
		}	
	}
	return 0;
	
}

