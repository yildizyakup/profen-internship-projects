   GET metodu, formdaki verileri sayfa adresi açık bir şekilde yani herkesin görebileceği biçimde gönderme işlemi yapmaktadır. 
   Bunu sayfa bağlantısını incele diyerek “Network” kısmında veri gönderilip gönderilmediğini görebiliriz. 
   Eğer ki bir butona basılırsa GET metodu sayesinde veriler adrese eklenir ve bu adrese eklenen veriler STM32 mikrodenetleyicisi ile işlenir. 
   Adres çubuğuna eklenen veriler aşağıdaki örnekteki gibi gözükmektedir.
   
 - http://169.254.228.35/index.html?baud=115200&parity=None&data=8&stop=1&hardware=None&send=Test
 Bu uygulamada “index.html” olarak isimlendirilen dosya UART arayüzünü bulundurmaktadır. 
   Dosya isminden sonra gönderilen veriler formda bulunan seçeneklerdir. M
   Mikrodenetleyiciye ulaşan istekte eğer dosya ismi “index.html” ise veride bulunan “? & =” sembollerine göre bir ayrıştırma işlemi gerçekleştirilmektedir. 
   Ayrıştırılan veriler “strcmp” fonksiyonu ile karşılaştırılarak hangi değer geldiyse ona bağlı olarak UART işleyici yapısının parametrelerini ayarlamaktadır. 
