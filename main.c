#include <stdio.h>

#include "ring_cfg.h"
#include "ring_buffer.h"

uint32_t Buffer[RING_BUFFER_SIZE] = {0};

void *RingBufferPtr;

int main(void)
{
    uint32_t insertData = 1;
    uint32_t removeData = 0;

    RingBufferPtr = CreateRingBuffer(Buffer, RING_BUFFER_SIZE);

    while (RingFull(RingBufferPtr) == false)
    {
        RingInsert(RingBufferPtr, insertData);
        insertData++;
    }

    while (RingEmpty(RingBufferPtr) == false)
    {
        RingRemove(RingBufferPtr, &removeData);
        printf("Data = %d \n", removeData);
    }

    return 0;
}