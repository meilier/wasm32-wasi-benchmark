#!/usr/bin/env bash

# This script print benchmark result to result.csv.
# We do this excluding mandelbrot SIMD test, for wasmtime which do not support SIMD completely now.

NAME=(
    nop
    cat-sync
    nbody-c
    nbody-cpp
    fannkuch-redux-c
    mandelbrot-c
    binary-trees-c
    fasta-c
)

function print_result() {
    echo -n native > result.csv
    for type in ssvm lucet wavm wasmer_singlepass wasmer_cranelift wasmer_llvm wasmer_cranelift_native wasmer_llvm_native wasmer_jit wasmtime_jit wasmtime_cranelift_native docker; do
        echo -n ,"$type"
    done >> result.csv

    echo >> result.csv

    for name in "${NAME[@]}"; do
        echo -n "$name"
        for type in native ssvm lucet wavm wasmer_singlepass wasmer_cranelift wasmer_llvm wasmer_cranelift_native wasmer_llvm_native wasmer_jit wasmtime_jit wasmtime_cranelift_native docker; do
            echo -n ,"$(awk 'function abs(x){return ((x < 0.0) ? -x : x)} {sum+=$0; sumsq+=($0)^2} END {mean = sum / NR; error = sqrt(abs(sumsq / NR - mean^2)); printf("%.3f(%.3f)", mean, error)}' benchmark/"$type"/"$name".log)"
        done
        echo
    done | tee >> result.csv
}

print_result