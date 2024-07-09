# Porting OpenACC to OpenMP Offloading

This repository facilitates seamless translation of code written with OpenACC directives to use equivalent OpenMP directives. OpenACC is primarily designed for offloading compute-intensive operations to GPUs, whereas OpenMP is widely used for multi-threading on CPUs and can also be used for GPU offloading. This project enhances portability between these two parallel programming APIs using C macros.

# Contents
 ```
└── src 
    ├── binopenacc
    ├── binopenmp
    ├── gpuCommands.inc
    ├── laplace2d.c
    └── Makefile
```  

# How to use it 

```
git clone https://github.com/yourusername/OpenACC-to-OpenMP.git
cd OpenACC-to-OpenMP/src

make USE_OPENACC=1
or
make USE_OPENMP=1
```


# Contributing
Contributions are welcome! If you have improvements or bug fixes, please fork the repository and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.

# License
This project is licensed under the MIT License - see the LICENSE file for details.


