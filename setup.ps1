# ######################################################################################################################
# set `DEU_ROOT_DIR` as environment variable
# ######################################################################################################################
$DEU_ROOT_DIR = Split-Path -Parent $MyInvocation.MyCommand.Definition

# environment variable
[Environment]::SetEnvironmentVariable("DEU_ROOT_DIR", $DEU_ROOT_DIR, [EnvironmentVariableTarget]::User)

Write-Host "$DEU_ROOT_DIR has been set as a environment viriable."

# ######################################################################################################################
# add EEU directories to PATH
# ######################################################################################################################
$EEU_BIN_DIR = "$DEU_ROOT_DIR/eeu/bin"
$EEU_SCRIPTS_DIR = "$DEU_ROOT_DIR/eeu/scripts"
$oldPath = [System.Environment]::GetEnvironmentVariable("Path", "User")
$newPath = "$oldPath;$EEU_BIN_DIR;$EEU_SCRIPTS_DIR"
setx Path $newPath

Write-Host "$EEU_BIN_DIR and $EEU_SCRIPTS_DIR have been added to PATH."

# ######################################################################################################################
# add PYEU directories to PYTHONPATH
# ######################################################################################################################
$PYEU_DIR = "$DEU_ROOT_DIR/pyeu"
$oldPythonPath = [System.Environment]::GetEnvironmentVariable("PYTHONPATH", "User")
$newPythonPath = "$PYEU_DIR;$oldPythonPath"
setx PYTHONPATH $newPythonPath

Write-Host "$PYEU_DIR has been added to PYTHONPATH."
