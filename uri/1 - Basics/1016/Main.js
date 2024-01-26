var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n').map(parseFloat);
const a = parseFloat(lines[0])
console.log(`${(a*60)/30} minutos`)