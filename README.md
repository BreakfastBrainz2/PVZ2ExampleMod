# **Example Mod for PvZ2**

# Credits

[Smali lib loader](https://github.com/joeyjurjens/Android-Hooking-Template) by **joeyjurjens** 

# What is this?

Example Mod is an example of how function hooking (using [Cydia Substrate](http://www.cydiasubstrate.com/)) can be utilized in PvZ2. All of the addresses and function definitions are from PvZ2 9.4.1's ARM-v7a lib.

Update 1/10/2025: I've seen people perpetuating the myth that code injection is "unstable" - it's not. The only way for code injection to become unstable is if the code you inject is buggy. 
Please don't let this myth deter you from potentially using code injection in your mod.

# Current Features

* Adding new internal Plant IDs
* Adding new internal Zombie IDs
* Mummy Memory crash fix

# Build Instructions

### Prerequisites
* Android Studio
* Android Substrate SDK for Android Studio (see: [Android Substrate SDK](http://www.cydiasubstrate.com/id/73e45fe5-4525-4de7-ac14-6016652cc1b8/))
* Android C++ for Visual Studio 2022

After you have all the prerequisites above, simply clone the repo and open the solution in Visual Studio 2022. To build the lib, you'll need to change some of the local paths in the project:

* C/C++
* * Additional Include Directories: Change the substrate path to the root directory of the substrate path on your computer.

* Linker
* * Additional Library Directories: Change the substrate lib path to the path of the **\lib\armeabi** directory in your substrate folder.

Now you should be able to build the lib. Before attempting a build, make sure the config is set to Debug ARM and not Debug x64 or anything else.

### APK Integration

* Build the lib and copy the resulting lib to the **lib\armeabi-v7a** folder in your APK.
* Delete the **arm64-v8a** folder in the lib folder.
* Copy both of the libs in this repo's **deps\lib\armeabi-v7a** folder to the **lib\armeabi-v7a** folder in your APK.
* Copy the **smali** folder in this repo's **deps** folder and paste it into the root of your APK. This will automatically place the files where they need to go.
* Rebuild your APK, install it, and play. Your custom code will be injected into PvZ2 as soon as the app is opened.
