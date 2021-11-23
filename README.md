## FreeRTOS Cellular Interface Community Supported Ports

This repository contains the cellular module ports supported by FreeRTOS community members. We welcome the contribution to expand the catalog of medems.

### Contribute a cellular module port

1. Fork the ```FreeRTOS/FreeRTOS-Cellular-Interface``` repository.
2. Write code for your cellular module.  
    For details, see [Porting the Cellular Interface Library to another Modem](https://www.freertos.org/cellular-porting-guide.html).
3. Do the following to add a new cellular module:  
   - Create a new folder for your cellular module in the root folder and create an ```README.md``` file at the top level of the module port folder.
   - [Optional] If you are contributing a new cellular module with supporting demos, create a new demo in the cellular demo repository and update the ```README.md``` in the root folder.
4. The a ```README.md``` should tell the reader the following:
    1. Hardware information: Give the reader a cellular module introduction and the steps to setup the hardware environment.
    2. Objectives: Tell the reader a high-level summary of what steps they need to take and how to use this port. 
    3. Relevant information: Tell the reader what they should read or take care if they would dive deeper.
5. Raise a Pull Request (PR). Maintainers and other contirbutors will review your PR. Please be proactive in the conversation and make the requested changes. The code will be merged after PR is approved. 

## License

The FreeRTOS Cellular Interface library is distributed under MIT open source license. The code in this repository is licensed under the MIT License. See the [LICENSE](https://github.com/FreeRTOS/FreeRTOS-Kernel-Community-Supported-Ports/blob/main/LICENSE) file.
