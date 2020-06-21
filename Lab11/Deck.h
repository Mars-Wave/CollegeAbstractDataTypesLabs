#pragma once
#include "List.h"
#include <utility>

class Deck {
public:
	Deck();
	void addStickers(int stickerModel, int numStickers);
	int getNumStickers(int stickerModel);
	int numCommonStickers(Deck deck);
private:
	List<std::pair<int, int>>* list;
	int binarySearch(int l, int r, int x);
};

Deck::Deck() {
	this->list = new List<std::pair<int, int>>();
}

void Deck::addStickers(int stickerModel, int numStickers) {
	int beg = 0, end = this->list->numElems();
	if (!this->list->empty()) {
		List<std::pair<int, int>>::MutableIterator iter = this->list->begin();
		while (beg != end && iter.elem().first < stickerModel  )
		{
			iter.next();
			beg++;
		}
		if (beg == end)
		{
			this->list->push_back(std::pair<int, int>(stickerModel, numStickers));
		}
		else {
			list->insert(std::pair<int, int>(stickerModel, numStickers), iter);
		}
	}
	else {
		list->push_front(std::pair<int, int>(stickerModel, numStickers));
	}
}

int Deck::getNumStickers(int stickerModel) {
	if (!this->list->empty()) {
		int idx = this->binarySearch(0, this->list->numElems(), stickerModel);
		if (idx != -1)
		{
			return this->list->elem(idx).second;
		}
		
	}
	return -1;
}

int Deck::numCommonStickers(Deck deck) {
	if (!this->list->empty() && !deck.list->empty()) {
		int numsticks, aux = 0;
		List<std::pair<int, int>>::Iterator iter = this->list->cbegin();
		for (int i = 0; i < this->list->numElems(); i++)
		{
			numsticks = deck.getNumStickers(iter.elem().first);
			if (numsticks != -1)
			{
				aux += std::min<int>(numsticks, iter.elem().second);
			}
			iter.next();
		}
		return aux;
	}
	else {
		return 0;
	}

}


int Deck::binarySearch(int l, int r, int stickerModel)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (list->elem(mid).first == stickerModel)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (list->elem(mid).first > stickerModel)
			return binarySearch(l, mid - 1, stickerModel);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(mid + 1, r, stickerModel);
	}
	return -1;
}
