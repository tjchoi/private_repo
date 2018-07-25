#include <stdio.h>

void test1()
{
	FILE *fp;
	char buf[20] = {0};

	fp = fopen("test.txt", "r");
	if (!fp) {
		printf("Can't fopen fread_test.txt\n");
		return;
	}
	/**
	 *	fread() function reads data continuously!
	 *	it dosen't consider '\n' character
	 */

	printf("test1\n");
	
	fread(buf, 1, sizeof(buf), fp);
	printf("(1):%s\n", buf);

	fread(buf, 1, sizeof(buf), fp);
	printf("(2):%s\n", buf);

	fread(buf, 1, sizeof(buf), fp);
	printf("(3):%s\n", buf);

	fread(buf, 1, sizeof(buf), fp);
	printf("(4):%s\n", buf);

	fclose(fp);
	return;
}

void test2()
{
    FILE *fp;
    char buf[20] = {0};

    fp = fopen("test.txt", "r");
    if (!fp) {
        printf("Can't fopen fread_test.txt\n");
        return;
    }
    /**
     *  fread() function reads data continuously!
     *  until newline character!!
     */
	printf("test2\n");
	
    fgets(buf, sizeof(buf), fp);
    printf("(1):%s\n", buf);

    fgets(buf, sizeof(buf), fp);
    printf("(2):%s\n", buf);

    fgets(buf, sizeof(buf), fp);
    printf("(3):%s\n", buf);

    fgets(buf, sizeof(buf), fp);
    printf("(4):%s\n", buf);

    fclose(fp);
    return;
}

int main()
{
	test1();

	test2();

	return 0;
}
