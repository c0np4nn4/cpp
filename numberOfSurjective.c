#include <stdio.h>

int S(int n, int k)
{
	if( n == k || k == 1) return 1;
	else
	{
		return k * S( n-1, k) + S( n-1, k-1 );
	}
}

int main()
{
	while(1)
	{
		printf("[+] Input n, k >> ");
		int n, k;
		scanf("%d %d", &n, &k);
		
		if( n == 0 )
			break;

		int result = S( n, k );
		printf("[*] S( %d, %d ) == %d\n\n", n, k, result );
		
	}

	return 0;
}
