#!/usr/bin/node
exports.nbOccurences = function (list, searchElement) {
  let N = 0;
  let i = 0;
  while (i < list.length) {
    if (searchElement === list[i]) {
      N++;
    }
    i++;
  }
  return N;
};
