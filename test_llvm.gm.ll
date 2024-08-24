; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4
@0 = private unnamed_addr constant [20 x i8] c"le petit test : %d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  br label %cond

cond:                                             ; preds = %body, %entry
  %i1 = phi i32 [ 0, %entry ], [ %2, %body ]
  %0 = icmp slt i32 %i1, 25
  br i1 %0, label %body, label %loopend

body:                                             ; preds = %cond
  %1 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @0, i32 %i1)
  %2 = add i32 %i1, 1
  br label %cond

loopend:                                          ; preds = %cond
  ret i32 0
}
