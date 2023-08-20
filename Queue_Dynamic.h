#ifndef QUEUE_DYNAMIC_H
#define QUEUE_DYNAMIC_H


#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct{
    void **QueueArray;
    uint32 MaxElement;
    uint32 CountElement;
    sint32 Front;
    sint32 Rear;
}Queue_D;


typedef enum{
    QUEUE_OK = 0,
    QUEUE_NOK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL,
}Queue_Status;


 Queue_D *QueueCreate(uint32 Count, Queue_Status *status);
//Queue_Status QueueCreate(Queue_D *pqueue, uint32 Size);

Queue_Status QueueDestroy(Queue_D *pqueue);

Queue_Status QueueInsert(Queue_D *pqueue, void *Value);

void *QueueDelete(Queue_D *pqueue, Queue_Status *status);

void *QueueFront(Queue_D *pqueue, Queue_Status *status);

void *QueueRear(Queue_D *pqueue, Queue_Status *status);

uint32 QueueCount(Queue_D *pqueue, Queue_Status *status);







#endif // QUEUE_DYNAMIC_H
