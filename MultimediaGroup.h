#ifndef MULTIMEDIAGROUP_H
#define MULTIMEDIAGROUP_H

#include <list>

#include "MultimediaAsset.h"

/// A group of MultimediaAssets
class MultimediaGroup: public std::list<MultimediaAssetPtr> {

private:

	/// The name of the group
	std::string name;

public:

	/// Constructor
	/**
	Creates a MultimediaGroup with the given name
	\param name The name of the new group
	*/
	MultimediaGroup(std::string name);

	/// Destructor
	virtual ~MultimediaGroup();

	/// Getter
	/**
	Returns the groups's name
	\return name
	*/
	std::string getName() const { return name; }


	/// Prints information about the group to the given stream
	/**
	The informations include the name of the group and informations about each
	of it's elements.
	\param stream The stream to which information should be output to
	*/
	virtual void printTo(std::ostream& stream) const;

};

/// Type used to refer to a shared pointer to MultimediaGroup
typedef std::shared_ptr<MultimediaGroup> MultimediaGroupPtr;

#endif
