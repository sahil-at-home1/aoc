use std::fmt;
use std::fs;

#[derive(Clone, Copy, Debug)]
enum Shape {
    Rock,
    Paper,
    Scissors,
}

impl Shape {
    fn new(lett: String) -> Shape {
        let letter = lett.trim();
        if letter == "A" || letter == "X" {
            return Shape::Rock;
        } else if letter == "B" || letter == "Y" {
            return Shape::Paper;
        } else if letter == "C" || letter == "Z" {
            return Shape::Scissors;
        } else {
            panic!("invalid letter: {}", letter);
        }
    }
    fn points(&self) -> i32 {
        return match self {
            Shape::Rock => 1,
            Shape::Paper => 2,
            Shape::Scissors => 3,
        };
    }
}

#[derive(Clone, Copy, Debug)]
enum GameResult {
    Win,
    Loss,
    Draw,
}
impl GameResult {
    // fn new(op_choice: Shape, my_choice: Shape) -> GameResult {
    //     return match (op_choice, my_choice) {
    //         (Shape::Rock, Shape::Rock) => GameResult::Draw,
    //         (Shape::Rock, Shape::Paper) => GameResult::Win,
    //         (Shape::Rock, Shape::Scissors) => GameResult::Loss,
    //         (Shape::Paper, Shape::Rock) => GameResult::Loss,
    //         (Shape::Paper, Shape::Paper) => GameResult::Draw,
    //         (Shape::Paper, Shape::Scissors) => GameResult::Win,
    //         (Shape::Scissors, Shape::Rock) => GameResult::Win,
    //         (Shape::Scissors, Shape::Paper) => GameResult::Loss,
    //         (Shape::Scissors, Shape::Scissors) => GameResult::Draw,
    //     };
    // }

    fn new(lett: String) -> GameResult {
        let letter = lett.trim();
        if letter == "X" {
            GameResult::Loss
        } else if letter == "Y" {
            GameResult::Draw
        } else if letter == "Z" {
            GameResult::Win
        } else {
            panic!("invalid letter {}", letter);
        }
    }

    fn points(&self) -> i32 {
        return match self {
            GameResult::Loss => 0,
            GameResult::Draw => 3,
            GameResult::Win => 6,
        };
    }
}

struct Game {
    op_choice: Shape,
    my_choice: Shape,
    result: GameResult,
}

impl Game {
    // fn new(op_choice: Shape, my_choice: Shape) -> Game {
    //     Game {
    //         op_choice: op_choice,
    //         my_choice: my_choice,
    //         result: GameResult::new(op_choice, my_choice),
    //     }
    // }
    fn new(op_choice: Shape, result: GameResult) -> Game {
        let my_choice = match (op_choice, result) {
            (Shape::Rock, GameResult::Loss) => Shape::Scissors,
            (Shape::Rock, GameResult::Draw) => Shape::Rock,
            (Shape::Rock, GameResult::Win) => Shape::Paper,
            (Shape::Paper, GameResult::Loss) => Shape::Rock,
            (Shape::Paper, GameResult::Draw) => Shape::Paper,
            (Shape::Paper, GameResult::Win) => Shape::Scissors,
            (Shape::Scissors, GameResult::Loss) => Shape::Paper,
            (Shape::Scissors, GameResult::Draw) => Shape::Scissors,
            (Shape::Scissors, GameResult::Win) => Shape::Rock,
        };
        Game {
            op_choice: op_choice,
            my_choice: my_choice,
            result: result,
        }
    }

    fn points(&self) -> i32 {
        self.my_choice.points() + self.result.points()
    }
}

impl fmt::Display for Game {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let points = self.my_choice.points() + self.result.points();
        write!(
            f,
            "(Op: {:?}, My: {:?}) {:?} = {} pts.",
            self.op_choice, self.my_choice, self.result, points,
        )
    }
}

fn main() {
    let contents: String = fs::read_to_string("data/input.txt").unwrap();
    let mut games: Vec<Game> = Vec::new();
    for line in contents.split("\n") {
        if line.trim() == "" {
            continue;
        }
        let mut letters: Vec<String> = line.split(" ").map(String::from).collect();
        // let my_choice = Shape::new(letters.pop().unwrap());
        let result = GameResult::new(letters.pop().unwrap());
        let op_choice = Shape::new(letters.pop().unwrap());
        games.push(Game::new(op_choice, result));
    }
    let mut total_points: i32 = 0;
    for game in games {
        println!("{}", game);
        total_points += game.points();
    }
    println!("Total points: {}", total_points);
}
