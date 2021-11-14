# background business context 

Sue is the owner of "Ed's Fantastic, Awesome, and Incredible Carwash!" 
Ed built the carwash on a half acre lot in Middleville in 1973. 
Sue inherited her uncle's carwash in 2013. 

The carwash has seen ups and downs but overall has been moderately successful. 
Sue is pondering expansion of the carwash business, specifically an increase in the number of wash bays. 
Sue knows the current cost of operation, the charge per customer, how long a customer is willing to wait, 
the typical pattern of people waiting for a car wash, and the cost of building a new bay. 

Sue is looking for your help in understanding whether it would make financial sense to construct one or more new car wash bays. 

# mapping the business scenario and question to Discrete Event Simulation using the Structural Simulation Toolkit

From the scenario, what should the model be? 

There are aspects that are not relevant: 
* the car wash was built in 1973
* the car wash ownership changed in 2013

Potential constraints:
* the car wash is on a half acre lot. Since wash bays use space, the number of wash bays is limited. We'll need to ask Sue what the upper bound would be.
* Sue has a limited budget
* the number of customers

A Discrete Event Simulation is focused on timing, so the specific monetary cost values are not necessary for the model. 
