use std::fs;

fn main() {
    let input: String = fs::read_to_string("data/input.txt").unwrap();
    let mut stacks: Vec<Vec<char>> = Vec::new();
    // read the lines backwards
    for line in input.lines().rev() {
        // skip arrange steps,
        if line.contains("move") || line.trim().is_empty() {
            continue;
        }
        // use number of stacks to initialize list of stacks
        if line.contains("1") {
            let nums: Vec<&str> = line.split_whitespace().collect();
            let num_stacks: usize = nums[nums.len() - 1].parse().unwrap();
            for _ in 0..num_stacks {
                stacks.push(Vec::new());
            }
            continue;
        }
        // push items onto stacks
        let mut stack_idx: usize = 0;
        let letters: Vec<char> = line.chars().collect();
        // each item is 3 chars apart
        for i in 0..letters.len() {
            let item: char = letters[i];
            if item.is_alphabetic() {
                let stack: &mut Vec<char> = &mut stacks[stack_idx];
                stack.push(item);
            }
            // integer division
            stack_idx = i / 4;
        }
    }
    for stack in &stacks {
        println!("{:?}", stack);
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
            println!("moving item from {} to {}", from_idx, to_idx);
            let item_to_move: char = stacks[from_idx].pop().unwrap();
            stacks[to_idx].push(item_to_move);
        }
    }
    // print the items on the top of each stack
    print!("The items on the top of each stack are: ");
    for stack in stacks {
        print!("{}", stack[stack.len() - 1]);
    }
}
