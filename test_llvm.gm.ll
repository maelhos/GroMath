; ModuleID = 'GroMathLLVM'
source_filename = "GroMathLLVM"

@VERSION = global i32 1, align 4
@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @gcd(i32 %a, i32 %b) {
entry:
  br label %cond

cond:                                             ; preds = %body, %entry
  %a8 = phi i32 [ %b4, %body ], [ %a, %entry ]
  %b4 = phi i32 [ %tmprem, %body ], [ %b, %entry ]
  %tmpcmp.not = icmp eq i32 %b4, 0
  br i1 %tmpcmp.not, label %loopend, label %body

body:                                             ; preds = %cond
  %tmprem = srem i32 %a8, %b4
  br label %cond

loopend:                                          ; preds = %cond
  ret i32 %a8
}

define i32 @main() {
entry:
  %0 = call i32 @gcd(i32 15, i32 25)
  %1 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @0, i32 %0)
  %2 = call i32 @gcd(i32 78, i32 36)
  %3 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @1, i32 %2)
  %4 = call i32 @gcd(i32 65537, i32 256)
  %5 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @2, i32 %4)
  ret i32 0
}
