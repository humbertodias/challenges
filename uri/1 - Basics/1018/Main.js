var input = require("fs").readFileSync("/dev/stdin", "utf8");
var lines = input.split("\n").map(parseFloat);
const inteiro = parseInt(lines[0]);
console.log(`${inteiro}`);
const banknotes = [100, 50, 20, 10, 5, 2, 1];
var aux = inteiro;
for (var i = 0; i < banknotes.length; i++) {
  div = banknotes[i];
  console.log(`${parseInt(aux / div)} nota(s) de R$ ${div},00`);
  aux = aux % div;
}
