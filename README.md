# librpiplc
### by Industrial Shields

**librpiplc** implements useful functions to use Raspberry based Industrial Shields PLCs for industrial environments. It also contains some adaptations based on the code structure of the Arduino IDE to make it more familiar.


## Licensing
This library is licensed under the LGPL-3.0-or-later. The test programs are licensed under the GPL-3.0-or-later.


## Prerequisites

### One of our PLCs: https://www.industrialshields.com/

### Installing Git and CMake

1. Start by updating the package manager:
```
sudo apt update
```

2. Run the following command to install Git and CMake: 
```
sudo apt install git cmake
```

3. Verify the installation by typing the following commands, which will print the versions of each package:
```
git --version && cmake --version
```


### `/boot/config.txt` setup
Make sure that the `/boot/config.txt` file has all the parameters appropriate for your Raspberry PLC version.

**TODO: Method to only install /boot/config.txt, without using install.sh**



## Installing

### Normal procedure

1. Go to the directory where you want the library repository to be. For example, in your *home*:
```
cd
```

2. Run the following command to clone the repository:
```
git clone -b v<tag-version> https://github.com/Industrial-Shields/librpiplc.git
```
Where `<tag-version>` is the version number you wish to download. Before this unification, you had to choose between versions 1.X.X (for V3 PLCs) or 2.X.X (for V4 PLCs). As of 3.X.X, this library is compatible with all our Raspberry PLCs regardless of it's version. At the moment of writing, this library is available to Raspberry PLCs V6, V4 and V3.
You can check the available versions in here: https://github.com/Industrial-Shields/librpiplc/tags

