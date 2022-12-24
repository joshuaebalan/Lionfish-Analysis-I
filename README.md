# Lionfish Analysis: FAQ

### What are lionfish, and why are they a problem?
Lionfish are an invasive species in the Carribean, especially surrounding tropical coral reefs. They are native to the tropical waters of the equatorial Pacific in which they have natural predators. However, they are the apex predators here in the West, due to their unnatural origin. First sighted in 2008 by various dive crews, lionfish have become generealistic in their diet, with the current understanding that they "eat anything they can fir in their mouths", according to ReefCI. The most problematic part of this is their culling of the parrotfish population, a keystone species that indirectly ensures the reefs are not snuffed out in their light competition with algae species. 

Here specifically, the first invasive lionfish were sighted in 2009, and ReefCI has been killing them ever since. They have also been dissecting them for years, and keeping careful log of the data, which this project hopes to use for greater understanding of their efforts.

### What's the goal of this project?
This project aims to accomplish the following:
1. Identify trends in the data
2. Attempt to use current scientific understanding to explain trends away
3. Should an unexplainable trend exist, further investigate and potentially organize an experiment for ReefCI.

### What does the data look like?
#### In general,
this project uses dissection reports from diver-speared lionfish, which occur once weekly and dissect 10 fish. This spans over the course of about 2 years, and maps 638 dissections. Work is in progress to estimate the amount of lionfish in total this represents using the calculated confidence index, the second column in the .csv files. 

#### Computationally, a basic Lionfish Structure looks like so:
1. Day, month and year of date dissected
2. Index of confidence, calculated by dividing 10 by the total amount of fish caught that day
3. Length of the fish with tail
4. Length of the fish without tail
5. Whether or not the fish has Supraorbital Tentacles(referred hereafter as "noodles" by ReefCI); 1 for yes, 0 for no
6. Whether or not the fish has a set of rough bumps on the chin, referrred hereafter as "beards" by ReefCI; 1 for yes, 0 for no
7. Determined sex of the fish, since (6) is a sex-determining trait; 2 for male, 3 for female
8. Whether or not the fish has eggs; 1 for yes, 0 for no
9. Whether or not the fish is juvenile based on length(no tail) and sex traits; 1 for yes, 0 for no
10. Stomach content: string of contents, or 0 for empty, -1 for incomprehensibly digested.

On (6) and (8): According to ReefCI, all males have beards and all females eggs; if they do not and are 15 cm or less without tail in length, they are considered juvenile (9).

On (5): The purpose of noodles are unclear; this project hopes to confirm or invalidate the hypothesis that noodles are more prevalent in juveniles.

#### These structures are organized...
by putting them in a jagged 2D array. The way that it works is that on the x-axis is the date caught represneted as an integer, i.e. 03/01/2022 = 220301, oldest at the front, newest in the back. From there, each link is first connected to a "Diagnostic Node"(see below), and then to the all of the individual fish structures(as described above) of the fish that were dissected on that day.

#### A "Diagnostic Node" is...
a completely different kind structure linked to the x-axis of the chain. The entire point of this is to take a space-time trade-off to make calculating statistics faster. It contains:
1. The date integer to identify the chain
2. The total number of lionfish in that chain
3. The total amount of noodles across all of the lionfish*
4. The total length of all the lionfish put together*
5. The total length of all the lionfihs(without tail) put toggether*
6. The total number of egg sacs across all of the lionfish
7. the total number of beards across all of the lionfish

*Split by sex
##### What's the point of a "Diagnostic node?"
Here's how much faster this makes things.
Let's say that I want to know what percentage of fish across the whole set of 638 lionfish (as given by ReefCI) have noodles. If we don't have diagnostic nodes, I have to iterate across the entire set of chains, and increment a counter 638 times. However, if I do have diagnostic nodes, I only have to iterate over the number of days, in this case, is 64. So, with a diagnostic node, I'm doing the same thing in 574, or 89%, less comparisons.
### When will the full version of this tool be released?

At the completion of this project, the prospective plan is to format all tools into one single .exe file, which will automatically carry out the calculations that I did for my statistics. I am currently in the process of working with the [Belize Lionfish Working Group](https://eatdalion.bz) in order to release this to mainstream hunters. When that gets sorted, this tool will be released publicly, both to them and as a full repository for the wider public. 

### Is this an actual academic study or just a personal project? Where can I get more information?

This is a full undergraduate research project sponsored by the Purdue University Office of Undergraduate Research. Under Dr. Greg Michalski, I have documented this study academically, including presentations to both Purdue colloquia and international partners. As of this commit, this project has been approved for publication in the [Journal of Purdue Undergraduate Research](jpur.org), with the full article slated for release in August 2023. Note: Full project called "A Computational Analysis of Invasive Lionfish In Belize" in publications. 

### Can I copy/use this now?

Until distribution, all works here are solely and exclusively intended for use by Purdue University, specifically students of the Purdue University Earth, Atmospheric, and Planetary Studies Department. Use of materials without written consent from Joshua E. Balan is strictly prohibited.

### Key People/Thanks to:
1. Dr. Greg Michalski, main advisor
2. Willie Caal, ReefCI in-house marine biologist and owner of the dataset used in this project
3. Linda Searle, ECOMAR Founder, primary Lionfish Working Group contact
4. Dr. Jeff Turkstra, for his advice in technical elements of this project
5. Skylar Guffey, for her assistance in data entry and her consultation on biological aspects of this project
#### Data entry helpers:
1. Hanna Fulford
2. Stefano Parducci
3. John(Jack) Rodriguez
