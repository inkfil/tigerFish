# *tigerFish*

An Image Processing Utility using C++.

###### Directory Structure.

```
../
└── tigerFish/
	├── CMakeLists.txt
	├── main.cpp
	├── include/
	│   ├── stb_image.h
	│   ├── stb_image_writer.h
	│   ├── base64.hpp
	│   └──image.h
	└── src/
	    └── image.cpp
```


#### Dependencies:
1. [Stb_image](https://github.com/nothings/stb/tree/master)
2. [Base64](https://github.com/tobiaslocker/base64/tree/master)

#### Image Class Members:
01. read images in memory from disk.
02. write images to disk from memory.
03. grayscaleAvg
04. grayscaleLum
05. grayscaleToRGB
06. colorMask
07. encodeMessage
08. decodeMessage
09. diffMap
10. diffMapScale

<!-- 
```
tigerFish/
└── src
	├── Oscillator/
	│   ├── SineOscillator.cpp
	│   ├── SquareOscillator.cpp
	│   ├── SawToothOscillator.cpp
	│   |	├── ForwardSawToothOscillator.cpp
	│   |	└── InverseSawToothOscillator.cpp
	│   ├── TriangleOscillator.cpp
	│   └── PulseOscillator.cpp
	├── Filter/
	│   ├── LowPassFilter.cpp
	│   └── HighPassFilter.cpp
	│   └── LowShelfFilter.cpp
	│   └── HighShelfFilter.cpp
	│   └── BandPassFilter.cpp
	│   └── PeakFilter.cpp
	│   └── NotchFilter.cpp
	├── Envolopes/
	|   ├── .cpp
	|   ├── .cpp
	|   ├── .cpp
	|   └── .cpp
	├── DSP/
	└── Libs/
	    ├── .cpp
	    ├── .cpp
	    ├── .cpp
	    └── .cpp
```
-->
