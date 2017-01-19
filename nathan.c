#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
char line[500];
int n = atoi(getenv("CONTENT_LENGTH"));
fgets(line, n+1, stdin);
printf("Content-Type:text/html\n\n");
printf("<html><body>");
printf("<table align=\"center\" width=\"100%\"><center>");
printf("<tr><td>hello nathan</td><td>hello mia</td></tr>");
printf("<tr><td>hello world</td><td>hello auggi</td></tr></center></table>");
printf("<bt>%s<br>",line);
printf("welcome &lt/br&gt");
printf("</body></html>");
return 0;
}
