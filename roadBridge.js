const peoples = [
  {
    time: 5,
    cross: 0,
    name: "A",
  },
  {
    time: 10,
    cross: 0,
    name: "B",
  },
  {
    time: 1,
    cross: 0,
    name: "C",
  },
  {
    time: 2,
    cross: 0,
    name: "D",
  },
];

function roadBridge(peoples) {
  let time = 0;

  let left = [...peoples].sort((a, b) => a.time - b.time);
  let right = [];

  let fatest = left.shift();
  let secondFatest = left.shift();
  let secondLowest = left.shift();
  let lowest = left.shift();

  const fatestStrategie =
    fatest.time * 2 + secondFatest.time + lowest.time + secondLowest.time; // 1 * 2 + 2 + 5 + 10 = 19
  const lowestStrategie =
    secondLowest.time * 2 + lowest.time + fatest.time + secondFatest.time; // 5 * 2 + 10 + 1 + 2 = 23

  const medianStrategie = fatest.time + secondFatest.time * 3 + lowest.time; // 1 + 2 * 3 + 10 = 17

  time += Math.min(fatestStrategie, lowestStrategie, medianStrategie);

  return time;
}

console.log(roadBridge(peoples));
