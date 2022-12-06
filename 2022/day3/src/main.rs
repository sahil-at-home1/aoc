use std::fs;

struct Compartment {
    items: Vec<char>,
}
struct Rucksack {
    compartments: [Compartment; 2],
}

fn item_to_value(item: char) -> i32 {
    if !item.is_alphabetic() {
        panic!("Item is not alphabetic!");
    } else {
        let value = (item as i32) - ('a' as i32);
        return value;
    }
}

fn main() {
    let contents: String = fs::read_to_string("data/input.txt").unwrap();
    for line in contents.split("\n") {
        if line.trim() == "" {
            continue;
        }
    }
}
