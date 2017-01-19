#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[400];
int length;

int main(){
    length = atoi(getenv("CONTENT_LENGTH"));
    fgets(str, length+1, stdin);
    str[length] = '\0';

    printf("Content-Type:text/html\n\n");
    printf("<html>");
    printf("<body bgcolor=\"#D9D5D9\"><h3>");
   // printf("%s\n <br>", str);

    char *ptr = strstr(str, "=");
    ptr = ptr+1;
    ptr = strtok(ptr, "&");
    char *user = ptr;
    //printf("%s\n <br>", user);

    ptr = strtok(NULL, "&");
    char *password = ptr;
    password = password+9;

    ptr = strtok(NULL, "\0");
    char *hidden = ptr;
    hidden = hidden+5;
    //printf("%s\n <br>", password);
    //printf("%s\n <br>", hidden);
    

    

    char line[500];
    FILE *fptr = fopen("users.txt","r");
    fgets(line, 499, fptr);	
    line[strlen(line)-1] = '\0';
    if(strcmp(user, line)!=0){
      while(1){
        if(feof(fptr)){
          printf("<font face=\"Comic sans Ms\"> <center>");
          printf("Sorry, your user name or password is wrong. <br> <br>");
          printf("Back to the login page: <br><br>");
          printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/login.html\">");
          printf("<input type=\"submit\" value=\"GO BACK!\">");
          printf("</form> Back to the landing page: <br><br>");
          printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/welcome.html\">");
          printf("<input type=\"submit\" value=\"GO BACK!\">");
          printf("</form> </center> </font>");
	        //printf("nothing match the user name\n");
	        exit(0);
	      }
        else{
          int i;
          for(i=0; i<4; i++)	fgets(line, 499, fptr);
          line[strlen(line)-1] = '\0';
          if(strcmp(user, line) == 0){	
	          fgets(line, 499, fptr);
            line[strlen(line)-1] = '\0';
	            if(strcmp(password, line)==0){
                printf("<font face=\"Comic sans Ms\"> <center>");
                printf("<br><br><br>You have logged in your account successfully! <br><br>");
                //printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/seefriends.cgi\" method=\"post\">");
                //printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/makefriends.py\">");
		printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/dashboard.py\" method=\"post\">");
                printf("<input type=\"hidden\" name=\"user\" value=\"%s\">", user);
                printf("<br><br><input type=\"submit\" value=\"Go Dashboard\">");
                printf("</center> </font>");
	              //printf("match\n");
                exit(0);
	            }
	        }
        }	  
      }
    }
    else{
      fgets(line, 499, fptr);
      line[strlen(line)-1] = '\0';
      if(strcmp(password, line)==0){
	      printf("<font face=\"Comic sans Ms\"> <center>");
        printf("<br><br> You has logged in your account successfully! <br><br>");
        //printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/seefriends.cgi\" method=\"post\">");
        //printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/makefriends.py\">");
	printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/cgi-bin/dashboard.py\" method=\"post\">");
        printf("<input type=\"hidden\" name=\"user\" value=\"%s\">", user);
        printf("<br><br><input type=\"submit\" value=\"Go Dashboard\">");
        printf("</center> </font>");
	      exit(0);
      }
      else{
        printf("<font face=\"Comic sans Ms\"> <center>");
        printf("Sorry, your user name or password is wrong <br> <br>");
        printf("Back to the login page: <br><br>");
        printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/login.html\">");
        printf("<input type=\"submit\" value=\"GO BACK!\">");
        printf("</form> Back to the landing page: <br><br>");
        printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/welcome.html\">");
        printf("<input type=\"submit\" value=\"GO BACK!\">");
        printf("</form> </center> </font>");
        //printf("password not match\n");
        exit(0);
      }	
    }
    fclose(fptr);
    printf("</h3></body> </html>");
    return 0;
}

