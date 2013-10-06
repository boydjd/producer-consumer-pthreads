#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "buffer.h"
#include "producer.h"

void *producer(void *param) {
    buffer_item item;

    while (true) {
        // sleep for a random period of time
        sleep(rand()%10);
        // generate a random number
        item = rand();
        if (insert_item(item))
            printf("Error occured during insertion.");
        else
            printf("producer produced %d\n", item);
    }
}
