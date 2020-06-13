#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#define LOG(id,...) log(id,__LINE__,__VA_ARGS__)
void log(int id,int linenum,const char*fmt,...)
{
    va_list ap;
    char msg[1024]={0};
    int len;

    len =snprintf(msg,sizeof(msg),"[%d]test the log va_list:%d",id,linenum);
    va_start(ap,fmt);
    vsnprintf(msg+len,sizeof(msg)-len,fmt,ap);
    va_end(ap);
    printf("%s\n",msg);
}
#define assert(_e) ((_e)?(void)0 : (_serverAssert(#_e,__FILE__,__LINE__),_exit(1)))

void _serverAssert(const char *estr, const char *file, int line) {
    fprintf(stderr, "=== ASSERTION FAILED ===");
    fprintf(stderr, "==> %s:%d '%s' is not true",file,line,estr);
    *((char*)-1) = 'x';
}



int main()
{
    LOG(__LINE__,"this is a va_list test %d,%f",110,12.777);
    assert(1>2);
    while(1)sleep(1);
}
