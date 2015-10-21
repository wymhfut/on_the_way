#pragma once

#include <fstream>
#include <string>

using std::ifstream;
using std::string;

class HMM
{
public:
	HMM(const char* pHmmParaFile) : nHiddenStateNum_(0), nOutputStateNum_(0)
	{

	}

	~HMM()
	{
	}

private:
	void initPara(const char* pHmmParaFile)
	{
		ifstream inFile(pHmmParaFile);
		string strCurLine;
		while(getline(inFile, strCurLine))
		{

		}
	}

private:
	int nHiddenStateNum_;
	int nOutputStateNum_;
	float** ppTransMat_;
	float** ppOutputMat_;
	float*	pInitState_;
};