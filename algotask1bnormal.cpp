#include<iostream>
#include<cstdio>
#include<cctype>
#include<sstream>

using namespace std;

void bubbleSort(int arr[100], int n)
{
   int i, j,temp;
   for (i = 0; i < n-1; i++)      
   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
           {
           	temp=arr[j];
           	arr[j]=arr[j+1];
           	arr[j+1]=temp;
		   }
}

int main()
{
	int init,x,flag,b[100],c[100],i=0,j=0,k=0,sum1=0,m=0,ct=0,input=0,sum2=0,sum3=0;
	int a[100]={0};
	string line;
	cout<<"enter initial floor number";
	cin>>init;
	cout<<"enter floor sequence";
	while(i<100)
	{
		cin>>input;
		a[i++]=input;
		if(cin.get()=='\n')
		break;
		
	}
	
	/*while(!((a[m]==0)&&(a[m+1]==0)))
	{
		cout<<a[m++]<<" ";
	}*/
	for(int x=0;x<i;x++)
	{
		if(a[x]>init)
		{
			b[j++]=a[x];
		}	
		else
		{
			c[k++]=a[x];
		}
	}
	bubbleSort(b,j);
	bubbleSort(c,k);
	cout<<"possibility 1:"<<init<<" ";
	for(int x=0;x<j;x++)
	{
		if(x>0)
		{
			sum1+=b[x]-b[x-1];
		}
		cout<<b[x]<<" ";
	}
	for(int x=0;x<k;x++)
	{
		if(x>0)
		{
			sum1+=c[x]-c[x-1];
		}
		cout<<c[k-x-1]<<" ";
	}
	sum2+=sum1;
	sum2+=b[j-1]-c[k-1];
	sum2+=b[0]-init;
	cout<<"\n"<<"Total Distance:"<<sum2<<"\n";


	cout<<"possibility 2:"<<init<<" ";
	for(int x=0;x<k;x++)
	{
		cout<<c[k-x-1]<<" ";
	}
	for(int x=0;x<j;x++)
	{
		cout<<b[x]<<" ";
	}
	sum3+=sum1;
	sum3+=b[0]-c[0];
	sum3+=init-c[k-1];
	cout<<"\n"<<"Total Distance:"<<sum3;


	return 0;
	
}
