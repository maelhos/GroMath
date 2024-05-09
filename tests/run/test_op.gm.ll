; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  ret i32 11
}
