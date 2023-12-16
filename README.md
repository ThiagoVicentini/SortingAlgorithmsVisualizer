# SortingAlgorithmsVisualizer
Basic application built with OpenGL to explore differents sorting algorithms. It uses the FreeGlut API, which implements the OpenGL commands.

### Bubble sort
<p align="center">
<img src="./github_images/bubblesort.gif?raw=true" height="250">
</p>

### Selection sort
<p align="center">
<img src="./github_images/selectionsort.gif?raw=true" height="250">
</p>

### Double-Selection sort
<p align="center">
<img src="./github_images/dselectionsort.gif?raw=true" height="250">
</p>

## How to use
### Installing freeglut on Ubuntu
```
$ sudo apt-get install mesa-common-dev
$ sudo apt-get install freeglut3-dev
```

### Compile
```
make
```

### Run
```
make run
```

### Usage
* Use the 'r' key to regenerate the array
* Use the 'b' key to sort with bubble sort
* Use the 's' key to sort with selection sort
* Use the 'd' key to sort with double-selection sort
* Use the 'S' key to sort with c++ standart sort implementation