/* Copyright 2016, Gerardo Puga (UNLP)
 *
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _OS_ARCH_H_
#define _OS_ARCH_H_

/** \brief FreeOSEK Os Architecture Dependent Header File
 **
 ** This file is included form os.h and defines macros
 ** and types which depend on the architecture.
 **
 ** \file sparcV8/Os_Arch.h
 ** \arch sparcV8
 **
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Global
 ** @{ */

/*==================[inclusions]=============================================*/


#include "Os_Internal_Arch_Cpu.h"


/*==================[macros]=================================================*/


/** \brief Enable All Interrupts Arch
 **/
#define EnableAllInterrupts_Arch() { sparcEnableAllInterrupts(); }


/** \brief Disable All Interrupts Arch
 **/
#define DisableAllInterrupts_Arch() { sparcDisableAllInterrupts(); }


/** \brief Resume All Interrupts Arch
 **
 ** This macro shall resume (enable) all interrupts.
 **/
#define ResumeAllInterrupts_Arch() { sparcEnableAllInterrupts(); }


/** \brief Suspend All Interrupts Arch
 **
 ** This macro shall suspend (disable) all interrupts.
 **/
#define SuspendAllInterrupts_Arch() { StartOs_Arch(); sparcDisableAllInterrupts(); }


/** \brief Resume OS Interrupts Arch
 **
 ** This macro shall resume (enable) all interrupts configured on the
 ** FreeOSEK OIL configuration file as ISR2.
 **/
#define ResumeOSInterrupts_Arch() { sparcEnableISR2Interrupts(); }


/** \brief Suspend OS Interrupts Arch
 **
 ** This macro shall suspend (disable) all interrupts configured on the
 ** FreeOSEK OIL configuration file as ISR2.
 **/
#define SuspendOSInterrupts_Arch() { sparcDisableISR2Interrupts(); }


/*==================[typedef]================================================*/


/*==================[external data declaration]==============================*/


/*==================[external functions declaration]=========================*/


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef _OS_ARCH_H_ */

