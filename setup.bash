#!/bin/bash
# TODO: UNTESTED

# ######################################################################################################################
# set `DEU_ROOT_DIR` as environment variable
# ######################################################################################################################
DEU_ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"

# environment variable
export DEU_ROOT_DIR="$DEU_ROOT_DIR"
echo "export DEU_ROOT_DIR=\"$DEU_ROOT_DIR\"" >>~/.bashrc

echo "$DEU_ROOT_DIR has been set as a environment viriable."

# ######################################################################################################################
# add EEU directories to PATH
# ######################################################################################################################
EEU_BIN_DIR = "$DEU_ROOT_DIR/eeu/bin"
EEU_SCRIPTS_DIR = "$DEU_ROOT_DIR/eeu/scripts"

# add EEU_BIN_DIR to PATH
if [[ ":$PATH:" != *":$EEU_BIN_DIR:"* ]]; then
    echo "export PATH=\"\$PATH:$EEU_BIN_DIR\"" >>~/.bashrc
    echo "Path added permanently to ~/.bashrc: $EEU_BIN_DIR"
else
    echo "Path already exists: $EEU_BIN_DIR"
fi

# add EEU_SCRIPTS_DIR to PATH
if [[ ":$PATH:" != *":$EEU_SCRIPTS_DIR:"* ]]; then
    echo "export PATH=\"\$PATH:$EEU_SCRIPTS_DIR\"" >>~/.bashrc
    echo "Path added permanently to ~/.bashrc: $EEU_SCRIPTS_DIR"
else
    echo "Path already exists: $EEU_SCRIPTS_DIR"
fi

# ######################################################################################################################
# add PYEU directories to PYTHONPATH
# ######################################################################################################################
PYEU_DIR = "$DEU_ROOT_DIR/pyeu"
if [[ ":$PYTHONPATH:" != *":$PYEU_DIR:"* ]]; then
    echo "export PYTHONPATH=\"\$PYTHONPATH:$PYEU_DIR\"" >>~/.bashrc
    echo "Path added permanently to ~/.bashrc: $PYEU_DIR"
else
    echo "Path already exists: $PYEU_DIR"
fi

echo "$PYEU_DIR has been added to PYTHONPATH."

# ######################################################################################################################
# source .bashrc
# ######################################################################################################################
source ~/.bashrc
