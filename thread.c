{ 
printf("thread 1 returning ... \n"); 
int *p = (int*)malloc(sizeof(int)); 
*p = 1; 
return (void*)p;
 }
void *thread2( void *arg ) {
printf("thread 2 exiting ...\n"); 
int *p = (int*)malloc(sizeof(int)); 
*p = 2;
 pthread_exit((void*)p); 
}
void *thread3( void *arg )
 { while ( 1 )
{ 
// printf("thread 3 is running ...\n");
//  sleep(1);
//   }
//   return NULL; 
//   }
