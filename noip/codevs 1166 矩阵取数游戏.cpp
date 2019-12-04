#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=80+5;
int n,m;
int a[maxn];//以上是非高精类定义 

const int power=4;
const int base=10000;
const int maxl=10;

/*
*需要用到
  *高精加高精（状态转移时数组加数组）
  *高精加单精（状态转移时a[k]+f[i][j]） 
  *重载等号 用于把int赋值给结构体 
  *把f数组开成结构体，每个结构体都是一个高精数
  *按普通数组读入，高精处理
  *可以尝试一下，先写出来框架 
*/

struct num
{
    int a[maxl];
    
    num()
    {
         memset(a,0,sizeof(a));
    }
    
    num operator + (const num &b)
    {
        num c;
        c.a[0]=max(a[0],b.a[0]);
        for (int i=1;i<=c.a[0];i++)
        {
            c.a[i]+=a[i]+b.a[i];
            c.a[i+1]+=c.a[i]/base;
            c.a[i]=c.a[i]%base;
        }
        if (c.a[c.a[0]+1])++c.a[0];  
        return c; 
    }
    
    num operator + (const int &b)//this->都可以省略 
    {
        a[1]+=b;
        int i=1;
        while (a[i]>=base)
        {
            a[i+1]+=a[i]/base;
            a[i]%=base;
            i++;
        }
        if (a[a[0]+1])a[0]++;  
        return *this;
    }
    
    num operator = (int b)
    {
        a[0]=0;
        while (b)
        {
            a[0]++;
            a[a[0]]=b%base;
            b/=base;
        }
        return *this;
    }
    
    bool operator < (const num &b)const//必须加const 
    {
        if (a[0] < b.a[0]) return true;  
        if (a[0] > b.a[0]) return false;  
        for (int i = a[0];i > 0;--i)  
        {  
            if (a[i] != b.a[i]) return a[i] < b.a[i];  
        }  
        return false;  
    }
    
    void print()
    {
        printf("%d", a[ a[0] ]);        
        //先打印最高位，为了压位 或者 该高精度数为0 考虑  
        for (int i = a[0]-1;i > 0;--i)  
        printf("%0*d", power, a[i]);    
        //这里"%0*d", power的意思是，必须输出power位，不够则前面用0补足  
        printf("\n"); 
    }
    
}ans,f[maxn][maxn];

int main()
{ 
    scanf("%d%d",&n,&m);//n行m列 
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) scanf("%d",&a[j]);
        for (int j=1;j<=m;j++) f[j][j]=a[j];//如何赋值？ 可以尝试重载等号 
        for (int j=1;j<=m-1;j++)//区间长度 
        {
            for (int k=1;k<=m-j;k++)//起点
            {
                int l=k+j;
                //f[k][l] = max(a[k] + f[k+1][l] + f[k+1][l], a[l] + f[k][l-] + f[k][l-1]);//这样写无法识别 除非在结构体外面写 或者重载前加friend 
                f[k][l] = max(f[k+1][l] + f[k+1][l] + a[k], f[k][l-1] + f[k][l-1] + a[l]);//高精加即可 重载一下加号用于高精加单精 
            } 
        }
        ans = ans + f[1][m];
        ans = ans + f[1][m];
    }
    ans.print();
    return 0;
}
