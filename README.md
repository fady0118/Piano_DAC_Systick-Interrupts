# Piano_DAC_Systick-Interrupts
This is my solution for Lab13 of Embedded systems shape the world MOOC \
Author Fady Abd Elshahid
## Purpose

This lab has these major objectives: 
1. To learn about DAC conversion
2. To understand how digital data stored in a computer could be used to represent sounds and music
3. To study how the DAC  and interrupts can be used together to create sounds

## System Requirements

Most digital music devices rely on high-speed DACs to create the analog waveforms required to produce high-quality sound. \

The goal is to create an embedded system that plays four notes, which will be a digital piano with four keys.

The first step is to design and test a 4-bit binary-weighted DAC, which converts 4 bits of digital output from the TM4C123 to an analog signal.

Converting the digital output signals to an analog output using the binary-weighted circuit method. 

*DAC allows the software to create music. In the simulator mode, the output voltage Vout is called DACOUT*.

The second step is to design a low-level device driver for the DAC.\
The third step is to design a low-level device driver for the four keys of the piano. \
The fourth step is to organize the sound generation software into a device driver

The wave should be generated whenever one key is pressed and held. These are the standard frequencies which your digital piano must produce:
- Piano key 3: G generates a sinusoidal DACOUT at 783.991 Hz
- Piano key 2: E generates a sinusoidal DACOUT at 659.255 Hz
- Piano key 1: D generates a sinusoidal DACOUT at 587.330 Hz
- Piano key 0: C generates a sinusoidal DACOUT at 523.251 Hz

## Completed files

`Dac.c` - DAC functions file \
`Sound.c` - sound generation functions file \
`Piano.h` - output header file \
`Piano.c` - output functions file \
`Lab13.c` - main file
