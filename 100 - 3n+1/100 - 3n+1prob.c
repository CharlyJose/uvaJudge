
#include <stdio.h>


int calc(long low, long high){
	int countf=0, countp;
	long n,i;

	n= high;

	/* THE HEART OF THE PROGRAM */
	for(i= high; i>= low; i--){
		n=i;
		countp=1;

		while(n>1){
			if(n%2 == 0)		/*EVEN*/
				n= n/2;
			else			/*ODD*/
				n= 3*n+1;		
			countp++;
			
		}	
		if(countp> countf)
			countf=countp;	

	}
	
	return countf;
}


int main(void){
	FILE* input;
	long low,high;
	int i;
	input= fopen("input.txt", "r");
	printf("\n");

	while(fscanf(input,"%ld %ld", &low, &high)!=EOF){
		if(low>high){
			low= low+high;
			high= low-high;
			low= low-high;
		}
		printf("%ld %ld %d\n",low, high, calc(low, high));
	}
	fclose(input);
	printf("\n");
	
	return 0;
}

