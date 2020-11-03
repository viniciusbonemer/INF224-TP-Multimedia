#ifndef VIDEO_H
#define VIDEO_H

#include "MultimediaAsset.h"

/// A multimedia Video
class Video: public MultimediaAsset {

protected:

	/// The duration of the video
	int duration;

public:

	/// Constructor
	/**
	Creates a Video with the given name, path and duration
	\param name The name of the new video
	\param filePath The path of the new video's file
	\param duration The duration of the new video
	*/
	Video(std::string name = "", std::string filePath = "", int duration = 0);

	/// Destructor
	~Video();

	virtual void printTo(std::ostream& stream) const override;

	/// Displays the video in Preview
	virtual void display() const override;

	/// Getter
	/**
	Returns the video's duration
	\return duration
	*/
	int getDuration() const { return duration; }

	/// Setter
	/**
	Sets a duration to the video
	\param newDuration The duration to be set
	*/
	void setDuration(int newDuration) { duration = newDuration; }
};

/// Type used to refer to a shared pointer to Video
typedef std::shared_ptr<Video> VideoPtr;

#endif
