/*******************************************************************************
 * Copyright (C) 2016 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 * $Date: 2017-10-06 15:44:45 -0500 (Fri, 06 Oct 2017) $ 
 * $Revision: 31227 $
 *
 ******************************************************************************/
 
#ifndef _USBIO_HWOPT_H_
#define _USBIO_HWOPT_H_

#include "mxc_config.h"
#include "usbhs_regs.h"

/* Configuration options for MUSBHSFC */
typedef struct {
  unsigned int enable_hs; /* 0 = full-speed only, otherwise high-speed if negotiated */
  void (*delay_us)(unsigned int usec); /* User-supplied function to delay usec micro-seconds */
  int (*init_callback)(void); /* User-supplied function for initializing the USB block */
  int (*shutdown_callback)(void); /* User-supplied function for shutting down the USB block */
} maxusb_cfg_options_t;

#define MAXUSB_ENTER_CRITICAL() __disable_irq()
#define MAXUSB_EXIT_CRITICAL() __enable_irq()

/** 
 * @brief Put the transceiver into a low power state.
 */
void usb_sleep(void);

/** 
 * @brief Power up the USB transceiver, must be called once the device wakes from sleep.
 */
void usb_wakeup(void);

/** 
 * @brief Send a remote wakeup signal to the host.
 */
void usb_remote_wakeup(void);

/*
 * @brief USB internal DMA engine interrupt handler
 */
void usb_dma_isr(void);

#endif /* _USBIO_HWOPT_H_ */
