#include "Table.h"
#include "Exceptions.h"
#include <iostream>
#include <utility>
#include "List.h"
#include "Hash.h"

class LawFirm {
public:
	LawFirm() {
		this->Create();
	}
	void Create() {
		this->caseFiles = Table<std::string,std::pair<std::string, std::string>>();
		this->caseOrder = List<List<std::string>>();
		for (int i = 0; i < 3; i++)
		{
			this->caseOrder.insert(List<std::string>(), this->caseOrder.begin());
		}
	}

	void getCase(std::string id, std::string &name, std::string &type) {
		try
		{
			name = this->caseFiles.get(id).first;
			type = this->caseFiles.get(id).second;
		}
		catch (EWrongKey)
		{
			throw EWrongKey("This case does not exist");
		}

	}

	void nextCase(std::string &id, int &priority) {
		int i = 0;
		List<List<std::string>>::MutableIterator iter = caseOrder.begin();
		while (iter != caseOrder.end())
		{
			List<std::string>::MutableIterator iter1 = iter.elem().begin();
			if (iter1 != iter.elem().end()) {
				id = iter1.elem();
				priority = i;
				return;
			}
			i++;
			iter.next();
		}
		id = -1;
		priority = -1;
	}

	void removeNextCase() {
		List<List<std::string>>::MutableIterator iter = caseOrder.begin();
		while (iter != caseOrder.end())
		{
			List<std::string>::MutableIterator iter1 = iter.elem().begin();
			if (iter1 != iter.elem().end()) {
				caseFiles.remove(iter1.elem());
				iter.elem().remove(iter1);
				return;
			}
			iter.next();
		}
	}

	void addCase(std::string id, std::string  name, std::string type, int priority) {
		try
		{
			caseFiles.get(id);
		}
		catch (EWrongKey)
		{
			caseOrder.elem(priority).push_back(id);
			caseFiles.insert(id, make_pair(name, type));
		}
	}

	bool empty() {
		return this->caseFiles.esVacia();
	}

private:
	List<List<std::string>>caseOrder;
	Table<std::string, std::pair<std::string, std::string>> caseFiles;
};

