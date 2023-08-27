#include<stdio.h>
int search(int arr[],int c,int l,int h)
{
	int mid=(l+h)/2;
	if(l<=h)
	{
		if(arr[mid]==c)
		{
			return mid;
		}
		else if(arr[mid]>c)
		{
			return search(arr,c,l,mid-1);
		}
		else if(arr[mid]<c)
		{
			return search(arr,c,mid+1,h);
		}
	}
	return -1;
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
	int f=search(arr,c,0,n-1);
	if(f==-1)
	{
		printf("Element not found.");
	}
	else
	{
		printf("Element found at position-->%d",(f+1));
	}
}
