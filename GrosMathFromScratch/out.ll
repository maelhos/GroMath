; ModuleID = 'GroMathllvm'
source_filename = "GroMathllvm"

@VERSION = global i32 42, align 4
@0 = private unnamed_addr constant [14 x i8] c"Gromathed %d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  %0 = call i32 @square(i32 2, i32 3)
  %1 = call i32 @square(i32 8, i32 3)
  %tmpadd = add i32 %0, %1
  %2 = call i32 (ptr, ...) @printf(ptr @0, i32 %tmpadd)
  ret i32 0
}

define i32 @square(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %a3 = load i32, ptr %a1, align 4
  %b4 = load i32, ptr %b2, align 4
  %tmpadd = add i32 %a3, %b4
  %b5 = load i32, ptr %b2, align 4
  %tmpmul = mul i32 %tmpadd, %b5
  ret i32 %tmpmul
}
