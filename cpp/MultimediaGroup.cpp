#include "MultimediaGroup.h"

MultimediaGroup::MultimediaGroup(std::string name):
	std::list<MultimediaAssetPtr>(),
	name(name)
	{}

MultimediaGroup::~MultimediaGroup() {
	for (auto & p : *this) {
		p.reset();
	}
}

void MultimediaGroup::printTo(std::ostream& stream) const {
	stream << name << " -> ";
	for (auto & el : *this) {
		el->printTo(stream);
		stream << ", ";
	}
}
