#include <iostream>
#include "les_v1.h"

using namespace std;

void print( SNPtr _pAIL ){
	if(_pAIL == nullptr){
		cout << ">>>EMPTY LIST!" << endl;
		return;
	}
	cout << "List values: [ ";
 	while(_pAIL != nullptr){
 		cout << _pAIL->miData << " ";
 		_pAIL = _pAIL->mpNext;
 	}
 	cout << "]\n";
}

int length( SNPtr _pAIL ){
	auto i(0);
	if(_pAIL == nullptr)
		return 0;
	while(_pAIL != nullptr){
		i++;
		_pAIL = _pAIL->mpNext;
	}
	return i;
}

bool empty( SNPtr _pAIL ){
	if(_pAIL == nullptr) return true;
	return false;
}

void clear(SNPtr & _pAIL)
{
	if(_pAIL != nullptr){
	    std::cout << ">>>>CLEARING LIST!\n" << std::endl;
	    SNPtr work(_pAIL);
	    while (work != nullptr) {
	        _pAIL = _pAIL->mpNext;
	        delete [] work;
	        work = _pAIL;
	    }
	    _pAIL = nullptr;
	}
}

bool front( SNPtr _pAIL, int & _retrievedVal ){
	if(_pAIL == nullptr){
		_retrievedVal = 0;
		return false;
	}
	_retrievedVal = _pAIL->miData;
	return true;
}
bool back( SNPtr _pAIL, int & _retrievedVal ){
	if(_pAIL == nullptr){
		_retrievedVal = 0;
		return false;
	}
	while( _pAIL->mpNext != nullptr){
		_pAIL = _pAIL->mpNext;
	}
	_retrievedVal = _pAIL->miData;
	return true;
}
bool pushFront( SNPtr & _pAIL, int _newVal ){
	SNPtr work(nullptr);
	try{
		work = new SLLNode;
	}catch( const bad_alloc & e){
		return false;
	}

	work->miData = _newVal;
	work->mpNext = _pAIL;
	_pAIL = work;

	return true;
}

bool pushBack( SNPtr & _pAIL, int _newVal ){
	SNPtr tail(_pAIL);
	if(_pAIL == nullptr){
		pushFront(_pAIL, _newVal);
	} else{
	    while (_pAIL->mpNext != NULL)
	        _pAIL = _pAIL->mpNext;
	    if (pushFront(_pAIL->mpNext, _newVal))
	        _pAIL = tail;
	    else
	        return false;
	}
	return true;
}

bool popFront( SNPtr & _pAIL, int & _retrievedVal ){
	if(front(_pAIL, _retrievedVal)){
		SNPtr work(_pAIL);
		delete _pAIL;
		_pAIL = work->mpNext;
		return true;
	}
	return false;
}

bool popBack( SNPtr & _pAIL, int & _retrievedVal ){
    SNPtr work(_pAIL);
    SNPtr work1(nullptr);
	if(_pAIL == nullptr){
		_retrievedVal = 0;
		return false;
	}
	while(_pAIL->mpNext != nullptr){
		work1 = _pAIL;
		_pAIL = _pAIL->mpNext;
	}
    _retrievedVal = _pAIL->miData;
    delete _pAIL;
    work1->mpNext = nullptr;
    _pAIL = work;
  	return true;
}
SNPtr find( SNPtr _pAIL, int _targetVal){
    SNPtr work(_pAIL);
    while (work != nullptr and _pAIL->mpNext != nullptr) {
        if(work->miData == _targetVal)
            return work;
        work = work->mpNext;
    }
    return nullptr;
}
bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal ){
	SNPtr work1(_pAnte);
	if(_pAnte == nullptr){
		return pushFront(_pAnte, _newVal);
	}
	if(pushFront(_pAnte, _newVal)){
		SNPtr work2(_pAnte);
		while(_pAIL->mpNext != work1 and _pAIL != nullptr)
			_pAIL = _pAIL->mpNext;

		if(_pAIL == nullptr){
			_pAIL = work2;
			return false;
		}
		_pAIL->mpNext = _pAnte;
		_pAIL = work2;

		return true;
	}
	return false;
}
bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal ){
	if(_pAIL == nullptr){
		return true; // Already empty.
	}

	if(_retrievedVal == _pAIL->miData){
		_retrievedVal = _pAIL->miData;
		SNPtr work = _pAIL->mpNext;
		delete _pAIL;
		_pAIL = work;
		return true;
	}

	SNPtr work1 = _pAIL;
	while(_pAIL != _pAnte and _pAIL != nullptr){
		_pAIL = _pAIL->mpNext;
	}

	if(_pAIL == nullptr){
		_pAIL = work1;
		return false;
	}
	_retrievedVal = _pAIL->mpNext->miData;
	delete _pAIL;
	_pAIL->mpNext = _pAnte->mpNext->mpNext;;
	_pAIL = work1;
	return true;
}