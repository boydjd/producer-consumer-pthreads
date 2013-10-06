/* buffer.h */
#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#define BUFFER_SIZE 5

typedef int buffer_item;

int initialize();
int deinitialize();
int insert_item(buffer_item item);
int remove_item(buffer_item *item);

#endif
