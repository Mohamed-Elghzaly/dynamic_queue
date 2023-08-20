#include "Queue_Dynamic.h"


Queue_D *QueueCreate(uint32 Count, Queue_Status *status){
     Queue_D *pqueue = (Queue_D *)malloc(sizeof(Queue_D));
    *status = QUEUE_NOK;
    if(NULL == pqueue){
        *status = QUEUE_NULL;
    }
    else{
        pqueue->QueueArray = (void **)calloc(Count, sizeof(void *));
        if(NULL == (pqueue->QueueArray)){
            *status = QUEUE_NULL;
            free(pqueue);
        }
        else{
            pqueue->CountElement = 0;
            pqueue->Front = -1;
            pqueue->Rear = -1;
            pqueue->MaxElement = Count;
            *status = QUEUE_OK;
        }
    }
    return pqueue;
}

Queue_Status QueueInsert(Queue_D *pqueue, void *Value){
    Queue_Status status = QUEUE_NOK;
    if((NULL == pqueue) || (NULL == Value)){
        status = QUEUE_NULL;
    }
    else{
        if(pqueue->CountElement == pqueue->MaxElement){
            status = QUEUE_FULL;
        }
        else{
            (pqueue->Rear)++;
            if(pqueue->Rear == pqueue->MaxElement){
                pqueue->Rear = 0;
            }
            pqueue->QueueArray[pqueue->Rear] = Value;
            if(pqueue->CountElement == 0){
                pqueue->Front = 0;
                pqueue->CountElement = 1;
            }else{
                (pqueue->CountElement)++;
            }
            status = QUEUE_OK;
        }
    }
    return status;
}


void *QueueDelete(Queue_D *pqueue, Queue_Status *status){
    void *Value = NULL;
    if((NULL == pqueue) || ( NULL == status)){
        *status = QUEUE_NULL;
    }
    else{
        if(pqueue->CountElement == 0){
            *status = QUEUE_EMPTY;
        }
        else{
            Value = pqueue->QueueArray[pqueue->Front];
            (pqueue->Front)++;
            if(pqueue->Front == pqueue->MaxElement){
                pqueue->Front = 0;
            }
            if(pqueue->CountElement == 1){
                pqueue->Rear = -1;
                pqueue->CountElement = 0;
            }else{
                (pqueue->CountElement)--;
            }
            *status = QUEUE_OK;
        }
    }
    return Value;
}

void *QueueFront(Queue_D *pqueue, Queue_Status *status){
    void *Value = NULL;
    if((NULL == pqueue) || ( NULL == status)){
        *status = QUEUE_NULL;
    }
    else{
        if(pqueue->CountElement == 0){
            *status = QUEUE_EMPTY;
            Value = NULL;
        }
        else{
            Value = pqueue->QueueArray[pqueue->Front];
            *status = QUEUE_OK;
        }
    }
    return Value;
}

void *QueueRear(Queue_D *pqueue, Queue_Status *status){
    void *Value = NULL;
    if((NULL == pqueue) || ( NULL == status)){
        *status = QUEUE_NULL;
    }
    else{
        if(pqueue->CountElement == 0){
            *status = QUEUE_EMPTY;
            Value = NULL;
        }
        else{
            Value = pqueue->QueueArray[pqueue->Rear];
            *status = QUEUE_OK;
        }
    }
    return Value;
}


uint32 QueueCount(Queue_D *pqueue, Queue_Status *status){
    if((NULL == pqueue) || ( NULL == status)){
        *status = QUEUE_NULL;
    }
    else{}
    return (pqueue->CountElement);
}

Queue_Status QueueDestroy(Queue_D *pqueue){
    Queue_Status status = QUEUE_NOK;
    if(NULL == pqueue){
        status = QUEUE_NULL;
    }
    else{
        free(pqueue->QueueArray);
        free(pqueue);
        status = QUEUE_OK;
    }
    return status;
}









