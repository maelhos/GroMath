#pragma once
#include "stdinc.h"
#include "token.h"
#include "parser.h"
#include "generator.h"

extern llvm::ExitOnError ExitOnErr;

void MainLoop();
void HandleExtern();
void HandleIdentifierExpression();

void HandleDefinition();
void HandleTopLevelExpression();