# HyperScan SPG29x SDK
 SPG29x SDK with Mattel HyperScan support

## DO NOT USE THIS YET UNLESS YOU KNOW WHAT YOU'RE DOING!!!! 
# It's still very much a work in progress, and it's dangerous. 

## Support

HyperScan specifc:
- HyperScan controllers/I2C
- HyperScan LEDs

SPG29x specific:
- UART
- NOR flash interface
- Basic TVE/Framebuffer
- Custom interrupt handling

More will hopefully be added in the future..

## Features

This SDK includes multiple examples for how to interface with the hardware, and most of
the code should be documented.

- [Default (outside of examples)] - This shows a very basic controller/framebuffer demo
- [FlashRecovery] - This flashes a custom bootloader to allow CFW/OFW recovery, and live loading FW
- [PONG] - A very terrible PONG game, I wouldn't use it for production of any kind
- [FlashCFW] - This allows flashing a CFW/OFW permanently from recovery mode on HyperScan

## Installation
I've included the S+Core IDE in the tools directory. This only works for Windows, but could be installed in WINE under Linux, which was the reason I chose to develop with this method since the S+Core Binutils/GCC hasn't been supported in years it makes trying to track down and build the toolchain from source unneccessary, and a lot more accessible, plus we can ensure that anyone who uses the IDE from this repo will be on the same versions since the back-end of the IDE uses a fixed version Bintuils/GCC.

#### Installing the S+Core IDE

Get this repo and navigate to HyperScan-SPG29x-SDK\tools\S+core IDE-V2.6.1.exe and then double click to install.

Done.


## Compiling the examples

All of the examples *SHOULD* be documented in the code. The best way to test out the examples is to get this repo, install the IDE, and then go to File->Open Workspace and then navigate to the examples folder and open the desired example folder and select the .spw/.spg file of that example and everything should load.

The IDE will actually produce a HYPER.EXE file for HyperScan by default in the Debug folder of the selected example (ex: /examples/PONG/Debug/Hyper.Exe) when compiled. Some projects have other projects embedded into them, and some are made to be ran from recovery mode instead of as a HyperScan app.

## Considerations
The HYPER.EXE files on HyperScan are loaded to address 0xA00901FC and their entry point is 0xA0091000 and so if you try to
compile an example that is meant to run from recovery/firmware space, you will not get results as the firmware is loaded from NOR flash (or UART for recovery) to 0xA00001FC and entry is at 0xA0001000 on HyperScan. This can be checked by looking at the *.ld file of your current project (ex: hyperscan_Prog.ld) and you'll see for example:

```sh
/* Read-only sections, merged into text segment: */
  . = 0xA0001000;
```

Which tells you that this is build for running in recovery, or as a firmware file, as opposed to it saying 0xA0091000 there, which would indicate it's to be ran from CD, or loaded in the HyperScan OS as a HYPER.EXE.

## Thanks to
- Bushing - RIP :( He was responsible for the hyperscan.bin firmware file being dumped originally, and a good source of valid information
- LiraNuna - Reverse engineering, and coding, etc
- HyperScanDev - Reverse engineering, Discord moderator, etc
- Sunplus - They actually indirectly provided a lot of information and tools through other S+Core products, and at least made a very good effort to support open-source
- Mattel - I like Barbie
## License

**Free Software, Hell Yeah!**