
#include "Video.h"

Video::Video(std::string name, std::string filePath, int duration):
	MultimediaAsset(name, filePath),
	duration(duration)
	{}

void Video::printTo(std::ostream& stream) const {
	stream << "Name: " << name << " File path: " << filePath << " Duration: "
	<< duration << std::endl;
}

void Video::display() const {
	std::string cmd = "open " + filePath + " &";
	system(cmd.c_str());
}

Video::~Video() {
	std::cout << "Deleted video " << name << std::endl;
}
