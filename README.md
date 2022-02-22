# Arduino-Midi-Controller
Simple Arduino MIDI Controller for controlling MIDI parameters on any DAW

## Install

First download the code and push it to your Arduino (it doesn't use any external libraries)

### Schematics

List of components you need:

| Object            | Pcz |
|-------------------|-----|
| Arduino UNO       | 1   |
| Button            | 5   |
| LED RGB           | 1   |
| 10k Potenziometer | 1   |
| 220 ohm Resistor  | 3   |

Schematics:

[!Schematics]("https://github.com/Bildcraft1/Arduino-Midi-Controller/raw/main/.assets/Fabulous%20Jofo.png")

## How to connect to PC

For connecting to your PC without any MIDI Port, you will need to use 2 software on Windows (maybe just one on mac and linux)

First is [Hairless MIDI Bridge]("http://projectgus.github.io/hairless-midiserial/") and the seconds is [Loopbe1 Bridge]("https://nerds.de/en/loopbe1.html")

For Hairless set up like this:

[!Hairless]("https://github.com/Bildcraft1/Arduino-Midi-Controller/raw/main/.assets/Hairless.png")

then on your daw set the Loopbe1 MIDI bridge as a MIDI Controller and you'r done
