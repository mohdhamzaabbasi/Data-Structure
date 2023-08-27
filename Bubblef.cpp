#include<stdio.h>
void sort(int arr[])
{
	int n;
	for(n=0;arr[n]!='\0';n++);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
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
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
}
