#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void myprint(char *str){
    char c;
    while((c = *str++) != '\0'){
        write(1, &c, 1);
    }
}


void *thread_func(void *arg){
    int is_child = *(int *)arg;
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&mutex);
        if(is_child){
            myprint("THIS IS THE CHILD THREAD PRINTING\n");
        } else {
            myprint("This is the parent thread printing\n");
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;
    int child = 1; 
    int parent = 0;
    
    pthread_create(&t1, NULL, thread_func, &child);
    pthread_create(&t2, NULL, thread_func, &parent);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    return 0;
}
