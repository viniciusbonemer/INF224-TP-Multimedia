#ifndef FILM_H
#define FILM_H

#include "Video.h"

/// A Film
class Film: public Video {

private:

	/// The number of chapters of the film
	int chaptersCount;

	/// An array of chapter duration
	/**
	Each entry contains the duation of a chapter in the film.
	\see chaptersCount
	*/
	int *chapterDurations;

public:

	/// Constructor
	/**
	Creates a Film with the given name, path, duration and chapters information
	\param name The name of the new film
	\param filePath The path of the new film's file
	\param duration The duration of the new film
	\param chapterDurations An array of `chaptersCount` entries
	Each entry contains the duration of the chapter at that index.
	\param chaptersCount The number of chapters in the film
	*/
	Film(std::string name = "", std::string filePath = "", int duration = 0,
		int *chapterDurations = nullptr, int chaptersCount = 0);

	/// Constructor
	/**
	Creates a Film from another film instance
	\param from The film to be copied
	*/
	Film(const Film& from);

	/// Assignement operator
	/**
	The same as calling the copy constructor
	\see Film()
	*/
	Film& operator=(const Film& from);

	/// Destructor
	virtual ~Film();

	virtual void printTo(std::ostream& stream) const override;

	/// Getter
	/**
	Returns the films's array of chapter durations. To know the number of elements
	in the array, access the associated getter for the number of chapters durations
	\return the chapters' durations
	\see getChaptersCount()
	*/
	const int* getChapterDurations() const { return chapterDurations; }

	/// Setter
	/**
	Sets the chapters' durations and count
	\param newChapterDurations The new durations to be set
	\param newChaptersCount The number of chapters in the newChapterDurations array
	*/
	void setChapterDurations(const int *newChapterDurations, int newChaptersCount);

	/// Getter
	/**
	Returns the number of elements in the films's array of chapter durations
	\return the number of chapters durations
	*/
	int getChaptersCount() const { return chaptersCount; }

};

/// Type used to refer to a shared pointer to Film
using FilmPtr = std::shared_ptr<Film>;

#endif
