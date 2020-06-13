#include <unistd.h>
#include <sys/time.h>
#include "rax.h"
#include "stdio.h"
#include "util.h" //ll2string string2ll
static long long ustime(void) {
    struct timeval tv;
    long long ust;

    gettimeofday(&tv, NULL);
    ust = ((long long)tv.tv_sec)*1000000;
    ust += tv.tv_usec;
    return ust;
}

static long long mstime(void) {
    return ustime()/1000;
}

int main()
{
    //-----------------
    int a,b;
    printf("%p,%p\n",&a,&b);
    //------------------
    rax * r=raxNew();
    char * x;
    raxInsert(r,"foot",4,"lemon",(void**)&x);
    void * value = raxFind(r,"foot",4);
    printf("value=%s\n",value);
    raxInsert(r,"football",8,"lemon lemon",(void**)&x);
    char buf[32];int sz;
    for(int i=0;i<20;i++){
        long long v=mstime();
        sz=ll2string(buf,sizeof buf,v);
        raxInsert(r,buf,sz,buf,NULL);//raxInsert 中data 保存的是地址
        usleep(2000);
    }
    raxShow(r);
    //------------iterator------------
    raxIterator ri;
    raxStart(&ri,r);
    raxSeek(&ri,"^",NULL,0);//查找第一个。
    printf("first:%.*s,,,,%s\n",ri.key_len,ri.key,ri.data);
    //
    raxNext(&ri);//和当前相等。
    printf("second.%.*s,,,,%s\n",ri.key_len,ri.key,ri.data);
    raxNext(&ri);
    printf("Next.%.*s,,,,%s\n",ri.key_len,ri.key,ri.data);
    raxSeek(&ri,">",ri.key,ri.key_len);
    printf("seek>.%.*s,,,,%s\n",ri.key_len,ri.key,ri.data);
    raxSeek(&ri,"$",NULL,0);//查找最后一个。
    printf("Last:%.*s,,,,%s----eof:%d\n",ri.key_len,ri.key,ri.data,ri.flags&RAX_ITER_EOF);
    //raxSeek(&ri,">",ri.key,ri.key_len);
    raxNext(&ri);
    raxNext(&ri);
    printf("Last:%.*s,,,,%s----eof:%d\n",ri.key_len,ri.key,ri.data,ri.flags&RAX_ITER_EOF);
    raxStop(&ri);
    //-------------------------------
    raxFree(r);
    return 0;
}
