var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n').map(parseFloat);
const R = parseFloat(lines[0])
const PI = 3.14159;
var A = PI * R * R;
console.log(`A=${A.toFixed(4)}`)