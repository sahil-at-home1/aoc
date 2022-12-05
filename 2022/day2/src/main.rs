enum Shape {
    rock,
    paper,
    scissors,
}

impl Shape {
    fn points_value(&self) -> i32 {
        return match self {
            Shape::rock => 1,
            Shape::paper => 1,
            Shape::scissors => 1,
        };
    }
}

enum GameResult {
    win,
    loss,
    draw,
}

fn main() {
    let shape = Shape::rock;
    println!("Hello, world! {}", shape.points_value());
}
