# **Example Mod for PvZ2**

# What is this?

Example Mod is an example of how function hooking (using [Cydia Substrate](http://www.cydiasubstrate.com/)) can be utilized in PvZ2. All of the addresses and function definitions are from PvZ2 9.4.1's ARM-v7a lib.  
This repository will be updated with sample code whenever I make new discoveries.

# Current Features

* Adding new internal Plant IDs
* Adding new internal Zombie IDs
* Mummy Memory crash fix

# Build Instructions

### Prerequisites
* Android Studio
* Android NDK
* Android Substrate SDK for Android Studio (see: [Android Substrate SDK](http://www.cydiasubstrate.com/id/73e45fe5-4525-4de7-ac14-6016652cc1b8/))
* Android C++ for Visual Studio 2022

After you have all the prerequisites above, simply clone the repo and open the solution in Visual Studio 2022. To build the lib, you'll need to change some of the local paths in the project:

* C/C++
* * Additional Include Directories: Change the substrate path to the root directory of the substrate path on your computer.

* Linker
* * Additional Library Directories: Change the substrate lib path to the path of the **\lib\armeabi** directory in your substrate folder.

Now you should be able to build the lib.

### APK Integration
**TODO**