/**
Simple Model with one clock that prints "Hello World!"
*/

#include <sst/core/sst_config.h>
#include "hello.h"

// Component Constructor
hello::hello( SST::ComponentId_t id, SST::Params& params ) : SST::Component(id), repeats(0) {

	// Initialize output
	output.init("hello-" + getName() + "-> ", 1, 0, SST::Output::STDOUT);

	// Get parameters from the python file, if not found use 5, 15 as defaults
	printFreq = params.find<SST::Cycle_t>("printFrequency", 5);
	maxRepeats = params.find<SST::Cycle_t>("repeats", 15);

	// Verify parameter
	if( ! (printFreq > 0) ) {
		output.fatal(CALL_INFO, -1, "Error: printFrequency must be greater than zero.\n");
	}

	// Show user the parameters
	output.verbose(CALL_INFO, 1, 0, "Config: maxRepeats=%" PRIu64 ", printFreq=%" PRIu64 "\n",
	static_cast<uint64_t>(maxRepeats), static_cast<uint64_t>(printFreq));

	// Just register a plain clock for this simple example
	registerClock("100MHz", new SST::Clock::Handler<hello>(this, &hello::clockTick));

	// Tell SST to wait until we authorize it to exit
	registerAsPrimaryComponent();
	primaryComponentDoNotEndSim();
}

hello::~hello() {

}

// setup is called by SST after a component has been constructed and should be used
// for initialization of variables
void hello::setup() {
	output.verbose(CALL_INFO, 1, 0, "Component is being setup.\n");
}

// finish is called by SST before the simulation is ended and should be used
// to clean up variables and memory
void hello::finish() {
	output.verbose(CALL_INFO, 1, 0, "Component is being finished.\n");
}

// clockTick is called by SST from the registerClock function
// this function runs once every clock cycle
bool hello::clockTick( SST::Cycle_t currentCycle ) {

	if( currentCycle % printFreq == 0 ) {
		output.verbose(CALL_INFO, 1, 0, "Hello World!\n");
	}

	repeats++;

	if( repeats == maxRepeats ) {
		primaryComponentOKToEndSim();
		return true;
	} else {
		return false;
	}
}
