# Quectel GSM cellular modules support

This port is contributed by [1NCE](https://github.com/1NCE-GmbH) 

It supports Quectel GSM Modules according to [Quectel_GSM_TCP(IP)_Recommended_Process_V2.0](https://www.quectel.com/download/quectel_gsm_tcpip_recommended_process_v2-0/) 

Tested with:
   * [Quectel M95](https://www.quectel.com/product/gsm-gprs-m95/)
   * [Quectel M66](https://www.quectel.com/product/gsm-gprs-m66/)


## How to use this port?
You can reference the demos in [FreeRTOS repository](https://github.com/FreeRTOS/FreeRTOS/tree/main/FreeRTOS-Plus/Demo/FreeRTOS_Cellular_Interface_Windows_Simulator) and create a demo for this porting. The flag CELLULAR_MODEM_NO_EPS_NETWORK should be added to cellular_config.h

## Hardware Setup
 The development was done using [Quectel GSM EVB Kit](https://www.quectel.com/product/gsm-nb-iot-evb-kit) with M95FA-TEA-03-STDN and M66FA-TEA-04-STDN
