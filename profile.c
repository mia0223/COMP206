#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(){
	char *friends, *me;	char input[500], str[500], temp[500];
	int n = atoi(getenv("CONTENT_LENGTH"));
	fgets(input, n+1, stdin);
	friends = input;	 friends = friends + 7;
	strcpy(temp, friends);
	me = strstr(friends, "=");
	me = me+1;
	printf("Content-Type: text/html\n\n");
	//printf("input---%s\n<br>", input);
	//printf("me---%s<br>", me);
	//printf("%s<br>", temp);
	int i;
	for(i=0; i<strlen(friends); i++){
		if(temp[i] == '%'){
			str[i] = '\0';
			//str[i] = temp[i];	str[i+1] = temp[i+1];	
			break;
		}
		else if(temp[i] == '&'){
			str[i] = '\0';
			break;
		}
		str[i] = temp[i];
	}
	//printf("%d<br>", strlen(str));
	//if(str[strlen(str)-4] == '%')	str[strlen(str)-4] = '\0';
	//else	str[strlen(str)-2] = '\0';
	
	printf("<html><head><title>See Friends</title></head>");
	printf("<body bgcolor=\"#D9D5D9\"> <h3> <center> <font face=\"Comic sans Ms\">");
	//printf("friend---%s<br>", str);
	printf("<h2>Profile of %s</h2>", str);

	char line[500];
	FILE *ptr = fopen("users.txt", "r");
	fgets(line, 499, ptr);
	while(!feof(ptr)){
		line[strlen(line)-1] = '\0';
		//printf("test---%s<br>", line);
		if(strcmp(line, str) == 0){
			printf("User Name: %s <br>", str);
			fgets(line, 499, ptr);
			fgets(line, 499, ptr);
			printf("Full Name: %s <br>", line);
			fgets(line, 499, ptr);
			//printf("Job Description: %s <br>", line);
			break;
		}
		else{
			int i;
			for(i=0; i<3; i++)
				fgets(line, 499, ptr);
		}
		fgets(line, 499, ptr);
	}

	char cpy[500];
	for(i=0; i<strlen(line); i++){
		if(line[i] == '+')	line[i] = ' ';
	}
	printf("Job Description: %s <br>", line);

	fclose(ptr);
	printf ("<br> <br>");
	printf ("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/dashboard.py\" method=\"post\">");
	printf ("<input type=\"hidden\" name=\"user\" value=\"%s\">", me);
	printf ("<input type=\"submit\" value=\"Go Back To Dashboard\">");
	printf("</center></h3></body>");
	return 0;
}
