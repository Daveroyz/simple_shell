#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

char *get_line(void);
void execute_command(char *cmd, char *args[]);
char *get_path(void);
void process_input(void);
void print_error_message(const char *message);

#endif
