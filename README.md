# cable-tester
Test a cable by putting power on each pin sequentially, and check at the other side.



# Problem
When a lot of different cables have to be tested, it's not economic to make a custom tester for each one. So a universal tester is needed. 

# Use case: Testing a batch of cables that all should be identical to a known good cable.
The tester needs to recognize a know-good cable, and compare other cables against that known good cable. The indication can be as simple as a green and red LED for pass / fail. Optionally 
# Use case: Sorting cables by pinout.
The user has a pile of cables with unknown pinout. The cables can be all RJ45, but some can be various kind of network cables (different number of wires, crossed over / straight), ISDN, or various custom cables. 
The tester needs to display the measured pinout of the cable. This can be done by a display on the tester itself, or via a serial port with a serial terminal.

# Solution
The tester is trained on a known-good cable, and then it provides a fail/pass indication.

# Features
## Measure a cable. (planned)
## Auto shut down. (planned)
## Auto power up. (planned)
## Compare the measured cable to the reference cable. (planned)
## Store the reference cable in non volatile RAM, and load it again on startup. (planned)
## Show the connections of the measured cable on a display. (planned)
## Show the differences between the measured and the reference cable on a display. (planned)
## Save the measured cable to a file. (planned)
## Load cables from a file. (planned)
## Show the result of the last 100 measurements, to catch intermitted faults (planned)
## Use one microcontroller as master, and connect other microcontrollers as slaves to increase pincount. (planned)
### Use one serial port in a ring structure to give the slaves an address.
Each slave receives a byte, increases the byte by one, and sends it to the next slave. The master then receives a byte containing the number of slaves.
### Use the second serial port to send commands to the slaves, and to receive replys, on one party line. Slaves only respond to commands with their address.
* communication frame: Start of command bit
* address bits
* command (assert output, clear output, get inputs)
* command argument (output number)
#### reply
* Start of reply bit
* address bits
* command
* reply length (bytes)
* measured inputs

## Show the current and the expected pinout on a screen (planned)
## Show the current and expected pinout on a serial console (planned)


