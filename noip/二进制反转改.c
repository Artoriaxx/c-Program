#include <stdio.h>
#include <limits.h>

int main()
{
	int x, p, n;
	scanf("%d%d%d", &x, &p, &n);
	int i;
	const int num = sizeof(int)*CHAR_BIT;
	int mask = 1 << (num - 1);
	int temp = x;
	for (i = num-1; i >= 0; i--)
	{
		putchar(!(temp&mask) ? '0' : '1');
		temp <<= 1;
		if (i % CHAR_BIT == 0)
		{
			printf(" ");
		}
	}
	printf("\n");

	for (i = num-1; i >= 0; i--)
	{
		if (i >= p && i <= p + n-1)
		{
			putchar((x&mask) ? '0' : '1');
		}
		else
		{
			putchar(!(x&mask) ? '0' : '1');
		}
		x <<= 1;
		if (i % CHAR_BIT == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}


