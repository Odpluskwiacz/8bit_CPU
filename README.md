## Emulator CPU w C

Specyfikacje 
 8 bit CPU
 256 bajtów Ramu 0x00 0xFF
 Rejestry A, B, PC, FLAG

    Zestaw instrukcji
        0x01 LDA Załaduj do A z pamięci
        0x02 STA Zapisz do pamięci
        0x03 ADD Dodaj do A wartość z pamięci
        0x04 SUB Odejmij od A wartość z pamięci
        0x05 JMP Skocz do addresu
        0x06 JZ Skocz jeśli FLAGI == 0
        0xFF HLT Zatrzymaj koniec basta


Do skompilowania mam plik Makefile
    do edycji pamięci CPU należy użyć memory.bin: znajdującym się w Makefile
