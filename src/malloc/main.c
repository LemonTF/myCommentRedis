//#include "zmalloc.h"
#include <stdio.h>
//#include "sds.h"
#include <stdint.h>
#include <limits.h>
struct __attribute__ ((__packed__)) sdshdr64 {
    uint64_t len; /* used */
    uint64_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};

typedef struct zskiplistNode {
    char *ele;
    double score;
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned long span;
    } level[];
} zskiplistNode;


//struct __attribute__ ((__packed__)) sdshdr8 {
struct  sdshdr8 {
    uint8_t len; /* used */
    uint8_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};
struct  sdshdr18 {
    uint8_t len; /* used */
    uint8_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    int c;
    char buf[];
};


int main()
{
//    void * ptr=zmalloc(11);
//    int page = sysconf(_SC_PAGESIZE);
    printf("sds_8:%d\n",sizeof(struct sdshdr8));
    printf("sds_64:%d\n",sizeof(struct sdshdr64));
    printf("sds_18:%d\n",sizeof(struct sdshdr18));
    printf("zkiplist:%d\n",sizeof(struct zskiplistNode
));
    printf("LONG_MAX:%ld --LLONG_MAX:%lld\n",LONG_MAX,LLONG_MAX);
    return 0;
}
