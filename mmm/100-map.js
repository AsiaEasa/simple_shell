#!/usr/bin/node
const { list } = require('./100-data');
const N = list.map((value, index) => value * index);
console.log(list);
console.log(N);
