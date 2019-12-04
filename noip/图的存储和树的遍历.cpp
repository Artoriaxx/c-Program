
int point[]  to[]  next[]  cc;


void AddEdge(int x,int y)
{
	cc=cc+1;
	to[cc]=y;
	next[cc]=point[x];
	point[x]=cc;
}


void Find(int x)
{
	int now=point[x];
	while(now!=0)
	{
		printf("%d\n",to[now]);
		now=next[now];
	}
}

int tot[];

void Dfs(int x,int y)
{
	tot[x]=1;
	int now=point[x];
	while(now)
	{
		if(to[now]!=y)
		{
			Dfs(to[now],x);
			tot[x]=tot[x]+tot[to[now]];
		}
		now=next[now];
	}
}

int t[]={0,1},top=0,tail=1,fa[],depth[];

void Bfs()
{
	depth[1]=1;
	while(top<tail)
	{
		top=top+1;
		int x=dui[top];
		int now=point[x];
		while(now)
		{
			if(to[now]!=fa[x])
			{
				tail++;
				dui[tail]=to[now];
				fa[to[now]]=x;
				depth[to[now]]=depth[x]+1;
			}
			now=next[now];
		}
	}
}

int main()
{
	Dfs(1,0);
	Bfs();
}








