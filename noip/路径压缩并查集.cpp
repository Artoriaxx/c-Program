


int fa[];

int getf(int x)
{
	if(fa[x]==x)
		return x;
	fa[x]=getf(fa[x]);
	return fa[x];
}


void Link(int x,int y)
{
	x=getf(x);
	fa[x]=y;
}

bool Judge(int x,int y)
{
	x=getf(x);
	y=getf(y); 
	if(x==y)
		return true;
	else
		return false;
}


int main()
{
	int i;
	for(i=1;i<=n;i++)
		fa[i]=i;
}












