use regex::Regex;
use std::fs;

struct Elf {
    snacks: Vec<i32>,
    total_calories: i32,
}

impl Elf {
    fn new() -> Elf {
        Elf {
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
    for snacks in re.split(&contents) {
        let mut elf = Elf::new();
        for snack in snacks.trim().split('\n') {
            elf.add_snack(snack.trim().parse::<i32>().unwrap());
        }
        elves.push(elf);
    }

    // Part 1: find the elf with most calories in snacks
    let mut max_calories: i32 = 0;
    let mut max_elf_idx: usize = 0;
    for i in 0..elves.len() {
        let elf: &Elf = &elves[i];
        if elf.total_calories >= max_calories {
            max_calories = elf.total_calories;
            max_elf_idx = i;
        }
    }
    println!("Elf {max_elf_idx} has the maximum amount of calories in snacks: {max_calories}");

    // Part 2: find the elf with most calories in snacks
}
