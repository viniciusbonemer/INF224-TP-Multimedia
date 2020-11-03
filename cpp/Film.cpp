
#include "Film.h"

Film::Film(std::string name, std::string filePath, int duration,
	int *chapterDurations, int chaptersCount):
		Video(name, filePath, duration),
		chaptersCount(chaptersCount),
		chapterDurations(chapterDurations)
		{
			this->chapterDurations = new int[chaptersCount];
			for (int i = 0; i < chaptersCount; ++i) {
				this->chapterDurations[i] = chapterDurations[i];
			}
}

Film::Film(const Film& from) : Video(from) {
	chaptersCount = from.chaptersCount;
	chapterDurations = new int[chaptersCount];
	for (int i = 0; i < chaptersCount; ++i) {
		chapterDurations[i] = from.chapterDurations[i];
	}
}

Film& Film::operator=(const Film& from) {
	Video::operator=(from);
	setChapterDurations(from.chapterDurations, from.chaptersCount);
	return *this;
}

Film::~Film() {
	delete [] chapterDurations;
	std::cout << "Deleted film " << name << std::endl;
}

void Film::setChapterDurations(const int *newChapterDurations, int newChaptersCount) {
	delete [] chapterDurations;
	chaptersCount = newChaptersCount;
	chapterDurations = new int[chaptersCount];
	for (int i = 0; i < chaptersCount; ++i) {
		chapterDurations[i] = newChapterDurations[i];
	}
}

void Film::printTo(std::ostream& stream) const {
	stream << "Name: " << name << " File path: " << filePath << " Duration: "
		<< duration << " Chapters durations: ";
	for (int i = 1; i < chaptersCount; ++i) {
		stream << chapterDurations[i - 1]  << ", ";
	}
	stream << chapterDurations[chaptersCount - 1] << std::endl;
}
