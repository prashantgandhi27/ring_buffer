/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       02/14/2022
********************************************************************************
*  \file       ring_cfg.h
*
*  \brief      Defines for ring buffer.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#ifndef __RING_CFG_H__
#define __RING_CFG_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* Type of the ring buffer */
typedef uint32_t RING_BUFFER_TYPE;

/* Size of the ring buffer */
#define  RING_BUFFER_SIZE  (10U)

/* Define NULL pointer */
#define RING_NULL          (void *)(0)

#ifdef __cplusplus
}
#endif


#endif /* __RING_CFG_H__ */