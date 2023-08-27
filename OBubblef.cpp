#include<stdio.h>
#include<stdbool.h>
void sort(int arr[])
{
	bool x=true;
	int ch;
	printf("Which way you want to sort:-\n1-Ascending\n2-Descending\n");
	scanf("%d",&ch);
	if(ch!=1&&ch!=2)
	{
		printf("Wrong Chice");
		return;
	}
	int n;
	for(n=0;arr[n]!='\0';n++);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			bool k;
			if(ch==1)
			{
				k=arr[j]>arr[j+1];
			}
			else if(ch==2)
			{
				k=arr[j]<arr[j+1];
			}
			if(k)
			{
				x=false;
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
		if(x)
		{
			return;
		}
	}
}
int main()
{
	int n;
	printf("Enter the length of array.");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the element.");
		scanf("%d",&arr[i]);
	}
	sort(arr);
	printf("Sorted Array-->");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
}
