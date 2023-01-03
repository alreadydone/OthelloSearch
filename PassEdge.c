#include <stdio.h>
#include <time.h>
#define n 12
#define neatup

void main()
{
	int i=0,j=0,k,l,turn,rvs=0,step=0,black=4;
	unsigned long slvn=0;
	char ctrl;
	int start[8][8]={0},now[8][8]={0},mvrw[n],mvcl[n],mvtr[n];
	clock_t begin,end;
	FILE *fp;

	fp=fopen("output.txt","a");
	fprintf(fp,"\nINPUT");

	begin=clock();

	start[2][3]=1; start[3][3]=1; start[3][4]=1; start[4][3]=1; start[4][4]=-1;
	turn=-1;


	for(i=0;i<8;i++)
	for(j=0;j<8;j++)
		now[i][j]=start[i][j];


	fprintf(fp,"\nSTART");
	for(i=0;i<8;i++)
	{
		fprintf(fp,"\n");
		for(j=0;j<8;j++) fprintf(fp,"%3d",start[i][j]);
	}

	i=1; j=1;
	mov:
	while(1)
	{
		if(now[i][j]==0)
		{
			k=i; l=j;
			while(k<7)
			{
				k++;
				if(now[k][l]==turn)
				{
					for(k--;k>i;k--)
					{
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
						now[k][l]*=-1,rvs++;
					}
					break;
				}
				else if(now[k][l]==0) break;
			}
			if(rvs>0)
			{
				if(step==n) goto rtn;
				if(turn==1) black++, black+=rvs;
				else black-=rvs;
				now[i][j]=turn;
				mvrw[step]=i; mvcl[step]=j; mvtr[step]=turn;
				step++;
				turn*=-1, ctrl='3', i=1, j=1, rvs=0;
				continue;
			}
		}
		if(j<6) j++;
		else if(i<6) i++, j=1;
		else break;
	}


	if(ctrl=='2') goto rtn;
	i=0; j=0;
	while(1)
	{
		if(now[i][j]==0)
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
		if(j<7)
			if(i==0||i==7) j++;
			else j=7;
		else if(i<7) i++, j=0;
		#ifdef neatup
		else if(black==step+5||black==0) break;
		#endif
		else if(step==n)
		{
			slvn++;
			fputc('\n',fp);
			fprintf(fp,"%lu. ",slvn);
			for(i=0; i<step; i++)
				fprintf(fp, "%c%c%c  ", ','-mvtr[i], 'a'+mvcl[i], '1'+mvrw[i]);
			break;
		}
		else if(ctrl=='4') break;
		else
		{
			i=1; j=1;
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
		#ifdef debug
		fputc('\n',fp);
		for(i=0; i<step; i++)
			fprintf(fp, "%c%c%c  ", ','-mvtr[i], 'a'+mvcl[i], '1'+mvrw[i]);
		#endif
		black=4;
		step--;
		for(ctrl=0,rvs=0;ctrl<step;ctrl++,rvs=0)
		{
			i=mvrw[ctrl]; j=mvcl[ctrl]; turn=mvtr[ctrl];
			k=i; l=j;
			while(k<7)
			{
				k++;
				if(now[k][l]==turn)
				{
					for(k--;k>i;k--)
						now[k][l]*=-1,rvs++;
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
						now[k][l]*=-1,rvs++;
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
						now[k][l]*=-1,rvs++;
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
						now[k][l]*=-1,rvs++;
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
						now[k][l]*=-1,rvs++;
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
						now[k][l]*=-1,rvs++;
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
						now[k][l]*=-1,rvs++;
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
						now[k][l]*=-1,rvs++;
					break;
				}
				else if(now[k][l]==0) break;
			}
			now[i][j]=turn;
			if(turn==1) black++,black+=rvs;
			else black-=rvs;
		}
		i=mvrw[step];
		j=mvcl[step];
		turn=mvtr[step];
		ctrl='2';
		rvs=0;
		if(j<6)
		{
			j++;
			goto mov;
		}
		else if(i<6)
		{
			i++; j=1;
			goto mov;
		}
		else goto rtn;
	}
	die:
	fprintf(fp,"\n%ld Solves\n",slvn);
	fprintf(fp,"THE END\n");

	end=clock();
	fprintf(fp,"TIME: %f s\n",(end-begin)/CLK_TCK);
	fclose(fp);

	printf("\nTHE END\nPress Any Key to Exit");
	getche();
}
