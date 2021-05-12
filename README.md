# CRC
Computing CRC 
Implementing the CRC value

## Polynomial 
x^{16} + x^{12} + x^5 + 1    

|Name| Uses |Normal |Reversed| Reciprocal| Reversed Reciprocal| Parity|
|----|------|-------|--------|-----------|--------------------|-------|
|CRC-16-CCITT|X.25, V.41, HDLC FCS, XMODEM, Bluetooth, PACTOR, SD, DigRF, many others; known as CRC-CCITT|0x1021(x^{16} + x^{12} + x^5 + 1)|0x8408|0x811|0x8810|Even|

Binary Representation=1 0001 0000 0010 0001
Width = 16 bits
Hex polynomial = 0x11021
Initial value = 0xFFFF
Input data is NOT reflected
Output CRC is NOT reflected
No XOR is performed on the output CRC