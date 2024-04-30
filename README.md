# GroMath

GroMath is a programming language made for *Crytography* and *Crytanalysis* to hopefully be :
- Cool syntax like SageMath
- As fast as PARI/GP
- As robust as Magma

Without being :
- Slow and spaghetti code like SageMarh
- Horrible syntax like PARI/GP
- $$$$ ... Magma

## Technologies in usage

In this project, we wanted to experience the usage of LLVM to compile our language "the modern way", therefore having ways to cross compile easily and to add features for performances (s.a. phi nodes). Our objective was also to do something that merges our vision of what a "great" language could be :
- On Mael's side, being able to use it in the context of CTFs (Capture The Flag) in his main category : cryptography.
- On Narcisse's side, being able to have functional traits (and I hope pattern matching some day).

## Building the project

The requirements are precised in the file `requirements.txt`, mainly taken from LLVM's install guide for the developpment branch. After this, multiple `.sh` files are provided and then it's time to execute GroMath !

## Testing the project

To ensure great ways to debug our code and to pretty print our results, we work on a pretty printing of ASTs, but also trying to procedurally generate snippets of code to test our compiler. WIP but you can have a look at `json_prettyprint.py` and `test_gen.py` to see the progress.