# Let's Split - nic

## Flashing

A custom Makefile target (`avrdude`) will help you flash your Pro Micro by finding your serial port automatically.


```
$ make rev2-nic-avrdude
```

Output:

```bash
$ make rev2-nic-avrdude
Making lets_split/rev2 with keymap nic and target avrdude

avr-gcc (GCC) 4.9.3
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text    data     bss     dec     hex filename
      0   22282       0   22282    570a lets_split_rev2_nic.hex

Compiling: ./tmk_core/common/command.c                                                              [OK]
Linking: .build/lets_split_rev2_nic.elf                                                             [OK]
Creating load file for Flash: .build/lets_split_rev2_nic.hex                                        [OK]
Reset your Pro Micro now

Connecting to programmer: .
Found programmer: Id = "CATERIN"; type = S
    Software Version = 1.0; No Hardware Version given.
Programmer supports auto addr increment.
Programmer supports buffered memory access with buffersize=128 bytes.

Programmer supports the following devices:
    Device code: 0x44

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9587 (probably m32u4)
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "./.build/lets_split_rev2_nic.hex"
avrdude: input file ./.build/lets_split_rev2_nic.hex auto detected as Intel Hex
avrdude: writing flash (22286 bytes):

Writing | ################################################## | 100% 1.71s

avrdude: 22286 bytes of flash written
avrdude: verifying flash memory against ./.build/lets_split_rev2_nic.hex:
avrdude: load data flash data from input file ./.build/lets_split_rev2_nic.hex:
avrdude: input file ./.build/lets_split_rev2_nic.hex auto detected as Intel Hex
avrdude: input file ./.build/lets_split_rev2_nic.hex contains 22286 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.24s

avrdude: verifying ...
avrdude: 22286 bytes of flash verified

avrdude: safemode: Fuses OK (E:CB, H:D8, L:FF)

avrdude done.  Thank you.
```
