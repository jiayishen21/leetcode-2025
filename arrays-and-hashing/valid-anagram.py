class Solution:
	def isAnagram(self, s: str, t: str) -> bool:
		sFreq = {}	
		tFreq = {}

		for char in s:
			sFreq[char] = sFreq.get(char, 0) + 1

		for char in t:
			tFreq[char] = tFreq.get(char, 0) + 1

		for char in sFreq:
			if sFreq[char] != tFreq.get(char, 0):
				return False
		for char in tFreq:
			if tFreq[char] != sFreq.get(char, 0):
				return False

		return True