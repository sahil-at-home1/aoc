use std::fs;

struct Compartment {
    items: Vec<char>,
}

impl Compartment {
    fn new() -> Compartment {
        Compartment { items: Vec::new() }
    }
}
struct Rucksack {
    c1: Compartment,
    c2: Compartment,
    common_item: Option<char>,
}

impl Rucksack {
    fn new() -> Rucksack {
        Rucksack {
            c1: Compartment::new(),
            c2: Compartment::new(),
            common_item: Option::None,
        }
    }

    fn find_common_item(&mut self) -> char {
        for item in &self.c1.items {
            if self.c2.items.contains(&item) {
                self.common_item = Option::Some(item.clone());
            }
        }
        panic!("No common items!")
    }
}

fn item_to_value(item: char) -> i32 {
    if !item.is_alphabetic() {
        panic!("Item is not alphabetic!");
    } else {
        let value = (item as i32) - ('a' as i32) + 1;
        return value;
    }
}

fn main() {
    let contents: String = fs::read_to_string("data/input.txt").unwrap();
    let mut rucksacks: Vec<Rucksack> = Vec::new();

    // collect all the items into rucksacks
    for line in contents.split("\n") {
        if line.trim() == "" {
            continue;
        }
        let mut rucksack = Rucksack::new();
        let items: Vec<char> = line.trim().chars().collect();
        rucksack.c1.items = items[0..(items.len() / 2)].to_vec();
        rucksack.c2.items = items[(items.len() / 2)..(items.len())].to_vec();
        rucksacks.push(rucksack)
    }
    // find the common it
}
