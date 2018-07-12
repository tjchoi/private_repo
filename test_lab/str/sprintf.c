
#include <stdio.h>

#define MAX_MAC_LEN	18

/* Number to String */ 

void division(int num, int *q, int *r)
{
	*q = (int)(num / 0x100);
	*r = (int)(num % 0x100);

	return;
}

int num_to_str()
{
	int i = 0, remainder, quotient;
	int num;
	unsigned char pMacAddr[6] = {0};
	char dev_mac[MAX_MAC_LEN];
	
	printf("Insert number to convert into string!\n");
	scanf("%d", &num);

	do
	{
		if (i == 0) {
			division(num, &quotient, &remainder);
			pMacAddr[i] = remainder;
		}
		else {
			division(quotient, &quotient, &remainder);
			pMacAddr[i] = remainder;
		}

		i++;
	} while(quotient);
	
	snprintf(dev_mac, sizeof(dev_mac), "%02X:%02X:%02X:%02X:%02X:%02X",
			pMacAddr[5], pMacAddr[4], pMacAddr[3],
			pMacAddr[2], pMacAddr[1], pMacAddr[0]);

	printf("dev_mac: %s\n", dev_mac);

	return 0;
}

int test()
{
	/* you'd better initialize array at the beggining.
	 * especailly when you handle strings 
	 */
#if 0
	char buf[20] = {0};
#else
	char buf[20] = {0};
#endif
	int i;
	for (i=0; i<20; i++)
	{
		printf("\nbuf[%d]:%c", i, buf[i]);
	}
	snprintf(buf, 5, "12345");
	for (i=0; i<20; i++)
	{
		printf("\nbuf[%d]:%d", i, buf[i]);
	}
	//printf("\nbuf:%s", buf);
	
	return 0;
}


int main()
{
	//num_to_str();

	test();

	return 0;
}
