# About

- main
  - 本番使用するコード
- test
  - 各種デバイスの動作確認用

## XBee設定を簡単にまとめてみる

Arduinoがシリアルモニタに送るデータをUSB経由でPCに送っていたのを無線化するためXBeeを使用するのでその際の手順を簡単に残しておく

| 項目 | Arduino側（送信） | PC側（受信） |
|----|----|----|
| SH | 13A300 | 13A200 |
| SL | _SL-Arduino_ | _SL-PC_ |
| CH | C | C |
| ID | PC側と同じならなんでもよし | Arduino側と同じならなんでもよし |
| DH | 13A200 | 13A200 |
| DL | _SL-PC_ | _SL-PC_ |
| CE | End Device[0] | Cordinator[1] |

この状態になるようにいい感じに設定をする
オススメは

- Arduino側XBeeを接続して上記4項目を設定
- ID, SLをどこかにメモる
- PCから取り外し、Arduinoに接続
- PC側XBeeを接続し上記4項目を設定
- コンソールモニタを開いてCloseにし、Arduinoを起動

## 使用方法

### ①ハードウェアシリアルを使用する場合

マイコン側の`TX`とXBeeの`DIN`、`RX`と`DOUT`を接続する  
Arduinoにプログラムを書き込む際はTX,RXの接続を何かしらの方法で外す必要があるので、2回路入スイッチを介して接続するか、マイコン自体をそのまま外せるようにピンソケットに差し込むなどする

`Serial.print()`などで直接送信はできると思われるが、未確認なため後日検証。

### ②ソフトウェアシリアルを使用する場合

特段のハードウェア的な考慮事項はないが、GPSもソフトウェアシリアルを使用するため、競合する可能性には注意

`#include <SoftwareSerial.h>`でライブラリを導入し、`SoftwareSerial mySerial(RX_Pin, TX_Pin);`でソフトウェアシリアルを定義、`Serial.print()`の代わりに`mySerial.print()`で送信する。`mySerial`の部分は自由に決めれるので、用途がわかりやすい名前にすることが望ましい（例：XBeeSerial, GPS_Serial）

### ソフトウェアシリアルの競合対策

同時に送受信することがない限り複数同時に使用できる

以下にコードの例を示す

```cpp
#include <SoftwareSerial.h>

#define BaudRate 9600

SoftwareSerial Serial_1(RX_1, TX_1);
SoftwareSerial Serial_2(RX_2, TX_2);

void setup() {
  Srial_1.Begin(BaudRate);
  Srial_2.Begin(BaudRate);
}

void loop() {
  //Serial_1 を使用:
  Serial_1.listen();
  /*
   * ここにSerial_1のコードを書く
   */

  //Serial_2 を使用:
  Serial_2.listen();
  /*
   * ここにSerial_2のコードを書く
   */
  
  delay(1000);
}
```
