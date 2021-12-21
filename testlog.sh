# TIMEFORMAT=%4R
# for ((i=0; i < 10; i++)); do
#     if (( i % 2 == 0)); then
#         time echo "yes" >&/dev/null
#     else
#         time isul >&/dev/null
#     fi
# done 2> fulea

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
ARGS=(
    0
    0
    2
    2
    1
    1
    0
    0
    3
)


TIMEFORMAT=%4R
COUNT=2

function benchmark_ssvm2() {
    echo benchmark_ssvm
    for ((i=0; i<"${#NAME[@]}"; ++i)); do
        LOG="mengbile$i.log"
        for ((j=0; j<$COUNT; ++j)); do
            time sleep "${ARGS[i]}"
        done 2> "$LOG"
    done
}
benchmark_ssvm2