# CEU: C/Cpp/CSharp/Cuda/CMake External Utils

---

1. How to Use

cmake:

```cmake
set(CEU_AUTO_SOLVE_VCPKG ON)
include("$ENV{DEU_ROOT_DIR}/ceu/ceu.cmake")
```

or you could declare a macro:

```cmake
macro(ceu_import)
    set(CEU_AUTO_SOLVE_VCPKG ON)
    include("$ENV{DEU_ROOT_DIR}/ceu/ceu.cmake")
endmacro(ceu_import)
```

