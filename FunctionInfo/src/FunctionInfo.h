/*************************************************************************
> File Name: runOnModule.cpp
> Author: puzhiming
> Mail: 
> Created Time: 2018年08月24日 星期五 18时16分44秒
************************************************************************/

#include "../include/log.h"
#include "../include/OutputResult.hpp"
#include "llvm/IR/Module.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"

class FunctionInfo : public ModulePass
{
public:
	static char ID;

private:
	vector<Ming::FuncInfo> fInfoVec;

public:
	FunctionInfo();
	~FunctionInfo();

	bool runOnModule(Module &M);
};