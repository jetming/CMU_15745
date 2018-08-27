#include "llvm/ObjectYAML/YAML.h"
#include "llvm/Support/raw_ostream.h"
#include <string>
#include <vector>
using namespace std;
using namespace llvm;
using llvm::yaml::MappingTraits;
using llvm::yaml::IO;

namespace Ming {
	struct FuncInfo
	{
		std::string name;
		int argCount;
		int dirCalls;
		int blockCount;
		int instCount;
	};
}
LLVM_YAML_IS_SEQUENCE_VECTOR(Ming::FuncInfo);
namespace llvm {
	namespace yaml {
		template <>
		struct MappingTraits<Ming::FuncInfo> {
			static void mapping(IO &io, Ming::FuncInfo &info) {
				io.mapRequired("Name", info.name);
				io.mapRequired("argCount", info.argCount);
				io.mapRequired("dirCalls", info.dirCalls);
				io.mapRequired("blockCount", info.blockCount);
				io.mapRequired("instCount", info.instCount);
				//io.mapOptional("hat-size", info.hatSize);
			}
		};
	}
}

namespace Ming {
	template<typename T>
	bool writeResult(std::string fileName, vector<T> &in)
	{
		yaml::Output yout(llvm::outs());
		yout << in;
		return false;
	}
}