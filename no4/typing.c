#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char sentence[30], input[30];

int main()
{	
 	char c;
	time_t start_time, finish_time;
	int O_TA = 0;	//오타횟수
	int num_typing=0;
	double time_gap;
		
	strcpy(sentence, "I'm practicing typing.");
	
	printf("타자 연습 프로그램입니다. 다음의 문장을 입력하시오. \n y 를 입력하면 시작합니다. ");
	scanf("%s", &c);

	if(c == 'y' || c == 'Y')	//타자 프로그램 시작.
	{
		time(&start_time);
		printf("시간을 재기 시작합니다. 문장을 입력하세요.\n");
		printf(sentence);
		printf("\n");
		
		//사용자에게 문자열 입력받음.		
		scanf(" %[^\n]", &input);
		time(&finish_time);

		for(int i = 0 ; i < sizeof(input) ; i++)
		{
			if(sentence[i] != input[i])	//오타발생
			O_TA++;
			//글자 수 세기
			if((sentence[i] == input[i]) && input[i] != NULL)
				num_typing ++;
		}
		//결과출력
		printf("\n오타 발생 횟수는 %d입니다.\n", O_TA);
		time_gap = difftime(finish_time, start_time);
		time_gap = (num_typing / time_gap)*60;
		printf("평균 분당 타자수는 %lf입니다.", time_gap);

/*		if(!strcmp(sentence, input))
		{
			
			printf("\n같아요.");
			
		}
		else
		{	

			printf("\n달라요.");
		}
*/		
		
	}	
	else 				//이상한 문자 입력. 타자프로그램 종료
	{
		printf("Wrong letter. Exit the program.\n");
		exit(1);
	}
	
	return 0;
}

