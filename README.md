# Google Maps Points of Interest (POI) Parser

This program parses and processes coordinates of points of interest from a Google Maps data file. The file has the following format:

N
POI1
POI2
...


Each POI has the format: `latitudine longitudine denumire_POI`, where latitude and longitude are expressed in [degrees minutes seconds]. Degrees, minutes, and seconds are integers, and the name is a character string with a maximum length of 100.

## Features

1. **Read File and Create Structures**: Reads the file and stores the data in a dynamically allocated array of structures.

2. **Validate Coordinates**: Verifies that the coordinates adhere to the format: latitude [-90, +90], longitude [-180, 180], and minutes/seconds [0, 60].

3. **Display Points of Interest**: Displays points of interest containing the word "teatru" in their name.

4. **Write Romanian POIs to File**: Writes to another file the points of interest located within the territory of Romania (43° < latitude < 48° and 20° < longitude < 29°).

## How to Use

1. Create a text file with the points of interest data in the specified format.
2. Compile the program using a C compiler.
3. Run the executable, providing the input file as an argument.
4. Check the console for the results and messages.
