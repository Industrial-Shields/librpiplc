# RPIPLC-LIB library


### by Industrial Shields
Rpiplc-lib implements some common applications on industrial environments for Raspberry based Industrial Shields PLC, based on the code structure as the Arduino IDE.

## Getting started


### Prerequisites

Raspberry based Industrial Shields PLC.

### Installing Git

**1**. Start by updating the package manager:

```sudo apt update```

**2**. Run the following command to install Git: 

```sudo apt install git```

**3**. Verify the installation by typing the following command which will print the Git version.

```git --version```


### Installation

**1**. Go to the directory where you want to have the library.

**2**. Run the following command to clone the repository:

```git clone https://github.com/Industrial-Shields/rpiplc-lib.git```
Note: 

**3**. Access to the directory and execute the makefile:

```cd rpiplc-lib```

```make```

```sudo make install```

**4**. Now, you can open any file from the rpiplc-lib/ directory.

**5**. Finally, go to the /boot/config.txt file:
```
sudo nano /boot/config.txt
```

**6**. Comment all the following lines by adding a hash mark at the beginning of the lines like this:

```
#dtoverlay=mcp23017,noints,mcp23008,addr=0x20
#dtoverlay=mcp23017,noints,mcp23008,addr=0x21

#dtoverlay=i2c-pwm-pca9685a,addr=0x40
#dtoverlay=i2c-pwm-pca9685a,addr=0x41

#dtoverlay=ads1015,addr=0x48
#dtparam=cha_enable=true,cha_gain=1
#dtparam=chb_enable=true,chb_gain=1
#dtparam=chc_enable=true,chc_gain=1
#dtparam=chd_enable=true,chd_gain=
#dtoverlay=ads1015,addr=0x49
#dtparam=cha_enable=true,cha_gain=1
#dtparam=chb_enable=true,chb_gain=1
#dtparam=chc_enable=true,chc_gain=1
#dtparam=chd_enable=true,chd_gain=1
#dtoverlay=ads1015,addr=0x4a
#dtparam=cha_enable=true,cha_gain=1
#dtparam=chb_enable=true,chb_gain=1
#dtparam=chc_enable=true,chc_gain=1
#dtparam=chd_enable=true,chd_gain=1
#dtoverlay=ads1015,addr=0x4b
#dtparam=cha_enable=true,cha_gain=1
#dtparam=chb_enable=true,chb_gain=1
#dtparam=chc_enable=true,chc_gain=1
#dtparam=chd_enable=true,chd_gain=1
```
**7** Reboot the system to apply changes:

```sudo reboot now```


### Compilation

**g++** is a GNU project C and C++ compiler. When you invoke GCC, it normally does preprocessing, compilation, assembly and linking. The gcc program accepts options and file names as operands. 
Compile the rpiplc-lib applications with the essential parameters:

```g++ -o file file.cpp -L /usr/local/lib -l rpiplc -I /usr/local/include/rpiplc -D DEVICE_MODEL```

**-o** file: Place output in file file.

**-l** library. Search the library named library when linking.

**-I** dir. Add the directory dir to the list of directories to be searched for header files. Directories named by -I are searched before the standard system include directories.

**-D** name=definition. The contents of definition are tokenized and processed as if they appeared during translation phase three in a #define directive.

*Know more: https://linux.die.net/man/1/g++*

## Reference


Rpiplc-lib contains different applications:

