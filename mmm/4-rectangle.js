#!/usr/bin/node
module.exports = class Rectangle {
  constructor (w, h) {
    if (w > 0 && h > 0) {
      this.width = w;
      this.height = h;
    }
  }

  print () {
    let m = 0;
    while (m < this.height) {
      let X = '';
      let n = 0;
      while (n < this.width) {
        X += 'X';
        n++;
      }
      console.log(X);
      m++;
    }
  }

  rotate () {
    const temp = this.width;
    this.width = this.height;
    this.height = temp;
  }

  double () {
    this.width *= 2;
    this.height *= 2;
  }
};
