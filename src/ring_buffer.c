/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       02/14/2022
********************************************************************************
*  \file       ring_buffer.c
*
*  \brief      This files contains ring buffer function definations.
*
*  \details    This version of ring buffer does not make use of buffer
*              size to check whether ring is empty or full. Instead it reserves
*              one space for that. Meaning, when ring buffer size is given 10,
*              ring can hold only 9 elements in buffer at a time. 
*
*  \note       VERSION - 0.1.0
*
*******************************************************************************/
#include <assert.h>

#include "ring_buffer.h"

/******************************************************************************/
RING_BUFFER *CreateRingBuffer(uint32_t *buffer, uint32_t ringSize)
{
    assert(buffer != RING_NULL);
    assert(ringSize > 0);

    RING_BUFFER *localRingPtr = (RING_BUFFER *)malloc(sizeof(RING_BUFFER));
    localRingPtr->buffer = buffer;
    localRingPtr->mFront = 0;
    localRingPtr->mRear = 0;
    localRingPtr->size = ringSize;

    return localRingPtr;
}

/******************************************************************************/
bool RingInsert(RING_BUFFER *ringBuffer, uint32_t data)
{
    assert(ringBuffer != RING_NULL);

    bool status = false;

    if (RingFull(ringBuffer) == false)
    {
        ringBuffer->mRear = (ringBuffer->mRear + 1) % ringBuffer->size;
        ringBuffer->buffer[ringBuffer->mRear] = data;

        status = true;
    }

    return status;
}

/******************************************************************************/
bool RingRemove(RING_BUFFER *ringBuffer, uint32_t *data)
{
    assert(ringBuffer != RING_NULL);

    bool status =  false;

    if (RingEmpty(ringBuffer) == false)
    {
        ringBuffer->mFront = (ringBuffer->mFront + 1) % ringBuffer->size;
        *data = ringBuffer->buffer[ringBuffer->mFront];

        status = true;
    }

    return status;
}

/******************************************************************************/
uint32_t RingUsedCount(RING_BUFFER *ringBuffer)
{
    assert(ringBuffer != RING_NULL);

    uint32_t count = 0;

    if (RingFull(ringBuffer) == true)
    {
        count = ringBuffer->size - 1;
    }
    else if (RingEmpty(ringBuffer) == true)
    {
        count = 0;
    }
    else
    {
        uint32_t localIdx = ringBuffer->mFront;

        while (localIdx != ringBuffer->mRear)
        {
            count++;
            localIdx = (localIdx + 1) % ringBuffer->size;
        }
    }

    return count;
}

/******************************************************************************/
bool RingClear(RING_BUFFER *ringBuffer)
{
    assert(ringBuffer != RING_NULL);

    bool status =  false;
    uint32_t data = 0;

    while (!RingEmpty(ringBuffer))
    {
        RingRemove(ringBuffer, &data);
    }

    if(RingEmpty(ringBuffer) == true)
    {
        status = true;
    }

    return status;
}

/******************************************************************************/
bool RingFull(RING_BUFFER *ringBuffer)
{
    assert(ringBuffer != RING_NULL);

    bool status = false;

    if (((ringBuffer->mRear + 1) % ringBuffer->size) == ringBuffer->mFront)
    {
        status = true;
    }

    return status;
}

/******************************************************************************/
bool RingEmpty(RING_BUFFER *ringBuffer)
{
    assert(ringBuffer != RING_NULL);

    bool status = false;

    if (ringBuffer->mRear == ringBuffer->mFront)
    {
        status =  true;
    }

    return status;
}