0. [Main](#main-0)
1. [AnalogBlink](#analog-blink)
2. [AnalogRead](#analog-read)
3. [Delay](#delay-1)
4. [DigitalBlink](#digital-blink)
5. [DigitalRead](#digital-read)


### <a name="main-0"></a>Main
All the applications must implement the main function that looks like the example below:
```
int main(int argc, char* argv[]) {
    initPins();

    setup();

    while (1) {
        loop();
    }
    
    return 0;
}
```

The main() function will call the setup() and loop() function so that they can be executed.


### <a name="analog-blink"></a>AnalogBlink

```
#include <rpiplc.h>
#include "common.h"
```

This application shows the simplest thing you can do to see physical outputs: it blinks the on-board LEDs from the analog outputs.

The pinMode function, like in Arduino, configures the specified pin to behave either as an input or an output. In the setup function, all the analog outputs are set as outputs:
```
void setup() {
  for (int i = 0; i < numAnalogOutputs; ++i) {
    pinMode(analogOutputs[i], OUTPUT);
  }
}
```

In the loop function, all the analog outputs are written with the different analog values, with a 1000 milliseconds delay in every loop.

```
void loop() {
  for (int i = 0; i < numValues; ++i) {
    printf("Set value %d\n", values[i]);

    for (int j = 0; j < numAnalogOutputs; ++j) {
      analogWrite(analogOutputs[j], values[i]);
    }

    delay(1000);
  }
}
```

So, in the ~/rpiplc-lib/test directory, execute the following command to create an executable file called analogBlink:
```
g++ -o analogBlink analogBlink.cpp -l rpiplc -I  /usr/local/include/rpiplc -D RPIPLC_58
```

Execute the created file named analogBlink, to run the application:
```
./analogBlink
```

and start getting an output every 1000 milliseconds:
```
Set value 0
Set value 511
Set value 1023
Set value 2047
Set value 4095
Set value 2047
Set value 1023
Set value 511
Set value 0
```

### <a name="analog-read"></a>AnalogRead
The analogRead application reads the value from the analog input pins. In this setup function, all the inputs are set as analog inputs:

```
void setup() {
  for (int i = 0; i < numAnalogInputs; ++i) {
    pinMode(analogInputs[i], INPUT);
  }
}
```

In the loop function below, it prints out all the analog input values, and there is a 1000 milliseconds delay after that.

```
void loop() {
  for (int i = 0; i < numAnalogInputs; ++i) {
    uint16_t value = analogRead(analogInputs[i]);
    printf("Pin %08x value: %u\n", analogInputs[i], value);
  }
  delay(1000);
}
```

Compile the application executing the following command:
```
g++ -o analogRead analogRead.cpp -l rpiplc -I /usr/local/include/rpiplc -DRPIPLC_58 (or any other Raspberry PLC model)
```

Run it executing the following:
```
./analogRead
```

The output on the terminal will be shown like this:
```
Pin 00004a00 value: 1
Pin 00004a01 value: 1
Pin 00004b00 value: 1
Pin 00004802 value: 1
Pin 00004800 value: 2
Pin 00004801 value: 2
Pin 00004900 value: 1
Pin 00004a03 value: 1
Pin 00004b02 value: 2
Pin 00004b03 value: 2
Pin 00004a02 value: 2
Pin 00004901 value: 1
Pin 00004903 value: 2
Pin 00004902 value: 1
Pin 00004803 value: 2
Pin 00004b01 value: 1
```

### <a name="delay-1"></a>Delay
The delay application pauses the program for the amount of time (in milliseconds) specified as parameter. 

Syntax:

delay(ms) - ms: the number of milliseconds to pause.
```
int counter = 0;
void setup() {
}

void loop() {
  printf("%d\n", counter++);
  delay(1000);
}
```

Compile the application executing the following command:
```
g++ -o delay delay.cpp -l rpiplc -I /usr/local/include/rpiplc -DRPIPLC_58 (or any other Raspberry PLC model)
```

Run it executing the following:
```
./delay
```

The example file in the rpiplc-lib/test directory, delays the program and it prints a counter every 1000 milliseconds. The output is shown like this:
```
0
1
2
3
4
5
```

### <a name="digital-blink"></a>DigitalBlink

This application shows the on-board LEDs blinking from the digital outputs. The values change every 1000 milliseconds.

The setup function configures all the possible outputs as digital outputs.

```
void setup() {
  printf("Num digital outputs: %d\n", numDigitalOutputs);
  for (int i = 0; i < numDigitalOutputs; ++i) {
    pinMode(digitalOutputs[i], OUTPUT);
  }
}
```

The loop function makes all the digital output LEDs blink every 1000 milliseconds.
```
void loop() {
  value = value == 0 ? 1 : 0;

  printf("Set value %d\n", value);
  for (int i = 0; i < numDigitalOutputs; ++i) {
    digitalWrite(digitalOutputs[i], value);
  }

  delay(1000);
}
```

Compile the application executing the following command:
```
g++ -o digitalBlink digitalBlink.cpp -l rpiplc -I /usr/local/include/rpiplc -DRPIPLC_58 (or any other Raspberry PLC model)
```

Run it executing the following:
```
./digitalBlink
```

The output on the terminal will be shown like this:

```
Num digital outputs: 24

Set value 1
Set value 0
Set value 1
Set value 0
Set value 1
```

### <a name="digital-read"></a>DigitalRead

The digitalRead application reads the value from the digital input pins. In this setup function, all the inputs are set as digital inputs:

```
void setup() {
  printf("Num digital inputs: %d\n", numDigitalInputs);
  for (int i = 0; i < numDigitalInputs; ++i) {
    pinMode(digitalInputs[i], INPUT);
  }
}
```

In the loop function below, it prints out all the digital input values, and there is a 1000 milliseconds delay after that.

```
void loop() {
  for (int i = 0; i < numDigitalInputs; ++i) {
    int value = digitalRead(digitalInputs[i]);
    printf("Pin %08x value: %u\n", digitalInputs[$
  }
  delay(1000);
}
```

To run the application, execute the following command:
```
g++ -o digitalRead digitalRead.cpp -lrpiplc -I/usr/local/include/rpiplc -DRPIPLC_58 (or any other Raspberry PLC model)
```

Run it executing the following:
```
./digitalRead
```

The output on the terminal will be shown like this:
```
Pin 00002105 value: 0
Pin 00002103 value: 0
Pin 00002102 value: 0
Pin 00002101 value: 0
Pin 00002100 value: 0
Pin 0000000d value: 0
Pin 0000000c value: 0
Pin 00002002 value: 0
Pin 00002001 value: 0
Pin 00002000 value: 0
Pin 00002107 value: 0
Pin 00002106 value: 0
Pin 0000001b value: 0
Pin 00000004 value: 0
Pin 00002006 value: 0
Pin 00002005 value: 0
Pin 00002007 value: 0
Pin 00002004 value: 0
Pin 00002003 value: 0
Pin 00000011 value: 0
Pin 00000010 value: 0
```

