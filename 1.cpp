#include<iostream>
using namespace std;
int readfile(FILE *fi,int *&a,int &n)
{
	fscanf(fi,"%d",&n);
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		fscanf(fi,"%d",&a[i]);
	}	
}
int minArr(FILE *fo,int *a,int n)
{
	
	int min=a[0];
	for(int i=1;i<n;i++)
	{
		if(min>a[i]) min=a[i];
	}
	fprintf(fo,"%d\n",min);
}
int maxArr(int *a,int n)
{
	
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<a[i]) max=a[i];
	}
	return max;
}
int slnn(FILE *fo,int *a,int n)
{
	int max=maxArr(a,n);
	for(int i=max+1; ;i++)
	{
		if(i%2==1) 
		{
			fprintf(fo,"%d",i);
			break;
		}
	}
}
int main()
{
	const char *fileinput="C:\\input.txt";
	const char *fileoutput="C:\\output.txt";
	FILE *fi,*fo;
	int n,*a;
	fi=fopen(fileinput,"rt");
	readfile(fi,a,n);
	fo=fopen(fileoutput,"wt");
	minArr(fo,a,n);
	slnn(fo,a,n);
	
	fclose(fi);
	fclose(fo);
		
}