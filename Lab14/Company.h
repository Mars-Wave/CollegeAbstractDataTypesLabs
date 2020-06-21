#include <utility>
#include "List.h"
#include "Table.h"
/*
Create() : Builder to create the clothing company without pieces of cloth.
‐ addShop(shop) : It adds a shop to the company with a given name in the input parameter.If it
already exists, it ignores the operation.
‐ addModel(shop, model, n) : It adds n cloth pieces of a new cloth model to a shop.If the shop
already had this model, it increments the number of pieces.If the shop does not exist, it
ignores the operation.
‐ lastModels(shop, n) : It returns a list of the “n” last models added to a given shop in inverse
order.First, it should be the last model added.Second should be the second to the last model,
and so on.If there are not enough last models, it only returns the available ones in this inverse
order.If the shop does not exist, it returns an empty list.
‐ shops() : It returns a list of the shops shorted alphabetically.
‐ pieces(shop, model) : It returns the number of pieces of cloth of a given shop and model.It
returns 0 if either the model or the shop does not exist.*/

class Company {
public:

	Company Create() {
		return Company();
	}

	void addShop(std::string shop) {
		this->c.insert(shop, Table<std::string, int>());
		if (this->s.empty())
		{
			s.push_front(shop);
		}
		else {
			List<std::string>::MutableIterator iter = this->s.begin();
			while (iter != s.end() && iter.elem() < shop)
			{
				iter.next();
			}
			if (iter != s.end())
			{
				this->s.insert(shop, iter);
			}
			else {
				s.push_back(shop);
			}
		}
		this->m.insert(shop, List<std::string>());
	}

	int pieces(std::string shop, std::string  model) {
		if (c.exists(shop))
		{
			if (c.get(shop).exists(model)) {
				return c.get(shop).get(model);
			}

		}
		return 0;
	}

	List<std::string> lastModels(std::string shop, int n) {
		List<std::string> aux = m.get(shop);
		while (aux.numElems() > n)
		{
			aux.pop_back();
		}
		return aux;
	}

	void addModel(std::string shop, std::string model, int n) {
		if (c.exists(shop))
		{

			if (c.get(shop).exists(model)) {
				int aux = c.get(shop).get(model);
				c.get(shop).insert(model, n + aux);
			}
			else {
				c.get(shop).insert(model, n);
			}
			m.get(shop).push_front(model);
		}
	}

	List<std::string> shops() {
		return s;
	}

	Company() {
		this->c = Table<std::string, Table<std::string, int>>();
		this->m = Table<std::string, List<std::string>>();
		this->s = List<std::string>();
	}

private:
	Table<std::string, Table<std::string, int>> c;
	Table<std::string, List<std::string>> m;
	List<std::string> s;
};