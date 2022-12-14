use std::fs;

type Section = Option<Vec<i32>>;
type SectionPair = [Section; 2];

fn main() {
    let contents: String = fs::read_to_string("data/input.txt").unwrap();
    let mut section_pairs: Vec<SectionPair> = Vec::new();

    for line in contents.split('\n') {
        if line.trim().is_empty() {
            continue;
        }
        let sections: Vec<&str> = line.split(',').collect();
        let mut pair: SectionPair = [None, None];
        for i in 0..sections.len() {
            let nums_str: Vec<&str> = sections[i].split('-').collect();
            let start: i32 = nums_str[0].trim().parse().unwrap();
            let end: i32 = nums_str[1].trim().parse().unwrap();
            pair[i] = Some((start..=end).collect());
        }
        section_pairs.push(pair);
    }
    let mut num_overlapping_pairs: i32 = 0;
    for pair in section_pairs {
        println!("{:?}", pair);
        let mut is_overlapping: bool = false;
        for num in pair[0].clone().unwrap() {
            if pair[1].clone().unwrap().contains(&num) {
                is_overlapping = true;
                break;
            }
        }
        if is_overlapping {
            num_overlapping_pairs += 1;
            continue;
        }
    }

    println!("Number of overlapping pairs: {}", num_overlapping_pairs);
}
