# cable-tester
Test a cable by putting power on each pin sequentially, and check at the other side.



# Problem
We make a lot of different, custom cables. Each one needs to be tested, but the number of identical cables is too low to make a dedicated tester for each one. So a self-learning, universal tester is needed.

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
## Show the current and the expected pinout on a screen (planned) 

# Status
Firmware: No firmware has been written yet. See documents/todo-cable-tester-firmware.mm for the roadmap. This file requires freeplane to open (https://docs.freeplane.org/)
Hardware: No hardware has been chosen, and no schematics have been made yet.

# Building
## building on Windows
To be written
## building on Linux
To be written

## building on MacOS
To be written

# flashing the microcontroller
To be written

# License
Copyright This file is part of cable-tester which is released under GPL2 or higher or (at your option) LGPL2 or higher.
See file LICENSE-GPL.txt or LICENSE-LGPL.txt for details
# Disclaimer
THIS SOFTWARE AND HARDWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS AND CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE OR HARDWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.