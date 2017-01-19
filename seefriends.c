#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse(char line[], char temp[]);
//int checkSpace(char *token, char cpy[]);
char input[500];
char *me;

int main(){	
	//char me[] = "nathan";
	int n = atoi(getenv("CONTENT_LENGTH"));
	fgets(input, n+1, stdin);
	me = input;	me = me+5;

	printf("Content-Type: text/html\n\n");
	printf("<html><head><title>See Friends</title></head>");
	printf("<body bgcolor=\"#D9D5D9\"> <h3> <center> <font face=\"Comic sans Ms\">");
	//printf("hello world---%s\n <br>", me);


	char *token = (char*)malloc(500), *tk;
	char line[500], temp[500], cpy[500];
	FILE *fptr = fopen("friends.txt", "r");
	fgets(line, 499, fptr);
	while(!feof(fptr)){
		parse(line, temp);
//printf("temp---%s\n<br>", temp);
		if(strcmp(temp, me) == 0)
			break;
		fgets(line, 499, fptr);
		memset(temp, 0, 500);
	}

	//printf("me and my friends: %s\n<br>", line);
	printf("<h2>All My Friends</h2><br>");
	//printf("line---%s<br>", line);
	//printf("me1 length---%d<br>", strlen(line));

	line[strlen(line)-1] = '\0';
	//printf("me1 length---%d<br>", strlen(line));
	//printf("me---%s<br>", me);
	//printf("me2 length---%d<br>", strlen(me));

	if(strlen(line) == strlen(me)){
		printf("<br>You do not have any friend<br><br>");
		printf ("<form name=\"back\" action=\"http://cgi.cs.mcgill.ca/~cwang84/dashboard.py\" method=\"post\">");
		printf ("<input type=\"hidden\" name=\"user\" value=\"%s\">", me);
		printf ("<input type=\"submit\" value=\"Go Back To Dashboard\">");
		printf("</form>");

		fclose(fptr);
		printf("</h3></font></center></body></html>");
		exit(0);
	}

	token = strstr(line, " ");
	token = token+1;
	//printf("token---%s<br>", token);
	//printf("last---%d--mia<br>", *(token+strlen(token)-1));
	if(*(token+strlen(token)-1) == '\n'){
		printf ("<form name=\"profile\" action=\"http://cgi.cs.mcgill.ca/~cwang84/profile.cgi\" method=\"post\">");
		printf("My friend: %s <input type=\"checkbox\" name=\"friend\" value=\"%s\"> <br>", token, token);
	}
	else{	
		tk = strtok(token, " ");
		printf ("<form name=\"profile\" action=\"http://cgi.cs.mcgill.ca/~cwang84/profile.cgi\" method=\"post\">");
		while(tk != NULL){
			printf("My friend: %s <input type=\"checkbox\" name=\"friend\" value=\"%s\"> <br>", tk, tk);
			tk = strtok(NULL, " ");
		}
	}
	printf("<br>");
	printf ("<input type=\"hidden\" name=\"user\" value=\"%s\">", me);
	printf ("<input type=\"submit\" value=\"See Profile!\">");
	printf("</form>");

	printf ("<form name=\"back\" action=\"http://cgi.cs.mcgill.ca/~cwang84/dashboard.py\" method=\"post\">");
	printf ("<input type=\"hidden\" name=\"user\" value=\"%s\">", me);
	printf ("<input type=\"submit\" value=\"Go Back To Dashboard\">");
	printf("</form>");

	fclose(fptr);
	printf("</h3></font></center></body></html>");
	//free(token);*/
	return 0;
}

void parse(char line[], char temp[]){
	int i, len = strlen(line);
	for(i=0; i<len; i++){
		if(line[i] == ' ' || line[i] == '\n')
			break;
		temp[i] = line[i];
	}
	temp[strlen(temp)] = '\0';
}



