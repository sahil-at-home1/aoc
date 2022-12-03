use regex::Regex;
use std::fs;

#[derive(Debug, Clone, PartialEq)]
struct Elf {
    id: i32,
    snacks: Vec<i32>,
    total_calories: i32,
}

impl Elf {
    fn new(id: i32) -> Elf {
        Elf {
            id: id,
            snacks: Vec::new(),
            total_calories: 0,
        }
    }

    fn add_snack(&mut self, calories: i32) {
        self.snacks.push(calories);
        self.total_calories += calories;
    }
}

fn main() {
    // read data and create list of elves with their snacks
    let mut elves: Vec<Elf> = Vec::new();
    let contents: String = fs::read_to_string("data/input.txt").unwrap();
    let re = Regex::new(r"(\n[\n\r])").unwrap();
    for (i, snacks) in re.split(&contents).enumerate() {
        let mut elf = Elf::new(i.try_into().unwrap());
        for snack in snacks.trim().split('\n') {
            elf.add_snack(snack.trim().parse::<i32>().unwrap());
        }
        elves.push(elf);
    }

    // Part 1: find the elf with most calories in snacks
    let mut top_elves: Vec<&Elf> = Vec::new();
    const TOP_NUM: i32 = 3;
    // initialize top elves
    for i in 0..TOP_NUM {
        top_elves.push(&elves[i as usize]);
    }
    // compare against top elves
    for i in TOP_NUM..(elves.len() as i32) {
        for j in 0..TOP_NUM {
            if elves[i as usize].total_calories > top_elves[j as usize].total_calories {
                if top_elves.contains(&&elves[i as usize]) == false {
                    top_elves.insert(j as usize, &elves[i as usize]);
                }
            }
        }
    }
    let mut sum_of_top: i32 = 0;
    for (i, elf) in top_elves.iter().enumerate() {
        if i >= TOP_NUM as usize {
            break;
        }
        println!(
            "{}: Elf {} has calories in snacks: {}",
            elf.id, i, elf.total_calories
        );
        sum_of_top += elf.total_calories as i32;
    }
    println!(
        "Sum of top {} Elves' snacks' calories is {}",
        TOP_NUM, sum_of_top
    );

    // Part 2: find the elf with most calories in snacks
}
