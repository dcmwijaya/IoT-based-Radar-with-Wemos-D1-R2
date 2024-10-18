[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/IoT-based-Radar-with-Wemos-D1-R2?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-Wemos-light.svg?style=flat&logo=espressif&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-Course-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# IoT-based-Radar-with-Wemos-D1-R2
<strong>Tugas Akhir UCI Coursera 2023</strong><br><br>
Radar ini sangat erat kaitannya dengan teknologi pertahanan, yang mana alat ini dapat difungsikan sebagai penentu arah pergerakan / posisi / bentuk dari suatu objek yang terdeteksi. Tujuan diadakannya proyek ini adalah untuk dapat membuat sistem radar yang sederhana dari pemanfaatan sensor Ultrasonik. Proyek ini telah dilaksanakan dan memakan waktu kurang lebih 1 hari. Sistem radar ini berbasis Internet of Things, sehingga menggunakan MQTT sebagai protokol komunikasinya. Antarmuka sistem dapat diakses secara bergantian melalui Serial Monitor maupun Processing. Manfaat dari pembuatan proyek ini tidak lain adalah untuk menambah pengalaman. Hasil penelitian menunjukkan bahwa sistem yang dibuat ini dapat berfungsi dengan baik.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | Wemos D1 R2 |
| Editor Kode | • Arduino IDE<br>• Processing |
| Driver | CH340 USB Driver |
| Platform IoT | mosquitto |
| Protokol Komunikasi | Message Queuing Telemetry Transport (MQTT) |
| Arsitektur IoT | 3 Lapisan |
| Dukungan Aplikasi | MQTT Explorer |
| Bahasa Pemrograman | • C/C++<br>• Processing |
| Pustaka Arduino | • ESP8266WiFi (bawaan)<br>• PubSubClient<br>• ArduinoJson<br>• Servo |
| Aktuator | Motor Servo SG90 180° (x1) |
| Sensor | HC-SR04: Sensor Ultrasonik (x1) |
| Komponen Lainnya | • Kabel USB Mikro - USB tipe A (x1)<br>• Kabel jumper (1 set)<br>• Sekrup (1 set)<br>• Braket Pemasangan HC-SR04 (x1) |

<br><br>

## Unduh & Instal
1. Arduino IDE

   <table><tr><td width="810">
   
   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>
   
2. Processing

   <table><tr><td width="810">
   
   ```
   https://bit.ly/Processing_Installer
   ```

   </td></tr></table><br>

3. MQTT Explorer

   <table><tr><td width="810">
   
   ```
   https://bit.ly/MQTT_Explorer_Installer
   ```

   </td></tr></table><br>
   
4. CH340 USB Driver

   <table><tr><td width="810">

   ```
   https://bit.ly/CH340_USB_Driver
   ```

   </td></tr></table>
   
<br><br>

## Skema Alur Sistem
Ketika sebuah objek berada di area deteksi sensor, maka sensor akan merespon dengan mengirimkan data publish ke platform IoT (mosquito) dan kemudian mengirimkan kembali dalam bentuk data subscribe untuk ditampilkan pada serial monitor. Sedangkan pada grafik, pengguna juga dapat melihat perbedaan warna yang signifikan pada area deteksi. Jika tidak ada objek yang ditemukan, sensor dan aktuator akan selalu siaga.

<br><br>

## Rancangan Proyek
<table>
<tr>
<th width="420">Diagram Blok</th>
<th width="420">Diagram Ilustrasi</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
<td><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Pengkabelan</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek ini dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
   
      ``` wemos_d1r2_radar.ino ```

   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">
   
      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
      
      ```
      http://arduino.esp8266.com/stable/package_esp8266com_index.json
      ```

   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` WEMOS D1 R2 ```
            
      </th></tr>
      <tr><td>
      
      • Klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp8266 ```. 
      
      • Kemudian klik ``` Tools ``` -> ``` Board ``` -> ``` ESP8266 Board ``` -> ``` LOLIN(WEMOS) D1 R2 & mini ```.

      </td></tr>
   </table><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE

   <table><tr><td width="810">
   
      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```

   </td></tr></table><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">
   
      Unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

6. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">
   
      Klik ``` Port ``` -> Pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```

   </td></tr></table><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan ``` ID Klien ``` sesuai dengan yang anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.<br><br>

10. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan Processing
1. Buka ``` Processing ``` terlebih dahulu, kemudian buka proyek Radar GUI dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
      
      ``` radar_gui.pde ```

   </td></tr></table><br>

2. Sesuaikan ``` port ``` anda dengan yang ada di ``` Arduino IDE ```. Hal ini dilakukan agar board dapat dikenali oleh ``` Processing ```, sehingga kode dapat dijalankan dengan benar.<br><br>

3. Langkah terakhir, silakan klik: ``` Run ```.

<br><br>

## Pengaturan MQTT Explorer
1. Buka ``` MQTT Explorer ```. Kemudian, klik Connections: ``` test.mosquitto.org ```.<br><br>

2. Klik ``` ADVANCED ``` -> ``` Delete All Topics ```.<br><br>

3. Buat ``` Topik baru ``` dengan QoS "0":

   <table><tr><td width="810">
      
   ```
   coursera/uci/radar
   ```

   </td></tr></table><br>

4. Salin dan tempelkan ``` ID Klien ``` ke dalam proyek ``` Arduino IDE ```.<br><br>

5. Kemudian, klik: ``` BACK ```. Langkah terakhir, silakan klik: ``` CONNECT ```.

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>

2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
   
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>

5. Selamat menikmati [Selesai].

<br><br>

## Sorotan
<table>
<tr>
<th width="840" colspan="2">Perangkat</th>
</tr>
<tr>
<td width="420"><img src="Assets/Documentation/Experiment/Device-1.jpg" alt="device-1"></td>
<td width="420"><img src="Assets/Documentation/Experiment/Device-2.jpg" alt="device-2"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">MQTT Explorer (Data JSON pada Topik)</th>
</tr>
<tr>
<td width="420"><img src="Assets/Documentation/Experiment/MQTT Explorer-1.jpg" alt="mqtt-explorer-1"></td>
<td width="420"><img src="Assets/Documentation/Experiment/MQTT Explorer-2.jpg" alt="mqtt-explorer-2"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="2">Serial Monitor (Publish & Subscribe)</th>
</tr>
<tr>
<td width="420"><img src="Assets/Documentation/Experiment/Serial Monitor-1.jpg" alt="serial-monitor-1"></td>
<td width="420"><img src="Assets/Documentation/Experiment/Serial Monitor-2.jpg" alt="serial-monitor-2"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Processing (Antarmuka Pengguna Grafis Radar)</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Experiment/Processing.jpg" alt="processing"></td>
</tr>
</table>

<br><br>

## Pengingat

<table><tr><td width="840">
      
1. Sebelum memulai proyek, anda harus menguji komponen terlebih dahulu untuk memastikan perangkat yang digunakan dapat bekerja dengan baik. Hal ini sudah disediakan oleh pembuat program, silakan unduh dan coba satu per satu bagian.
   
2. Penggunaan komunikasi serial antara Arduino IDE dan Processing tidak dapat dijalankan secara bersamaan, sehingga jika anda ingin membuka Processing GUI maka pada saat yang sama anda tidak dapat membuka Serial Monitor Arduino IDE. Hal ini juga berlaku untuk sebaliknya.

</td></tr></table>

<br><br>

## Pengujian Komponen
Anda dapat mengunduh berkas uji komponen melalui tautan berikut: <a href="https://github.com/devancakra/IoT-based-Radar-with-Wemos-D1-R2/tree/master/Assets/Component%20Testing">Klik Disini</a>

<br><br>

## Apresiasi
Jika karya ini bermanfaat bagi anda, maka dukunglah karya ini sebagai bentuk apresiasi kepada penulis dengan mengklik tombol ``` ⭐Bintang ``` di bagian atas repositori.

<br><br>

## Penafian
Aplikasi ini merupakan hasil karya saya sendiri dan bukan merupakan hasil plagiat dari penelitian atau karya orang lain, kecuali yang berkaitan dengan layanan pihak ketiga yang meliputi: pustaka, kerangka kerja, dan lain sebagainya.

<br><br>

## LISENSI
LISENSI MIT - Hak Cipta © 2023 - Devan C. M. Wijaya, S.Kom

Dengan ini diberikan izin tanpa biaya kepada siapa pun yang mendapatkan salinan perangkat lunak ini dan file dokumentasi terkait perangkat lunak untuk menggunakannya tanpa batasan, termasuk namun tidak terbatas pada hak untuk menggunakan, menyalin, memodifikasi, menggabungkan, mempublikasikan, mendistribusikan, mensublisensikan, dan/atau menjual salinan Perangkat Lunak ini, dan mengizinkan orang yang menerima Perangkat Lunak ini untuk dilengkapi dengan persyaratan berikut:

Pemberitahuan hak cipta di atas dan pemberitahuan izin ini harus menyertai semua salinan atau bagian penting dari Perangkat Lunak.

DALAM HAL APAPUN, PENULIS ATAU PEMEGANG HAK CIPTA DI SINI TETAP MEMILIKI HAK KEPEMILIKAN PENUH. PERANGKAT LUNAK INI DISEDIAKAN SEBAGAIMANA ADANYA, TANPA JAMINAN APAPUN, BAIK TERSURAT MAUPUN TERSIRAT, OLEH KARENA ITU JIKA TERJADI KERUSAKAN, KEHILANGAN, ATAU LAINNYA YANG TIMBUL DARI PENGGUNAAN ATAU URUSAN LAIN DALAM PERANGKAT LUNAK INI, PENULIS ATAU PEMEGANG HAK CIPTA TIDAK BERTANGGUNG JAWAB, KARENA PENGGUNAAN PERANGKAT LUNAK INI TIDAK DIPAKSAKAN SAMA SEKALI, SEHINGGA RISIKO ADALAH MILIK ANDA SENDIRI.
