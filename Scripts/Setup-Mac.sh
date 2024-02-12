#!/bin/bash


pushd ..
Vendor\Binaries\Premake\Windows\premake5.exe --file=Build.lua xcode4
popd