3. Go to the library directory and install the library with the following commands:
```
cd librpiplc/
cmake -B build/ -DPLC_VERSION=<version> -DPLC_MODEL=<model>
cmake --build build/ -- -j $(nproc)
sudo cmake --install build/
sudo chown -R $USER:$USER ~/test/
sudo ldconfig
```
Where `<version>` is the [version number](#available-versions) and `<model>` is the [model number](#model-number). For example, if you want to build the library, including the tests for the Raspberry PLC 21 V4:
```
cmake -B "build" -DPLC_VERSION=RPIPLC_V4 -DPLC_MODEL=RPIPLC_21
cmake --build build/ -- -j $(nproc)
sudo cmake --install build/
sudo chown -R $USER:$USER ~/test/
sudo ldconfig
```
If you don't want to install the test files for your PLC, you can skip the version and model flags:
```
cmake -B "build"
cmake --build build/ -- -j $(nproc)
sudo cmake --install build/
sudo ldconfig
```

### Other options
If you want to compile the tests for all PLC versions, or all PLC models, or both, you can pass "ALL" to the `cmake -B` command. This command will build for all versions and models of our PLCs (it may take a while to complete!):
```
cmake -B "build" -DPLC_VERSION=ALL -DPLC_MODEL=ALL
```
And if you want to compile in Debug mode (with sanitizing included), call `cmake -B` with `-DCMAKE_BUILD_TYPE=Debug`:
```
cmake -B "build" -DPLC_VERSION=ALL -DPLC_MODEL=ALL -DCMAKE_BUILD_TYPE=Debug
```


## Compilation
**g++** is a GNU project C and C++ compiler. When you invoke **g++**, it normally does preprocessing, compilation, assembly and linking. This program can also accept options and file names as operands. If you want to compile your program to use our library (or you want to manually compile our tests), you have to call **g++** with the following arguments:
```
g++ -o file file.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -D PLC_VERSION -D PLC_MODEL
```

If you already had our library installed (because you are using one of our images), you have to change the included paths from `/usr/local...` to `/usr...`:
```
g++ -o file file.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -D PLC_VERSION -D PLC_MODEL
```

`-o file`: Place the output executable in file `file`.

`-l library`. Search the library named `library` when linking.

`-I dir`. Add the directory `dir` to the list of directories to search for header files. This line is needed in order to search for the librpiplc library headers.

`-D name=definition`. It is used to define macros before preprocessing occurs. It is ideal to define configuration macros, like the version or the model of the PLC.

Examples to build the program for Raspberry PLC 38AR V3:
```
g++ -o file file.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -D RPIPLC_V3 -D RPIPLC_38AR
```
or if you have the original image
```
g++ -o file file.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -D RPIPLC_V3 -D RPIPLC_38AR
```


*Know more: https://linux.die.net/man/1/g++*



## Reference
librpiplc contains several tests in order to verify the correct operation of the PLCs:

1. [Arduino setup() and loop() functions](#loop-setup-functions)
1. [set-digital-output](#set-digital-output)
1. [set-analog-output](#set-analog-output)
1. [set-pwm-output](#set-pwm-output)
1. [get-digital-input](#get-digital-input)
1. [get-analog-input](#get-analog-input)
1. [analogBlink](#analogBlink)
1. [analogBlinkAll](#analogBlinkAll)
1. [analogRead](#analogRead)
1. [delay](#delay)
1. [digitalBlink](#digitalBlink)
1. [digitalBlinkAll](#digitalBlinkAll)
1. [digitalRead](#digitalRead)
1. [Available PLC versions](#available-versions)
1. [Available PLC models](#available-models)


### <a name="loop-setup-functions"></a>Arduino **setup()** and **loop()** functions
In Arduino sketches you must define at least these two functions:
1. **setup()**: A function that is called only once when booting up the PLC.
1. **loop()**: A function that will be continuously called when it ends or returns.

This approach is completely different from C/C++ programs in other environments such as GNU/Linux, where you only need to declare the function **int main(int argv, const char* argc[])**. This function must return an integer, which will be 0 if the process was terminated correctly, or some other integer if there was an error. The two arguments that it accepts (if given) are the number of arguments given in the program call, and an array of those arguments.

Some of the examples we provide with the library use this approach because it's the standard way to write C/C++ programs. However, our library also allows you to write programs the Arduino way by declaring the ``__ARDUINO_FUNCTIONS__`` macro before including the library header:
```
#define __ARDUINO_FUNCTIONS__
#include <rpiplc.h>
```
With this definition you can omit the **main()** function and use the **setup()** and **loop()** functions. But remember that, in order to exit the program without killing it externally, you will need to call **exit(EXIT_NUM)**, where **EXIT_NUM** is an integer that indicates whether the process exited successfully or not.


### <a name="set-digital-output"></a>set-digital-output
This application sets a digital output or relay to the specified value.

The **main()** function first checks that the given arguments are correct, and then initializes the pin ICs with the **initExpandedGPIO(restart)** function. Then, as in Arduino programming, it sets the given pin to output mode, and it writes to it the specified value in the second parameter: either 1 (HIGH) or 0 (LOW).

Apart from using the `build.sh` script, you can build the executable file called `set-digital-output` with **g++**. Assuming you are inside the `librpiplc/tests/src` directory:
```
g++ -o set-digital-output set-digital-output.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o set-digital-output set-digital-output.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the compiled file named `set-digital-output` with two parameters:
1. The output to control
1. The value to set
```
./set-digital-output Q0.0 1
```

And see how the Q0.0 output activates.


### <a name="set-analog-output"></a>set-analog-output
This application sets an analog output to the specified value.

The **main()** function first checks that the given arguments are correct, and then initializes the pin ICs with the **initExpandedGPIO(restart)** function. Then, as in Arduino programming, it sets the given pin to output mode, and it writes to it the specified value in the second parameter: from 0 to 4095 (12 bits).

Apart from using the `build.sh` script, you can build the executable file called `set-analog-output` with **g++**:
```
g++ -o set-analog-output set-analog-output.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o set-analog-output set-analog-output.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the compiled file named `set-analog-output` with two parameters:
1. The output to control
1. The value to set
```
./set-analog-output Q0.5 1024
```
And see how Q0.5 outputs around 2.5V.


### <a name="set-pwm-output"></a>set-pwm-output
This application sets a digital output to the specified PWM value.

The **main()** function first checks that the given arguments are correct, and then initializes the pin ICs with the **initExpandedGPIO(restart)** function. Then, as in Arduino programming, it sets the given pin to output mode, and it writes to it the specified value in the second parameter: from 0 to 4095 (12 bits).

Apart from using the `build.sh` script, you can build the executable file called `set-pwm-output` with **g++**:
```
g++ -o set-pwm-output set-pwm-output.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o set-pwm-output set-pwm-output.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

All the digital outputs can output PWM signals using the `set-pwm-output` program, but using it in digital outputs.
Execute the compiled file named `set-pwm-output` with two parameters:
1. The digital output to control
1. The PWM (analog) value to set (from 0 to 4095)
```
./set-pwm-output Q0.1 2047
```
This will output a 50% duty cycle PWM in Q0.1.


### <a name="get-digital-input"></a>get-digital-input
This application prints out the value of a digital input.

The **main()** function first checks that the given arguments are correct, and then initializes the pin ICs with the **initExpandedGPIO(restart)** function. Then, as in Arduino programming, it sets the given pin to input mode, and it prints it's value: 0 or 1.

Apart from using the `build.sh` script, you can build the executable file called `get-digital-output` with **g++**:
```
g++ -o get-digital-input get-digital-input.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o get-digital-input get-digital-input.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the compiled file named `get-digital-input` with the input as parameter.
```
./get-digital-input I0.0
1
```
And it will print the value of I0.0 at the moment.


### <a name="get-analog-input"></a>get-analog-input
This application prints out the value of an analog input.

The **main()** function first checks that the given arguments are correct, and then initializes the pin ICs with the **initExpandedGPIO(restart)** function. Then, as in Arduino programming, it sets the given pin to input mode, and it prints it's analog value.

Apart from using the `build.sh` script, you can build the executable file called `get-analog-output` with **g++**:
```
g++ -o get-analog-input get-analog-input.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o get-analog-input get-analog-input.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the compiled file named `get-analog-input` with the input as parameter.
```
./get-analog-input I0.7
1330
```
And it will print the value of I0.0 at the moment.


### <a name="analogBlink"></a>analogBlink
This application shows the simplest thing you can do to see physical outputs: it blinks the on-board LEDs from the analog outputs.

In the **setup()** function we configure all the analog outputs as **OUTPUT**s:
```
void setup() {
	printf("Number of analog outputs: %ld\n", numAnalogOutputs);
	
	for (size_t i = 0; i < numAnalogOutputs; i++) {
		pinMode(analogOutputs[i], OUTPUT);
	}
}
```

And in the **loop()** function, all the analog outputs are written with the different analog values, with a 1000 milliseconds delay for every loop.

```
void loop() {
	for (size_t i = 0; i < numValues; i++) {
		printf("Set value %d\n", values[i]);

		for (size_t j = 0; j < numAnalogOutputs; j++) {
			analogWrite(analogOutputs[j], values[i]);
		}

		delay(1000);
	}
}
```

To compile the executable file called `analogBlink` with **g++**:
```
g++ -o analogBlink analogBlink.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o analogBlink analogBlink.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the created file named `analogBlink` to run the application, and you will get an output every 1000 milliseconds: 
```
./analogBlink
Number of analog outputs: 3
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


### <a name="analogBlinkAll"></a>analogBlinkAll
This application is the same as <a name="analogBlink"></a>analogBlink, but it is more efficient when doing so. It uses the `analogWriteAll` function, which requires many fewer I2C cycles than calling analogWrite for each pin. It currently applies to all output pins.

To compile the executable file called `analogBlinkAll` with **g++**:
```
g++ -o analogBlinkAll analogBlinkAll.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o analogBlinkAll analogBlinkAll.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the created file named `analogBlinkAll` to run the application, and you will get an output every 1000 milliseconds:
```
./analogBlinkAll
Number of analog outputs: 3
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


### <a name="analogRead"></a>analogRead
The analogRead application reads and prints the value from all the analog input pins.

In this **setup()** function, all the inputs are set as analog inputs:
```
void setup() {
	printf("Number of analog inputs: %ld\n", numNamedAnalogInputs);
	
	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		pinMode(namedAnalogInputs[i].pin, INPUT);
	}
}
```

In the **loop()** function below, it prints out all the analog input values, and there is a 1000 milliseconds delay after that.
```
void loop() {
	for (size_t i = 0; i < numNamedAnalogInputs; i++) {
		uint16_t value = analogRead(namedAnalogInputs[i].pin);
		printf("Pin %s value: %u\n", namedAnalogInputs[i].name, value);
	}

	printf("\n");
	delay(1000);
}
```

To compile the executable file called `analogRead` with **g++**:
```
g++ -o analogRead analogRead.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o analogRead analogRead.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the created file named `analogRead` to run the application, and you will get an output every 1000 milliseconds:
```
./analogRead
Number of analog inputs: 6
Pin I0.7 value: 0
Pin I0.8 value: 3840
Pin I0.9 value: 0
Pin I0.10 value: 0
Pin I0.11 value: 1971
Pin I0.12 value: 0
```


### <a name="delay"></a>Delay
The delay application prints an incremental number every second (the time specified by the `delay` function). This function accepts as argument the number of milliseconds it has to wait before resuming execution.
```
int counter = 0;

void setup() {}

void loop() {
	printf("%d\n", counter++);
	delay(1000);
}
```

Compile the application executing the following command:
```
g++ -o delay delay.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o delay delay.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```

And if you run it executing the following, you will get an output every 1000 milliseconds:
```
./delay
0
1
2
3
4
5
```


### <a name="digitalBlink"></a>digitalBlink
This application shows the on-board LEDs blinking from the digital outputs. The values change every 1000 milliseconds.

The **setup()** function configures all the possible outputs as digital outputs.
```
void setup() {
	printf("Number of digital outputs: %ld\n", numDigitalOutputs);

	for (size_t i = 0; i < numDigitalOutputs; i++) {
		pinMode(digitalOutputs[i], OUTPUT);
	}
}
```

The **loop()** function makes all the digital output LEDs blink every 1000 milliseconds.
```
int value = 1;

void loop() {
	value = value == 0 ? 1 : 0;

	printf("Set value %d\n", value);
	for (size_t i = 0; i < numDigitalOutputs; i++) {
		digitalWrite(digitalOutputs[i], value);
	}

	delay(1000);
}
```

Compile the application executing the following command:
```
g++ -o digitalBlink digitalBlink.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o digitalBlink digitalBlink.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -DRPIPLC_V4 -DRPIPLC_21
```

The output on the terminal will show you this when you run the program:
```
./digitalBlink
Number of digital outputs: 8
Set value 0
Set value 1
Set value 0
Set value 1
Set value 0
Set value 1
```

### <a name="digitalBlinkAll"></a>digitalBlinkAll
This application is the same as <a name="digitalBlink"></a>digitalBlink, but it is more efficient when doing so. It uses the `digitalWriteAll` function, which requires many fewer I2C cycles than calling digitalWrite for each pin.

To compile the executable file called `digitalBlinkAll` with **g++**:
```
g++ -o digitalBlinkAll digitalBlinkAll.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o digitalBlinkAll digitalBlinkAll.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -DRPIPLC_V4 -DRPIPLC_21
```


Execute the created file named `digitalBlinkAll` to run the application, and you will get an output every 1000 milliseconds:
```
./digitalBlinkAll
Number of digital outputs: 8
Set value 0x0
Set value 0xFFFFFFFF
Set value 0x0
Set value 0xFFFFFFFF
Set value 0x0
Set value 0xFFFFFFFF
Set value 0x0
```


### <a name="digitalRead"></a>digitalRead
The digitalRead application reads and prints the value from all the isolated digital input pins.

In this **setup()** function, all the inputs are set as digital inputs:
```
void setup() {
	printf("Number of digital inputs: %ld\n", numNamedDigitalInputs);

	for (size_t i = 0; i < numNamedDigitalInputs; i++) {
		pinMode(namedDigitalInputs[i].pin, INPUT);
	}
}
```

In the **loop()** function below, it prints out all the digital input values, and there is a 1000 milliseconds delay after that.
```
void loop() {
	for (size_t i = 0; i < numNamedDigitalInputs; i++) {
		int value = digitalRead(namedDigitalInputs[i].pin);
		printf("Pin %s value: %u\n", namedDigitalInputs[i].name, value);
	}

	printf("\n");
	delay(1000);
}
```

To compile the executable file called `digitalRead` with **g++**:
```
g++ -o digitalRead digitalRead.cpp -l rpiplc -I/usr/local/include/librpiplc/include -I/usr/local/include/librpiplc/include/include -I../include -DRPIPLC_V4 -DRPIPLC_21
```
or if you have the original image
```
g++ -o digitalRead digitalRead.cpp -l rpiplc -I/usr/include/librpiplc/include -I/usr/include/librpiplc/include/include -DRPIPLC_V4 -DRPIPLC_21
```

Execute the created file named `digitalRead` to run the application, and you will get an output every 1000 milliseconds:
```
./digitalRead
Number of digital inputs: 8
Pin PIN8 value: 0
Pin I0.0 value: 0
Pin I0.1 value: 1
Pin I0.2 value: 1
Pin I0.3 value: 0
Pin I0.4 value: 0
Pin I0.5 value: 1
Pin I0.6 value: 0
```


### <a name="available-versions"></a>Available PLC versions
```
RPIPLC_V3 (deprecated)
RPIPLC_V4
RPIPLC_V6

UPSAFEPI_V6

GATEBERRY_V9

TOUCHBERRY_PI_V1
```


### <a name="available-models"></a>Available PLC models
```
RPIPLC_CPU
RPIPLC_19R
RPIPLC_21
RPIPLC_38AR
RPIPLC_38R
RPIPLC_42
RPIPLC_50RRA
RPIPLC_53ARR
RPIPLC_54ARA
RPIPLC_57AAR
RPIPLC_57R
RPIPLC_58

UPSAFEPI (for UPSafePis)

GATEBERRY (for GateBerries)

TOUCHBERRY_PI (for TouchBerry Pis)
```
