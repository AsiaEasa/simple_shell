#!/usr/bin/node
function add (x, y) {
  const i = x + y;
  console.log(i);
}

add(Number(process.argv[2]), Number(process.argv[3]));
