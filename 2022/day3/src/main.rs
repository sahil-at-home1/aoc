use std::fs;

#[derive(Debug)]
struct Compartment {
    items: Vec<char>,
}

impl Compartment {
    fn new() -> Compartment {
        Compartment { items: Vec::new() }
    }
}

#[derive(Debug)]
struct Rucksack {
    c1: Compartment,
    c2: Compartment,
}

impl Rucksack {
    fn new() -> Rucksack {
        Rucksack {
            c1: Compartment::new(),
            c2: Compartment::new(),
        }
    }

    fn find_common_item(&mut self) -> Option<char> {
        for item in &self.c1.items {
            if self.c2.items.contains(&item) {
                return Option::Some(item.clone());
            }
        }
        return Option::None;
    }
}

fn item_to_value(item: char) -> i32 {
    let mut letters: Vec<char> = ('a'..='z').collect();
    let mut uppers: Vec<char> = ('A'..='Z').collect();
    letters.append(&mut uppers);
    if !item.is_alphabetic() {
        panic!("Item is not alphabetic!");
    } else {
        let idx: i32 = letters.iter().position(|&x| x == item).unwrap() as i32;
        return idx + 1;
    }
}

fn main() {
    let contents: String = fs::read_to_string("data/input.txt").unwrap();
    // let mut rucksacks: Vec<Rucksack> = Vec::new();
    let mut item_sum: i32 = 0;

    // collect all the items into rucksacks
    for line in contents.split("\n") {
        if line.trim() == "" {
            continue;
        }
        let mut rucksack = Rucksack::new();
        let items: Vec<char> = line.trim().chars().collect();
        rucksack.c1.items = items[0..(items.len() / 2)].to_vec();
        rucksack.c2.items = items[(items.len() / 2)..(items.len())].to_vec();
        // find the common item
        // println!("{:#?}", rucksack);
        let common_item: char = rucksack.find_common_item().unwrap();
        let common_item_val: i32 = item_to_value(common_item);
        println!("{}: {}", common_item, common_item_val);
        item_sum += common_item_val;
        // rucksacks.push(rucksack)
    }

    println!("Sum of common items is {}", item_sum);
}
