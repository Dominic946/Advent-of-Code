# Advent-of-Code
These are my solutions to [Advent of Code](https://adventofcode.com/) problems.
I started doing Advent of Code in 2021, and I plan to keep doing it every year.

My solutions for each year are in their respective folder.

## To run:
- You must have a directory titled `inputs`, as well as a file within that directory titled `day##.txt`, that includes the input data for day ##.
  - For example, there must exist file `2023/inputs/day10.txt` if you wish to run the 2023 code for Day 10.
  - I did not push the the input files to github, because [the creator of advent of code specifically asked](https://mobile.twitter.com/ericwastl/status/1465805354214830081) for people to not share their input data.
  
- To run any Python code (which is all of the 2023 and 2024 sultions), run like a standard Python file, `python3 day1.py`
   - Though I do also have the files start with `#!/usr/bin/python3` so I can run them by simply typing `./day1.py` instead of doing `python3 day1.py`, it is a small optimization for when I was trying for speed. But recently I have been doing Advent of Code only for fun, not for speed.

 - To run any C++ code (which is all of my 2022 solutions), just compile and run like any C++ program.
   - I like to do `g++ src/Day14/main.cc` to compile, and `./a.out` to run. Pretty basic stuff, but it works for me.

- To run Java code (which was my 2021 solutions), I don't entirely remember how my 2021 solutions work because it was a long time ago and I didn't document my process at all back then. So just run it I guess; I probably just clicked the run button in my IDE. And in fact, the input files for this 2021 code may need to be in the same directory as the src code, rather than in a separate `../inputs` directory.


 ## Notes:
 Not all days have a working solution.
 - Some days were too hard for me to attempt at the time, and either don't have a code file for that day, or just have my default template file for that day
 - Some days, I made an attempt but couldn't solve, so the code just doesn't give the right answer.
 - Other days may only have a solution for part 1, but not part 2.
 - Some days/parts may have a solution that works in theory, but is very inefficient and therefore has an rediculously long runtime.
 - To see the answer for part 1 vs part 2:
   - Some days have one main program that prints the answer for both parts.
   - For some days, I solved part 1 and then overwrote my part 1 code to with my part 2 code. On these days, the code will only give an answer for part 2, although it shouldn't be too hard to modify most of them back to give the part 1 answers again.
   - On other days, I did make 2 seperate files `main.cc` and `part2.cc`, where running main.cc gives the part 1 answer, and running part2.cc give the part 2 answer, for example.

My python src directories (`2023/src` and `2024/src`) contain a file `create.py`, this is the script I wrote that I can run at the start of each year to easily create src files with my base template code for every day, and create an input file for every day.