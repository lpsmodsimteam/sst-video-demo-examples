#ifndef _hello_H
#define _hello_H

#include <sst/core/component.h>

class hello : public SST::Component {

public:
	hello( SST::ComponentId_t id, SST::Params& params );
	~hello();

	void setup();
	void finish();

	bool clockTick( SST::Cycle_t currentCycle );

	// Register the component
	SST_ELI_REGISTER_COMPONENT(
		hello, // class
		"helloSST", // element library
		"hello", // component
		SST_ELI_ELEMENT_VERSION( 1, 0, 0 ),
		"Simple model that prints Hello World!",
		COMPONENT_CATEGORY_UNCATEGORIZED
	)

	// Parameter name, description, default value
	SST_ELI_DOCUMENT_PARAMS(
		{ "printFrequency", "How frequently to print a message from the component", "5" },
		{ "repeats", "Number of repetitions to make", "15" }
	)

private:
	// local variables
	SST::Output output;
	SST::Cycle_t printFreq;
	SST::Cycle_t maxRepeats;
	SST::Cycle_t repeats;

};

#endif
