#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUF 256

//ls 코드
void ls(char *argv)
{
	DIR *dir, *tempDir;
	struct dirent *directory;
	struct stat file_state;

	char current[MAX_BUF];
	char temp[MAX_BUF];

	memset(temp, 0, MAX_BUF);		
	memset(current, 0, MAX_BUF);		
	strcpy(temp, argv);
	
	//printf(temp);

	if( (dir = opendir(temp)) < 0)
	{
		perror("opendir");
		exit(1);
	}
	
	//항목 읽기 시작
	while( (directory = readdir(dir)) != NULL)
	{
		if(!strncmp(directory->d_name, ".", 1) || !strcmp(directory->d_name, ".."))
        {
            continue;
        }
		sprintf(current, "%s/%s", temp, directory->d_name);
		printf("%s\n", current);

		if(lstat(current, &file_state) < 0)
		{
			perror("stat");
			exit(1);
		}

		if(S_ISDIR(file_state.st_mode))
		{
			ls(current);
		}
	}
}

void main(int argc, char *argv[])
{
	
	if(argc<2)
	{
		fprintf(stderr, "Usage: file_dir dirname\n");
		exit(1);
	}
			
	ls(argv[1]); 
	
}

/*

DIR *dir;
	struct dirent *pde;
	int i = 0;

	char buffer[MAX_BUF];
	
	struct stat buf;
	char *msg;	
	
	memset(buffer, 0, MAX_BUF);		
	strcpy(buffer,argv);

	if( (dir = opendir(argv)) < 0)
	{
		perror("opendir");
		exit(1);
	}
	
	//항목 읽기 시작
	while( (pde = readdir(dir)) != NULL)
	{
		char currentFile[MAX_BUF];
		char tempFile[MAX_BUF];

		//현재 디렉토리 가져오기		
//		printf("현재 디렉토리의 경로를 출력합니다.\n");
//		getcwd(buffer, MAX_BUF);
//		printf("working directory = %s \n", buffer);
		
		//만약 지금 읽은 파일 형식이 디렉토리라면 ls함수를 재귀적으로 호출
			//일단 오류출력
		sprintf(currentFile, "%s/%s", buffer, pde->d_name);
		printf("현재 읽는 파일 : %s", currentFile);

		if(lstat(currentFile, &buf) < 0)
		{
			perror("stat");
			exit(1);
		}
		
			//파일형식이 디렉토리라면 ls함수를 재귀적으로 호출
		if(S_ISDIR(buf.st_mode))
		{

			ls(currentFile);
		}
	
//		printf("%20s ", pde->d_name);
//		if(++i % 3 == 0)
//			printf("\n");
	}
	printf("\n");
	closedir(dir);

*/