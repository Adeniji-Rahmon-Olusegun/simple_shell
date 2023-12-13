#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strlen_for_sshell(char *s);
char *_strdup_for_sshell(char *str);
char *_strcpy_for_sshell(char *dest, char *src);
char *_strcat_for_sshell(char *dest, char *src);
void get_and_execute_command_line(char *arg_string, char **env);
void get_and_execute_command_linev(char *arg_string, char **env);
char *read_command_line(void);
char **tokenize_cmd_strings(char *cmd_string, char *delimeter);
char **tokenize_cmd_first_string(char *cmd_string, char *delimeter, char *arg);
#endif
