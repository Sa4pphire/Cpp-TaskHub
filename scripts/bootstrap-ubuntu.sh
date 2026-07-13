#!/usr/bin/env bash

set -euo pipefail

sudo apt update
sudo apt install -y \
    build-essential \
    clang-format \
    cmake \
    curl \
    gdb \
    git \
    jq \
    libsqlite3-dev \
    sqlite3

echo "Ubuntu development tools are ready."
