   
   ##
   The GET method performs the process of sending the data in the form with the page address clearly, that is, in a format that everyone can see. We can see if data has      been sent in the “Network” section by saying "Inspect". If a button is pressed, the data is added to the address using the GET method, and the data added to this          address is processed by using the STM32 microcontroller.
   ##
 - http://169.254.228.35/index.html?baud=115200&parity=None&data=8&stop=1&hardware=None&send=Test
   ##
   
   In this application, the file named “index.html” contains the UART interface.
   The data sent after the file name are the settings available in the form.
   In the incoming file request, if the file name is "index.html" a parsing operation is performed according to the "? & =” symbols.
   The parsed data is compared with the "strcmp" function, and it adjusts the parameters of the UART handler structure depending on which value it is.
