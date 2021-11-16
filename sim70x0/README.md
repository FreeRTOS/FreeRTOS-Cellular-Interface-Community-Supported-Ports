# SIMCOM SIM7080 cellular modem support

This port is contributed by [xiewqja](https://github.com/xiewqja) in this [PR](https://github.com/FreeRTOS/FreeRTOS-Cellular-Interface/pull/6).

This folder contains SIM7080 cellular modem support for [FreeRTOS-Cellular-Interface](https://github.com/FreeRTOS/FreeRTOS-Cellular-Interface).<br> More information about the cellular modem can be found in the [website](https://www.simcom.com/product/SIM7080G.html).

## How to use this port?
You can reference the demos in [FreeRTOS repository](https://github.com/FreeRTOS/FreeRTOS/tree/main/FreeRTOS-Plus/Demo/FreeRTOS_Cellular_Interface_Windows_Simulator) and create a demo for this porting.

## SIM7080 specific config

Besides the configurations described in the [cellular interface document](https://www.freertos.org/cellular-demo.html#configure-cellular), SIM7080 cellular module porting needs the following extra configs.
|
| Configuration   |      Description      |  Value |
|-----------------|-----------------------|--------|
| CELLULAR_PDN_CONTEXT_ID_MIN | The minimum PDN context ID | 0 |
| CELLULAR_PDN_CONTEXT_ID_MAX | The maximum PDN context ID | 4 |
| CELLULAR_MAX_SEND_DATA_LEN | The socket send data length. | 1459 |
| CELLULAR_MAX_RECV_DATA_LEN | The socket receive data length. | 1459 |
| CELLULAR_IP_ADDRESS_MAX_SIZE | GethostByName is not supported. IP address is used to store the hostname. | The Maximum length of domain address |
| CELLULAR_CHECK_IS_PREFIX_CHAR | Override the default prefix check function | Referece the code example below |


<b>cellular_config.h example</b>

```C

/*
 * FreeRTOS V202111.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/**
 * @file cellular_config.h
 * @brief cellular config options.
 */

#ifndef __CELLULAR_CONFIG_H__
#define __CELLULAR_CONFIG_H__

/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/* Include logging header files and define logging macros in the following order:
 * 1. Include the header file "logging_levels.h".
 * 2. Define the LIBRARY_LOG_NAME and LIBRARY_LOG_LEVEL macros depending on
 * the logging configuration for DEMO.
 * 3. Include the header file "logging_stack.h", if logging is enabled for DEMO.
 */

#include "logging_levels.h"

/* Logging configuration for the Demo. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "CellularLib"
#endif

#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_INFO
#endif

/* Prototype for the function used to print to console on Windows simulator
 * of FreeRTOS.
 * The function prints to the console before the network is connected;
 * then a UDP port after the network has connected. */
extern void vLoggingPrintf( const char * pcFormatString,
                            ... );

/* Map the SdkLog macro to the logging function to enable logging
 * on Windows simulator. */
#ifndef SdkLog
    #define SdkLog( message )    vLoggingPrintf message
#endif

#include "logging_stack.h"

/************ End of logging configuration ****************/

/* This is a project specific file and is used to override config values defined
 * in cellular_config_defaults.h. */

/**
 * Cellular comm interface make use of COM port on computer to communicate with
 * cellular module on windows simulator, for example "COM5".
 * #define CELLULAR_COMM_INTERFACE_PORT    "...insert here..."
 */

/*
 * Default APN for network registration.
 * #define CELLULAR_APN                    "...insert here..."
 */

/*
 * PDN context id for cellular network.
 */
#define CELLULAR_PDN_CONTEXT_ID         ( CELLULAR_PDN_CONTEXT_ID_MIN )

/*
 * PDN connect timeout for network registration.
 */
#define CELLULAR_PDN_CONNECT_TIMEOUT    ( 100000UL )

/*
 * Overwrite default config for different cellular modules.
 */

/*
 * GetHostByName API is not used in the demo. IP address is used to store the hostname.
 * The value should be longer than the length of democonfigMQTT_BROKER_ENDPOINT in demo_config.h.
 */
#define CELLULAR_IP_ADDRESS_MAX_SIZE     /* Maximum length of domain addres. */

#define	CELLULAR_PDN_CONTEXT_ID_MIN		 0
#define	CELLULAR_PDN_CONTEXT_ID_MAX		 4

#define	CELLULAR_MAX_SEND_DATA_LEN			1459
#define	CELLULAR_MAX_RECV_DATA_LEN			1459

#define CELLULAR_CHECK_IS_PREFIX_CHAR( inputChar )                                 \
    ( ( ( ( int32_t ) isalpha( ( ( int8_t ) ( inputChar ) ) ) ) == 0 ) && \
      ( ( ( int32_t ) isdigit( ( ( int8_t ) ( inputChar ) ) ) ) == 0 ) && \
      ( ( inputChar ) != '+' ) && ( ( inputChar ) != '_' ) && ( ( inputChar ) != ' ' ) )
```

#endif /* __CELLULAR_CONFIG_H__ */

