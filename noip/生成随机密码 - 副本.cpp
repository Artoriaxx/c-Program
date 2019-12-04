#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
char *rand_str(char *str,const int len)
{
    srand(time(NULL));
    int i;
    for(i=0;i<len;++i)
    {
         switch((rand()%3))
         {
             case 1:
              str[i]='A'+rand()%26;
              break;
             case 2:
             str[i]='a'+rand()%26;
              break;
              default:
             str[i]='0'+rand()%10;
              break;
         }
    }
     str[++i]='\0';
    return str;
}

int main()
{

    char name[10];
    cout<<rand_str(name,10)<<endl;
 system("pause");
 return 0;
}
