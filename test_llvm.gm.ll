; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4
@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @sum(i32 %n) {
entry:
  %n1 = alloca i32, align 4
  store i32 %n, ptr %n1, align 4
  %n2 = load i32, ptr %n1, align 4
  %tmpcmp = icmp eq i32 %n2, 0
  br i1 %tmpcmp, label %then, label %ifend

then:                                             ; preds = %entry
  ret i32 0
  br label %ifend

ifend:                                            ; preds = %then, %entry
  %n3 = load i32, ptr %n1, align 4
  %tmpsub = sub i32 %n3, 1
  %1 = call i32 @sum(i32 %tmpsub)
  %n4 = load i32, ptr %n1, align 4
  %tmpadd = add i32 %1, %n4
  ret i32 %tmpadd
}

define i32 @main() {
entry:
  %0 = call i32 @sum(i32 10)
  %1 = call i32 (ptr, ...) @printf(ptr @0, i32 %0)
  ret i32 0
}
