# GroMath

GroMath is a programming language made for *Crytography* and computational math in general to hopefully be :

- Cool syntax like SageMath
- As fast as PARI/GP
- As robust as Magma

Without being :

- Slow and spaghetti code like SageMath
- Horrible syntax like PARI/GP
- \$\$\$\$ ... Magma

The main focus are :

- Aim for general programming as much as possible on the user side
- Write optimized backend for known cases ($\mathbb Q, \mathbb Z, ...$) using *GMP* for bigint and *NTL* for algos
- Always try to be "as optimized as possible" (to try and be better than SageMath on at least a few occasion O_o)

## Technologies in usage

In this project, we wanted to experience the usage of LLVM to compile our language "the modern way", therefore having ways to cross compile easily and to add features for performances (s.a. phi nodes). Our objective was also to do something that merges our vision of what a "great" language could be :

## Building the project

The requirements are precised in the file `requirements.txt`, mainly taken from LLVM's install guide for the developpment branch. After this, multiple `.sh` files are provided and then it's time to execute GroMath !
The current version is made to be built with llvm-20 which sadly isn't so available yet.

## Testing the project

To ensure great ways to debug our code and to pretty print our results, we work on a pretty printing of ASTs, but also trying to procedurally generate snippets of code to test our compiler. WIP but you can have a look at `json_prettyprint.py` and `test_gen.py` to see the progress.