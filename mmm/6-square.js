#!/usr/bin/node
const SquareP = require('./5-square');

module.exports = class Square extends SquareP {
  charPrint (c) {
    if (c === undefined) {
      c = 'X';
    }
    let i = 0;
    while (i < this.height) {
      let s = '';
      let j = 0;
      while (j < this.width) {
        s += c;
        j++;
      }
      console.log(s);
      i++;
    }
  }
};
