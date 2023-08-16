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

# License
Copyright 2013 Cedric de Wijs. This file is part of cable-tester which is released under GPL2 or higher or (at your option) LGPL2 or higher.
See file LICENSE-GPL.txt or LICENSE-LGPL.txt for details
# Disclaimer
THIS SOFTWARE AND HARDWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS AND CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE OR HARDWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.