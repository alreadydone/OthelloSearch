#include <stdio.h>
#include <time.h>

void main()
{
	int i=0,j=0,k,l,turn,rvs=0,step=0,stp=0,slvn=0;
	char ctrl;
	int start[8][8]={0},target[8][8]={0},now[8][8]={0},rvsn[8][8]={0},mvrw[61],mvcl[61],mvtr[61];
	clock_t begin,end;
	FILE *fp;

	fp=fopen(".\\output.txt","a");
	fprintf(fp,"\nINPUT");

	printf("\nSTART");
	printf("\nu - Up   d - Down   l - Left   r - Right   b - Black   w - White   c - Clear\na - clear All   f - deFault   s - Set position   e - End\n");
	while(1)
	{
		ctrl=getche();
		if(ctrl=='f')
		{
			for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				start[i][j]=0;
			start[3][3]=-1;
			start[3][4]=1;
			start[4][3]=1;
			start[4][4]=-1;
			break;
		}
		else if(ctrl=='a')
		{
			for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				start[i][j]=0;
			i=0; j=0;
		}
		else if(ctrl=='s')
		{
			printf("\nRow(1~8)");
			scanf("%d",&i); i%=8; i+=7; i%=8;
			printf("Col(1~8)");
			scanf("%d",&j); j%=8; j+=7; j%=8;
		}
		else if(ctrl=='u') i+=7, i%=8;
		else if(ctrl=='d') i++, i%=8;
		else if(ctrl=='l') j+=7, j%=8;
		else if(ctrl=='r') j++, j%=8;
		else if(ctrl=='b') start[i][j]=1;
		else if(ctrl=='w') start[i][j]=-1;
		else if(ctrl=='c') start[i][j]=0;
		else if(ctrl=='e')
		{
			for(i=0;i<8;i++)
			{
				printf("\n");
				for(j=0;j<8;j++) printf("%3d",start[i][j]);
			}
			printf("\nCorrect?(y/n)");
			ctrl=getche();
			if(ctrl=='y') break;
		}
		else printf("\nError!\n");
	}
	i=0; j=0;
	printf("\nTARGET");
	printf("\nu - Up   d - Down   l - Left   r - Right   b - Black   w - White   c - Clear\na - clear All   s - Set position   e - End\n");
	while(1)
	{
		ctrl=getche();
		if(ctrl=='a')
		{
			for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				target[i][j]=0;
			i=1; j=1;
		}
		else if(ctrl=='s')
		{
			printf("\nRow(1~8)");
			scanf("%d",&i); i%=8; i+=7; i%=8;
			printf("Col(1~8)");
			scanf("%d",&j); j%=8; j+=7; j%=8;
		}
		else if(ctrl=='u') i+=7, i%=8;
		else if(ctrl=='d') i++, i%=8;
		else if(ctrl=='l') j+=7, j%=8;
		else if(ctrl=='r') j++, j%=8;
		else if(ctrl=='b') target[i][j]=1;
		else if(ctrl=='w') target[i][j]=-1;
		else if(ctrl=='a') target[i][j]=0;
		else if(ctrl=='e')
		{
			for(i=0;i<8;i++)
			{
				printf("\n");
				for(j=0;j<8;j++) printf("%3d",target[i][j]);
			}
			for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				if(start[i][j]!=0&&target[i][j]==0) ctrl='0';
			if(ctrl=='0') printf("\nError! Please Check\n");
			else
			{
				printf("\nCorrect?(y/n)");
				ctrl=getche();
				if(ctrl=='y') break;
			}
		}
		else printf("\nError!\n");
	}
	printf("\nWhose Turn (When START)?");
	while(1)
	{
		ctrl=getche();
		if(ctrl=='b')
		{
			turn=1;
			break;
		}
		else if(ctrl=='w')
		{
			turn=-1;
			break;
		}
		else printf("\nError!\n");
	}





	begin=clock();

	for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	{
		now[i][j]=start[i][j];
		if(start[i][j]==0&&target[i][j]!=0) stp++;
	}

	i=0; j=0;
	while(1)
	{
		if(target[i][j]!=0)
		{
			if(i>0&&i<7)
				if(target[i-1][j]!=0&&target[i+1]!=0)
					rvsn[i][j]++;
			if(j>0&&j<7)
			{
				if(target[i][j-1]!=0&&target[i][j+1]!=0)
					rvsn[i][j]+=2;
				if(i>0&&i<7)
				{
					if(target[i-1][j-1]!=0&&target[i+1][j+1]!=0)
						rvsn[i][j]+=4;
					if(target[i-1][j+1]!=0&&target[i+1][j-1]!=0)
						rvsn[i][j]+=8;
				}
			}
		}
		if(j<7) j++;
		else if(i<7) j=0, i++;
		else break;
	}



	for(j=0;j<8;j++)
	{
		ctrl='4';
		for(i=0;i<8;i++)
			if(rvsn[i][j]==0||rvsn[i][j]==1)
				if(ctrl=='5')
				{
					if(target[i-1][j]*target[i][j]==-1)
						rvsn[i-1][j]=0, rvsn[i][j]=0;
				}
				else ctrl='5';
			else ctrl='4';
	}
	for(i=0;i<8;i++)
	{
		ctrl='4';
		for(j=0;j<8;j++)
			if(rvsn[i][j]==0||rvsn[i][j]==2)
				if(ctrl=='5')
				{
					if(target[i][j-1]*target[i][j]==-1)
						rvsn[i][j-1]=0, rvsn[i][j]=0;
				}
				else ctrl='5';
			else ctrl='4';
	}
	i=5; j=0;
	while(j<6)
	{
		ctrl='4';
		while(i<8&&j<8)
		{
			if(rvsn[i][j]==0||rvsn[i][j]==4)
				if(ctrl=='5')
				{
					if(target[i-1][j-1]*target[i][j]==-1)
						rvsn[i-1][j-1]=0, rvsn[i][j]=0;
				}
				else ctrl='5';
			else ctrl='4';
			i++, j++;
		}
		if(j<i) i-=j, i--, j=0;
		else j-=i, j++, i=0;
	}
	i=0; j=2;
	while(i<6)
	{
		ctrl='4';
		while(i<8&&j>=0)
		{
			if(rvsn[i][j]==0||rvsn[i][j]==8)
				if(ctrl=='5')
				{
					if(target[i-1][j+1]*target[i][j]==-1)
						rvsn[i-1][j+1]=0, rvsn[i][j]=0;
				}
				else ctrl='5';
			else ctrl='4';
			i++, j--;
		}
		if(i+j<7) j+=i, j++, i=0;
		else i+=j, i-=6, j=7;
	}



	for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	{
		if(rvsn[i][j]==0&&start[i][j]*target[i][j]==-1)
		{
			printf("\nIMPOSSIBLE");
			goto die;
		}
	}


	fprintf(fp,"\nSTART");
	for(i=0;i<8;i++)
	{
		fprintf(fp,"\n");
		for(j=0;j<8;j++) fprintf(fp,"%3d",start[i][j]);
	}
	fprintf(fp,"\nTARGET");
	for(i=0;i<8;i++)
	{
		fprintf(fp,"\n");
		for(j=0;j<8;j++) fprintf(fp,"%3d",target[i][j]);
	}
	fprintf(fp,"\n");


	i=0; j=0;
	mov:
	while(1)
	{
		if(target[i][j]!=0)
		if(now[i][j]==0)
		if(rvsn[i][j]!=0||target[i][j]==turn)
		{
			k=i; l=j;
			while(k<7)
			{
				k++;
				if(now[k][l]==turn)
				{
					for(k--;k>i;k--)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1, rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i;
			while(k>0)
			{
				k--;
				if(now[k][l]==turn)
				{
					for(k++;k<i;k++)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i;
			while(l<7)
			{
				l++;
				if(now[k][l]==turn)
				{
					for(l--;l>j;l--)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			l=j;
			while(l>0)
			{
				l--;
				if(now[k][l]==turn)
				{
					for(l++;l<j;l++)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			l=j;
			while(k<7&&l<7)
			{
				k++; l++;
				if(now[k][l]==turn)
				{
					for(k--,l--;k>i;k--,l--)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k<7&&l>0)
			{
				k++; l--;
				if(now[k][l]==turn)
				{
					for(k--,l++;l<j;k--,l++)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k>0&&l<7)
			{
				k--; l++;
				if(now[k][l]==turn)
				{
					for(k++,l--;l>j;k++,l--)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k>0&&l>0)
			{
				k--; l--;
				if(now[k][l]==turn)
				{
					for(k++,l++;k<i;k++,l++)
					{
						if(rvsn[k][l]==0) ctrl='6';
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			if(rvs>0)
			{
				now[i][j]=turn;
				mvrw[step]=i; mvcl[step]=j; mvtr[step]=turn;
				step++;
				
				
				if(ctrl=='6')
					{
						step++;
						goto rtn;
					}



				if(step==stp)
				{
					for(i=0;i<8;i++)
					for(j=0;j<8;j++)
						if(now[i][j]!=target[i][j]) ctrl='1';
					if(ctrl!='1')
					{
						slvn++;
						fputc('\n',fp);
						for(step=0;step<stp;step++) fputc(','-mvtr[step],fp), fputc('a'+mvcl[step],fp), fputc('1'+mvrw[step],fp), fputc(' ',fp), fputc(' ',fp);
						step--;
					}
					goto rtn;
				}
				turn*=-1, ctrl='3', i=0, j=0, rvs=0;
				continue;
			}
		}
		if(j<7) j++;
		else if(i<7) i++, j=0;
		else break;
	}


	if(ctrl=='2') goto rtn;
	i=0; j=0;
	while(1)
	{
		if(target[i][j]!=turn)
		if(now[i][j]==0)
		if(target[i][j]==0||rvsn[i][j]==0)
		{
			k=i; l=j;
			while(k<7)
			{
				k++;
				if(now[k][l]==turn)
					if(k-i>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
			k=i;
			while(k>0)
			{
				k--;
				if(now[k][l]==turn) 
					if(i-k>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
			k=i;
			while(l<7)
			{
				l++;
				if(now[k][l]==turn)
					if(l-j>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
			l=j;
			while(l>0)
			{
				l--;
				if(now[k][l]==turn)
					if(j-l>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
			l=j;
			while(k<7&&l<7)
			{
				k++; l++;
				if(now[k][l]==turn)
					if(k-i>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k<7&&l>0)
			{
				k++; l--;
				if(now[k][l]==turn)
					if(j-l>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k>0&&l<7)
			{
				k--; l++;
				if(now[k][l]==turn)
					if(l-j>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k>0&&l>0)
			{
				k--; l--;
				if(now[k][l]==turn)
					if(i-k>1) goto rtn;
					else break;
				else if(now[k][l]==0) break;
			}
		}
		if(j<7) j++;
		else if(i<7) i++, j=0;
		else if(ctrl=='4') goto rtn;
		else
		{
			i=0; j=0;
			ctrl='4';
			turn*=-1;
			goto mov;
		}
	}


	rtn:
	if(step>0)
	{
		for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			now[i][j]=start[i][j];
		step--;
		for(ctrl=0;ctrl<step;ctrl++)
		{
			i=mvrw[ctrl]; j=mvcl[ctrl]; turn=mvtr[ctrl];
			k=i; l=j;
			while(k<7)
			{
				k++;
				if(now[k][l]==turn)
				{
					for(k--;k>i;k--)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i;
			while(k>0)
			{
				k--;
				if(now[k][l]==turn)
				{
					for(k++;k<i;k++)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i;
			while(l<7)
			{
				l++;
				if(now[k][l]==turn)
				{
					for(l--;l>j;l--)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			l=j;
			while(l>0)
			{
				l--;
				if(now[k][l]==turn)
				{
					for(l++;l<j;l++)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			l=j;
			while(k<7&&l<7)
			{
				k++; l++;
				if(now[k][l]==turn)
				{
					for(k--,l--;k>i;k--,l--)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k<7&&l>0)
			{
				k++; l--;
				if(now[k][l]==turn)
				{
					for(k--,l++;l<j;k--,l++)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k>0&&l<7)
			{
				k--; l++;
				if(now[k][l]==turn)
				{
					for(k++,l--;l>j;k++,l--)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			k=i; l=j;
			while(k>0&&l>0)
			{
				k--; l--;
				if(now[k][l]==turn)
				{
					for(k++,l++;k<i;k++,l++)
						now[k][l]*=-1;
					break;
				}
				else if(now[k][l]==0) break;
			}
			now[i][j]=turn;
		}
		i=mvrw[step];
		j=mvcl[step];
		turn=mvtr[step];
		ctrl='2';
		rvs=0;
		if(j<7)
		{
			j++;
			goto mov;
		}
		else if(i<7)
		{
			i++; j=0;
			goto mov;
		}
		else goto rtn;
	}
	die:
	fprintf(fp,"\n%d Solves\n",slvn);
	fprintf(fp,"THE END\n");

	end=clock();
	fprintf(fp,"TIME: %lf s\n",(double)(end-begin)/CLOCKS_PER_SEC);
	fclose(fp);

	printf("\nTHE END\nPress Any Key to Exit");
	getche();
}
