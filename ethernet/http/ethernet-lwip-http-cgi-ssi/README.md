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
<!DOCTYPE html>
<html>
<body>

<h1>Serial Port</h1>

<p>Serial port setup and connection</p>

<form action="/uart.cgi">
  <label for="baud">Baud:</label>
  <select name="baud" id="baud">
  <option value="115200">115200</option>
  <option value="9600">9600</option>
  <option value="19200">19200</option>
  <option value="38400">38400</option>
  <option value="57600">57600</option>
  </select>
  
  <br><br>
  
  <label for="parity">Parity:</label>
  <select name="parity" id="parity">
  <option value="None">None</option>
  <option value="Odd">Odd</option>
  <option value="Even">Even</option>
  <option value="Mark">Mark</option>
  <option value="Space">Space</option>
  </select>
  
  <br><br>
   
  <label for="data">Data Bits:</label>
  <select name="data" id="data">
  <option value="8">8 bits</option>
  <option value="7">7 bits</option>
  <option value="6">6 bits</option>
  <option value="5">5 bits</option>
  </select>
 
  <br><br>
   
  <label for="stop">Stop Bits:</label>
  <select name="stop" id="stop">
  <option value="1">1 bits</option>
  <option value="2">2 bits</option>
  </select>
 
  <br><br>
   
  <label for="hardware">Hardware Flow Control:</label>
  <select name="hardware" id="hardware">
  <option value="None">None</option>
  <option value="RTS/CTS">RTS/CTS</option>
  <option value="DTR/DSR">DTR/DSR</option>
  <option value="RS485-rts">RS485-rts</option>
  </select>
 
  <br><br>

  <label for="senddata">Send:</label>
  <input type="text" id="send" name="send" value="Test">
  
  <br><br>
  
  <input type="submit" value="Submit">
  
  </form>
  </body>
  </html>
