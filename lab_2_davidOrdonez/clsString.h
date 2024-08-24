#pragma once
#include <string>

using std::string;

namespace clsString {
	int opContainsBy(const string& prmStr, const string& prmPattern) {

		if (prmStr.length() < prmPattern.length()) return 0;
		if (prmStr.empty()||prmPattern.empty()) return 0;
		int varCount = 0;

		for (size_t i = 0; i <= prmStr.length() - prmPattern.length(); i++) {
			bool coincidencia = true;
			for (size_t j = 0; j < prmPattern.length(); j++) {
				if (prmStr[i + j] != prmPattern[j]) {
					coincidencia = false;
					break;
				}
			}
			if (coincidencia) varCount++;
		}
		return varCount;
	}
	bool opContainsBy(string prmStr, string prmPattern, size_t prmStrPost, size_t prmPatternPost)
	{
		if (prmStrPost >= prmStr.length() && prmPatternPost < prmPattern.length()) return false;
		if (prmPatternPost >= prmPattern.length()) return true;

		if (prmStr[prmStrPost] == prmPattern[prmPatternPost]) 
		{
			return opContainsBy(prmStr, prmPattern, prmStrPost + 1, prmPatternPost + 1);
		}
		else {
			return opContainsBy(prmStr, prmPattern, prmStrPost + 1, 0);
		}

		return false;
	}
}