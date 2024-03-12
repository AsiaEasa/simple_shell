#!/usr/bin/node

let X = 0;

exports.logMe = function (item) {
  console.log(`${X}: ${item}`);
  X++;
};
