int main( void )
 { 
pthread_t tid;
 void *ret;
 // thread 1 return 
pthread_create(&tid, NULL, thread1, NULL); 
pthread_join(tid, &ret);
 printf("thread return, thread id %X, return code:%d\n", tid, *(int*)ret); free(ret); 
// thread 2 exit 
pthread_create(&tid, NULL, thread2, NULL);
 pthread_join(tid, &ret); printf("thread return, thread id %X, return code:%d\n", tid, *(int*)ret); free(ret);
 // thread 3 cancel by other 
pthread_create(&tid, NULL, thread3, NULL); 
sleep(3); pthread_cancel(tid); pthread_join(tid, &ret);
 if ( ret == PTHREAD_CANCELED )
 printf("thread return, thread id %X, return code:PTHREAD_CANCELED\n", tid);
 else
printf("thread return, thread id %X, return code:NULL\n", tid);
}
