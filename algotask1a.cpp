#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ct1=1;
int ct2=1;
void encrypt(char a[100],int b)
{
	int x;
	for(int i=0;i<strlen(a);i++)
	{
		if(isalpha(a[i]))
		{
			x=a[i];
			x=x+b;
			if(isupper(a[i]))
			{
				if(x>90)
				{
					x-=26;
				}
			}
			else if(islower(a[i]))
			{
				if(x>122)
				{
					x-=26;
				}
			}
			a[i]=(char)x;
		}			
	}
	cout<<"ciphertext#"<<ct1<<":";puts(a);
	ct1++;
}

void decrypt(char c[100],int d)
{
	int z;
	for(int j=0;j<strlen(c);j++)
	{
		if(isalpha(c[j]))
		{
			z=c[j];
			z=z-d;
			if(isupper(c[j]))
			{
				if(z<65)
				{
					z+=26;
				}
			}
			else if(islower(c[j]))
			{
				if(z<97)
				{
					z+=26;
				}
			}
			c[j]=(char)z;
		}
		
	}
	cout<<"plaintext"<<ct2<<":";puts(c);
	ct2++;
}

int main()
{
	
	char m[100][100];
	int n,k;
	cout<<"enter number of strings and value of key";
	cin>>n>>k;
	k=k%26;
	cout<<"enter strings";
	for(int f=0;f<(2*n);f++)
	{
		cin>>(m[f]);
	}
	for(int y=0;y<n;y++)
	{
		encrypt(m[y],k);
	}
	for(int o=n;o<(2*n);o++)
	{
		decrypt(m[o],k);
	}
	return 0;
}
