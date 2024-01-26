var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');
var l1 = lines[0].split(' ').map(parseFloat)
var l2 = lines[1].split(' ').map(parseFloat)
var x1 = l1[0]
var y1 = l1[1]
var x2 = l2[0]
var y2 = l2[1]
const distance = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2))
console.log(distance.toFixed(4))