import sst

# component hello from element helloSST (helloSST.hello) named "Hello World"
helloComponent = sst.Component("Hello World", "helloSST.hello")
# overide default parameters
helloComponent.addParams({
	"printFrequency" : "5", # print every 5 ticks
	"repeats" : "15" # run for 15 ticks
	})
