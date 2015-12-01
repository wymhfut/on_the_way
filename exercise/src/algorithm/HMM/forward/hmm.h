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
		initPara(pHmmParaFile);
	}

	~HMM()
	{
	}

	int getHiddenStateNum() const
	{
		return nHiddenStateNum_;
	}

	int getOutputStateNum() const
	{
		return nOutputStateNum_;
	}

	const float** getTransMat() const
	{
		return ppTransMat_;
	}

	const float** getOutputMat() const
	{
		return ppOutputMat_;
	}

	const float* getInitState() const
	{
		return pInitState_;
	}

private:
	void initPara(const char* pHmmParaFile)
	{
		nHiddenStateNum_ = 3;
		nOutputStateNum_ = 4;
		/*ppTransMat_ = new float*[nHiddenStateNum_]();
		for(int nHiddStIdx = 0; nHiddStIdx < nHiddenStateNum_; nHiddStIdx++)
		{
			for (int nNextHiddStIdx = 0; nNextHiddStIdx < nHiddenStateNum_; nNextHiddStIdx++)
			{
				ppTransMat_[nHiddStIdx][nNextHiddStIdx] = 
			}
		}*/
		
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