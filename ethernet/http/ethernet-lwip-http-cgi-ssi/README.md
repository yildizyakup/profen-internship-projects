In order to create a UART interface as a web page, a file named cgiuart.html has been created. 
An html form is created in this file. 
The created form is likened to the serial port settings of the Tera Term program.
After the desired UART settings are selected, the data to be sent via UART is written in the text section at the bottom of the form and the “submit” button is clicked.
After this process, we can see the text sent in the terminal, but we need to check the terminal settings.
When parameters such as baud rate do not match, the values sent to the terminal may not appear.
The “CGIUART_Handler” function has been created to process the data sent from the web page. 
Thanks to the ”Handler“, the received form parameters (pcParam[...]) are compared with the ”strcmp" function and it is decided which parameter will be processed. 
If a match is achieved, the values in the form (pcValue[...]) are processed and the parameters of the UART handler structure are set. 
After this process is completed, cgiuart.the html file is exported as a return.
