#!/usr/bin/node

const { dict } = require('./101-data');
const U = {};

for (const u in dict) {
  const O = dict[u];
  if (!U[O]) {
    U[O] = [];
  }
  U[O].push(u);
}

console.log(U);
