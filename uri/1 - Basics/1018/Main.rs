use std::io;

fn main() {
    let mut input = String::new();

    // Read input from the user
    io::stdin().read_line(&mut input).expect("Failed to read line");

    // Parse input to integer
    let inteiro: i32 = input.trim().parse().expect("Invalid input");

    // Print the original integer
    println!("{}", inteiro);

    let banknotes = [100, 50, 20, 10, 5, 2, 1];
    let mut aux = inteiro;

    for &div in banknotes.iter() {
        println!("{} nota(s) de R$ {},00", aux / div, div);
        aux = aux % div;
    }
}