# Status
Firmware: No firmware has been written yet. See documents/todo-cable-tester-firmware.mm for the roadmap. This file requires freeplane to open (https://docs.freeplane.org/)
Hardware: No hardware has been chosen, and no schematics have been made yet.

# Firmware
## Pi Pico
### Debugging
Eclipse
|
OpenOCD
|
RP2040 running picoprobe
|
RP2040 running cable tester firmware

References: 
https://mcuoneclipse.com/2022/09/17/picoprobe-using-the-raspberry-pi-pico-as-debug-probe/
https://mcuoneclipse.com/2023/04/08/open-source-picolink-raspberry-pi-rp2040-cmsis-dap-debug-probe/
OpenOCD has Raspberry Pi Pico RP2040 support in the Flash Layer as of 0.12.0
https://github.com/berrak/eclipse-ide-debug-pico-howto

https://github.com/raspberrypi/picoprobe

#### installing clipse on arch linux:
https://aur.archlinux.org/packages/eclipse-cpp
```bash
$ wget https://aur.archlinux.org/cgit/aur.git/snapshot/eclipse-cpp.tar.gz
$ cd eclipse-cpp
$ makepkg
# pacman -U pacman -U eclipse-cpp-2\:4.28-2-x86_64.pkg.tar
```
Help->install new software->add:
Name: embed-cdt
Location: https://download.eclipse.org/embed-cdt/updates/v6/
Install:
Embedded C/C++ GDB JTAG Debugging
Embedded C/C++ J-Link Debugging.

todo: install pipico sdk on Ubuntu 22.04 (to be able to use github hosted runners)
reference: https://lindevs.com/set-up-raspberry-pi-pico-sdk-on-ubuntu/


```bash
# pacman -S arm-none-eabi-binutils arm-none-eabi-gcc arm-none-eabi-newlib
$ wget https://aur.archlinux.org/cgit/aur.git/snapshot/pico-sdk.tar.gz
$ tar -xf pico-sdk.tar.gz
$ cd pico-sdk
$ makepkg
# pacman -U pico-sdk-1.5.1-1-any.pkg.tar
```
```bash
$ git clone --recursive https://github.com/raspberrypi/picoprobe.git
$ cd picoprobe
$ mkdir build
$ cd build
$ export PICO_SDK_PATH=/usr/share/pico-sdk
$ cmake ..
$ make
$ ls -l picoprobe.uf2 
-rw-r--r-- 1 cedric cedric 80896 Aug 10 21:03 picoprobe.uf2
```



references:
https://mcuoneclipse.com/2022/07/16/getting-started-raspberry-pi-pico-rp2040-with-eclipse-and-j-link/
https://github.com/raspberrypi/picoprobe


## Building picoprobe
``` bash
$ cd ~/
$ mkdir pico
$ cd pico

$ git clone https://github.com/raspberrypi/pico-sdk.git --branch master
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone https://github.com/raspberrypi/pico-examples.git --branch master #optional

$ git clone https://github.com/raspberrypi/picoprobe.git
$ cd picoprobe
$ git submodule update --init
$ mkdir build
$ cd build
$ export PICO_SDK_PATH=../../pico-sdk
$ cmake ..
$ make -j4
```

Complete output excluding the build itself:
``` bash
[cedric@cedric ~]$ cd
[cedric@cedric ~]$ mkdir pico
[cedric@cedric ~]$ cd pico
[cedric@cedric pico]$ git clone https://github.com/raspberrypi/pico-sdk.git --branch master
Cloning into 'pico-sdk'...
remote: Enumerating objects: 7587, done.
remote: Counting objects: 100% (2242/2242), done.
remote: Compressing objects: 100% (410/410), done.
remote: Total 7587 (delta 1889), reused 1890 (delta 1814), pack-reused 5345
Receiving objects: 100% (7587/7587), 2.61 MiB | 3.49 MiB/s, done.
Resolving deltas: 100% (4163/4163), done.
[cedric@cedric pico]$ cd pico-sdk
[cedric@cedric pico-sdk]$ git submodule update --init
Submodule 'lib/btstack' (https://github.com/bluekitchen/btstack.git) registered for path 'lib/btstack'
Submodule 'lib/cyw43-driver' (https://github.com/georgerobotics/cyw43-driver.git) registered for path 'lib/cyw43-driver'
Submodule 'lib/lwip' (https://github.com/lwip-tcpip/lwip.git) registered for path 'lib/lwip'
Submodule 'lib/mbedtls' (https://github.com/Mbed-TLS/mbedtls.git) registered for path 'lib/mbedtls'
Submodule 'tinyusb' (https://github.com/hathach/tinyusb.git) registered for path 'lib/tinyusb'
Cloning into '/home/cedric/pico/pico-sdk/lib/btstack'...
Cloning into '/home/cedric/pico/pico-sdk/lib/cyw43-driver'...
Cloning into '/home/cedric/pico/pico-sdk/lib/lwip'...
Cloning into '/home/cedric/pico/pico-sdk/lib/mbedtls'...
Cloning into '/home/cedric/pico/pico-sdk/lib/tinyusb'...
Submodule path 'lib/btstack': checked out '72ef1732c954d938091467961e41f4aa9b976b34'
Submodule path 'lib/cyw43-driver': checked out '8ef38a6d32c54f850bff8f189bdca19ded33792a'
Submodule path 'lib/lwip': checked out '239918ccc173cb2c2a62f41a40fd893f57faf1d6'
Submodule path 'lib/mbedtls': checked out 'a77287f8fa6b76f74984121fdafc8563147435c8'
Submodule path 'lib/tinyusb': checked out '86c416d4c0fb38432460b3e11b08b9de76941bf5'
[cedric@cedric pico-sdk]$ cd ..
[cedric@cedric pico]$ git clone https://github.com/raspberrypi/pico-examples.git --branch master
Cloning into 'pico-examples'...
remote: Enumerating objects: 2763, done.
remote: Counting objects: 100% (148/148), done.
remote: Compressing objects: 100% (97/97), done.
remote: Total 2763 (delta 64), reused 118 (delta 50), pack-reused 2615
Receiving objects: 100% (2763/2763), 7.93 MiB | 3.13 MiB/s, done.
Resolving deltas: 100% (1394/1394), done.
[cedric@cedric pico]$ pwd
/home/cedric/pico
[cedric@cedric pico]$ git clone https://github.com/raspberrypi/picoprobe.git
Cloning into 'picoprobe'...
remote: Enumerating objects: 357, done.
remote: Counting objects: 100% (357/357), done.
remote: Compressing objects: 100% (161/161), done.
remote: Total 357 (delta 257), reused 241 (delta 191), pack-reused 0
Receiving objects: 100% (357/357), 77.87 KiB | 2.78 MiB/s, done.
Resolving deltas: 100% (257/257), done.
[cedric@cedric pico]$ cd picoprobe
[cedric@cedric picoprobe]$ git submodule update --init
Submodule 'CMSIS_5' (https://github.com/ARM-software/CMSIS_5) registered for path 'CMSIS_5'
Submodule 'freertos' (https://github.com/FreeRTOS/FreeRTOS-Kernel) registered for path 'freertos'
Cloning into '/home/cedric/pico/picoprobe/CMSIS_5'...
Cloning into '/home/cedric/pico/picoprobe/freertos'...
Submodule path 'CMSIS_5': checked out 'a65b7c9a3e6502127fdb80eb288d8cbdf251a6f4'
Submodule path 'freertos': checked out '2dfdfc4ba4d8bb487c8ea6b5428d7d742ce162b8'
[cedric@cedric picoprobe]$ mkdir build
[cedric@cedric picoprobe]$ cd build
[cedric@cedric build]$ export PICO_SDK_PATH=../../pico-sdk
[cedric@cedric build]$ ls ../../pico-sdk
cmake  CMakeLists.txt  CONTRIBUTING.md	docs  external	lib  LICENSE.TXT  pico_sdk_init.cmake  pico_sdk_version.cmake  README.md  src  test  tools
[cedric@cedric build]$ cmake ..
Using PICO_SDK_PATH from environment ('../../pico-sdk')
PICO_SDK_PATH is /home/cedric/pico/pico-sdk
Defaulting PICO_PLATFORM to rp2040 since not specified.
Defaulting PICO platform compiler to pico_arm_gcc since not specified.
-- Defaulting build type to 'Release' since not specified.
PICO compiler is pico_arm_gcc
-- The C compiler identification is GNU 13.2.0
-- The CXX compiler identification is GNU 13.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/arm-none-eabi-gcc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/arm-none-eabi-g++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- The ASM compiler identification is GNU
-- Found assembler: /usr/bin/arm-none-eabi-gcc
Build type is Release
Defaulting PICO target board to pico since not specified.
Using board configuration from /home/cedric/pico/pico-sdk/src/boards/include/boards/pico.h
-- Found Python3: /usr/bin/python3.11 (found version "3.11.3") found components: Interpreter 
TinyUSB available at /home/cedric/pico/pico-sdk/lib/tinyusb/src/portable/raspberrypi/rp2040; enabling build support for USB.
BTstack available at /home/cedric/pico/pico-sdk/lib/btstack
cyw43-driver available at /home/cedric/pico/pico-sdk/lib/cyw43-driver
Pico W Bluetooth build support available.
lwIP available at /home/cedric/pico/pico-sdk/lib/lwip
mbedtls available at /home/cedric/pico/pico-sdk/lib/mbedtls
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /home/cedric/pico/picoprobe/build
```

## building on Windows
To be written
## building on Linux
To be written

## building on MacOS
To be written

# flashing the microcontroller
To be written


# hardware
## SPI Oled screen:
https://nl.aliexpress.com/item/1005004166227174.html

## pi pico
https://nl.aliexpress.com/item/1005003753880564.html
https://nl.farnell.com/raspberry-pi/raspberry-pi-pico/raspberry-pi-32bit-arm-cortex/dp/3643332
https://nl.farnell.com/raspberry-pi/raspberry-pi-pico-h/raspberry-pi-board-arm-cortex/dp/3996081
https://nl.farnell.com/raspberry-pi/raspberry-pi-pico-w/raspberry-pi-board-arm-cortex/dp/3996082


## Tang nano 9k FPGA
https://learn.lushaylabs.com/getting-setup-with-the-tang-nano-9k/
https://nl.aliexpress.com/item/4000336442972.html

## run github actions locally:
https://aur.archlinux.org/packages/act
``` bash
[cedric@cedric cable-tester]$ sudo systemctl start docker
[cedric@cedric cable-tester]$ act
? Please choose the default image you want to use with act:

  - Large size image: +20GB Docker image, includes almost all tools used on GitHub Actions (IMPORTANT: currently only ubuntu-18.04 platform is available)
  - Medium size image: ~500MB, includes only necessary tools to bootstrap actions and aims to be compatible with all actions
  - Micro size image: <200MB, contains only NodeJS required to bootstrap actions, doesn't work with all actions

Default image and other options can be changed manually in ~/.actrc (please refer to https://github.com/nektos/act#configuration for additional information about file structure) Medium
[CI/build] 🚀  Start image=catthehacker/ubuntu:act-latest
[CI/build]   🐳  docker pull image=catthehacker/ubuntu:act-latest platform= username= forcePull=true
[CI/build]   🐳  docker create image=catthehacker/ubuntu:act-latest platform= entrypoint=["tail" "-f" "/dev/null"] cmd=[]
[CI/build]   🐳  docker run image=catthehacker/ubuntu:act-latest platform= entrypoint=["tail" "-f" "/dev/null"] cmd=[]
[CI/build] ⭐ Run Main actions/checkout@v3
[CI/build]   🐳  docker cp src=/home/cedric/overflow/github/cable-tester/. dst=/home/cedric/overflow/github/cable-tester
[CI/build]   ✅  Success - Main actions/checkout@v3
[CI/build] ⭐ Run Main Run a one-line script
[CI/build]   🐳  docker exec cmd=[bash --noprofile --norc -e -o pipefail /var/run/act/workflow/1] user= workdir=
| Hello, world!
[CI/build]   ✅  Success - Main Run a one-line script
[CI/build] ⭐ Run Main Run a multi-line script
[CI/build]   🐳  docker exec cmd=[bash --noprofile --norc -e -o pipefail /var/run/act/workflow/2] user= workdir=
| Add other actions to build,
| test, and deploy your project.
[CI/build]   ✅  Success - Main Run a multi-line script
[CI/build] 🏁  Job succeeded
```


## running a virtual pi pico in CI/CD:
https://docs.wokwi.com/wokwi-ci/getting-started

## pi pico PIO emulator:
https://rp2040pio-docs.readthedocs.io/en/latest/introduction.html

https://github.com/NathanY3G/rp2040-pio-emulator

Online:
https://wokwi.com/projects/new/pi-pico

# License
Copyright 2013 Cedric de Wijs. This file is part of cable-tester which is released under GPL2 or higher or (at your option) LGPL2 or higher.
See file LICENSE-GPL.txt or LICENSE-LGPL.txt for details
# Disclaimer
THIS SOFTWARE AND HARDWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS AND CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE OR HARDWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.