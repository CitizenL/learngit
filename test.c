#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1024
extern int optind;
int getopt(int argc, char *argv[],const char *optstring);

int main(int argc, char *argv[])
{
    char *pstr;
    char buf[BUF_SIZE+1];
    int fd,openFlags,cnt;
    int opt;

    openFlags =  O_WRONLY | O_CREAT | O_TRUNC;
    while((opt = getopt(argc,argv,":a")) != -1){
	switch (opt){
	    case 'a' : openFlags = O_WRONLY | O_CREAT | O_APPEND; break;
	    default : openFlags =  O_WRONLY | O_CREAT | O_TRUNC; break; 
	}
    }
    if(optind < argc)
	fd = open(argv[optind],openFlags,S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IWOTH | S_IROTH);
    while( (cnt = read(STDIN_FILENO,buf,BUF_SIZE)) != 0){
	write(fd,buf,cnt);
	//printf("Write %d chunks\n",cnt);
	}
    return 0;
}
