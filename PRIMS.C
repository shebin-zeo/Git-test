#include <stdio.h>
#include <conio.h>

void main(){
int i,j,visited[10],x=1,min,a,b,u,v,mincost=0;

int cost[5][5]={
			{-1,-1,-1,-1},
		     {0,10,5,0},
		     {10,0,0,11},
		     {5,0,0,2},
		     {0,11,2,0}
		    };
clrscr();
for(i=1;i<=4;++i){
	for(j=1;j<=4;++j){
		if(cost[i][j]==0)
			{
			  cost[i][j]=999;
			}
		printf("%d ",cost[i][j]);
	}
	printf("\n");

}

visited[1]=1;

while(x<4){

	for(i=1,min=999;i<=4;++i)
	{
		for(j=1;j<=4;++j)
		{
			if(cost[i][j]<min)
			{
				if(visited[i]!=0)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
	}
				if(visited[u]==0 || visited[v]==0)
				{
					printf("Edge %d (%d , %d ) : %d\n",x++,a,b,min);
					mincost+=min;
					visited[b]=1;

				}


			cost[a][b]=999;
			cost[b][a]=999;


	}
	printf("Minimum cost : %d",mincost);

getch();
}