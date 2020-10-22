
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
	<< latitude << " Longitude: " << longitude << std::endl;
}

void Photo::display() const {
	std::string cmd = "open " + filePath + " &";
	system(cmd.c_str());
}
