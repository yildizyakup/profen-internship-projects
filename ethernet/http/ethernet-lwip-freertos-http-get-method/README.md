## [eN]
The GET method performs the process of sending the data in the form with the page address clearly, that is, in a format that everyone can see. We can see if data has      been sent in the “Network” section by saying "Inspect". If a button is pressed, the data is added to the address using the GET method, and the data added to this          address is processed by using the STM32 microcontroller. As an example, the data added to the address bar can be shown as follows.
   
http://169.254.228.35/index.html?baud=115200&parity=None&data=8&stop=1&hardware=None&send=Test
   
In this application, the file named “index.html” contains the UART interface.
The data sent after the file name are the settings available in the form.
In the incoming file request, if the file name is "index.html" a parsing operation is performed according to the "? & =” symbols.
The parsed data is compared with the "strcmp" function, and it adjusts the parameters of the UART handler structure depending on which value it is.

## [tR]
GET metodu, formdaki verileri sayfa adresi açık bir şekilde yani herkesin görebileceği biçimde gönderme işlemi yapmaktadır. Bunu sayfa bağlantısını incele diyerek     “Network” kısmında veri gönderilip gönderilmediğini görebiliriz. Eğer ki bir butona basılırsa GET metodu sayesinde veriler adrese eklenir ve bu adrese eklenen veriler STM32 mikrodenetleyicisi ile işlenir. Adres çubuğuna eklenen veriler örnek olarak verilen url gibi gözükmektedir.  

http://169.254.228.35/index.html?baud=115200&parity=None&data=8&stop=1&hardware=None&send=Test  

Bu uygulamada “index.html” olarak isimlendirilen dosya UART arayüzünü bulundurmaktadır. Dosya isminden sonra gönderilen veriler formda bulunan seçeneklerdir. Gelen dosya isteğinde eğer dosya ismi “index.html” ise veride bulunan “? & =” sembollerine göre bir ayrıştırma işlemi gerçekleştirilmektedir. Ayrıştırılan veriler “strcmp” fonksiyonu ile karşılaştırılarak hangi değer geldiyse ona bağlı olarak UART işleyici yapısının parametrelerini ayarlamaktadır. 
