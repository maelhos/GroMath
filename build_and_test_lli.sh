#!/bin/bash

sh build.sh

./GroMath test_llvm.gm
lli test_llvm.gm.ll