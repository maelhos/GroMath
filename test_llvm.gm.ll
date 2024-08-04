; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4
@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  br label %cond

cond:                                             ; preds = %body, %entry
  %a2 = phi i32 [ 0, %entry ], [ %tmpadd, %body ]
  %i1 = phi i32 [ 0, %entry ], [ %1, %body ]
  %0 = icmp slt i32 %i1, 1000000
  br i1 %0, label %body, label %loopend

body:                                             ; preds = %cond
  %tmpmul = mul i32 %a2, 65537
  %tmprem = srem i32 %tmpmul, 512
  %tmpadd = add i32 %tmprem, %i1
  %1 = add i32 %i1, 1
  br label %cond

loopend:                                          ; preds = %cond
  %2 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @0, i32 %a2)
  ret i32 0
}
