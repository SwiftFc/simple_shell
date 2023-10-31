#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

/* AUTHORED BY - HENRY DADE AND KINGSLEY*/

/* Interactive Header prototypes*/
int create_process(char **args);
char *get_stream(void);
char **divide_line(char *line);
char *scan_line(void);
void myshell_isnot(void);
void myshell_works(void);
/*void interactive_func(void);*/

/*string headers*/
char *strcpy(char *dest, const char *src);
char *strdup(const char *str);
int mycustom_strcmp(char *fs, char *ss);
int mycustom_strlen(const char *s);

/* Executing Headers*/
int my_exit(char **args);
int my_env(char **args);
int exec_arg(char **args);
#endif /* MAIN_H */
