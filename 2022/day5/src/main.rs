use std::fs;

fn main() {
    let input: String = fs::read_to_string("data/test.txt").unwrap();
    let mut stacks: Vec<Vec<char>> = Vec::new();
    // read the lines backwards
    for line in input.lines().rev() {
        // skip arrange steps, but use stack number step
        if line.contains("move") || line.is_empty() {
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
        for word in line.split_whitespace() {
            let item: char = word.chars().nth(1).unwrap();
            let stack: &mut Vec<char> = &mut stacks[stack_num];
            stack.push(item);
            stack_num += 1
        }
    }
    // move items across stacks based on steps
    for line in input.lines() {
        if !line.contains("move") {
            continue;
        }
        let words: Vec<&str> = line.split_whitespace().collect();
        let num_to_move: usize = words[1].parse::<usize>().unwrap();
        let from_idx: usize = words[3].parse::<usize>().unwrap() - 1;
        let to_idx: usize = words[5].parse::<usize>().unwrap() - 1;
        for _ in 0..num_to_move {
            let item_to_move: char = stacks[from_idx].pop().unwrap();
            stacks[to_idx].push(item_to_move);
        }
    }
    // print the items on the top of each stack
    print!("The items on the top of each stack are: ");
    for stack in stacks {
        print!("{}", stack[stack.len()]);
    }
}
