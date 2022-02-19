/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       02/14/2022
********************************************************************************
*  \file       ring_buffer.h
*
*  \brief      This files contains ring buffer function declaration.
*
*  \details    This version of ring buffer does not make use of buffer
*              size to check whether ring is empty or full. Instead it reserves
*              one space for that. Meaning, when ring buffer size is given 10,
*              ring can hold only 9 elements in buffer at a time. 
*
*  \note       VERSION - 0.1.0
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

/*!*****************************************************************************
*  \fn         RING_BUFFER *CreateRingBuffer(uint32_t *buffer, uint32_t ringSize)
*  \brief      Allocates and initializes a ring
*
*  \param[in]  buffer     - pointer to user's buffer
*  \param[in]  ringSize   - size of user's buffer
*
*  \retval     pointer to a ring if successful, else NULL
*
******************************************************************************/
RING_BUFFER *CreateRingBuffer(uint32_t *buffer, uint32_t ringSize);

/*!*****************************************************************************
*  \fn         bool RingInsert(RING_BUFFER *ringBuffer, uint32_t data)
*  \brief      Adds data to the specified ring
*
*  \param[in]  ringBuffer - pointer returned from CreateRingBuffer()
*  \param[in]  data       - the data to add to the ring
*
*  \retval     false - ring is full and data can not be inserted.
*              true  - data inserted successfully.
*
******************************************************************************/
bool RingInsert(RING_BUFFER *ringBuffer, uint32_t data);

/*!*****************************************************************************
*  \fn         RingRemove(RING_BUFFER *ringBuffer, uint32_t *data)
*  \brief      Removes a data from the specified ring
*
*  \param[in]  ringBuffer - pointer returned from CreateRingBuffer()
*  \param[out] data       - pointer to the data where removed data from the 
*                           ring should be stored.
*
*  \retval     false - ring is empty and data can not be removed.
*              true  - data removed successfully.
*
******************************************************************************/
bool RingRemove(RING_BUFFER *ringBuffer, uint32_t *data);

/*!*****************************************************************************
*  \fn         bool RingFull(RING_BUFFER *ringBuffer)
*  \brief      Determines if the specified ring is full. Specifically when
*              the ring is one less than full.  One more enring would result in 
*              a completely full buffer that is indistinguishable from an empty 
*              buffer.
*
*  \param[in]  ringBuffer - pointer returned from CreateRingBuffer()
*
*  \retval     true  - ring is full
*              false - ring is not full
*
******************************************************************************/
bool RingFull(RING_BUFFER *ringBuffer);

/*!*****************************************************************************
*  \fn         bool RingEmpty(RING_BUFFER *ringBuffer)
*  \brief      Determines whether the specified ring is empty or not
*
*  \param[in]  ringBuffer - pointer returned from ring_allocate()
*
*  \retval     true  - ring is empty
*              false - ring is not empty
*
******************************************************************************/
bool RingEmpty(RING_BUFFER *ringBuffer);

#ifdef __cplusplus
}
#endif


#endif /* __RING_BUFFER_H__ */