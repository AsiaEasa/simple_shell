#!/usr/bin/node
function factorial (N) {
  if (N < 0) {
    return (-1);
  }
  if (N === 0 || isNaN(N)) {
    return (1);
  }
  return (N * factorial(N - 1));
}

console.log(factorial(Number(process.argv[2])));
