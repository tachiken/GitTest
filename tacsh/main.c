#include <stdio.h>
#include <string.h>
#include <assert.h>

static void printPrompt();
static void getCommand(char**);
static void execCommand(char*);

int main()
{
	printf("tacsh start.\n");

	/* main loop */
	while(1){
		char* cmd;

		printPrompt();

		getCommand(&cmd);

		execCommand(cmd);
	}
}

static void printPrompt()
{
	static char buf[1024];

	memset(buf, '\0', sizeof(buf));
	(void)getcwd(buf, sizeof(buf));
	printf("%s >", buf);
	return;
}

static void getCommand(char** arg)
{
	static char buf[1024];

	assert(NULL != arg);

	*arg = buf;
	memset(buf, '\0', sizeof(buf));
	(void)fgets(buf, sizeof(buf), stdin);
	return;
}

static void execCommand(char* arg)
{
	return;
}

