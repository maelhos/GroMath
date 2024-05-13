; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4
@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %cond

cond:                                             ; preds = %body, %entry
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 5
  br i1 %1, label %body, label %loopend

body:                                             ; preds = %cond
  %i1 = load i32, ptr %i, align 4
  %2 = call i32 (ptr, ...) @printf(ptr @0, i32 %i1)
  %3 = load i32, ptr %i, align 4
  %4 = add i32 %3, 1
  store i32 %4, ptr %i, align 4
  br label %cond

loopend:                                          ; preds = %cond
  ret i32 0
}
