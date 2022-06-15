#include "main.h"

#define	MAX_SIZE_CMD	256
#define	MAX_SIZE_ARG	16

void get_cmd(void);
void convert_cmd(void);
void c_shell(void);
void log_handle(int sig);

/**
 * main - Entry point
 * Return: 0 on success.
 */

int main(void)
{
signal(SIGCHLD, log_handle);
c_shell();
return (0);
}

/**
 * c_shell - Entry point
 *
 */

void c_shell(void)
{
char cmd[256];
char *argv[16];
pid_t pid;
char i = 0;
while (1)
{
get_cmd();

if (!strcmp("", cmd))
continue;

if (!strcmp("exit", cmd))
break;

convert_cmd();

pid = fork();
if (pid == -1)
{
printf("failed to create a child\n");
}
else if (pid == 0)
{
execvp(argv[0], argv);
}
else
{
if (*argv[i] == NULL)
waitpid(pid, NULL, 0);
}
}
}

/**
 * get_cmd - Entry point
 *
 */
void get_cmd(void)
{
char cmd[256];

printf("Shell>\t");
fgets(cmd, MAX_SIZE_CMD, stdin);
if ((strlen(cmd) > 0) && (cmd[strlen(cmd) - 1] == '\n'))
cmd[strlen(cmd) - 1] = '\0';
}

/**
 * convert_cmd - Entry point
 *
 */
void convert_cmd(void)
{
char cmd[256];
char *argv[16];

char i;
char *ptr;
i = 0;
ptr = strtok(cmd, " ");
while (ptr != NULL)
{
argv[i] = ptr;
i++;
ptr = strtok(NULL, " ");
}

if (!strcmp("&", argv[i - 1]))
{
argv[i - 1] = NULL;
argv[i] = "&";
}
else
{
argv[i] = NULL;
}
}

/**
 * log_handle - Entry point
 * @sig: param
 *
 */
void log_handle(int sig)
{
FILE *pFile;
pFile = fopen("log.txt", "a");
if (pFile == NULL)
perror("Error opening file.");
else
fprintf(pFile, "[LOG] child proccess terminated.\n");
fclose(pFile);
}
