In order to create a TCP server on the STM32 microcontroller, lwIP was activated with STM32CubeMX.
Since it was desired to assign an ip to the device, “LWIP_DHCP (DHCP Module)” was disabled from the lwIP general settings and thus an ip assignment was performed by the user.
It is necessary to specify an ip address in the same domain as the device used as a client. 
In order to do this, the IPv4 address of the ethernet connection was found out by typing the command “ipconfig” at the command prompt, and the device was given an ip address based on this ip address. The computer connection to the STM32 was successfully created by setting the necessary pins for the Ethernet cable connection. 
In order to test this connection, a ping operation was performed by typing > ping <ip address>.
FreeRTOS was activated to perform tcp server operations in a thread.
A task named ”defaulTask“ was created and its priority was set to ”osPriorityNormal". These options were saved so that everything else could not be changed.
The server initilization was performed by calling the ”tcpserver_init()“ function in the thread named ”defaultTask".
