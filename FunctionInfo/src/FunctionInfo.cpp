#include "FunctionInfo.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/MemoryBuffer.h"

char FunctionInfo::ID = 0;
static RegisterPass<FunctionInfo> X("FunctionInfo", "FunctionInfo");

FunctionInfo::FunctionInfo() : ModulePass(ID)
{
}

FunctionInfo::~FunctionInfo()
{
}

bool FunctionInfo::runOnModule(Module & M)
{
	for (auto ite = M.begin(); ite != M.end(); ++ite)
	{
		Ming::FuncInfo fInfo;
		Function* func = &*ite;
		fInfo.name = func->getName();
		fInfo.argCount = func->getArgumentList().size();
		fInfo.blockCount = func->getBasicBlockList().size();
		fInfo.instCount = 0;
		for (auto ite = inst_begin(func); ite != inst_end(func); ++ite) {
			fInfo.instCount++;
		}
		fInfoVec.push_back(fInfo);
	}
	Ming::writeResult("result", fInfoVec);
	return false;
}