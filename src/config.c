#include "config.h"

/* check if webhook exists in file */
/* does not check if valid webhook only if the config file has text in it */
/* RETURNS : number of chars in file. */
int config_check_hook()
{
	FILE *fp;
	int count;
	fp = fopen(CONFIG_FILENAME, "r");
	count = 0;
	
	if(!fp)
	{
		return 0;
	}

	while( getc(fp) != EOF )
	{
		count += 1;
	}

	fclose(fp);

	return count;
}

/* writes the url into the config file */
void config_set_hook(char *hook)
{
	FILE *fp;
	fp = fopen(CONFIG_FILENAME, "w");

	fprintf(fp, hook);

	if(ferror(fp))
	{
		puts("Error writing to config file");
	}
	fclose(fp);
}

/* get the webhook from config file */
char * config_get_hook()
{
	FILE *fp;
	char *webhook;
	char *stripped;
	int len;
	
	len = 0;
	webhook = NULL;
	fp = NULL;

	fp = fopen(CONFIG_FILENAME, "r");

	if(!fp)
	{
		return NULL;
	}

	webhook = (char *)calloc(MAXBUFF, sizeof(char));
	fgets(webhook, MAXBUFF, fp);
	len = strlen(webhook);
	
	/* subtract from len because of carriage returns \r\n */
	stripped = (char *)calloc(len, sizeof(char));
	strncpy(stripped, webhook, len - 1);
	free(webhook);

	return stripped;
}

/* check if config file is setup and has something in it */
void config_setup()
{
	if(config_check_hook() > 0)
	{
		return;
	}

	char *buff = (char *)calloc(sizeof(char), MAXBUFF);

	puts("No webhook found in config file. Enter a new one.");
	printf("webhook > ");
	fgets(buff, MAXBUFF, stdin);

	config_set_hook(buff);
}