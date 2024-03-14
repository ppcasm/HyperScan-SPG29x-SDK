# Sunplus S+core IDE Project File - Name = "hyperscan"
# Sunplus S+core IDE Generated Build File Format Version V2.6.1
#**DO NOT EDIT**
CFG = Debug

# Begin Project

!IF "$(CFG)" == "hyperscan - Debug"

OutPut Type = elf
OutPut Dir = Debug
Inc Path = 
Lib Path = 
Compiler = ..\S_CORE~1.1\GNU\bin\gcc
Compiler DefFlag = -mscore7 -mel -g -Wall -nostartfiles
Compiler AddFlag = 
Assembler = ..\S_CORE~1.1\GNU\bin\as
Assembler DefFlag = -Wa,-gdwarf-2  -x assembler-with-cpp
Assembler AddFlag = 
Linker = ..\S_CORE~1.1\GNU\bin\ld
Linker DefFlag = -T$(LDSCRIPT)   -lm -lc -lgcc
Linker AddFlag = -Wl,-Map,$@.map
RM = ..\S_CORE~1.1\GNU\bin\rm
RM Flag = 
AR = ..\S_CORE~1.1\GNU\bin\ar
AR Flag = 
OBJCOPY = ..\S_CORE~1.1\GNU\bin\objcopy
OBJCOPY Flag = 
OBJDUMP = ..\S_CORE~1.1\GNU\bin\objdump
OBJDUMP FLag = 
IMG2BIN = ..\S_CORE~1.1\GNU\bin\img2bin
IMG2BIN FLag = 
Lik Lib = 
Stack base address = a0fffff0
Pre-Link Description = 
Pre-Link Command = 
Post-Build Description = makehyper
Post-Build Command = 	cd ./Debug && copy hyperscan.elf.bin Hyper.Exe	cd ./Debug && copy hyperscan.elf.bin e:\doom.bin
Custom Build Enable = 0
WorkDir = 
Custom Build = 
Custom Clean = 
Makefile = 1
SymBol File = 0
Binary File = 1
Dasm File = 0
Resource File = 0
LD File = 0
Use C++ Configuration = 0
Search Header File = 0
Initial Stop = Main
Stop Point = 
Use_DBCT = 0
Remote_Device = COM1
BOOL_CUSTOM_CMD = 0
STR_CUSTOM_CMD = 
Parallel = LPT1
Device = Simulator
TCP_Address = 
TCP_Port = 
Serial_Device = 
Serial_Speed = 
Probe_Speed = LOW
Remote_Manner = Serial
Remote_Manner = 
Enable OSInfo = 0
OSInfo Dll = 
Project Path = C:\Users\ppcas\OneDrive\Documents\GitHub\HyperScan-SPG29x-SDK\hyperscan\examples\DOOM
OSInfo INIT = 
Show Cycles = 0
Exception Debug = 0
ROM Debug = 0
Adjust Reloc = 0
Check Sum = 0
ReDownload Data = 1
Class View = 1
Original Path = 
Replaced Path = 
Debug Level = 0
EXCP_ADDR = 0xA0000000
Initial Address = 
Address Check = 0
!ELSEIF "$(CFG)" == "hyperscan - Release"

OutPut Type = elf
OutPut Dir = Release
Inc Path = 
Lib Path = 
Compiler = ..\S_CORE~1.1\GNU\bin\gcc
Compiler DefFlag = -mscore7 -mel -O2 -Wall
Compiler AddFlag = 
Assembler = ..\S_CORE~1.1\GNU\bin\as
Assembler DefFlag = -x assembler-with-cpp
Assembler AddFlag = 
Linker = ..\S_CORE~1.1\GNU\bin\ld
Linker DefFlag = -T$(LDSCRIPT)   -lm -lc -lgcc
Linker AddFlag = -Wl,-Map,$@.map
RM = ..\S_CORE~1.1\GNU\bin\rm
RM Flag = 
AR = ..\S_CORE~1.1\GNU\bin\ar
AR Flag = 
OBJCOPY = ..\S_CORE~1.1\GNU\bin\objcopy
OBJCOPY Flag = 
OBJDUMP = ..\S_CORE~1.1\GNU\bin\objdump
OBJDUMP FLag = 
IMG2BIN = ..\S_CORE~1.1\GNU\bin\img2bin
IMG2BIN FLag = 
Lik Lib = 
Stack base address = a0fffffc
Pre-Link Description = 
Pre-Link Command = 
Post-Build Description = 
Post-Build Command = 
Custom Build Enable = 0
WorkDir = 
Custom Build = 
Custom Clean = 
Makefile = 1
SymBol File = 0
Binary File = 0
Dasm File = 0
Resource File = 1
LD File = 1
Use C++ Configuration = 0
Search Header File = 0
Initial Stop = Main
Stop Point = 
Use_DBCT = 0
Remote_Device = COM1
BOOL_CUSTOM_CMD = 0
STR_CUSTOM_CMD = 
Parallel = LPT2
Device = Simulator
TCP_Address = 
TCP_Port = 
Serial_Device = 
Serial_Speed = 
Probe_Speed = LOW
Remote_Manner = Serial
Remote_Manner = 
Enable OSInfo = 0
OSInfo Dll = 
Project Path = 
OSInfo INIT = 
Show Cycles = 0
Exception Debug = 0
ROM Debug = 0
Adjust Reloc = 0
Check Sum = 0
ReDownload Data = 1
Class View = 1
Original Path = 
Replaced Path = 
Debug Level = 0
EXCP_ADDR = 0xA0000000
Initial Address = 
Address Check = 0
!ENDIF

