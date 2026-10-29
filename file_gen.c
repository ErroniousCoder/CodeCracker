#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define size 5000

void bubble_sort(long int arr[size])
{
	long i,j;
	long tmp;
	long count=0;

	FILE *fp=fopen("bubble.txt","w");
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
						count++;
			if(arr[j]>arr[j+1])
			{
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}

		}
		
	}

	for(i=0;i<size;i++)
	{
		//printf("%ld\n",arr[i]);
		fprintf(fp,"%ld\n",arr[i]);
	}
		printf("\nThe number of comparision : %ld",count);
		fclose(fp);
	
}

void insertion_sort(long int arr[size])
{
	long i,j,key;

	for(i=1;i<size;i++)
	{
		key=arr[i];
		j=i-1;

		while(j>=0 && arr[j]	



int main()
{
	int ch;
	long int num;
	long int i;
	long int *num_array;
	FILE *fp=fopen("num.txt","w");
	
	num_array=(long int*)malloc(size*sizeof(long int));
	if(fp==NULL)
	{
		printf("\nFile creation failed\n");
		return 0;
	}
	srand(time(NULL));

	for(i=1;i<=size;i++)
	{
		num=rand()%size;
		fprintf(fp,"%ld\n",num);
	}

	fclose(fp);

	//reading the file
	fp=fopen("num.txt","r");
	
	num=0;
	printf("\n..........The Integers in file.........\n");
	for(i=0;i<size;i++)
	{
		fscanf(fp,"%ld",&num);
		//printf("%ld\t",num);
		num_array[i]=num;
	}
	fclose(fp);

	/*
	for(i=0;i<size;i++)
	{
		printf("%ld\t",num_array[i]);
	}
	*/

	printf("\nEnter 1 : Bubble Sort\t2 : Insertion Sort\t3 : Selection Sort\t5 : Exit\n");
	scanf("%d",&ch);

	switch(ch)
	{
	
		case 1: bubble_sort(num_array);
				break;

		
		case 5: exit(0);
		default : printf("\nInvalid choice\n");
	}
	return 0;
}

		
	
