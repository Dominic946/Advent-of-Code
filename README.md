# Advent-of-Code
These are my solutions to [Advent of Code](https://adventofcode.com/) problems.
I started doing Advent of Code in 2021, and I plan to keep doing it every year.

My solutions for each year are in their respective folder, except I didn't save my 2021 solutions.

## To run:
- You must have a directory titled `Inputs`, as well as a within that directory titled `Day##.txt`, that includes the input data for day ##.
  - For example, there must exist files `2022/Inputs/Day1.txt` or `2022/Inputs/Day24.txt` if you wish to run the 2022 code for Day 1 or 24 respectively.
  - I did not push the the `Inputs` folder nor my input text to github, because [the creator of advent of code specifically asked](https://mobile.twitter.com/ericwastl/status/1465805354214830081) for people to not share their input data.
  
 - To run any C++ code (which is all of my 2022 solutions), just compile and run like any C++ program.
   - I like to do `g++ src/Day14/main.cc` to compile, and `./a.out` to run. Pretty basic stuff, but it works for me.
  
 ## Notes:
 Not all days have a working solution.
 - Some days were too hard for my to even attempt at the time, and don't even have a code file for that day.
 - Some days, I made an attempt but couldn't solve, so the code just doesn't give the right answer.
 - Other days may only have a solution for part 1, but not part 2.
 - Some days/parts may have a solution that works in theory, but is very inefficient and therefore has an rediculously long runtime.
 - To see the answer for part 1 vs part 2:
   - Some days have one `main.cc` program that prints the answer for both parts.
   - For some days, I solved part 1 and then overwrote my part 1 code to with my part 2 code. On these days, the code will only give an answer for part 2, although it shouldn't be too hard to modify most of them back to give the part 1 answers again.
   - On other days, I did make 2 seperate files `main.cc` and `part2.cc`, where running main.cc gives the part 1 answer, and running part2.cc give the part 2 answer.
