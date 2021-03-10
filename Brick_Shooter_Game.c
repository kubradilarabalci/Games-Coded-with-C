#include <stdio.h>
#include <stdlib.h>
int width, height;
char **brick;
void display(char **arr);
int main()
{
	int j, i, k, boom=0, sum=0, total=0;
	scanf("%d%d",&width,&height);
	char kdb, colour;
	double a, b, x, y, datx, daty;
	int ch;
	ch=getchar();
	
	brick=(char**)malloc(width*sizeof(char*));
	
	for(i=0; i<height; i++)
		brick[i]=(char*)malloc(width*sizeof(char));
			
	for(i=0; i<height; i++)
	{
		for(j=0; j<width; j++)
		{
					
			if(j == 0 || j == (width-1)){
			brick[i][j]='|';
			}
			else if(i == 0 ){
			brick[i][j]='~';
			}	
			else{ brick[i][j] = ' ';}
		}			
	}
	
	
	for(i=1; i<(height-1); i++)
	{
	k=1;
			while((ch=getchar()) != 'e')
			{
				if(ch != '\n'){
				brick[i][k]=ch;
				k++;
				}
				
				if(k==width-1)
				break;	
			}
			
		if(ch == 'e')
		break;

	}
	scanf("%c%c",&kdb,&kdb);
	
	scanf("%lf%lf",&x,&y);	
	brick[(int)y][(int)x]='_';
	datx=x;
	daty=y;

	
	display(brick);
	
	while(scanf(" %c",&colour) != EOF)
	{
	x=datx;
	y=daty;
		if(colour == 'q'){
		break;
		}
		
	scanf("%lf%lf",&a,&b);
	a/=100000;
	b/=100000;
	
		
		while(1){
		y+=b;
		x+=a;		
		boom=0;
				
				if(brick[(int)y][(int)x] == '|'){
				x-=a;
				a*=-1;	
				}
				
				if(brick[(int)y][(int)x] != ' '){
				y-=b;
				x-=a;
			
					if((brick[(int)y][(int)x]) == ' '){
					brick[(int)y][(int)x]=colour;
					break;
					}
		
				}

		}


		if(brick[(int)y-1][(int)x] == colour)
			boom++;
		
		if(brick[(int)y+1][(int)x+1] == colour)
			boom++;
			
		if(brick[(int)y+1][(int)x-1] == colour)
			boom++;
		
		if(brick[(int)y-1][(int)x-1] == colour)
			boom++;
		
		if(brick[(int)y][(int)x+1] == colour)
			boom++;

		if(brick[(int)y-1][(int)x+1] == colour)
			boom++;

		if(brick[(int)y][(int)x-1] == colour)
			boom++;
		
		if(brick[(int)y][(int)x] == colour)
			boom++;

		if(brick[(int)y+1][(int)x] == colour)
			boom++;
		
			if(boom == 3){
				sum=30;
				total+=sum;
			}
					
			else if(boom == 4){
				sum=40;
				total+=sum;
			}
					
			else if(boom >= 4){
				sum=100;
				total+=sum;
			}
				
		if(boom >= 3)
		{

			
			if(brick[(int)y-1][(int)x] == colour)
				brick[(int)y-1][(int)x] = ' ';

			if(brick[(int)y+1][(int)x+1] == colour)
				brick[(int)y+1][(int)x+1] = ' ';

			if(brick[(int)y+1][(int)x-1] == colour)
				brick[(int)y+1][(int)x-1] = ' ';
			
			if(brick[(int)y-1][(int)x-1] == colour)
				brick[(int)y-1][(int)x-1] = ' ';
		
			if(brick[(int)y][(int)x+1] == colour)
				brick[(int)y][(int)x+1] = ' ';
				
			if(brick[(int)y-1][(int)x+1] == colour)
				brick[(int)y-1][(int)x+1] = ' ';
		
			if(brick[(int)y][(int)x-1] == colour)
				brick[(int)y][(int)x-1] = ' ';
		
			if(brick[(int)y-1][(int)x-1] == colour)
				brick[(int)y-1][(int)x-1] = ' ';
			
			if(brick[(int)y][(int)x] == colour)
				brick[(int)y][(int)x] = ' ';

			if(brick[(int)y+1][(int)x] == colour)
				brick[(int)y+1][(int)x] = ' ';

		printf("You got %d points. Score: %d\n",sum,total);
		}
		
	display(brick);

	}
			
	printf("Game is over. Your score is %d!",total);
			
	for(i=0; i<height; i++)
	{
		free(brick[i]);
		brick[i]=NULL;
	}
			
	free(brick);
}

void display(char **arr)
{
	int i,j;
	for(i=0; i<height; i++){
		for(j=0; j<width; j++)
			printf("%c",arr[i][j]);				
	printf("\n");
	}
	printf("\n");

}
