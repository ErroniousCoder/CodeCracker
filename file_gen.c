#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define size 1000

void print_arr(long a[size],char fname[50])
{
	long i;
	
	
	FILE *fp=fopen(fname,"w");
	fprintf(fp,"%s","\n..........The Sorted Integers in file.........\n");
	for(i=0;i<size;i++)
	{
		//printf("%ld\n",arr[i]);
		fprintf(fp,"%ld\n",a[i]);
	}
		
		fclose(fp);
	
		
}
void bubble_sort(long int arr[size])
{
	long i,j;
	long tmp;
	long count=0;
	long swap=0;
	

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
				swap++;
			}

		}
		
	}
	
	print_arr(arr,"bubble.txt");
	printf("\nThe number of comparision : %ld number of swap:%ld",count,swap);
	fclose(fp);
	
}

void insertion_sort(long int arr[size])
{
	long i,j,key;
	long count=0;
	for(i=1;i<size;i++)
	{
		key=arr[i];
		j=i-1;

		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
			count++;
		
		}

		arr[j+1]=key;
		
	}
	print_arr(arr,"insersion.txt");
	printf("\nThe number of comparision : %ld",count);
	
	
}	


void selection_sort(long arr[size])
{
	long i,j,tmp,count=0;
	long swap=0;
	int minIdx;
	
	for(i=0;i<size-1;i++)
	{
		minIdx=i;
		
		for(j=i+1;j<size;j++)
		{
			count++;
			if(arr[j]<arr[minIdx])
			{
				minIdx=j;
			}
		}
		if(minIdx!=i)
		{
			tmp=arr[i];
			arr[i]=arr[minIdx];
			arr[minIdx]=tmp;
			
			swap++;
		}

	}
	
	print_arr(arr,"selection.txt");
	printf("\nThe number of comparision : %ld number of swap:%ld",count,swap);
	

}
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
		case 2: insertion_sort(num_array);
				break;
				
		case 3: selection_sort(num_array);
				break;
		
		case 5: exit(0);
		default : printf("\nInvalid choice\n");
	}
	return 0;
}

		
	
