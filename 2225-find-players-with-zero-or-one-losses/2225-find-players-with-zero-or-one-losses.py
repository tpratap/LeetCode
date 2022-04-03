class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        mp = {}
        for match in matches:
            winneri = match[0]
            loseri = match[1]
            if winneri  not in mp:
                mp[winneri] = 0
            if loseri in mp: 
                mp[loseri] += 1
            else:
                mp[loseri] = 1
                
        lis1 = []
        lis2 = []
        for k , value in sorted(mp.items()):
            if value == 0:
                lis1.append(k)
            elif value == 1:
                lis2.append(k)
        return [lis1, lis2]
            