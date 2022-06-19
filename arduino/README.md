# About

- main
  - 本番使用するコード
- test
  - 各種デバイスの動作確認用

## XBee設定を簡単にまとめてみる

Arduinoがシリアルモニタに送るデータをUSB経由でPCに送っていたのを無線化するためXBeeを使用するのでその際の手順を簡単に残しておく

|| Arduino側（送信） | PC側（受信） |
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
