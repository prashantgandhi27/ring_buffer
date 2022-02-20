#include <stdio.h>

#include "ring_cfg.h"
#include "ring_buffer.h"

uint32_t Buffer[RING_BUFFER_SIZE] = {0};

void *RingBufferPtr = RING_NULL;

int main(void)
{
    uint32_t insertData = 1;
    uint32_t removeData = 0;

    RingBufferPtr = CreateRingBuffer(Buffer, RING_BUFFER_SIZE);

    while (!RingFull(RingBufferPtr))
    {
        RingInsert(RingBufferPtr, insertData++);
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