#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[500];
int length;

int main(){
    length = atoi(getenv("CONTENT_LENGTH"));
    fgets(str, length+1, stdin);
    str[length] = '\0';

    printf("Content-Type:text/html\n\n");
    printf("<html>");
    printf("<body bgcolor=\"pink\"><h3>");
    //printf("%s\n <br>", str);

    char *ptr = strstr(str, "=");
    ptr = ptr+1;
    ptr = strtok(ptr, "&");
    char *user = ptr;
    //printf("%s\n <br>", user);

    ptr = strtok(NULL, "&");
    char *fullName = ptr;
    fullName = fullName + 9;
    //printf("%s <br>", fullName);

    ptr = strtok(NULL, "&");
    char *descrip = ptr;
    descrip = descrip + 12;
    //printf("%s <br>", descrip);

    ptr = strtok(NULL, "\0");
    char *password = ptr;
    password = password+9;
    //printf("%s\n <br>", password);
    

    

    char line[500], line2[500];
    FILE *fptr = fopen("users.txt","r");
    fgets(line, 499, fptr); 
    line[strlen(line)-1] = '\0';
    if(strcmp(user, line)==0){
          printf("<font face=\"Comic sans Ms\"> <center>");
          printf("Sorry, your user name has already existed. Please try again. <br> <br>");
          printf("Back to the login page: <br><br>");
          printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/login.html\">");
          printf("<input type=\"submit\" value=\"GO BACK!\">");
          printf("</form> Back to the landing page: <br><br>");
          printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/welcome.html\">");
          printf("<input type=\"submit\" value=\"GO BACK!\">");
          printf("</form> </center> </font>");
          //printf("user name exists <br>");
          exit(0);
    }
    else{
      while(1){
        int i;
        for(i=0; i<4; i++)    fgets(line, 499, fptr);
        line[strlen(line)-1] = '\0';
        if(strcmp(user, line)==0){
          printf("<font face=\"Comic sans Ms\"> <center>");
          printf("Sorry, your user name has already existed. Please try again. <br> <br>");
          printf("Back to the login page: <br><br>");
          printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/login.html\">");
          printf("<input type=\"submit\" value=\"GO BACK!\">");
          printf("</form> Back to the landing page: <br><br>");
          printf("<form action=\"http://cgi.cs.mcgill.ca/~cwang84/welcome.html\">");
          printf("<input type=\"submit\" value=\"GO BACK!\">");
          printf("</form> </center> </font>");
          //printf("user name exists <br>");
          exit(0);
        }
        else if(feof(fptr)){
          //printf("okey to register");
          fclose(fptr);
          FILE *open = fopen("users.txt", "a");
          fprintf(open, "%s\n", user);   fprintf(open, "%s\n", password);
          fprintf(open, "%s\n", fullName);  fprintf(open, "%s\n", descrip);
          fclose(open);
          printf("<font face=\"Comic sans Ms\"> <center>");
          printf("<br><br> Now you created your account successfully. Please to login! :D <br><br>");
          printf("<a href=\"http://cgi.cs.mcgill.ca/~cwang84/login.html\" target=\"blank\"><font color=\"grey\"> Login now! </font></a>");
          
          FILE *p = fopen("friends.txt", "a");
          fprintf(p, "%s\n", user);
          fclose(p); 
          
          //printf("okey <br>");
          exit(0);  
        }
        else    continue;
      }
    }
    fclose(fptr);
    printf("</h3></body> </html>");
    return 0;
}


