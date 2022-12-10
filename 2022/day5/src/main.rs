use std::fs;

fn main() {
    let input: String = fs::read_to_string("data/input.txt").unwrap();
    let mut stacks: Vec<Vec<char>> = Vec::new();
    // read the lines backwards
    for line in input.lines().rev() {
        // skip arrange steps, but use stack number step
        if line.contains("move") || line.contains("\n") {
            continue;
        } else if line.contains("1") {
            let nums: Vec<&str> = line.split("\n").collect();
            let num_stacks: usize = nums[nums.len() - 1].parse().unwrap();
            for _ in 0..num_stacks {
                stacks.push(Vec::new());
            }
        }
        // push items onto stacks
        let mut stack_num: usize = 0;
        for word in line.split(' ') {
            let item: char = word.chars().nth(1).unwrap();
            let stack: &mut Vec<char> = &mut stacks[stack_num];
            stack.push(item);
            stack_num += 1
        }
    }
}
