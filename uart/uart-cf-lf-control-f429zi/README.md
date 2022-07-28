## [tR]  
Terminalden yazılan bir yazıda yazının sonuna bitirme karakterleri eklenebilir. Bunlar CR = Carriage Return ve LF = Line Feed olarak isimlendirilir. UART tan bir bilgi gönderildiği zaman bu karakterler yeni bir komut almak haberleşmeyi sonlandırabilir bunun için HAL kütüphanesinde " stm32f4xx_hal_uart.c " isimli dosyanın içerisinde “UART_Receive_IT” fonksiyonunda bir düzenleme yapılması gerekir ki bu sayede bu karakterler geldiği zaman işletilebilsin ve haberleşme devam edebilsin. Değiştirilmesi gereken kısım aşağıda belirtilen satırdaki gibi ayarlanmıştır.


> if ((--huart->RxXferCount == 0U) || (strchr(pdata8bits,'\n') != '\0') || (strchr(pdata8bits,'\r') != '\0')) 


Belirtilen kodda gelen veri CR veya LF ye eşit olduğunda kesme sonlandırılır. Haberleşmenin devam edebilmesi amacıyla “HAL_UART_RxCpltCallback” fonksiyonunda “HAL_UART_Receive_IT” fonksiyonu tekrardan çalıştırılarak kesme bir daha aktive edilmiş olur bu sayede haberleşmeye devam edilebilir.

Bu belirtilen CR ve LF karakterleri aldığımız veride istediğimiz karakterler değildirler bunları silebilmek amacıyla “removeChar” isimli bir fonksiyon yazılmıştır. Bu fonksiyon sayesinde bu istenmeyen karakterler alınan veriden silinir ve bu şekilde veri ele alınmaktadır. Fakat terminal ekranında bu karakterlerin basıldığını görebilmek için “HAL_UART_Transmit” fonksiyonuna girmeden bu karakterler geri eklenir ve verinin uzunluğu kadar veri gönderilir. Bahsedilen “removeChar” ile CR-LF karakterleri silme ve geri ekleme işlemi “MY_UART_Transmit” fonksiyonunda otomatik olarak yapılmaktadır.
