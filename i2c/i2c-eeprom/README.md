## [tR]  
Cihaz adresi “0xA0” olarak belirlenmiştir. EEPROM a veri aktarmak için HAL kütüphanesinde bulunan iki farklı fonksiyon vardır bunlar şunlardır:

•	HAL_I2C_Master_Transmit()  
•	HAL_I2C_Mem_Write()

Bu fonksiyonlar aracılığıyla cihaz adresiyle gönderilmesi istenen veri EEPROM a yazılabilmektedir. 
Fakat bu iki fonksiyonun farkı “HAL_I2C_Mem_Write()” fonksiyonun hafıza adresi parametresi vardır. Bu sayede hangi adrese bilgi yazılmak istendiği parametre olarak girilebilmektedir. 
“HAL_I2C_Master_Transmit()” fonksiyonunda ise gönderilen verinin baş kısmına gönderilmek istenen adres eklenmelidir ki istenilen hafızaya gönderilebilsin. 
Bu fonksiyonlar sayesinde EEPROM a veri başarıyla yazılmıştır.

EEPROM dan okuma yapmak için de yine aynı şekilde iki farklı fonksiyon bulunmaktadır bu fonksiyonlar şunlardır:

•	HAL_I2C_Master_Receive()  
•	HAL_I2C_Mem_Read()

Veriyi istemeden önce cihaz adresini ve okuma yapmak istenilen adres EEPROM a gönderilmiştir. Bunun ardından veri okunmuştur. 

Bu çalışmada Transmit ve Receive fonksiyonları kullanılarak I2C iletişimi daha iyi kavranmıştır. Verinin doğru iletilip geri alındığı lojik analizör ile teyit edilmiştir.

Terminalden girilen bir komutu ayrıştırarak hangi adrese ne yazılıp ne okunacağı veya hangi adresin temizleneceği için komut ayarları geliştirilmiştir. Bu komutların gösterimi aşağıdaki şekilde yapılabilir.

•	“<yapılmak istenilen işlem><hafıza adresi><,><[veri]>”

Örnek vermek gerekirse aşağıdaki komut bir yazma işlemidir. “W” nun yanında verilen sayılar adresi göstermektedir. 
Virgülden sonraki kısım ise o adrese ne yazılmak isteniyorsa onu belirtmektedir. Örnek komutta “Test” yazılmak istenmiştir.

>W0205,Test

Burada yapılan işlemin bir yazma işlemi olduğunu algılayabilmek için girilen dizinin ilk karakteri “strncmp” fonksiyonu ile algılanıyor. Bunun sonucunda “writeFlag” güncellenerek aktifleştiriliyor. Yazılması istenen adresi elde etmek amacıyla kesme(slicing) işlemi uygulanmaktadır. Bu kesme işlemi alınan dizinin belli bir aralığını başka bir değişkene atamaktadır. Alınan adresin başına “0x” eklenerek on altılık tabana çevrilir. On altılık tabandaki sayıyı tam sayı(integer) olarak işletmek için “strtol” fonksiyonu kullanılmıştır. Virgülden sonraki kısım EEPROM a yazılmak istenen veridir. Bunun için “strchr” fonksiyonu kullanılmıştır ve alınan değerden virgül silinerek atama gerçekleştirilmiştir. Tüm bu işlemler sonucunda istenen değerlere atamalar gerçekleştirilir ve i2cFlag güncellenir ve artık veri iletilmeye hazırdır. Veri gönderildikten sonra ana program akışı yeni bir komut beklemeye geçer. Örnekte verilen ilk karakter “C” olsaydı yanında belirtilen adrese NULL karakter ataması yapılacaktı. İlk karakter “R” olsaydı yanında verilen adresteki veriyi terminalde ekrana yazdırır.
