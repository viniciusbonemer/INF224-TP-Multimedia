
#include <memory>

#include "MultimediaFactory.h"

MultimediaFactory::MultimediaFactory():
	assets(std::map<std::string, std::shared_ptr<MultimediaAsset>>()),
	groups(std::map<std::string, std::shared_ptr<MultimediaGroup>>())
	{}

MultimediaFactory::~MultimediaFactory() {}

PhotoPtr MultimediaFactory::createPhoto(std::string name, std::string filePath,
																				float latitude, float longitude) {
		auto ptr = std::make_shared<Photo>(name, filePath, latitude, longitude);
		assets[ptr->getName()] = ptr;
		return ptr;
}

VideoPtr MultimediaFactory::createVideo(std::string name, std::string filePath,
																			int duration) {
	auto ptr = std::make_shared<Video>(name, filePath, duration);
	assets[ptr->getName()] = ptr;
	return ptr;
}

FilmPtr MultimediaFactory::createFilm(std::string name, std::string filePath,
																			int duration, int *chapterDurations,
																			int chaptersCount) {
	auto ptr = std::make_shared<Film>(name, filePath, duration, chapterDurations,
																		chaptersCount);
	assets[ptr->getName()] = ptr;
	return ptr;
}

MultimediaGroupPtr MultimediaFactory::createGroup(std::string name) {
	auto ptr = std::make_shared<MultimediaGroup>(name);
	groups[ptr->getName()] = ptr;
	return ptr;
}

void MultimediaFactory::printAsset(std::string name,
																	 std::ostream& stream) const {
	auto result = assets.find(name);

	if (result == assets.end()) {
		stream << "[Error] Couldn't find asset named \"" << name << "\"";
		return;
	}

	result->second->printTo(stream);
}

void MultimediaFactory::printGroup(std::string name, std::ostream& stream) const {
	auto result = groups.find(name);

	if (result == groups.end()) {
		stream << "[Error] Couldn't find group named \"" << name << "\"";
		return;
	}

	result->second->printTo(stream);
}

void MultimediaFactory::displayAsset(std::string name, std::ostream& stream) const {
	auto result = assets.find(name);

	if (result == assets.end()) {
		stream << "[Error] Couldn't find asset named \"" << name << "\"";
		return;
	}

	result->second->display();
}
