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
	stream << name << std::endl;
	for (auto & el : *this) {
		stream << "\t";
		el->printTo(stream);
	}
}
