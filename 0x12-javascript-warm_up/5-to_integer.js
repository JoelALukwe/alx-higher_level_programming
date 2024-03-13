#!/usr/bin/node
/*
 * this syntax block is used to check if the argument is an integer at first
 *
 * */
if (isNaN(process.argv[2]) || process.argv[2] === undefined) {
  console.log('Not a number');
} else {
  console.log('My number:', parseInt(process.argv[2]));
}
