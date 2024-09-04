# Questioning life choises
Here I will upload the arduino cpp so you can try it too and build your own GAMMa.
Also this version is actually another alpha for the first release.
Why am I stepping up one version if so little changes? Well it will be a lot to change like the mindset of the project.
Altschul is the project codename for this version but nothing radical will change in the software for the arduino. Here will be uploaded also some tests for different type of displays in the test folder.
There now is a CAD folder and I'm learning FreeCAD in order to make a fully opensource project.
This version is shipped with a custom driver (also open source) because I feel like masochism is the right way for this project.

## Software Requirements
Because I'm using a nano the midi is indirect so the computer hosts the conversion of the serial to midi. ~~In the future i will probably upgrade to a uno or a nano iot but the retrocompatibility is nice so... I even thinked of compile and create software to do that but i found something online and they already exist so why don't use them... Hairless midi-serial and loopMidi if you don't have a midi port like me.
here are the links for download~~
- ~~[Hairless](https://projectgus.github.io/hairless-midiserial/)~~
- ~~[loopMidi](https://www.tobias-erichsen.de/software/loopmidi.html)~~

WELL NO MORE...
From now on this as an hardware project will have it's own driver because I realized that using not one but two outdated and dead project as basis for a new and fresh one is like trying to eat on a pile of 
The driver will be available in another repo that will be made soon (tm).
...
The computer will use a custom driver that I will try to make so there will be a driver folder in the "near" future. Hardware components are still the same as Allan.
Actually I will actively try to maintain the compatibility with those but it's no longer a priority.
# OpenSource as priority
This project is and will always be open source and under GPL licence.
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
- sackcloth (only if you want to contribute)
