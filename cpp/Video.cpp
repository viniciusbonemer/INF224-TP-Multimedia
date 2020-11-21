
#include "Video.h"

Video::Video(std::string name, std::string filePath, int duration):
	MultimediaAsset(name, filePath),
	duration(duration)
	{}

void Video::printTo(std::ostream& stream) const {
	stream << "Name: " << name << " File path: " << filePath << " Duration: "
	<< duration;
}

void Video::display() const {
	#if defined(__APPLE__)
	std::string cmd = "open " + filePath + " &";
	#else
	std::string cmd = "mpv " + filePath + " &";
	#endif
	system(cmd.c_str());
}

Video::~Video() {
	std::cout << "Deleted video " << name << std::endl;
}
