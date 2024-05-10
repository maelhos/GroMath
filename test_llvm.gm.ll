; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4
@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @fib(i32 %n) {
entry:
  %n1 = alloca i32, align 4
  store i32 %n, ptr %n1, align 4
  %n2 = load i32, ptr %n1, align 4
  %tmpcmp = icmp eq i32 %n2, 0
  br i1 %tmpcmp, label %then, label %else

then:                                             ; preds = %entry
  ret i32 1

else:                                             ; preds = %entry
  %n3 = load i32, ptr %n1, align 4
  %tmpcmp4 = icmp eq i32 %n3, 1
  br i1 %tmpcmp4, label %then5, label %ifend

then5:                                            ; preds = %else
  ret i32 1

ifend:                                            ; preds = %else
  %n6 = load i32, ptr %n1, align 4
  %tmpsub = sub i32 %n6, 1
  %0 = call i32 @fib(i32 %tmpsub)
  %n7 = load i32, ptr %n1, align 4
  %tmpsub8 = sub i32 %n7, 2
  %1 = call i32 @fib(i32 %tmpsub8)
  %tmpadd = add i32 %0, %1
  ret i32 %tmpadd

ifend9:                                           ; No predecessors!
}

define i32 @main() {
entry:
  %0 = call i32 @fib(i32 10)
  %1 = call i32 (ptr, ...) @printf(ptr @0, i32 %0)
  ret i32 0
}
