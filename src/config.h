#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_FILENAME "./config"
#define MAXBUFF 255

/* check if webhook exists in file */
/* does not check if valid webhook only if the config file has text in it */
/* RETURNS : number of chars in file. */
int config_check_hook();

/* writes the url into the config file */
void config_set_hook(char *hook);

/* get the webhook from config file */
char * config_get_hook();

/* check if config file is setup and has something in it */
void config_setup();

#endif