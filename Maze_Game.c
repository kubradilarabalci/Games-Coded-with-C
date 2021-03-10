#include <stdio.h> 
int startrow, startcol, row, col, finalrow, finalcol;
void display(char arr[50][50]);
void move(char arr[50][50]);
int main()
{
	char maze[50][50], a, kdb;
	int b, c;
	int i, j;
	
	for(i=0;i<50;i++)
	for(j=0;j<50;j++)
	maze [i] [j] = ' ';		

	
	scanf("%d %d",&row,&col);
	for(i=0; i<row; i++){

	for(j=0; j<col; j++){
		if(j == 0 || j == (col-1)){
		maze[i][j]='*';
		}
		else if(i == 0 || (i == (row-1))){
		maze[i][j]='*';
		}
		else{ maze[i][j] = ' ';}
	
	}

	}

	while(1){
	
	scanf(" %c",&a);
	
	switch (a){
	
	case 's':
	scanf("%d %d",&b,&c);
	maze[b][c]='O';
	startrow=b, startcol=c; 
	break;	

	case 'f':
	scanf("%d %d",&b,&c);
	maze[b][c]='f';	
	finalrow=b, finalcol=c;
	break;	

	case '$':
	scanf("%d %d",&b,&c);
	maze[b][c]='$';	
	break;
	
	case 'b':
	scanf("%d %d",&b,&c);
	maze[b][c]='*';	
	break;	

	case 'X':
	scanf("%d %d",&b,&c);
	maze[b][c]='X';	
	break;	

	}
	
	if(a == 'e'){
	scanf("%c %c",&kdb, &kdb);
	break;	
	}

	}
	display(maze);
	move(maze);

return 0;

}
void display(char arr[50][50]){
	int i, j;
	for(i=0; i<row; i++){

		for(j=0; j<col; j++){
			if(arr[i][j] == 'f'){
			arr[i][j]=' ';
			}
		printf("%c",arr[i][j]);
		}
		
	printf("\n");

	}
printf("\n");

}
void move(char arr[50][50]){
	char tea;
	int sum=0, i=startrow, j=startcol;

	while(scanf(" %c",&tea) != EOF){
	
	

	switch (tea){
	
	case 'd':
		if(arr[i+1][j] == '*'){
		printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		}

		else if(arr[i+1][j] == '$'){
		sum++;
		printf("YOU GOT 1 $.\n");
		arr[i+1][j]='O';
		arr[i][j]=' ';
		i++;
		}

		else if((i+1 == finalrow) && (j == finalcol)){
		printf("CONGRATS! YOU GOT %d BONUS:)\n",sum);
		arr[i+1][j]='O';
		arr[i][j]=' ';
		i++;
		display(arr);
		return;
		}

		else if(arr[i+1][j] == 'X'){
		printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
		display(arr);
		return;
		}

	else{
	arr[i+1][j]='O';
	arr[i][j]=' ';
	i++;
	}
	break;

	case 'r':
		if(arr[i][j+1] == '*'){
		printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		}

		else if(arr[i][j+1] == '$'){
		sum++;
		printf("YOU GOT 1 $.\n");
		arr[i][j+1]='O';
		arr[i][j]=' ';
		j++;
		}

		else if((i == finalrow) && (j+1 == finalcol)){
		printf("CONGRATS! YOU GOT %d BONUS:)\n",sum);
		arr[i][j+1]='O';
		arr[i][j]=' ';
		j++;
		display(arr);
		return;
		}

		else if(arr[i][j+1] == 'X'){
		printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
		display(arr);
		return;
		}

	else{
	arr[i][j+1]='O';
	arr[i][j]=' ';
	j++;
	}
	break;

	case 'l':
		if(arr[i][j-1] == '*'){
		printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		}

		else if(arr[i][j-1] == '$'){
		sum++;
		printf("YOU GOT %d $.\n",sum);
		arr[i][j-1]='O';
		arr[i][j]=' ';
		j--;
		}

		else if((i == finalrow) && (j-1 == finalcol)){
		printf("CONGRATS! YOU GOT 1 BONUS:)\n");
		arr[i][j-1]='O';
		arr[i][j]=' ';
		j--;
		display(arr);
		return;
		}

		else if(arr[i][j-1] == 'X'){
		printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
		display(arr);
		return;
		}


	else{
	arr[i][j-1]='O';
	arr[i][j]=' ';
	j--;
	}
	break;

	case 'u':
		if(arr[i-1][j] == '*'){
		printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		}

		else if(arr[i-1][j] == '$'){
		sum++;
		printf("YOU GOT 1 $.\n");
		arr[i-1][j]='O';
		arr[i][j]=' ';
		i--;
		}

		else if((i-1 == finalrow) && (j == finalcol)){
		printf("CONGRATS! YOU GOT %d BONUS:)\n",sum);
		arr[i-1][j]='O';
		arr[i][j]=' ';
		i--;
		display(arr);
		return;
		}

		else if(arr[i-1][j] == 'X'){
		printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
		display(arr);
		return;
		}

	else{
	arr[i-1][j]='O';
	arr[i][j]=' ';
	i--;
	}
	break;
	
	case 'q':
	printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
	display(arr);
	return;
	}
	display(arr);
	
	}
printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
	for(i=0; i<row; i++){

		for(j=0; j<col; j++){
			if(arr[i][j] == 'f'){
			arr[i][j]=' ';
			}
		printf("%c",arr[i][j]);
		}
		
	printf("\n");

	}
return;
	}










