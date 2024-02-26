class Solution:

    def twoSum(self, num: List[int], target: int) -> List[int]:

        length = len(num)

        my_dict = {}

        i = 0

        while i < length:

            if my_dict.get(target - num[i]) != None:

                return [i,my_dict[target-num[i]]]

            else:

                my_dict[num[i]] = i

         

            i += 1

        print(my_dict)