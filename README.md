## Overview

This project is an example of a cross-platform project to
build executables for Windows and OS X using cocos2d-x.

This project organization allows you to pull changes to
cocos2d-x and then build your project against these.

I created this project from _samples/Cpp/HelloCpp_.

## Setup

Clone csusbdt/cocos2d-x into the same folder that will contain this project (multiproj).
The following shows how to do this within a folder named _git_ under your
home directory (~).

    cd ~/git
    git clone https://github.com/csusbdt/cocos2d-x
    git clone https://github.com/csusbdt/multiproj.git
 

## Under Xcode

Start Xcode and load the multiproj project.  Try to build and run.
In my case, the project would compile but not launch.  I needed to do the following.

- Select Product ... Scheme ... Edit Scheme.
- Select the Info tab.
- Set the Executable to HelloCpp.app.

Also, you need to set the working directory to the Resource folder.
Do the following.

- Select Product ... Scheme ... Edit Scheme.
- Select the Options tab.
- Check the box to set a custom working directory.
- Set the working directory to ``$(SRCROOT)/../Resources``.


## Project Creation Notes

These are my notes on how I set up the project.  You don't need to do these
if you are working from the multiproj project.

Set the search path for include files to the following.

    "$(SDKROOT)/usr/include/libxml2/" "$(SRCROOT)/../../cocos2d-x/cocos2dx/include" "$(SRCROOT)/../../cocos2d-x/cocos2dx" "$(SRCROOT)/../../cocos2d-x/cocos2dx/platform/mac" "$(SRCROOT)/../../cocos2d-x/cocos2dx/kazmath/include"


