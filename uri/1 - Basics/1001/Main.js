var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n').map(parseFloat);
const X = lines[0] + lines[1]
console.log(`X = ${X}`)
 