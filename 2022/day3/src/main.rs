use std::fs;

// #[derive(Debug)]
// struct Compartment {
//     items: Vec<char>,
// }

// impl Compartment {
//     fn new() -> Compartment {
//         Compartment { items: Vec::new() }
//     }
// }

#[derive(Debug)]
struct Rucksack {
    // c1: Compartment,
    // c2: Compartment,
    items: Vec<char>,
}

impl Rucksack {
    fn new() -> Rucksack {
        Rucksack {
            // c1: Compartment::new(),
            // c2: Compartment::new(),
            items: Vec::new(),
        }
    }

    // fn find_common_item(&mut self) -> Option<char> {
    //     for item in &self.c1.items {
    //         if self.c2.items.contains(&item) {
    //             return Option::Some(item.clone());
    //         }
    //     }
    //     return Option::None;
    // }
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
    let mut item_sum: i32 = 0;

    // collect all the items into rucksacks
    const GROUP_SIZE: usize = 3;
    let mut group: Vec<Rucksack> = Vec::new();
    for line in contents.split("\n") {
        if line.trim() == "" {
            continue;
        }
        let mut rucksack = Rucksack::new();
        rucksack.items.append(&mut line.trim().chars().collect());
        group.push(rucksack);
        if group.len() >= GROUP_SIZE {
            let r1 = &group[0];
            let r2 = &group[1];
            let r3 = &group[2];
            for item in &r1.items {
                if r2.items.contains(&item) && r3.items.contains(&item) {
                    item_sum += item_to_value(item.clone());
                    break;
                }
            }
            // println!("{:?}\n", group);
            group.clear();
        }
    }
    println!("Sum of common items is {}", item_sum);
}
