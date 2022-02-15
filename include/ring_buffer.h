/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       02/14/2022
********************************************************************************
*  \file       ring_buffer.h
*
*  \brief      TODO
*
*  \details    TODO
*
*  \note       TODO
*
*******************************************************************************/
#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ring_buffer
{
   uint32_t *buffer;
   uint32_t mFront;
   uint32_t mRear;
   uint32_t size;
} RING_BUFFER;

RING_BUFFER *CreateRingBuffer(uint32_t *buffer, uint32_t ringSize);

bool RingInsert(RING_BUFFER *ringBuffer, uint32_t data);

bool RingRemove(RING_BUFFER *ringBuffer, uint32_t *data);

bool RingFull(RING_BUFFER *ringBuffer);

bool RingEmpty(RING_BUFFER *ringBuffer);

#ifdef __cplusplus
}
#endif


#endif /* __RING_BUFFER_H__ */