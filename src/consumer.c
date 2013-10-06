#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "buffer.h"
#include "consumer.h"

void *consumer(void *param) {
    buffer_item item;

    while (true) {
        // sleep for a random period of time
        sleep(rand()%10);
        if (remove_item(&item))
            printf("Error occured during removal");
        else
            printf("consumer consumed %d\n", item);
    }
}
