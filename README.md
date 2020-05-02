# SweetwaterPump
RAK5205 based TTN Device to turn on and off a pump

There is very little custom code in this project. It is based of the official [RAKWireless firmware source](https://github.com/RAKWireless/Products_practice_based_on_RUI) for the RAK5205 device. Specifically [this source](https://github.com/RAKWireless/Products_practice_based_on_RUI/tree/master/based%20on%20RAK811/app_5205)

In app_sweetwater.c you can find any custom code by searching for *pump*. This code is mostly based around sending and recieving LoRa commands. All the rest of the custom code is contained in Pump.c.  

## Note
In the US, LoRa devices need to run at 915mHZ. As it pertains to the RAK family of devices, that means you are **H**(igh frequency) not **L**(ow frequency). Throughout your development, you will run into **L**s and **H**s. Always choose **H** for the win. 

## Setup
Most everything you need to get started can be found on the [RAKWireless](https://downloads.rakwireless.com/LoRa) site.

Specifically files for the [RAK5205](https://downloads.rakwireless.com/LoRa/WisTrio-LoRa-RAK5205)

The tools are located [here](https://downloads.rakwireless.com/LoRa/Tools)

You will need the [Serial Port Tool](https://downloads.rakwireless.com/LoRa/Tools/RAK_SERIAL_PORT_TOOL_V1.2.1.zip) to put the device into boot mode, configure and see its console.

You will need the [Upgrade Tool](https://downloads.rakwireless.com/LoRa/Tools/RAK_Upgrade_Tool_V1.0.rar) to push firmware (custom or original) to the device.

If the device becomes unresponsive use the official firmware and bootloader ([available here](https://downloads.rakwireless.com/LoRa/WisTrio-LoRa-RAK5205/Firmware)) to bring it back to life. You will need the [STM32CubeProgrammer](https://downloads.rakwireless.com/LoRa/Tools/SetupSTM32CubeProgrammer-2.1.0.rar) to upload the bootloader.

## Configuration
Use the Serial Port Tool to set the device to use 915 as well as all your OTA values. Additionally the polling intervals and the like can be set using this tool.

## Building
- Make all your edits to the code then save all the files.
- Zip the contents of the src folder (NOT THE FOLDER ITSELF).
- Upload that archive to the [RUI Online Compiler](http://47.112.137.11:12090/#/user/login).
- Be sure to choose the **H** type of your device.
- If there are no errors (and even if there are), an archive will be downloaded.
- Extract the bin from the archive.
- Use the serial tool to connect to your device and put it in boot mode. 
- Close the serial tool (to close the port).
- Open the opgrade tool and locate the bin file
- Start the upload and make yourself a cup of coffee.
- Once uploaded press stop on the upgrade tool.
- Upen the serial port tool again and see what your device is doing. 

##Hardware
The device can use two sets of three consecutive pins. One set uses the 3.3v bus and the other uses 5.0v bus.
As shipped, the device is set to use the 3.3v bus to conserve power.

If you would like to use the 5.0v bus move the header pins to the other row of sockets.
Then update Pump.c to use **PA_8** instead of **PB_3**

