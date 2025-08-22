#include <stdio.h>

void printSequance(int a, int n)
{
	int temp1 = 0;
	int temp2 = 0;

	for (int i = 0; i < n; i++)
	{
		temp2 = 0;
		printf("%d\t", a);
		while (a)
		{
			temp1 = a % 10;
			temp2 += (temp1 * temp1 * temp1);
			a /= 10;
		}
		a = temp2;
	}
}


int sequance(int a, int k, int n)
{
	int temp1 = 0;
	int temp2 = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		temp2 = 0;
		if (k == a)
			count++;
		while (a)
		{
			temp1 = a % 10;
			temp2 += (temp1 * temp1 * temp1);
			a /= 10;
		}
		a = temp2;
	}

	return count;
}

void kIncrStableA(int a, int A)
{
	int temp1 = 0;
	int temp2 = 0;
	int count = 0;
	int sum = a;

	for (int i = 0; i < 1000; i++)
	{
		temp2 = 0;

		sum += a;

		if (sum<A || sum==A)
		{
			count++;
		}
		else
			break;

		while (a)
		{
			temp1 = a % 10;
			temp2 += (temp1 * temp1 * temp1);
			a /= 10;
		}
		a = temp2;
	}

	if (count == 1000)
		printf("MAX");
	else
		printf("K is %d", count);

}

/*int main()
{
	int a;
	int A = 1;
	int n, r;

	printf("Enter the first number of the sequance and how long for it to be:\n");
	scanf_s("%d %d", &a, &n);

	printSequance(a, n);
	
	printf("Enter the number you want to check for repitition in this sequance:\n");
	scanf_s("%d", &r);

	printf("\n%d", sequance(a, 370, n));

	printf("Enter a series of A-prags:");

	while(A > 0)
	{
		scanf_s("%d", &A);
		kIncrStableA(a, A);
	}

	return 0;
}*/