#include <stdio.h>

#include "ring_buffer.h"

RING_BUFFER_TYPE Buffer[RING_BUFFER_SIZE] = {0};

void *RingBufferPtr = RING_NULL;

int main(void)
{
    uint32_t insertData = 1;

    RingBufferPtr = CreateRingBuffer(Buffer, RING_BUFFER_SIZE);

    while (!RingFull(RingBufferPtr))
    {
        RingInsert(RingBufferPtr, (RING_BUFFER_TYPE)(insertData++));
    }

    printf("Total elements in ring = %d \n", RingUsedCount(RingBufferPtr));

    RingClear(RingBufferPtr);

    printf("Total elements in ring after clear = %d \n", RingUsedCount(RingBufferPtr));

    free(RingBufferPtr);

    RingBufferPtr = RING_NULL;

    if (RING_NULL == RingBufferPtr)
    {
        printf("Ring successfully deleted. \n");
    }

    return 0;
}