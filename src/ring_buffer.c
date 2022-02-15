/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       02/14/2022
********************************************************************************
*  \file       ring_buffer.c
*
*  \brief      TODO
*
*  \details    TODO
*
*  \note       TODO
*
*******************************************************************************/

#include "ring_buffer.h"

RING_BUFFER *CreateRingBuffer(uint32_t *buffer, uint32_t ringSize)
{
    RING_BUFFER *localRingPtr = (RING_BUFFER *)malloc(sizeof(RING_BUFFER));
    localRingPtr->buffer = buffer;
    localRingPtr->mFront = 0;
    localRingPtr->mRear = 0;
    localRingPtr->size = ringSize;

    return localRingPtr;
}

bool RingInsert(RING_BUFFER *ringBuffer, uint32_t data)
{
    bool status = false;

    if (RingFull(ringBuffer) == false)
    {
        ringBuffer->mRear = (ringBuffer->mRear + 1) % ringBuffer->size;
        ringBuffer->buffer[ringBuffer->mRear] = data;

        status = true;
    }

    return status;
}

bool RingRemove(RING_BUFFER *ringBuffer, uint32_t *data)
{
    bool status =  false;

    if (RingEmpty(ringBuffer) == false)
    {
        ringBuffer->mFront = (ringBuffer->mFront + 1) % ringBuffer->size;
        *data = ringBuffer->buffer[ringBuffer->mFront];

        status = true;
    }

    return status;
}

bool RingFull(RING_BUFFER *ringBuffer)
{
    bool status = false;

    if (((ringBuffer->mRear + 1) % ringBuffer->size) == ringBuffer->mFront)
    {
        status = true;
    }

    return status;
}

bool RingEmpty(RING_BUFFER *ringBuffer)
{
    bool status = false;

    if (ringBuffer->mRear == ringBuffer->mFront)
    {
        status =  true;
    }

    return status;
}