# Name "hyperscan - Debug
# Name "hyperscan - Release
# Begin SubItem "hyperscan files"

# Begin Group "Source Files"
#PROP Default_Filter = c;cpp;cc;C;cxx;asm;s;

# Begin Group "Debug"
#PROP Default_Filter = 

# End Group
# Begin Group "hslibs"
#PROP Default_Filter = 

# Begin Group "HS_Controller"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\hslibs\HS_Controller\HS_Controller.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "FatFS"
#PROP Default_Filter = *.c

# Begin Source File
SOURCE=..\..\hslibs\FatFS\diskio.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\hslibs\FatFS\ff.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# End Group
# Begin Group "scorelibs"
#PROP Default_Filter = 

# Begin Group "I2C"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\scorelibs\I2C\I2C.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "IRQ"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\scorelibs\IRQ\sys_isr.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\scorelibs\IRQ\User_IRQ.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "NorFlash"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\scorelibs\NorFlash\NorFlash.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "TV"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\scorelibs\TV\TV.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "UART"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\scorelibs\UART\UART.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=..\..\scorelibs\libgloss.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=.\am_map.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_event.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_items.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_iwad.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_loop.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_main.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_mode.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_net.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomdef.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric_hyperscan.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomstat.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\dstrings.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\dummy.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\f_finale.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\f_wipe.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\g_game.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\gusconf.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\hu_lib.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\hu_stuff.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_cdmus.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_endoom.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_input.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_joystick.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_scale.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_sound.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_system.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_timer.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_video.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\icon.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\info.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_argv.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_bbox.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_cheat.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_config.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_controls.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_fixed.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_menu.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_misc.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_random.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\memio.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\mus2mid.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_ceilng.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_doors.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_enemy.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_floor.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_inter.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_lights.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_map.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_maputl.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_mobj.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_plats.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_pspr.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_saveg.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_setup.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_sight.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_spec.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_switch.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_telept.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_tick.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_user.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_bsp.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_data.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_draw.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_main.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_plane.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_segs.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_sky.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_things.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\s_sound.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\sha1.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\sounds.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\st_lib.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\st_stuff.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\statdump.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\tables.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\v_video.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_checksum.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_file.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_file_stdc.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_main.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_wad.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\wi_stuff.c
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\z_zone.c
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Header Files"
#PROP Default_Filter = h;inc;

# Begin Group "include"
#PROP Default_Filter = *.h

# Begin Group "HS_Controller"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\include\HS_Controller\HS_Controller.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "I2C"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\include\I2C\I2C.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "IRQ"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\include\IRQ\IntEnable.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "NorFlash"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\include\NorFlash\NorFlash.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "TV"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\include\TV\Font_8x16.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\include\TV\TV.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "UART"
#PROP Default_Filter = 

# Begin Source File
SOURCE=..\..\include\UART\UART.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "FatFS"
#PROP Default_Filter = *.h

# Begin Source File
SOURCE=..\..\include\FatFS\diskio.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\include\FatFS\ff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\include\FatFS\ffconf.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=..\..\include\SPG290_Constants.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=..\..\include\SPG290_Registers.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Source File
SOURCE=.\am_map.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\config.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_englsh.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_event.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_items.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_iwad.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_loop.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_mode.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_player.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_textur.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_think.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\d_ticcmd.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\deh_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\deh_misc.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\deh_str.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doom.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomdata.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomdef.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomfeatures.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomgeneric.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomkeys.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomstat.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\doomtype.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\dstrings.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\f_finale.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\f_wipe.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\g_game.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\gusconf.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\hu_lib.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\hu_stuff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_cdmus.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_endoom.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_joystick.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_scale.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_sound.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_swap.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_system.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_timer.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\i_video.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\info.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_argv.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_bbox.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_cheat.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_config.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_controls.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_fixed.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_menu.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_misc.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\m_random.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\memio.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\mus2mid.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_client.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_dedicated.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_defs.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_gui.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_io.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_loop.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_packet.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_query.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_sdl.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\net_server.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_inter.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_local.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_mobj.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_pspr.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_saveg.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_setup.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_spec.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\p_tick.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_bsp.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_data.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_defs.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_draw.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_local.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_plane.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_segs.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_sky.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_state.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\r_things.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\Resource.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\Resource.inc
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\s_sound.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\sha1.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\sounds.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\st_lib.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\st_stuff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\statdump.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\stdint.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\tables.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\v_patch.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\v_video.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_checksum.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_file.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_main.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_merge.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\w_wad.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\wi_stuff.h
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\z_zone.h
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "Resource Files"
#PROP Default_Filter = rc;

# Begin Source File
SOURCE=.\hyperscan.rc
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "External Dependencies"
#PROP Default_Filter = 

# Begin Source File
SOURCE=.\hyperscan_Prog.ld
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\hyperscan_startup.s
USEPARAM=FALSE
PARAM=
# End Source File

# Begin Source File
SOURCE=.\Makefile
USEPARAM=FALSE
PARAM=
# End Source File

# End Group
# Begin Group "External Headers"
#PROP Default_Filter = h;

# End Group
# End SubItem
# End Project
