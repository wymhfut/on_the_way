#pragma once

#include "hmm.h"

class CForward
{
public:
	CForward()
	{
	}

	~CForward()
	{
	}

	void process(HMM* pHmm, int T,
				 int* pObserve,
				 float** ppAlpha,/*local prob, row: T, col: hidden state*/
				 float* pProb)
	{
		int nHiddenStateNum = pHmm->getHiddenStateNum();
		int nOutputStateNum = pHmm->getOutputStateNum();
		
		const float** ppOutputMat = pHmm->getOutputMat();

		/*init alpha[0]*/
		const float* pInitState = pHmm->getInitState();
		int nCurOutState = pObserve[0];
		for (int nHiddStIdx = 0; nHiddStIdx < nHiddenStateNum; nHiddStIdx++)
		{
			/*for cache*/
			ppAlpha[0][nHiddStIdx] = pInitState[nHiddStIdx]*ppOutputMat[nCurOutState][nHiddStIdx];
			pProb[0] += ppAlpha[0][nHiddStIdx];
		}

		/*induce*/
		const float** ppTransMat = pHmm->getTransMat();
		for(int nTIdx = 1; nTIdx < T; nTIdx++)
		{
			nCurOutState = pObserve[nTIdx];
			for (int nHiddStIdx = 0; nHiddStIdx < nHiddenStateNum; nHiddStIdx++)
			{
				for(int nPreHiddStIdx = 0; nPreHiddStIdx < nHiddenStateNum; nPreHiddStIdx++)
				{
					ppAlpha[nTIdx][nHiddStIdx] += ppAlpha[nTIdx-1][nPreHiddStIdx]*ppTransMat[nPreHiddStIdx][nHiddStIdx];
				}
				ppAlpha[nTIdx][nHiddStIdx] *= ppOutputMat[nCurOutState][nHiddStIdx];
				pProb[nTIdx] += ppAlpha[nTIdx][nHiddStIdx];
			}
		}
	}
};