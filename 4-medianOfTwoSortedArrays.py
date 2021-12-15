class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        parM = (m - 1) // 2
        parN = (m + n + 1) // 2 - parM
        
        rightM = nums1[parM]
        leftM = nums1[parM-1]
        rightN = nums2[parN]
        leftN = nums2[parN-1]
        while leftM > rightN or leftN > rightM:
            if leftM > rightN:
                parN += 1
            else:
                parN -= 1
            rightN = nums2[parN]
            leftN = nums2[parN-1]
        rightM = nums1[parM]
        leftM = nums1[parM-1]
        print("{}, {}".format(parM, parN))
        # even combined length
        if m + n % 2 == 0:
            return 
        # odd combined length
        else:
            return max(leftM, leftN)
            
  #1 [1,3|8,9,15] 2
  #2 [7|11,18,19,21,25] 4


# [1,1,2,2,3,|3|,4,6,6,8,10]
