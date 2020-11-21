
#include "Photo.h"

Photo::Photo(std::string name, std::string filePath, float latitude, float longitude) :
		MultimediaAsset(name, filePath),
		latitude(latitude),
		longitude(longitude)
		{}

Photo::~Photo() {
	std::cout << "Deleted photo " << name << std::endl;
}

void Photo::printTo(std::ostream& stream) const {
	stream << "Name: " << name << " File path: " << filePath << " Latitude: "
	<< latitude << " Longitude: " << longitude;
}

void Photo::display() const {
	#if defined(__APPLE__)
	std::string cmd = "open " + filePath + " &";
	#else
	std::string cmd = "imagej " + filePath + " &";
	#endif
	system(cmd.c_str());
}
