# Fetch-Challenge
Challenge for Fetch, parse a JSON format and calculate the points you get from the information inside the JSON

## Getting Started

This code is based on two parts: One is the small parse system which is inside MainCore, where we read and identify the elements of the JSON and are pointed in the right direction to the second part, Fetch is the class where we calculate all the points from the JSON inputs.

Running locally you need a Linux environment, which can be the one inside Windows (Ubuntu).

### Prerequisites

For running you need g++, at least the 9.4.0
* g++
  ```sh
  sudo apt update && sudo apt-get install g++
  ```

### Compiling

1. You will need to generate the executable `Fetch`
   ```sh
   g++ -g -Wall main.cpp Fetch.cpp -o Fetch
   ```
2. Which will generate a the file `Fetch`

<!-- USAGE EXAMPLES -->
## Usage
To use we need to execute:
   ```sh
   ./Fetch
   ```

where we call the file "readFile.txt" where the JSON inputs are. It is important to note the format of the inputs, if the "whitespace" change for the struct of the JSON, will not work properly. We will need a better parse or change the approach (library).