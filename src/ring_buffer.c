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
*  \note       VERSION - 0.2.0
*
*******************************************************************************/
#include <assert.h>

#include "ring_buffer.h"

typedef struct ring_buffer
{
   RING_BUFFER_TYPE *buffer;
   uint32_t mFront;
   uint32_t mRear;
   uint32_t size;
} RING_BUFFER;

/******************************************************************************/
void *CreateRingBuffer(void *buffer, uint32_t ringSize)
{
    assert(ringSize > 0);

    RING_BUFFER *localRingPtr = (RING_BUFFER *)malloc(sizeof(RING_BUFFER));
    localRingPtr->buffer = (RING_BUFFER_TYPE *)buffer;
    localRingPtr->mFront = 0;
    localRingPtr->mRear = 0;
    localRingPtr->size = ringSize;

    return localRingPtr;
}

/******************************************************************************/
bool RingInsert(void *ringBuffer, RING_BUFFER_TYPE data)
{
   bool status = false;

   if (RingFull(ringBuffer) == false)
   {
      ((RING_BUFFER *)ringBuffer)->mRear = 
         (((RING_BUFFER *)ringBuffer)->mRear + 1) % ((RING_BUFFER *)ringBuffer)->size;
      ((RING_BUFFER *)ringBuffer)->buffer[((RING_BUFFER *)ringBuffer)->mRear] = data;

       status = true;
   }

   return status;
}

/******************************************************************************/
bool RingRemove(void *ringBuffer, uint32_t *data)
{
   bool status =  false;

   if (RingEmpty(ringBuffer) == false)
   {
      ((RING_BUFFER *)ringBuffer)->mFront = 
         (((RING_BUFFER *)ringBuffer)->mFront + 1) % ((RING_BUFFER *)ringBuffer)->size;
      *data = ((RING_BUFFER *)ringBuffer)->buffer[((RING_BUFFER *)ringBuffer)->mFront];

       status = true;
   }

   return status;
}

/******************************************************************************/
uint32_t RingUsedCount(void *ringBuffer)
{
   uint32_t count = 0;

   if (RingFull(ringBuffer) == true)
   {
      count = ((RING_BUFFER *)ringBuffer)->size - 1;
   }
   else if (RingEmpty(ringBuffer) == true)
   {
      count = 0;
   }
   else
   {
      uint32_t localIdx = ((RING_BUFFER *)ringBuffer)->mFront;

      while (localIdx != ((RING_BUFFER *)ringBuffer)->mRear)
      {
         count++;
         localIdx = (localIdx + 1) % ((RING_BUFFER *)ringBuffer)->size;
      }
   }

   return count;
}

/******************************************************************************/
bool RingClear(void *ringBuffer)
{
   bool status =  false;
   uint32_t data = 0;

   ((RING_BUFFER *)ringBuffer)->mFront = 0;
   ((RING_BUFFER *)ringBuffer)->mRear = 0;

   if(RingEmpty(ringBuffer) == true)
   {
      status = true;
   }

   return status;
}

/******************************************************************************/
bool RingFull(void *ringBuffer)
{
   bool status = false;

   if (((((RING_BUFFER *)ringBuffer)->mRear + 1) % ((RING_BUFFER *)ringBuffer)->size) == ((RING_BUFFER *)ringBuffer)->mFront)
   {
      status = true;
   }

   return status;
}

/******************************************************************************/
bool RingEmpty(void *ringBuffer)
{
   bool status = false;

   if (((RING_BUFFER *)ringBuffer)->mRear == ((RING_BUFFER *)ringBuffer)->mFront)
   {
      status =  true;
   }

   return status;
}