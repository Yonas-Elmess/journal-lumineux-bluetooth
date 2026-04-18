# Bluetooth-Controlled Scrolling LED Display (Journal Lumineux)

An embedded systems project built and programmed from scratch — a wireless scrolling LED display controlled in real time via Bluetooth.

## Demo

> The physical prototype in action — text sent from a phone scrolls across the LED matrix in real time.

![Prototype](./journalLumineuxFinalProd.png)

---

## How It Works

A smartphone or PC sends a text message wirelessly over Bluetooth. The Arduino receives it, displays it as scrolling text on the LED matrix, and updates the RGB status LED. Scroll speed can be adjusted on the fly by sending `+` or `-` commands.

```
[ Phone / PC ]  --Bluetooth-->  [ HC-06 ]  -->  [ Arduino Uno ]  -->  [ 32x8 LED Matrix ]
                                                       |
                                                 [ RGB LED ]
                                              (status indicator)
```

---

## Hardware Components

| Component | Reference | Role |
|---|---|---|
| Arduino Uno | ATmega328P | Main microcontroller |
| LED Matrix 32×8 | NH1088AS (4× MAX7219) | Scrolling text display |
| Bluetooth Module | HC-06 (slave) | Wireless serial communication |
| RGB LED | Common anode, 5V | Status indicator |

---

## Features

- Send any text message wirelessly from a phone or laptop
- Real-time scrolling display on a 32×8 LED matrix
- Live speed control via `+` (faster) and `-` (slower) commands
- RGB LED status feedback: green = idle, red = receiving data
- Default boot message: `"Pret !"`

---

## Tech Stack

- **Language:** C++ (Arduino)
- **Libraries:** MD_Parola, MD_MAX72xx, SoftwareSerial, SPI
- **Protocol:** UART over Bluetooth (HC-06, 9600 baud)
- **Hardware interface:** SPI (LED matrix), Software Serial (Bluetooth)

---

## Getting Started

### Requirements
- Arduino IDE
- Libraries: `MD_Parola`, `MD_MAX72xx` (installable via Arduino Library Manager)

### Wiring
| Arduino Pin | Connected To |
|---|---|
| Pin 10 (CS) | LED Matrix CS |
| Pin 11 (MOSI) | LED Matrix DIN |
| Pin 13 (SCK) | LED Matrix CLK |
| Pin 2 (RX) | HC-06 TX |
| Pin 3 (TX) | HC-06 RX |
| Pin 4 | RGB LED Red |
| Pin 5 | RGB LED Green |

### Upload & Use
1. Clone this repo and open `Journal_Lumineux_2ap.ino` in Arduino IDE
2. Install required libraries via Library Manager
3. Upload to Arduino Uno
4. Pair your phone with the HC-06 module (default PIN: `1234`)
5. Use any Bluetooth serial terminal app to send messages or speed commands

---

## Project Context

Built as a 2ème année préparatoire engineering project at ISGA (2024–2025).  
Fully designed, programmed, wired, and physically assembled — the prototype was printed and tested end to end.

---

## License

MIT
