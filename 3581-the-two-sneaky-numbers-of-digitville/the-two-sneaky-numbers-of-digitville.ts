function getSneakyNumbers(nums: number[]): number[] {
  let res: number[] = [];
  const seen = new Set<number>();
  for (const num of nums) {
    if (seen.has(num))
      res.push(num);
    else
      seen.add(num);
  }
  return res;
};