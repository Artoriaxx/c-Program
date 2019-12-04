#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=80+5;
int n,m;
int a[maxn];//�����ǷǸ߾��ඨ�� 

const int power=4;
const int base=10000;
const int maxl=10;

/*
*��Ҫ�õ�
  *�߾��Ӹ߾���״̬ת��ʱ��������飩
  *�߾��ӵ�����״̬ת��ʱa[k]+f[i][j]�� 
  *���صȺ� ���ڰ�int��ֵ���ṹ�� 
  *��f���鿪�ɽṹ�壬ÿ���ṹ�嶼��һ���߾���
  *����ͨ������룬�߾�����
  *���Գ���һ�£���д������� 
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
    
    num operator + (const int &b)//this->������ʡ�� 
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
    
    bool operator < (const num &b)const//�����const 
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
        //�ȴ�ӡ���λ��Ϊ��ѹλ ���� �ø߾�����Ϊ0 ����  
        for (int i = a[0]-1;i > 0;--i)  
        printf("%0*d", power, a[i]);    
        //����"%0*d", power����˼�ǣ��������powerλ��������ǰ����0����  
        printf("\n"); 
    }
    
}ans,f[maxn][maxn];

int main()
{ 
    scanf("%d%d",&n,&m);//n��m�� 
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) scanf("%d",&a[j]);
        for (int j=1;j<=m;j++) f[j][j]=a[j];//��θ�ֵ�� ���Գ������صȺ� 
        for (int j=1;j<=m-1;j++)//���䳤�� 
        {
            for (int k=1;k<=m-j;k++)//���
            {
                int l=k+j;
                //f[k][l] = max(a[k] + f[k+1][l] + f[k+1][l], a[l] + f[k][l-] + f[k][l-1]);//����д�޷�ʶ�� �����ڽṹ������д ��������ǰ��friend 
                f[k][l] = max(f[k+1][l] + f[k+1][l] + a[k], f[k][l-1] + f[k][l-1] + a[l]);//�߾��Ӽ��� ����һ�¼Ӻ����ڸ߾��ӵ��� 
            } 
        }
        ans = ans + f[1][m];
        ans = ans + f[1][m];
    }
    ans.print();
    return 0;
}
