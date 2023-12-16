#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

int _strlen_for_sshell(char *s);
char *_strdup_for_sshell(char *str);
char *_strcpy_for_sshell(char *dest, char *src);
char *_strcat_for_sshell(char *dest, char *src);
int _strcmp_for_sshell(char *s1, char *s2);
void execute_command_line(char **arg_string, char **env, char *arg);
void sshell_interactive_mode(char **env, char *arg);
void sshell_non_interactive_mode(char *file_path, char **env, char *arg);
char **tokenize_cmd_strings(char *cmd_string, char *delimeter);
char **tokenize_cmd_first_string(char *cmd_string, char *delimeter, char *arg);
#endif
