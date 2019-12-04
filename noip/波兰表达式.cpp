#include <stdio.h>   
#include<math.h>   
#include<cstdio>
#include<stdlib.h>
char a[1010]; 
double dfs(){    
scanf("%s",a);   
switch(a[0]){   
case'+': return dfs( ) + dfs( );   
case'-': return dfs( ) - dfs( );   
case'*': return dfs( ) * dfs( );   
case'/': return dfs( ) / dfs( );   
default: return atof(a);   
}   
}   
int main()   
{   
double ans;   
ans = dfs();   
printf("%f", ans);
return 0   ;
}   
