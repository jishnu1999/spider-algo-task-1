#include<iostream>
#include<cstdio>

using namespace std;


class request
{
	
	int no;
	int pplin;
	int pplout;
	public:
	void accept()
	{
		cin>>no;
		cin>>pplin;
		cin>>pplout;
	}
	
	void display()
	{
		cout<<no<<" "<<pplin<<" "<<pplout<<"\n";
	}
	int getno()
	{
		return no;
	}
	int getcap()
	{
		int p=pplin-pplout;
		return p;
	}
};

void bubbleSort(request arr[100], int n)
{
   int i, j;
   request temp;
   for (i = 0; i < n-1; i++)      
   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j].getno() > arr[j+1].getno())
           {
           	temp=arr[j];
           	arr[j]=arr[j+1];
           	arr[j+1]=temp;
		   }
}



int main()
{
	int i=0,j=0,k=0,cap=0,curcap=0,sum1=0,sum2=0,newcap=0,flag=0,d=0,e=0;
	request a[100],b[100],c[100],input,init;
	cout<<"enter lift capacity";
	cin>>cap;
	cout<<"enter initial floor data";
	init.accept();
	cout<<"enter floor request data";
	while(i<100)
	{
		a[i++].accept();
		if(cin.get()=='\n')
		break;	
	}
	for(int x=0;x<i;x++)
	{
		if(a[x].getno()>init.getno())
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
	curcap=init.getcap();
	d=j;
	e=k;
	cout<<"possibility 1:" <<init.getno()<<" ";
	for(int x=0;x<j;x++)
	{
		newcap=curcap + b[x].getcap();
		if(newcap<=cap)
		{
			curcap=newcap;
			cout<<b[x].getno()<<" ";
			if(x>0)
			{
				sum1+=b[x].getno()-b[x-1].getno();
			}
			else
			{
				sum1+=b[x].getno()-init.getno();
			}
		}
		else
		{
			c[k]=b[x];
			k++;
			for(int q=x;q<j-1;q++)
			{
				b[q]=b[q+1];
			}
			j--;
			x--;
		}
		
	}
	for(int x=0;x<k;x++)
	{
		newcap=curcap + c[k-x-1].getcap();
		if(newcap<cap)
		{
			curcap=newcap;
			cout<<c[k-x-1].getno()<<" ";
			if(x<k-1)
			{
				sum1+=c[k-x-1].getno()-c[k-x-2].getno();
			}
			else
			{
				sum1+=b[j-1].getno()-c[k-1].getno();
			}
		}
		else
		{
			for(int q=j;q>0;q--)
			{
				b[q]=b[q-1];
			}
			j++;
			b[0]=c[k-x-1];
			for(int q=k-x-1;q<k;q++)
			{
				c[q]=c[q+1];
			}
			k--;
			x--;
		}
	}
	cout<<"\n"<<"total distance: "<<sum1<<"\n";
	cout<<"possibility 2:"<<init.getno()<<" ";
	newcap=0;
	curcap=init.getcap();
	flag=1;
	j=d;
	k=e;
	for(int x=0;x<k;x++)
	{
		newcap=curcap + c[k-x-1].getcap();
		if(newcap<cap)
		{
			curcap+=newcap;
			cout<<c[k-x-1].getno()<<" ";
			if(flag==1)
			{
				sum2+=init.getno()-c[k-x-1].getno();
				flag=0;
			}
			else
			{
				sum2+=c[k-x-1].getno()-c[k-x-2].getno();
			}
			
		}
		else
		{
			for(int q=j;q>=0;q--)
			{
				b[q+1]=b[q];
			}
			j++;
			b[0]=c[x];
			for(int q=x;q<k;q++)
			{
				c[q]=c[q+1];
			}
			k--;
			x--;
		}
	}
	flag=1;
	for(int x=0;x<j;x++)
	{
		newcap=curcap + b[x].getcap();
		if(newcap<cap)
		{
			curcap+=newcap;
			cout<<b[x].getno()<<" ";
			if(flag==1) 
			{
				sum2+=b[x].getno()-c[0].getno();
				flag=0;
			}
			else
			{
				sum2+=b[x].getno()-b[x-1].getno();
			}
			
		}
		else
		{
			c[k++]=b[x];
			for(int q=x;q<j;q++)
			{
				b[x]=b[x+1];
			}
			j--;
			x--;
		}
		
	}
	cout<<"\n"<<"total distance: "<<sum2;
	return 0;
}

