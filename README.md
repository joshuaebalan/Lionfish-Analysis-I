# Lionfish-Analysis-I

This is intended for use for the analysis of invasive lionfish culling in Tom Owen's Caye, Belize with data from ReefCI, an ecotourism company aiming towards conservation.

### Background:
Lionfish are an invasive species in the Carribean, especially surrounding tropical coral reefs. They are native to the tropical waters of the equatorial Pacific in which they have natural predators. However, they are the apex predators here in the West, due to their unnatural origin. First sighted in 2008 by various dive crews, lionfish have become generealistic in their diet, with the current understanding that they "eat anything they can fir in their mouths", according to ReefCI. The most problematic part of this is their culling of the parrotfish population, a keystone species that indirectly ensures the reefs are not snuffed out in their light competition with algae species. 

Here specifically, the first invasive lionfish were sighted in 2009, and ReefCI has been killing them ever since. They have also been dissecting them for years, and keeping careful log of the data, which this project hopes to use for greater understanding of their efforts.

### Project Goal:
This project aims to accomplish the following:
1. Identify trends in the data
2. Attempt to use current scientific understanding to explain trends away
3. Should an unexplainable trend exist, further investigate and potentially organize an experiment for ReefCI.

### Data Summary:
This project uses dissection reports from diver-speared lionfish, which occur once weekly and dissect 10 fish. This spans over the course of about 2 years, and maps 638 dissections. Work is in progress to estimate the amount of lionfish in total this represents using the calculated confidence index, the second column in the .csv files. Additional findings may be found [here](https://docs.google.com/document/d/1qu2WIQ-7aA__ScxEGOMaAXd8uJPbYX2bNggdvtRtEPU/edit?usp=sharing).

A basic Lionfish Structure looks like so:
1. Time structure with the date caught
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

### Key People/Thanks to:
1. Dr. Greg Michalski, main advisor
2. Willie Caal, ReefCI in-house marine biologist and owner of the dataset used in this project
3. Dr. Jeff Turkstra, for his advice in technical elements of this project
4. Skylar Guffey, for her assistance in data entry and her consultation on biological aspects of this project
#### Data entry helpers:
1. Hanna Fulford
2. Stefano Parducci
3. John(Jack) Rodriguez

### Intended Release

At the completion of this project, the prospective plan is to format all tools into one single .exe file, which will automatically carry out the calculations that I did for my statistics, such that ReefCI or other keys in the Carribean may use my formatting to further understand the lionfish population. Additionally, I hope to derive future experiments such that ReefCI may re-establish their mission of conservation via the means of civilian science, a goal which was hindered by controversy years ago.

### Compilation instructions

1. Please add all data you'd like to compile into the MASTER\_DATA.csv file prior to use of the .exe file; Please follow the format provided in the sheet linked here.
2. Upon compilation, please answer prompts with numbers. For yes and no, please note that 1 corresponds to yes and 0 to no. This program is not designed to handle other inputs, which could result in unexpected behavior
### Privacy Statement
All works here are solely and exclusively intended for use by Purdue University, specifically students under Dr. Greg Michalski of the Purdue University Earth, Atmospheric, and Planetary Studies Department. Use of materials without written consent from Joshua E. Balan or Dr. Greg Michalski is strictly prohibited.
