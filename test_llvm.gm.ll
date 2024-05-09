; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4
@0 = private unnamed_addr constant [11 x i8] c"Test : %d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @test(i32 %b) {
entry:
  %b1 = alloca i32, align 4
  store i32 %b, ptr %b1, align 4
  %a = alloca i32, align 4
  store i32 2, ptr %a, align 4
  %a2 = load i32, ptr %a, align 4
  %b3 = load i32, ptr %b1, align 4
  %b4 = load i32, ptr %b1, align 4
  %tmpmul = mul i32 %b3, %b4
  %tmpadd = add i32 %a2, %tmpmul
  ret i32 %tmpadd
}

define i32 @main(i32 %argc) {
entry:
  %argc1 = alloca i32, align 4
  store i32 %argc, ptr %argc1, align 4
  %argc2 = load i32, ptr %argc1, align 4
  %0 = call i32 @test(i32 %argc2)
  %1 = call i32 (ptr, ...) @printf(ptr @0, i32 %0)
  ret i32 0
}
