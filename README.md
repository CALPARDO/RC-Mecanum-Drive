# Controlling FRC Robot Mecanum Drive with RC Transmitter & Receiver



## Customizing

## Defining min and max values

Change the following lines to define the minimum and the maximum value that you are getting currently from your receiver

```bash
// Mapping Constants
const int cur_min = -1000; // Change -1000
const int cur_max = 1000; // Change 1000
const int tar_min = 0; // 0 means CCW full throttle
const int tar_max = 180; // 180 means CW full throttle
```

## Defining Motor Pins

Define the digital pins that you used for motors

```bash
// Motors
const int M_1P = 13; // Motor 1 (Front Left)   Change 13
const int M_2P = 12; // Motor 2 (Front Right)  Change 12
const int M_3P = 11; // Motor 3 (Rear Left)    Change 11
const int M_4P = 10; // Motor 4 (Rear Right)   Change 10
```

## Defining Receiver Input Pins

Define the digital pins that you used to read values from the receiver

```bash
// Receiver Inputs
const int ch_xP = 1; // Horizontal Input    Change 1
const int ch_yP = 2; // Vertical Input      Change 2
const int ch_trP = 3; // Turn round         Change 3
const int ch_emP = 4; // Emergency Switch   Change 4
```
## Developer
[Calpardo](https://calpardo.com)
