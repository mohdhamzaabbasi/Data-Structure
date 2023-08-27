#include<stdio.h>
int search(int arr[],int c)
{
	int n;
	for(n=0;arr[n]!='\0';n++);
	int begin=0;
	int end=n;
	int f=0;
	while(begin<=end)
	{
		int mid=(begin+end)/2;
		if(arr[mid]>c)
		{
			end=mid-1;
		}
		else if(arr[mid]<c)
		{
			begin=mid+1;
		}
		else
		{
			f++;
			break;
		}
	}
	return f;
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
	int c;
	printf("Enter the searching element.");
	scanf("%d",&c);
	int f=search(arr,c);
	if(f==1)
	{
		printf("Element found.");
	}
	else
	{
		printf("Element not found.");
	}
}
