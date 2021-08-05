#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {

pid_t descendant_pid;
char *statement;
int count;

printf("Till now worked one proccess.\n");
descendant_pid = fork();

switch (descendant_pid) {
    case -1:
        printf("Forking didnt worked.\n");
        exit(1);

    case 0: //child
        statement = "I am descendant.";
        count = 5;
    break;

    default: //parent
        statement = "I am ancestor.";
        count = 5;
    break;
}
for (; count > 0; count--) {
puts(statement);
sleep(1);
}
}