class Solution(object):
	fx = [(1, 0), (0, 1), (-1, 0), (0, -1)]
	def dfs(self, grid, i, j, r, c):
		#print(i,j)
		grid[i][j] = "2"
		for f in self.fx:
			if i + f[0] in range(r) \
			and j + f[1] in range(c) \
			and grid[i + f[0]][j + f[1]] == "1":
				self.dfs(grid, i + f[0], j + f[1], r, c)
	def numIslands(self, grid):
		"""
		:type grid: List[List[str]]
		:rtype: int
		"""
		r = len(grid)
		if r > 0:
			c = len(grid[0])
		ans = 0
		for i in range(r):
			for j in range(c):
				if grid[i][j] == "1":
					self.dfs(grid, i, j, r, c)
					ans += 1
		return ans
def main():
	sol = Solution()
	ex = ["11000",\
	"11000",\
	"00100",\
	"00011",]
	ex = [[y for y in x] for x in ex]
	print(ex)
	print(sol.numIslands(ex))
if __name__ == '__main__':
	main()