#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

int main(int argc, char *argv[], char *envp[])
{
	while(TRUE)
	{
		char cwd[256] = {0};
		char command[256] = {0};
		char *argv_child[] = {NULL, NULL, NULL};
		char *envp_child[] = {NULL, NULL};
		int len = 0;
		char path_ls[] = "/bin/ls";
		char path_touch[] = "/usr/bin/touch";
		char path_rm[] = "/bin/rm";
		argv_child[0] = (char*)malloc(sizeof(char)*10);
		printf(">>");
		strcpy(argv_child[0], "ls"); /*need to put reall value 
		here because if we're gonna do somthing reall with 
		this argv_child value we gonna need some reall value 
		inside so we will modify this command later*/

		/*we'll get the desired command and check if it's the desired
		command for the desired path of the command*/
		scanf("%s", cwd);
		/*
		* 1.) "tikiyot_masrihot" will give us "/bin/ls" for directorys
		* 2.) "tahin_li_hommos" will make us file
		* 3.) "timhok_ya_maniak"
		*
		*/
		if(strcmp(cwd, "tikiyot_masrihot") == 0)
		{
			strcpy(cwd, path_ls);
			printf("success\n");
		}
		else if(strcmp(cwd, "tahin_li_hommos") == 0)
		{
			strcpy(cwd, path_touch);
			strcat(cwd, " ");
			scanf("%s", command);
			strcat(cwd, command);
			//len = strlen(cwd);
			//cwd[len] = "\0";
		}
		else if(strcmp(cwd, "timhok_ya_maniak") == 0)
		{
			strcpy(cwd, path_rm);
			strcat(cwd, " ");
			scanf("%s", command);
			strcat(cwd, command);
			len = strlen(cwd);
		}

		if(fork())
		{
			int status;
			waitpid(-1, &status, 0);
		}
		else
		{
			printf("the cwd is: %s \n", cwd); 
			execve(cwd, argv_child, envp_child);
		}
	}
	return 0;
}
