/*
NOTE: OUTPUT PATTERN IS NOT FULLY ACCORDING TO uva.onlinejudge.org 
*/


#include <stdio.h>

/*

pm: store elements used in m, helps i
qn: store elements used in n, helps j
temp: store k

*/

char a[50][50][50];
int m[50], n[50], p=0, q=0, km, kn;
int i=0, j=0, k=0, temp;


/*
VARIABLES USED
--------------
m,n,p,q,i,j,k
*/
void input(){

	printf("\n\n");
	scanf("%d%d", &m[p], &n[q]);

	while(m[p]!=0 && n[q]!=0){	
		for(i=0;i<m[p];i++){
			scanf("%s", a[k][i]);
		}
		k++;
		p++; q++;
		printf("\n");
		scanf("%d%d", &m[p], &n[q]);
	}
	temp=k; km=p-1; kn=q-1;
	p=0; q=0;
}


/*
VARIABLES USED
--------------
k,temp,m,n,p,q,i,j
*/
void mineReset(){
	
	p=0; q=0;
	for(k=0; k<temp; k++){
		for(i=0; i<m[p]; i++){
			for(j=0; j<n[q]; j++){
				if(a[k][i][j]=='.')
					a[k][i][j]='0';
			}
		}	 
		p++; q++;
	}
	p=0;q=0;
}


/*
VARIABLES USED
--------------
k,temp,m,n,p,q,i,j
*/
void mineFinder(){

	p=0; q=0;
	int x, y;

	for(k=0; k<temp; k++){
		for(i=0; i<m[p]; i++){
			for(j=0; j<n[q]; j++){
				if(a[k][i][j]!='*'){

					/* CHECKING 8 ELEMENTS AROUND PRESENT ELEMENT*/
					for (x= i-1; x < (i+2); ++x){
						for (y= j-1; y < (j+2) ; ++y){	/* CONSIDER SITUATIONS  WHEN x,y GOES OUT OF BOUNDS */
							if( a[k][x][y]=='*' ){			/* FOUND A MINE :) */ 
								if(a[k][i][j]=='0')				
									{a[k][i][j]='1';}
								else if(a[k][i][j]=='1')	
									{a[k][i][j]='2';}
								else if(a[k][i][j]=='2')	
									{a[k][i][j]='3';}
								else if(a[k][i][j]=='3')	
									{a[k][i][j]='4';}
								else if(a[k][i][j]=='4')	
									{a[k][i][j]='5';}
								else if(a[k][i][j]=='5')	
									{a[k][i][j]='6';}
								else if(a[k][i][j]=='6')	
									{a[k][i][j]='7';}
								else if(a[k][i][j]=='7')	
									{a[k][i][j]='8';}
							}
						}
					}	
				}
			}
		}	 
		p++; q++;
	}
	p=0;q=0;
}


/*
VARIABLES USED
--------------
p,k,temp,m
*/
void display(){

	p=0;
	for(k=0; k<temp; k++){
		printf("\nField #%d:\n", k+1);
		for(i=0; i<m[p]; i++){
			printf("%s",a[k][i]);
			printf("\n");
		}
		p++;
	}
	printf("\n");
}


int main(void){
	
	input();
	display();
	mineReset();
	display();
	mineFinder();
	display();
	return 0;
}



/*
SAMPLE OUTPUT

10 10
...*.*.*.*
*....*.*..    
..........
**........
*.....*...
*......*..
...*..*...
*.........
..........
.......*..

2 6
*.....
...*..

0 0

Field #1:
...*.*.*.*
*....*.*..
..........
**........
*.....*...
*......*..
...*..*...
*.........
..........
.......*..

Field #2:
*.....
...*..


Field #1:
000*0*0*0*
*0000*0*00
0000000000
**00000000
*00000*000
*000000*00
000*00*000
*000000000
0000000000
0000000*00

Field #2:
*00000
000*00


Field #1:
111*3*4*3*
*1113*4*31
3310112110
**10011100
*41001*210
*211123*10
221*11*210
*111111100
1100001110
0000001*10

Field #2:
*11110
111*10

*/
