# Syntax of GrosMath

## Introduction


### 1. Basic of GroMath

The goal of GroMath (GM) is to be a double sided language : imperative/object oriented and formal such that it is suited for uses in cryptanalysis and formal math. The main goal is for it to be very optimised on the backend (stdlib should be written in C/C++ for performance).
The imperative syntax should be simple (much like C) but with a BIG stdlib to be able to code very swiftly while doing CTF (we want a lot of). The language will OBVIOUSLY be staticly typed cuz writing a compiler is gonna be a pain overwise and optimsiation.

### 2. More goals

- The goals is NOT to make everything object-based as dealing with vtable and annoying stuff is really gonna be too much.

- The basic idea is to separte *MathObj* from *GenericObj*, almost everything will be *MathObj* except "programming" objects such as the main function and arrays, as those are not mathematical objects. This is because mathematical semantic isn't really ideal with loops and conditions... and doing math with a function that uses imperative methods seems frankly impossible... (TODO for much much much later ??) And we use sets more than arrays in math...

- The basic *MathObj* is *Set* as in ZFC axiom theory. Every *MathObj* as *Tags* which can be used for optimisation or requierement, adding tags is done by prepending that tag name :

```
Finite Set A = {1, 3, 4};
```

DISCUS: Should be force capital letters for *MathObj* and/or/nor tags ?

However the compiler may add tags for better performance and the *Set* object automatically propagate all tags to subset and suitable tag inheritence to elements.

The syntax for arrays is simply :

```
{MathObj (Type)} my_array[];
ZZ my_int_array[] = [1, 2, 5, 69, 420]; 
```

and the type :

```
ZZ[]
```
