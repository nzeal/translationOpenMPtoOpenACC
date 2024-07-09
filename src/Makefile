# Compiler
CC = nvc

# Compiler options
MP  = -mp=gpu -gpu=cc80 -Minfo=all -fast -DUSE_OPENMP
ACC = -acc -gpu=cc80 -Minfo=accel -fast -DUSE_OPENACC

# NVTX library include path
NVTXLIB := -I/leonardo/prod/spack/03/install/0.19/linux-rhel8-icelake/gcc-8.5.0/nvhpc-23.1-x5lw6edfmfuot2ipna3wseallzl4oolm/Linux_x86_64/23.1/cuda/include/

# Options selection based on defined macros
ifdef USE_OPENACC
	OPTIONS = $(ACC)
	BIN = binopenacc
else ifdef USE_OPENMP
	OPTIONS = $(MP)
	BIN = binopenmp
else
	OPTIONS =
	BIN = binary
endif

# Rule to build the binary from the source file
all: $(BIN)

$(BIN): laplace2d.c
	$(CC) $(OPTIONS) $(NVTXLIB) -o $(BIN) $<

# Rule to clean up the binary
clean:
	$(RM) binopenacc binopenmp binary

