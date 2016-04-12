/*
 * StrongClassifier.h
 *
 *  Created on: 16/mar/2016
 *      Author: lorenzocioni
 */

#ifndef BOOSTING_CLASSIFIERS_STRONGCLASSIFIER_H_
#define BOOSTING_CLASSIFIERS_STRONGCLASSIFIER_H_

#include <vector>
#include <iostream>
#include "../features/Data.h"
#include "WeakClassifier.h"

class StrongClassifier {

private:
	vector<WeakClassifier> classifiers;
	bool trained;

public:
	StrongClassifier(vector<WeakClassifier> classifiers);
	int predict(Data x);
	vector<int> predict(vector<Data> x);
	~StrongClassifier();
	const vector<WeakClassifier>& getClassifiers() const;
	void setClassifiers(const vector<WeakClassifier>& classifiers);
	bool isTrained() const;
	void setTrained(bool trained);
};



#endif /* BOOSTING_CLASSIFIERS_STRONGCLASSIFIER_H_ */