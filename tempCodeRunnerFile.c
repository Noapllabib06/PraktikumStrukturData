#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define sizeofbuffer 5   // buffer size

int buffer[sizeofbuffer];
int in = 0, out = 0;

sem_t s, n, e;

void produce() {
    printf("Produce item...\n");
    sleep(1);
}

void append() {
    int item = rand() % 100;
    buffer[in] = item;
    printf("Append item %d ke buffer[%d]\n", item, in);
    in = (in + 1) % sizeofbuffer;
}

void take() {
    int item = buffer[out];
    printf("Take item %d dari buffer[%d]\n", item, out);
    out = (out + 1) % sizeofbuffer;
}

void consume() {
    printf("Consume item...\n\n");
    sleep(2);
}

void *producer(void *arg)
{
    while (1) {
        produce();
        sem_wait(&e);
        sem_wait(&s);
        append();
        sem_post(&s);
        sem_post(&n);
    }
    return NULL;
}

void *consumer(void *arg)
{
    while (1) {
        sem_wait(&n);
        sem_wait(&s);
        take();
        sem_post(&s);
        sem_post(&e);
        consume();
    }
    return NULL;
}

int main()
{
    pthread_t prod, cons;

    sem_init(&s, 0, 1);
    sem_init(&n, 0, 0);
    sem_init(&e, 0, sizeofbuffer);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&s);
    sem_destroy(&n);
    sem_destroy(&e);

    return 0;
}