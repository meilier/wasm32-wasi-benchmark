NAME=(
    nop
    cat-sync
    nbody-c
    nbody-cpp
    fannkuch-redux-c
    mandelbrot-c
    mandelbrot-simd-c
    binary-trees-c
    fasta-c
)

function print_result() {
    for type in native ssvm lucet wavm wasmer_singlepass wasmer_cranelift wasmer_llvm wasmer_singlepass_native wasmer_cranelift_native wasmer_llvm_native wasmer_jit docker; do
        echo -n ,"$type"
    done
    echo
    for name in "${NAME[@]}"; do
        echo -n "$name"
        for type in native ssvm lucet wavm wasmer_singlepass wasmer_cranelift wasmer_llvm wasmer_singlepass_native wasmer_cranelift_native wasmer_llvm_native wasmer_jit docker; do
            echo -n ,"$(awk 'function abs(x){return ((x < 0.0) ? -x : x)} {sum+=$0; sumsq+=($0)^2} END {mean = sum / NR; error = sqrt(abs(sumsq / NR - mean^2)); printf("%.3f(%.3f)", mean, error)}' benchmark/"$type"/"$name".log)"
        done
        echo
    done | tee result.csv
}

print_result