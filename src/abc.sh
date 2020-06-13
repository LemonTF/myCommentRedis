gcc ziplist.c  -DREDIS_TEST -std=c99 zmalloc.c sds.c endianconv.c util.c  -DZIPLIST_TEST  adlist.c sha1.c -g -o ziplist.out
