#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "buffer.h"
#include "consumer.h"
#include "producer.h"

int main(int argc, char *argv[]) {
    int sleepTime;
    int numProducers;
    int numConsumers;
    int createdProducers;
    int createdConsumers;
    int i;
    //int threadCount;

    // 1. Get command line arguments argv[1], argv[2], argv[3]

    if (argc != 4) {
        printf("Invalid number of arguments!\n\r");
        return 1;
    }

    sleepTime = atoi(argv[1]);
    numProducers = atoi(argv[2]);
    numConsumers = atoi(argv[3]);

    if (sleepTime <= 0) {
        printf("Invalid sleep time!\n\r");
        return 1;
    }

    if (numProducers <= 0) {
        printf("Invalid number of producers!\n\r");
        return 1;
    }

    if (numConsumers <= 0) {
        printf("Invalid number of consumers!\n\r");
        return 1;
    }

    pthread_t producers[numProducers];
    pthread_t consumers[numConsumers];

    // 2. Initialize buffer

    initialize();

    // 3. Create producer thread(s)
    
    for (createdProducers = 0; createdProducers < numProducers; createdProducers++) {
        pthread_create(&producers[createdProducers], NULL, &producer, NULL);
    }
    
    // 4. Create consumer thread(s)

    for (createdConsumers = 0; createdConsumers < numConsumers; createdConsumers++) {
        pthread_create(&consumers[createdConsumers], NULL, &consumer, NULL);
    }
    
    // 5. Sleep
    
    sleep(sleepTime);

    for (i = 0; i < createdProducers; ++i) {
        pthread_cancel(producers[i]);
        pthread_join(producers[i], NULL);
    }

    for (i = 0; i < createdConsumers; ++i) {
        pthread_cancel(consumers[i]);
        pthread_join(consumers[i], NULL);
    }

    // 6. Exit

    // Deinitialize buffer
    deinitialize();

    return 0;
}
