
#include "MultimediaAsset.h"

MultimediaAsset::MultimediaAsset(std::string name, std::string filePath):
	name(name),
	filePath(filePath)
	{}

MultimediaAsset::~MultimediaAsset() {}

void MultimediaAsset::printTo(std::ostream& stream) const {
	stream << "Name: " << name << " File path: " << filePath << std::endl;
}
