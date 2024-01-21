use std::io;

fn main() {

    let mut input_a = String::new();
    io::stdin().read_line(&mut input_a).expect("Failed to read input A");
    let a: i32 = input_a.trim().parse().expect("Invalid input A");

    let mut input_b = String::new();
    io::stdin().read_line(&mut input_b).expect("Failed to read input B");
    let b: i32 = input_b.trim().parse().expect("Invalid input B");

    let x = a + b;

    println!("X = {}", x);

    
}