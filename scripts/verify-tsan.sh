#!/usr/bin/env bash

set -euo pipefail

project_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
build_dir="${project_root}/build/tsan"

cmake -E remove_directory "${build_dir}"
cmake \
    -S "${project_root}" \
    -B "${build_dir}" \
    -DCMAKE_BUILD_TYPE=Debug \
    -DTASKHUB_WARNINGS_AS_ERRORS=ON \
    -DTASKHUB_ENABLE_TSAN=ON
cmake --build "${build_dir}" --parallel
ctest --test-dir "${build_dir}" --output-on-failure

echo "ThreadSanitizer build and test run completed successfully."
