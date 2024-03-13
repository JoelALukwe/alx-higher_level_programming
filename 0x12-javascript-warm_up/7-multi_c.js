#!/usr/bin/node
/*
* process.argv[2]: This is an array containing the command line arguments provided when the script is executed.
* process.argv[0] is the path to the Node.js executable,
* process.argv[1] is the path to the script being executed,
* and process.argv[2] is the first command line argument provided by the user.
*
*
* if (process.argv[2] === undefined || isNaN(process.argv[2])):
* This condition checks if the first command line argument is either undefined or not a number.
* If this condition is true, it means the user did not provide a valid number of occurrences.
*
*
* console.log('Missing number of occurrences'): If the condition in the if statement is true,
* this line prints the message "Missing number of occurrences" to the console.else: If the condition in the if statement is false,
* this block of code is executed.const x = Number(process.argv[2]);: This line converts the command line argument provided by the user(
* which is assumed to be a valid number) into a number and assigns it to the variable x.
* let i = 0;: This line initializes a variable i with a value of 0. This variable will be used as a counter in the loop.
* while (i < x) { ... }: This is a while loop that iterates x times. It continues looping as long as the value of i is less than x.
* console.log('C is fun');: Inside the loop, this line prints the message "C is fun" to the console.
* i++;: This line increments the value of i by 1 in each iteration of the loop.
*
*
*/
if (process.argv[2] === undefined || isNaN(process.argv[2])) {
  console.log('Missing number of occurrences');
} else {
  const x = Number(process.argv[2]);
  let i = 0;
  while (i < x) {
    console.log('C is fun');
    i++;
  }
}
