# The road is signed
Here I will upload the arduino cpp so you can try it too and build your own GAMMa.
This version is actually the alpha for the first release.
This will be the first update to the project and this will be the first usable prototype because it will be not on a breadboard but soldered and a 3d printed board to attach things on. This is the main difference.
Allan is the project codename for this version but nothing radical will change in the software for the arduino. Here will be uploaded also some tests for different type of displays in the test folder.
You can check the work progress from the pull request page.
There will be soon a CAD folder with the freecad file to store the cad design.
## Software Requirements
Because I'm using a nano the midi is indirect so the computer hosts the conversion of the serial to midi. In the future i will probably upgrade to a uno or a nano iot but the retrocompatibility is nice so... I even thinked of compile and create software to do that but i found something online and they already exist so why don't use them... Hairless midi-serial and loopMidi if you don't have a midi port like me.
here are the links for download
- [Hairless](https://projectgus.github.io/hairless-midiserial/)
- [loopMidi](https://www.tobias-erichsen.de/software/loopmidi.html)
## Hardware required to build a prototype
- arduino nano: ATmega328
- display: tm1637
- trimmer 10Kohm
- 10x touch sensors: TTP223
- usb cable
- some wires
- breadboard
- 3d printer
## User Requirements
just in case you want to take a look under the hood
- c++ understanding
- arduino ide familiarity
- patience because i'm not actually a programmer
- coffee
