#include<stdio.h>
#include<conio.h>
void merge(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,temp[6],index=beg,k;
	while((i<=mid)&&(j<=end))
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
		}
		else
		{
			temp[index]=a[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=a[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
	{
		a[k]=temp[k];
	}
}
void merge_sort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(a,beg,mid);
		merge_sort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}
int main()
{
	int arr[6]={77,43,22,19,88,10},i;
	merge_sort(arr,0,5);
	for(i=0;i<6;i++)
	{
		printf("%d ",arr[i]);
	}
	getche();
}
