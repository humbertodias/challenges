var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n').map(parseFloat);
const a = parseFloat(lines[0])
const b = parseFloat(lines[1])
const f = (a*b)/12.0
console.log(`${f.toFixed(3)}`)