# include <stdio.h>

int main()
{
	char buf[256];
	char port_test[10];
	int val;
	int ret;
	FILE * fp;
	fp = fopen("./test.txt", "r");

	ret = fread(buf, 1, 256, fp);
	if (ret < 0) printf("fread fail\n");

	printf("%s", buf);
	sscanf(buf, "switch reg read offset=%*d, value=%x", &val);
	//sscanf(buf, "switch=%d", &val);
	printf("port:%d\n", val);

	fclose(fp);

	return 0;
}

